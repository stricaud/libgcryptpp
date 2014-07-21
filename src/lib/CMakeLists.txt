include_directories(AFTER "include/")
include_directories(AFTER "${CMAKE_CURRENT_BINARY_DIR}/")
include_directories(AFTER "${CMAKE_CURRENT_BINARY_DIR}/include/")
include_directories(AFTER ${Boost_INCLUDE_DIRS})
include_directories(AFTER ${GCRYPT_HEADERS})

set(gcrypt++_SRC_FILES
Hash.cpp
Utils.cpp
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set(GCRYPT++_LINK_LIBRARIES
    ${GCRYPT++_LINK_LIBRARIES}
    "-ldl"
    )
endif()


add_library(gcrypt++ SHARED ${gcrypt++_SRC_FILES})
set_target_properties(gcrypt++ PROPERTIES SOVERSION 1)
target_link_libraries(gcrypt++ ${GCRYPT++_LINK_LIBRARIES})

#add_subdirectory(tests)

install(TARGETS gcrypt++ LIBRARY DESTINATION lib)

