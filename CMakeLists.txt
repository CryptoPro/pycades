cmake_minimum_required(VERSION 3.18)

set(PYCADES_VERSION "0.1.70200")
project(PythonModule
    LANGUAGES CXX
    VERSION ${PYCADES_VERSION}
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(DEFINED ENV{REMOTE_CONTAINERS})
    message(STATUS "Dev Container detected: Forcing Debug build")
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "" FORCE)
endif()

find_package(Python3 REQUIRED COMPONENTS Development.Module)
find_package(Boost REQUIRED)
find_package(Patch REQUIRED)

execute_process(
    COMMAND bash -c "if type dpkg > /dev/null 2>&1; then dpkg -l|grep cprocsp-pki-cades|awk ' { print $3 } '; else rpm -qa|grep cprocsp-pki-cades; fi|cut -d. -f1|cut -d- -f1"
    OUTPUT_VARIABLE CPRO_CADES_VERSION_MAJOR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND bash -c "if type dpkg > /dev/null 2>&1; then dpkg -l|grep cprocsp-pki-cades|awk ' { print $3 } '; else rpm -qa|grep cprocsp-pki-cades; fi|cut -d. -f2|cut -d- -f1"
    OUTPUT_VARIABLE CPRO_CADES_VERSION_MINOR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND bash -c "if type dpkg > /dev/null 2>&1; then dpkg -l|grep cprocsp-pki-cades|awk ' { print $3 } '; else rpm -qa|grep cprocsp-pki-cades; fi|cut -d. -f3|cut -d- -f1"
    OUTPUT_VARIABLE CPRO_CADES_VERSION_BUILD
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
message("-- cprocsp-pki-cades: ${CPRO_CADES_VERSION_MAJOR}.${CPRO_CADES_VERSION_MINOR}.${CPRO_CADES_VERSION_BUILD}")

add_subdirectory(src)
