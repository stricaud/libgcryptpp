find_path(GCRYPT_INCLUDE_DIR gcrypt.h)
find_library(GCRYPT_LIBRARY gcrypt)

set(GCRYPT_LIBRARIES ${GCRYPT_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Gcrypt DEFAULT_MSG GCRYPT_LIBRARIES GCRYPT_INCLUDE_DIR)

mark_as_advanced(GCRYPT_LIBRARIES GCRYPT_INCLUDE_DIR)
