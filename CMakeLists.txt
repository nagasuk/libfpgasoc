cmake_minimum_required(VERSION 3.8)

# [ Project Setting ]
## Common
project(libfpgasoc C CXX)

## Options
option(LIBFPGASOC_BUILD_SHARED_LIBS "Build libfpgasoc as a shared library" OFF)

# [ For building this projects ]
file(GLOB srcs *.c *.cpp)
if (LIBFPGASOC_BUILD_SHARED_LIBS)
	add_library(fpgasoc SHARED ${srcs})
else()
	add_library(fpgasoc SHARED ${srcs})
endif()

set_target_properties(fpgasoc PROPERTIES VERSION "1.0.0" SOVERSION "1")
target_include_directories(fpgasoc INTERFACE include)
target_compile_options(fpgasoc PRIVATE -Wall)
target_compile_features(fpgasoc PRIVATE cxx_std_11)

# [ Installation ]
install(TARGETS fpgasoc LIBRARY       DESTINATION ${CMAKE_INSTALL_LIBIDR})
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)

