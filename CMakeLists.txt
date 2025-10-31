cmake_minimum_required(VERSION 3.10)
project(OPE_Design)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPED_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Root directory of OPEN Design project" FORCE)

include(ExternalProject)

ExternalProject_Add(OpenCASCADE
    GIT_REPOSITORY https://git.dev.opencascade.org/repos/occt.git
    GIT_TAG master
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/download/occt
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/install
        -DCMAKE_BUILD_TYPE=Debug
        -D3RDPARTY_DIR=${OCC3RDPARTY_DIR}
        -DINSTALL_DIR=${CMAKE_CURRENT_SOURCE_DIR}/Install
    BUILD_ALWAYS 1
    INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Install
)

add_executable(OPE_Design
    src/main.cpp
)

add_dependencies(OPE_Design OpenCASCADE)
target_include_directories(OPE_Design PRIVATE ${OpenCASCADE_INCLUDE_DIR})
target_link_libraries(OPE_Design PRIVATE ${OpenCASCADE_LIBRARIES})
