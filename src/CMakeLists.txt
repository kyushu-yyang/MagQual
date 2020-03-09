# -------------------------------
# cmakelists for the source file
# -------------------------------

# option
option( MAGQUAL_BUILD_SHARED_LIBS "build magqual as a shared library" ON )

# set the name of this library
set( LIBRARY_NAME MagQual )

# find the source files
file( GLOB_RECURSE SOURCE_FILES "*cxx" )

# create a library
if (MAGQUAL_BUILD_SHARED_LIBS)
  add_library( ${LIBRARY_NAME} SHARED ${SOURCE_FILES} )
else()
  add_library( ${LIBRARY_NAME} STATIC ${SOURCE_FILES} )
endif()

# include the head files
target_include_directories( ${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include )

