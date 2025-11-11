cmake_minimum_required(VERSION 3.10)
project(OPE_Design)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPED_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Root directory of OPEN Design project" FORCE)

include(cMake/OCCT.cmake)

add_executable(OPE_Design
    src/main.cpp
)

# Add linker options
foreach (LIB ${OpenCASCADE_LIBRARIES})
  target_link_libraries(OPE_Design debug ${OpenCASCADE_LIBRARY_DIR}/lib${LIB}.dll.a)
  target_link_libraries(OPE_Design optimized ${OpenCASCADE_LIBRARY_DIR}/lib${LIB}.dll.a)
  message(OPE_Design debug ${OpenCASCADE_LIBRARY_DIR}d/${LIB}.lib)
endforeach()

# Adjust runtime environment
set_property(TARGET OPE_Design PROPERTY VS_DEBUGGER_ENVIRONMENT "PATH=$<$<CONFIG:DEBUG>:${OpenCASCADE_BINARY_DIR}>$<$<NOT:$<CONFIG:DEBUG>>:${OpenCASCADE_BINARY_DIR}>;%PATH%")