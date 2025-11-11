# Check if OCC_INSTALL_DIR is defined
if(DEFINED OpenCASCADE_DIR)
  find_package(OpenCASCADE)
  message(STATUS "OCC_INSTALL_DIR is defined as ${OpenCASCADE_DIR}")

  # Define other variables based on OCC_INSTALL_DIR
  include_directories ( SYSTEM ${OpenCASCADE_INCLUDE_DIR} )
else()
  message(WARNING "OCC_INSTALL_DIR is not defined. OCCT paths will not be set.")
endif()