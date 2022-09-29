# src dir CMake

set(APP side-project-manager)
set(LIB provider)

add_subdirectory(provider)

add_executable(${APP} main.cpp)

target_link_libraries(${APP}
	PRIVATE
	${LIB}
)
