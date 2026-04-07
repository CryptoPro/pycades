set(pycades_LIB_SRCS
        PyCades.cpp PyCadesAbout.cpp PyCadesAlgorithm.cpp PyCadesAttribute.cpp PyCadesAttributes.cpp
        PyCadesBasicConstraints.cpp PyCadesBlobs.cpp PyCadesCertificate.cpp PyCadesCertificates.cpp
        PyCadesCertificateStatus.cpp PyCadesCRL.cpp PyCadesEncodedData.cpp PyCadesEnvelopedData.cpp
        PyCadesEKU.cpp PyCadesEKUs.cpp PyCadesExtension.cpp PyCadesExtensions.cpp PyCadesExtendedKeyUsage.cpp
        PyCadesHashedData.cpp PyCadesKeyUsage.cpp PyCadesOID.cpp PyCadesPrivateKey.cpp PyCadesPublicKey.cpp
        PyCadesRawSignature.cpp PyCadesRecipients.cpp PyCadesSignatureStatus.cpp PyCadesSignedData.cpp
        PyCadesSignedXML.cpp PyCadesSigner.cpp PyCadesSigners.cpp PyCadesStore.cpp PyCadesSymmetricAlgorithm.cpp
        PyCadesVersion.cpp PyEnrollContainer.cpp PyEnrollContainers.cpp PyEnrollContainerKey.cpp
        PyEnrollContainerKeys.cpp PyEnrollCspInformation.cpp
)

if(DEFINED PY_BUILD_CMAKE_IMPORT_NAME AND NOT "${PY_BUILD_CMAKE_IMPORT_NAME}" STREQUAL "")
    set (TARGET_NAME "_pycades")

    message("-- Applying ${CMAKE_CURRENT_SOURCE_DIR}/../patches/001-rename-lib.patch")

    execute_process(
        COMMAND ${Patch_EXECUTABLE} -p1 -i ${CMAKE_CURRENT_SOURCE_DIR}/../patches/001-rename-lib.patch
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/..   # Подняться на уровень выше
        RESULT_VARIABLE PATCH_RESULT
    )

    if(NOT PATCH_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to apply patch")
    endif()

    Python3_add_library(pycades MODULE ${pycades_LIB_SRCS} WITH_SOABI)

    set_target_properties(pycades PROPERTIES
        PREFIX ""
        OUTPUT_NAME ${TARGET_NAME}
    )

    install(TARGETS pycades
        EXCLUDE_FROM_ALL
        COMPONENT python_modules
        DESTINATION ${PY_BUILD_CMAKE_IMPORT_NAME})

    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/pycades.pyi
        DESTINATION ${PY_BUILD_CMAKE_IMPORT_NAME}
        RENAME _pycades.pyi
        COMPONENT python_modules)

else()
    set (TARGET_NAME "pycades")

    add_library(pycades SHARED ${pycades_LIB_SRCS})

    set_target_properties(pycades PROPERTIES
        PREFIX ""
        OUTPUT_NAME ${TARGET_NAME}
    )

    add_custom_command(TARGET pycades
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> "${CMAKE_SOURCE_DIR}/samples/"
        COMMENT "Copying pycades module to samples directory"
    )

endif()



target_compile_definitions(pycades PRIVATE
    UNIX
    SIZEOF_VOID_P=${CMAKE_SIZEOF_VOID_P}
    PYCADES_VERSION="${PYCADES_VERSION}"
    CPRO_CADES_VERSION_MAJOR=${CPRO_CADES_VERSION_MAJOR}
    CPRO_CADES_VERSION_MINOR=${CPRO_CADES_VERSION_MINOR}
    CPRO_CADES_VERSION_BUILD=${CPRO_CADES_VERSION_BUILD}
)

if(CMAKE_SYSTEM_PROCESSOR MATCHES "arm64|aarch64")
    target_compile_definitions(pycades PRIVATE
        LINUX
        PROC_TYPE_ARM64=7
        PROCESSOR_TYPE=PROC_TYPE_ARM64
    )
endif()

target_compile_options(pycades PRIVATE
    -Wno-write-strings
    -Wno-deprecated-declarations
    -Wno-narrowing
)

target_include_directories(pycades PRIVATE
    ${Boost_INCLUDE_DIRS}
    ${Python3_INCLUDE_DIRS}
    /opt/cprocsp/include
    /opt/cprocsp/include/cpcsp
    /opt/cprocsp/include/pki/atl
    /opt/cprocsp/include/pki/cppcades
    /opt/cprocsp/include/pki/cplib
    /opt/cprocsp/include/pki
    ${CMAKE_CURRENT_SOURCE_DIR}/cplib
)


find_library(FOUND_LIB_CPPCADES
    NAMES cppcades
    HINTS /opt/cprocsp/lib/amd64 /opt/cprocsp/lib/ia32 /opt/cprocsp/lib/aarch64)

find_library(FOUND_LIB_CPLIB
    NAMES cplib
    HINTS /opt/cprocsp/lib/amd64 /opt/cprocsp/lib/ia32 /opt/cprocsp/lib/aarch64)

target_link_libraries(pycades PRIVATE
    ${FOUND_LIB_CPPCADES}
    ${FOUND_LIB_CPLIB}
)


