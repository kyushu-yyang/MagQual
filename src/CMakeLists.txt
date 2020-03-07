# -------------------------------
# cmakelists for the source file
# -------------------------------

# set the name of this library
set( LIBRARY_NAME MagQual )

# find the source files
file( GLOB_RECURSE SOURCE_FILES "*cxx" )

# create a shared library
add_library( ${LIBRARY_NAME} SHARED ${SOURCE_FILES} )

# include the head files
target_include_directories( ${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include )

