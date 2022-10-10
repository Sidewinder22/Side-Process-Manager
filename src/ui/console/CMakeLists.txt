# Console CMake file

set(LIB console)

add_library(${LIB}
    STATIC
    ConsoleDisplay.cpp
)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

target_link_libraries(${LIB}
	${CURSES_LIBRARY}
)

target_include_directories(${LIB}
	# For the public header files
	PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}
)
