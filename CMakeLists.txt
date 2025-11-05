cmake_minimum_required(VERSION 3.10)
project(OPE_Design)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPED_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Root directory of OPEN Design project" FORCE)

include(cMake/OCCT.cmake)

add_executable(OPE_Design
    src/main.cpp
)

target_link_libraries(OPE_Design PRIVATE
  TKBin
  TKBinL
  TKBinTObj
  TKBinXCAF
  TKBO
  TKBool
  TKBRep
  TKCAF
  TKCDF
  TKDCAF
  TKDE
  TKDECascade
  TKDEIGES
  TKDEOBJ
  TKDEPLY
  TKDESTEP
  TKDESTL
  TKDEVRML
  TKDraw
  TKernel
  TKExpress
  TKFeat
  TKFillet
  TKG2d
  TKG3d
  TKGeomAlgo
  TKGeomBase
  TKHelix
  TKHLR
  TKLCAF
  TKMath
  TKMesh
  TKMeshVS
  TKOffset
  TKOpenGl
  TKOpenGlTest
  TKPrim
  TKQADraw
  TKRWMesh
  TKService
  TKShHealing
  TKStd
  TKStdL
  TKTObj
  TKTObjDRAW
  TKTopAlgo
  TKTopTest
  TKV3d
  TKVCAF
  TKViewerTest
  TKXCAF
  TKXDEDRAW
  TKXMesh
  TKXml
  TKXmlL
  TKXmlTObj
  TKXmlXCAF
  TKXSBase
  TKXSDRAW
  TKXSDRAWDE
  TKXSDRAWIGES
  TKXSDRAWOBJ
  TKXSDRAWPLY
  TKXSDRAWSTEP
  TKXSDRAWSTL
  TKXSDRAWVRML )
