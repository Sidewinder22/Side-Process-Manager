# src dir CMake

set(APP side-project-manager)
set(console_lib console)
set(provider_lib provider)

add_subdirectory(common)
add_subdirectory(provider)
add_subdirectory(ui)

add_executable(${APP} main.cpp)

target_link_libraries(${APP}
	PRIVATE
	${console_lib}
	${provider_lib}
)
