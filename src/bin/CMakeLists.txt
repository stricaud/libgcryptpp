include_directories(AFTER ${CMAKE_CURRENT_SOURCE_DIR}/../lib/include)
include_directories(AFTER ${Boost_INCLUDE_DIRS})

set(GCRYPT++_LIBRARY "${gcrypt++_BINARY_DIR}/src/lib/libgcrypt++.dylib")

add_executable(gcrypt-sha256 sha256.cpp)
target_link_libraries(gcrypt-sha256 ${GCRYPT++_LIBRARY})

install(TARGETS gcrypt-sha256 DESTINATION bin)

