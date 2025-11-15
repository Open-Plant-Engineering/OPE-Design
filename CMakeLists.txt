cmake_minimum_required(VERSION 3.10)
project(OPE_Design)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPED_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Root directory of OPEN Design project" FORCE)

include(cMake/OCCT.cmake)
include(cMake/FreeTypes.cmake)

add_executable(OPE_Design
    src/main.cpp
)

# Add linker options
foreach (LIB ${OpenCASCADE_LIBRARIES})
  target_link_libraries(OPE_Design debug ${OpenCASCADE_LIBRARY_DIR}d/${LIB}.lib)
  target_link_libraries(OPE_Design optimized ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
  # message(OPE_Design debug ${OpenCASCADE_LIBRARY_DIR}d/${LIB}.lib)
endforeach()

target_link_libraries(OPE_Design debug ${FREETYPE_DIR}/lib/freetype.lib)
target_link_libraries(OPE_Design optimized ${FREETYPE_DIR}/lib/freetype.lib)

# Adjust runtime environment
set_property(TARGET OPE_Design PROPERTY VS_DEBUGGER_ENVIRONMENT "PATH=${FREETYPE_DIR}/bin;$<$<CONFIG:DEBUG>:${OpenCASCADE_BINARY_DIR}d>$<$<NOT:$<CONFIG:DEBUG>>:${OpenCASCADE_BINARY_DIR}>;%PATH%")