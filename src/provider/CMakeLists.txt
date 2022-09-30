# Provider CMake file

set(LIB provider)

add_library(${LIB}
	STATIC
	ProcessDataProvider.cpp
)

# message("CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}")

target_include_directories(${LIB}
	# For the public header files
	PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}
)
