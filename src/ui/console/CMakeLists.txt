# Console CMake file

set(LIB console)

set(CURSES_NEED_NCURSES TRUE)

add_library(${LIB}
    STATIC
    Display.cpp
    Layout.cpp
    Tools.cpp
    Window.cpp
)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

target_link_libraries(${LIB}
	${CURSES_LIBRARY}
	-lpanel
)

target_include_directories(${LIB}
	# For the public header files
	PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}
)
