# Console CMake file

set(LIB console)

add_library(${LIB}
    STATIC
    ConsoleDisplay.cpp
)

target_include_directories(${LIB}
	# For the public header files
	PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}
)
