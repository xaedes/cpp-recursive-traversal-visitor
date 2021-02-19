cmake_minimum_required(VERSION 3.8)

set ( CMAKE_EXPORT_COMPILE_COMMANDS TRUE )
set ( PROJECT_NAME recursive_traversal_visitor_meta )
project( ${PROJECT_NAME} )

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/cmake-modules)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/extern/Catch2/contrib)
# list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/extern/Catch2/extras)

add_subdirectory(recursive_traversal_visitor)



