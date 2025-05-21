cmake_minimum_required(VERSION 3.5)
project(my-engine)

find_package(SFML 3.0.1 REQUIRED COMPONENTS Window System Graphics Audio) 

add_executable(my-engine ./src/main.cpp
			../../src/3d-engine/vector/vector.cpp
			../../src/3d-engine/mesh/mesh.cpp
	    		../../src/3d-engine/world/world.cpp
			../../src/3d-engine/animations/animator.cpp)


target_link_libraries(my-engine PRIVATE SFML::Window SFML::System SFML::Graphics SFML::Audio)

