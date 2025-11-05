# Check if OCC_INSTALL_DIR is defined
if(DEFINED OCC_INSTALL_DIR)
  message(STATUS "OCC_INSTALL_DIR is defined as ${OCC_INSTALL_DIR}")

  # Define other variables based on OCC_INSTALL_DIR
  set(OCCT_INCLUDE_DIR "${OCC_INSTALL_DIR}/inc")
  set(OCCT_LIB_DIR "${OCC_INSTALL_DIR}/win64/gcc/lib")
  set(OCCT_BIN_DIR "${OCC_INSTALL_DIR}/win64/gcc/bin")

  # Optionally, add these directories to include and link paths
  include_directories(${OCCT_INCLUDE_DIR})
  link_directories(${OCCT_LIB_DIR})
else()
  message(WARNING "OCC_INSTALL_DIR is not defined. OCCT paths will not be set.")
endif()