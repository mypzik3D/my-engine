# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mypzuk/Projects/3D-engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mypzuk/Projects/3D-engine/build

# Include any dependencies generated for this target.
include CMakeFiles/my-engine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/my-engine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my-engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my-engine.dir/flags.make

CMakeFiles/my-engine.dir/src/main.cpp.o: CMakeFiles/my-engine.dir/flags.make
CMakeFiles/my-engine.dir/src/main.cpp.o: /home/mypzuk/Projects/3D-engine/src/main.cpp
CMakeFiles/my-engine.dir/src/main.cpp.o: CMakeFiles/my-engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mypzuk/Projects/3D-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my-engine.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my-engine.dir/src/main.cpp.o -MF CMakeFiles/my-engine.dir/src/main.cpp.o.d -o CMakeFiles/my-engine.dir/src/main.cpp.o -c /home/mypzuk/Projects/3D-engine/src/main.cpp

CMakeFiles/my-engine.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/my-engine.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mypzuk/Projects/3D-engine/src/main.cpp > CMakeFiles/my-engine.dir/src/main.cpp.i

CMakeFiles/my-engine.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/my-engine.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mypzuk/Projects/3D-engine/src/main.cpp -o CMakeFiles/my-engine.dir/src/main.cpp.s

CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.o: CMakeFiles/my-engine.dir/flags.make
CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.o: /home/mypzuk/Projects/3D-engine/src/3d-engine/vector/vector.cpp
CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.o: CMakeFiles/my-engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mypzuk/Projects/3D-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.o -MF CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.o.d -o CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.o -c /home/mypzuk/Projects/3D-engine/src/3d-engine/vector/vector.cpp

CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mypzuk/Projects/3D-engine/src/3d-engine/vector/vector.cpp > CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.i

CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mypzuk/Projects/3D-engine/src/3d-engine/vector/vector.cpp -o CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.s

CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.o: CMakeFiles/my-engine.dir/flags.make
CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.o: /home/mypzuk/Projects/3D-engine/src/3d-engine/object/object.cpp
CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.o: CMakeFiles/my-engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mypzuk/Projects/3D-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.o -MF CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.o.d -o CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.o -c /home/mypzuk/Projects/3D-engine/src/3d-engine/object/object.cpp

CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mypzuk/Projects/3D-engine/src/3d-engine/object/object.cpp > CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.i

CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mypzuk/Projects/3D-engine/src/3d-engine/object/object.cpp -o CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.s

CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.o: CMakeFiles/my-engine.dir/flags.make
CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.o: /home/mypzuk/Projects/3D-engine/src/3d-engine/mesh/mesh.cpp
CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.o: CMakeFiles/my-engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mypzuk/Projects/3D-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.o -MF CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.o.d -o CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.o -c /home/mypzuk/Projects/3D-engine/src/3d-engine/mesh/mesh.cpp

CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mypzuk/Projects/3D-engine/src/3d-engine/mesh/mesh.cpp > CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.i

CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mypzuk/Projects/3D-engine/src/3d-engine/mesh/mesh.cpp -o CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.s

CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.o: CMakeFiles/my-engine.dir/flags.make
CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.o: /home/mypzuk/Projects/3D-engine/src/3d-engine/world/world.cpp
CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.o: CMakeFiles/my-engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mypzuk/Projects/3D-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.o -MF CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.o.d -o CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.o -c /home/mypzuk/Projects/3D-engine/src/3d-engine/world/world.cpp

CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mypzuk/Projects/3D-engine/src/3d-engine/world/world.cpp > CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.i

CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mypzuk/Projects/3D-engine/src/3d-engine/world/world.cpp -o CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.s

# Object files for target my-engine
my__engine_OBJECTS = \
"CMakeFiles/my-engine.dir/src/main.cpp.o" \
"CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.o" \
"CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.o" \
"CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.o" \
"CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.o"

# External object files for target my-engine
my__engine_EXTERNAL_OBJECTS =

my-engine: CMakeFiles/my-engine.dir/src/main.cpp.o
my-engine: CMakeFiles/my-engine.dir/src/3d-engine/vector/vector.cpp.o
my-engine: CMakeFiles/my-engine.dir/src/3d-engine/object/object.cpp.o
my-engine: CMakeFiles/my-engine.dir/src/3d-engine/mesh/mesh.cpp.o
my-engine: CMakeFiles/my-engine.dir/src/3d-engine/world/world.cpp.o
my-engine: CMakeFiles/my-engine.dir/build.make
my-engine: /usr/lib/libsfml-graphics.so.2.6.1
my-engine: /usr/lib/libsfml-audio.so.2.6.1
my-engine: /usr/lib/libsfml-window.so.2.6.1
my-engine: /usr/lib/libsfml-system.so.2.6.1
my-engine: CMakeFiles/my-engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/mypzuk/Projects/3D-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable my-engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my-engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my-engine.dir/build: my-engine
.PHONY : CMakeFiles/my-engine.dir/build

CMakeFiles/my-engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my-engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my-engine.dir/clean

CMakeFiles/my-engine.dir/depend:
	cd /home/mypzuk/Projects/3D-engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mypzuk/Projects/3D-engine /home/mypzuk/Projects/3D-engine /home/mypzuk/Projects/3D-engine/build /home/mypzuk/Projects/3D-engine/build /home/mypzuk/Projects/3D-engine/build/CMakeFiles/my-engine.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/my-engine.dir/depend

