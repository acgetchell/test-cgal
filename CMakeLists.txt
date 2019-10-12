cmake_minimum_required(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
  cmake_policy(VERSION 3.15)
endif()

project(test-cgal VERSION 1.0
DESCRIPTION "Testing CGAL functions"
LANGUAGES CXX)

set(BOOST_MIN_VERSION "1.70.0")
set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wno-comment)

# CGAL
find_package(CGAL QUIET COMPONENTS Core)
if(CGAL_FOUND)
  # Don't let CGAL override flags
  set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE true)
  set(CGAL_DONT_OVERRIDE_CMAKE_FLAGS TRUE
      CACHE BOOL "Force CGAL to maintain CMAKE flags")
  include(${CGAL_USE_FILE})
  include(CGAL_CreateSingleSourceCGALProgram)
else()
  message(
    FATAL_ERROR
      "Notice: This program requires the CGAL library, and will not be compiled."
    )
endif()

create_single_source_cgal_program("main.cpp")
