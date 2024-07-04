cmake_minimum_required(VERSION 3.5)
project(my-engine)

set(SFML_DIR "path/to/SFML_directory")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(my-engine src/main.cpp
	    		 src/3d-engine/vector/vector.cpp
			 src/3d-engine/mesh/mesh.cpp
	    		 src/3d-engine/world/world.cpp
                         src/3d-engine/animations/animator.cpp)

target_link_libraries(my-engine sfml-graphics sfml-audio)
