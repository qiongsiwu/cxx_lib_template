# Borrowed from 
# https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake
cmake_minimum_required(VERSION 3.10)

project(testlib VERSION 1.0.1 DESCRIPTION "trying out building .so with cmake")

# Use variables GNUInstallDirs to set installation path
include(GNUInstallDirs)

# Adding sorce files
# Obtain this with: ls source/*.cpp
add_library(testlib SHARED 
	src/api1.cpp 
	src/api2.cpp
)

# Optional, but good practice
set_target_properties(testlib PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(testlib PROPERTIES SOVERSION 1)

# Adding configure file so other projects can easily import this library
#configure_file(testlib.pc.in testlib.pc @ONLY)
configure_file(testlib-config.cmake.in testlib-config.cmake)

# Declaring public APIs: adding public header files
set_target_properties(testlib PROPERTIES PUBLIC_HEADER 
	"include/api1.h;include/api2.h"
)

# Setting subdirectories to avoid relative paths
target_include_directories(testlib PRIVATE include)
target_include_directories(testlib PRIVATE src)

# Creating an install rule
install(TARGETS testlib EXPORT testlib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(EXPORT testlib DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES ${CMAKE_BINARY_DIR}/testlib-config.cmake 
	DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#install(FILES ${CMAKE_BINARY_DIR}/testlib.pc 
#	DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
#)

