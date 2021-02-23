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
target_include_directories(fpgasoc PUBLIC include)
target_compile_options(fpgasoc PUBLIC -Wall)
target_compile_features(fpgasoc PUBLIC cxx_std_11)

# [ Installation ]
install(TARGETS fpgasoc LIBRARY DESTINATION lib)
install(FILES include/libfpgasoc.h include/libfpgasoc.hpp DESTINATION include)

