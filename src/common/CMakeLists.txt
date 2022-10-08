# Common CMake file

set(LIB common)

add_library(${LIB}
    STATIC
    ProcessState.cpp
    Tools.cpp
)

target_include_directories(${LIB}
    # For the public header files
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)
