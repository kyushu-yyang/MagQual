# -------------------------------
# cmakelists for the source file
# -------------------------------

# option
option( MAGQUAL_BUILD_SHARED_LIBS "build magqual as a shared library" ON )

# set the name of this library
set( LIBRARY_NAME MagQual )


# for eigen
find_package( Eigen3 REQUIRED )
message(STATUS "check EIGEN3_INCLUDE_DIRS: ${EIGEN3_INCLUDE_DIR}" )

if (EIGEN3_FOUND)
  include_directories( ${EIGEN3_INCLUDE_DIR} )
else()
  message(FATAL_ERROR "Eigen is not found.")
endif()


# for BOOST
find_package( Boost REQUIRED )
message(STATUS "check Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}" )
message(STATUS "check Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}" )


# find the source files
file( GLOB_RECURSE SOURCE_FILES "*cxx" )

# create a library
if (MAGQUAL_BUILD_SHARED_LIBS)
  add_library( ${LIBRARY_NAME} SHARED ${SOURCE_FILES} )
else()
  add_library( ${LIBRARY_NAME} STATIC ${SOURCE_FILES} )
endif()

# include the head files
if (Boost_FOUND)
  target_include_directories( ${LIBRARY_NAME} PUBLIC ${Boost_INCLUDE_DIRS} )
  target_link_libraries( ${LIBRARY_NAME} ${Boost_LIBRARIES} )
else()
  message( FATAL_ERROR "boost is not found" )
endif()

# include
target_include_directories( ${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include )

