# src dir CMake

set(APP side-project-manager)
set(provider_lib provider)
set(console_lib console)

add_subdirectory(common)
add_subdirectory(provider)
add_subdirectory(ui)

add_executable(${APP} main.cpp)

target_link_libraries(${APP}
	PRIVATE
	${provider_lib}
	${console_lib}
)
