FIND_PACKAGE(Netcdf REQUIRED)

FIND_PACKAGE(ZLIB REQUIRED)

INCLUDE_DIRECTORIES(${ZLIB_INCLUDE_DIRS})

LIST(APPEND deal_ii_external_libraries ${ZLIB_LIBRARIES})

SET(HAVE_LIBZ TRUE)
