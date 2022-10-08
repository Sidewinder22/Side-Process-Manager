# Provider CMake file

set(LIB provider)

add_library(${LIB}
	STATIC
	DirPathPreparator.cpp
	ProcessData.cpp
	ProcessDataProvider.cpp
	ProcessDataReader.cpp
	Reader.cpp
)

target_link_libraries(${LIB}
    common
)

# message("CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}")

target_include_directories(${LIB}
	# For the public header files
	PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}
)
