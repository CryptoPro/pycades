cmake_minimum_required(VERSION 3.15...3.27)

set(PYCADES_VERSION "0.1.70200")

project(
    pycades
    LANGUAGES CXX
    VERSION ${PYCADES_VERSION}
)

if (CMAKE_VERSION VERSION_LESS 3.18)
  set(DEV_MODULE Development)
else()
  set(DEV_MODULE Development.Module)
endif()

find_package(Python COMPONENTS Interpreter ${DEV_MODULE} REQUIRED)

set(CMAKE_CXX_STANDARD 11)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/ext)

set(pycades_LIB_SRCS
    ${SRC_DIR}/errormsg.cpp
    ${SRC_DIR}/PyCades.cpp
    ${SRC_DIR}/PyCadesAbout.cpp
    ${SRC_DIR}/PyCadesAlgorithm.cpp
    ${SRC_DIR}/PyCadesAttribute.cpp
    ${SRC_DIR}/PyCadesAttributes.cpp
    ${SRC_DIR}/PyCadesBasicConstraints.cpp
    ${SRC_DIR}/PyCadesBlobs.cpp
    ${SRC_DIR}/PyCadesCertificate.cpp
    ${SRC_DIR}/PyCadesCertificates.cpp
    ${SRC_DIR}/PyCadesCertificateStatus.cpp
    ${SRC_DIR}/PyCadesCRL.cpp
    ${SRC_DIR}/PyCadesEncodedData.cpp
    ${SRC_DIR}/PyCadesEnvelopedData.cpp
    ${SRC_DIR}/PyCadesEKU.cpp
    ${SRC_DIR}/PyCadesEKUs.cpp
    ${SRC_DIR}/PyCadesExtension.cpp
    ${SRC_DIR}/PyCadesExtensions.cpp
    ${SRC_DIR}/PyCadesExtendedKeyUsage.cpp
    ${SRC_DIR}/PyCadesHashedData.cpp
    ${SRC_DIR}/PyCadesKeyUsage.cpp
    ${SRC_DIR}/PyCadesOID.cpp
    ${SRC_DIR}/PyCadesPrivateKey.cpp
    ${SRC_DIR}/PyCadesPublicKey.cpp
    ${SRC_DIR}/PyCadesRawSignature.cpp
    ${SRC_DIR}/PyCadesRecipients.cpp
    ${SRC_DIR}/PyCadesSignatureStatus.cpp
    ${SRC_DIR}/PyCadesSignedData.cpp
    ${SRC_DIR}/PyCadesSignedXML.cpp
    ${SRC_DIR}/PyCadesSigner.cpp
    ${SRC_DIR}/PyCadesSigners.cpp
    ${SRC_DIR}/PyCadesStore.cpp
    ${SRC_DIR}/PyCadesSymmetricAlgorithm.cpp
    ${SRC_DIR}/PyCadesVersion.cpp
    ${SRC_DIR}/PyEnrollContainer.cpp
    ${SRC_DIR}/PyEnrollContainers.cpp
    ${SRC_DIR}/PyEnrollContainerKey.cpp
    ${SRC_DIR}/PyEnrollContainerKeys.cpp
    ${SRC_DIR}/PyEnrollCspInformation.cpp
)

find_package(Boost REQUIRED)

execute_process(
    COMMAND bash -c "if type dpkg > /dev/null 2>&1; then dpkg -l | grep cprocsp-pki-cades | awk '{print \$3}'; else rpm -qa | grep cprocsp-pki-cades; fi | cut -d. -f1 | cut -d- -f1"
    OUTPUT_VARIABLE CPRO_CADES_VERSION_MAJOR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND bash -c "if type dpkg > /dev/null 2>&1; then dpkg -l | grep cprocsp-pki-cades | awk '{print \$3}'; else rpm -qa | grep cprocsp-pki-cades; fi | cut -d. -f2 | cut -d- -f1"
    OUTPUT_VARIABLE CPRO_CADES_VERSION_MINOR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND bash -c "if type dpkg > /dev/null 2>&1; then dpkg -l | grep cprocsp-pki-cades | awk '{print \$3}'; else rpm -qa | grep cprocsp-pki-cades; fi | cut -d. -f3 | cut -d- -f1"
    OUTPUT_VARIABLE CPRO_CADES_VERSION_BUILD
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

message("-- Found cprocsp-pki-cades: ${CPRO_CADES_VERSION_MAJOR}.${CPRO_CADES_VERSION_MINOR}.${CPRO_CADES_VERSION_BUILD}")


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-write-strings -Wno-deprecated-declarations -Wno-narrowing")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(pycades_DIRS
    /opt/cprocsp/include
    /opt/cprocsp/include/cpcsp
    /opt/cprocsp/include/pki/atl
    /opt/cprocsp/include/pki/cppcades
    /opt/cprocsp/include/pki/cplib
    /opt/cprocsp/include/pki
    ${SRC_DIR}
    ${SRC_DIR}/cplib
)

include_directories(
    ${Boost_INCLUDE_DIRS}
    ${Python_INCLUDE_DIRS}
    ${pycades_DIRS}
)

Python_add_library(_pycades MODULE ${pycades_LIB_SRCS} WITH_SOABI)

target_compile_definitions(_pycades PRIVATE
    UNIX
    SIZEOF_VOID_P=${CMAKE_SIZEOF_VOID_P}
    CPRO_CADES_VERSION_MAJOR=${CPRO_CADES_VERSION_MAJOR}
    CPRO_CADES_VERSION_MINOR=${CPRO_CADES_VERSION_MINOR}
    CPRO_CADES_VERSION_BUILD=${CPRO_CADES_VERSION_BUILD}
    PYCADES_VERSION="${PROJECT_VERSION}"
)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|arm64|ARM64")
    target_compile_definitions(_pycades PRIVATE
        LINUX
        PROC_TYPE_ARM64=7
        PROCESSOR_TYPE=PROC_TYPE_ARM64
    )
    message("-- Enabled ARM64-specific definitions")
endif()

find_library(FOUND_LIB_CPPCADES
    NAMES cppcades
    HINTS
        /opt/cprocsp/lib/amd64
        /opt/cprocsp/lib/ia32
        /opt/cprocsp/lib/aarch64
    REQUIRED
)

target_link_libraries(_pycades PRIVATE ${FOUND_LIB_CPPCADES})

if(DEFINED PY_BUILD_CMAKE_IMPORT_NAME AND NOT "${PY_BUILD_CMAKE_IMPORT_NAME}" STREQUAL "")
    install(TARGETS _pycades
        EXCLUDE_FROM_ALL
        COMPONENT python_modules
        DESTINATION ${PY_BUILD_CMAKE_IMPORT_NAME})
endif()
