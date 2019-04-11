cmake_minimum_required(VERSION 3.0)

project(v4l2cpp)

add_subdirectory(leopard_tools)

set(CMAKE_C_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "-Wall")

# define executable to build

include_directories(
	inc
	leopard_tools/src/
)


aux_source_directory(src SRC_FILES)

add_library(${PROJECT_NAME} SHARED
	${SRC_FILES}
	leopard_tools
)

