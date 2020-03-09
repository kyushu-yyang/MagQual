# -------------------------------------------------
# CMakeLists for compile the field quality code
#
# Author: Y.Yang
# Date  : 2020.03.07
# -------------------------------------------------

# define the cmake version
cmake_minimum_required( VERSION 3.0 )

# project name
project( MagQual CXX )

# set the c++11
set(CMAKE_CXX_STANDARD, 11)

#
set(Boost_USE_STATIC_LIBS ON)

# setup
set( EXE_FILE test.exe )
set( MAIN_FILE main.cxx )

# find the source code
#file( GLOB_RECURSE SOURCE_FILES "src/*cxx")

# include the header files
add_subdirectory(src)

# for BOOST
find_package( Boost REQUIRED )
message(STATUS "check Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}" )
message(STATUS "check Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}" )

# for ROOT
find_package( ROOT REQUIRED )
message(STATUS "check ROOT_INCLUDE_DIRS: ${ROOT_INCLUDE_DIRS}" )
message(STATUS "check ROOT_LIBRARIES: ${ROOT_LIBRARIES}" )

# include the libraries head file
if (Boost_FOUND)
  include_directories( ${PROJECT_SOURCE_DIR}  ${Boost_INCLUDE_DIRS} )
else()
  message(FATAL_ERROR "boost is not found." )
endif()

if (ROOT_FOUND)
  include_directories( ${PROJECT_SOURCE_DIR} ${ROOT_INCLUDE_DIRS} )
else()
  message(FATAL_ERROR "ROOT is not found.")
endif()


# create an executable file
add_executable( ${EXE_FILE}  ${MAIN_FILE} )

# include the head files
#target_include_directories( ${EXE_FILE} PUBLIC ${PROJECT_SOURCE_DIR}/include )
target_link_libraries( ${EXE_FILE} MagQual )

# link the libraries
if (Boost_FOUND)
  target_link_libraries( ${EXE_FILE} ${Boost_LIBRARIES} )
endif()

if (ROOT_FOUND)
  target_link_libraries( ${EXE_FILE} ${ROOT_LIBRARIES} )
endif()
