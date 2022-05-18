cmake_minimum_required(VERSION 3.8)

# [ Project Setting ]
## Common
project(libfpgasoc VERSION 1.0.1 LANGUAGES C CXX)

## Options
option(LIBFPGASOC_BUILD_SHARED_LIBS "Build libfpgasoc as a shared library" OFF)

# [ For building this projects ]
file(GLOB srcs *.c *.cpp)

# Select shared or static lib
if (LIBFPGASOC_BUILD_SHARED_LIBS)
	add_library(fpgasoc SHARED ${srcs})
else()
	add_library(fpgasoc STATIC ${srcs})
endif()

# Register alias of namespace
add_library(fpgasoc::fpgasoc ALIAS fpgasoc)

# Ohter Settings for build
set_target_properties(fpgasoc PROPERTIES
	VERSION       "1.0.1"
	SOVERSION     "1"
)
target_include_directories(fpgasoc INTERFACE 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)
target_compile_options(fpgasoc PRIVATE -Wall)
target_compile_features(fpgasoc PRIVATE cxx_std_11)

# [ Installation ]
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/fpgasoc-config-version.cmake
	COMPATIBILITY SameMajorVersion
)

include(GNUInstallDirs)

install(TARGETS fpgasoc
	EXPORT  fpgasoc-config
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # for shared lib
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} # for static lib
)

install(EXPORT fpgasoc-config
	NAMESPACE   fpgasoc::
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/fpgasoc
	EXPORT_LINK_INTERFACE_LIBRARIES
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/fpgasoc-config-version.cmake
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/fpgasoc
)

