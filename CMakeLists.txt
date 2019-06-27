cmake_minimum_required(VERSION 3.6)
project(classico-demo)

set(CMAKE_CXX_STANDARD 11)


if( ${CMAKE_SYSTEM_PROCESSOR} STREQUAL "arm" )
	SET(CMAKE_C_FLAGS "-mfloat-abi=hard -march=armv8-a+simd -s -Os")
	SET(CMAKE_CXX_FLAGS " -mfloat-abi=hard -march=armv8-a+simd -s -Os")
	include_directories(src/include /home/mggk/PSC-CrossCompile-Toolchain-master/armv8-sony-linux-gnueabihf/armv8-sony-linux-gnueabihf/sysroot/usr/include)
	link_directories(/home/mggk/PSC-CrossCompile-Toolchain-master/armv8-sony-linux-gnueabihf/armv8-sony-linux-gnueabihf/sysroot/usr/lib$)
	else()

	endif()




find_package(Threads REQUIRED)

add_executable(classico-demo
		src/code/main.h
        src/code/main.cpp
		src/code/scenes/introText.cpp src/code/scenes/introText.h src/code/gfxUtils.cpp src/code/gfxUtils.h src/code/scenes/starfield.cpp src/code/scenes/starfield.h)

target_link_libraries(classico-demo
         Threads::Threads
         SDL2
         SDL2_image
         SDL2_mixer
         SDL2_ttf
         ${CMAKE_DL_LIBS}
)

add_custom_command(TARGET classico-demo PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/src/resources $<TARGET_FILE_DIR:classico-demo>)

