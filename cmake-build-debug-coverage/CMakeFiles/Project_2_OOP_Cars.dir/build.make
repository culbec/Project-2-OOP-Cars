# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /home/culbec/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/231.8109.222/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/culbec/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/231.8109.222/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/culbec/OOP/Project-2-OOP-Cars

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/culbec/OOP/Project-2-OOP-Cars/cmake-build-debug-coverage

# Include any dependencies generated for this target.
include CMakeFiles/Project_2_OOP_Cars.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Project_2_OOP_Cars.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Project_2_OOP_Cars.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project_2_OOP_Cars.dir/flags.make

CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.o: CMakeFiles/Project_2_OOP_Cars.dir/flags.make
CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.o: /home/culbec/OOP/Project-2-OOP-Cars/Sources/Car.cpp
CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.o: CMakeFiles/Project_2_OOP_Cars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/culbec/OOP/Project-2-OOP-Cars/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.o -MF CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.o.d -o CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.o -c /home/culbec/OOP/Project-2-OOP-Cars/Sources/Car.cpp

CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/culbec/OOP/Project-2-OOP-Cars/Sources/Car.cpp > CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.i

CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/culbec/OOP/Project-2-OOP-Cars/Sources/Car.cpp -o CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.s

CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.o: CMakeFiles/Project_2_OOP_Cars.dir/flags.make
CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.o: /home/culbec/OOP/Project-2-OOP-Cars/Sources/Repository.cpp
CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.o: CMakeFiles/Project_2_OOP_Cars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/culbec/OOP/Project-2-OOP-Cars/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.o -MF CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.o.d -o CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.o -c /home/culbec/OOP/Project-2-OOP-Cars/Sources/Repository.cpp

CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/culbec/OOP/Project-2-OOP-Cars/Sources/Repository.cpp > CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.i

CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/culbec/OOP/Project-2-OOP-Cars/Sources/Repository.cpp -o CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.s

CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.o: CMakeFiles/Project_2_OOP_Cars.dir/flags.make
CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.o: /home/culbec/OOP/Project-2-OOP-Cars/Sources/Service.cpp
CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.o: CMakeFiles/Project_2_OOP_Cars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/culbec/OOP/Project-2-OOP-Cars/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.o -MF CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.o.d -o CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.o -c /home/culbec/OOP/Project-2-OOP-Cars/Sources/Service.cpp

CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/culbec/OOP/Project-2-OOP-Cars/Sources/Service.cpp > CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.i

CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/culbec/OOP/Project-2-OOP-Cars/Sources/Service.cpp -o CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.s

CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.o: CMakeFiles/Project_2_OOP_Cars.dir/flags.make
CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.o: /home/culbec/OOP/Project-2-OOP-Cars/Sources/tests.cpp
CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.o: CMakeFiles/Project_2_OOP_Cars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/culbec/OOP/Project-2-OOP-Cars/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.o -MF CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.o.d -o CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.o -c /home/culbec/OOP/Project-2-OOP-Cars/Sources/tests.cpp

CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/culbec/OOP/Project-2-OOP-Cars/Sources/tests.cpp > CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.i

CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/culbec/OOP/Project-2-OOP-Cars/Sources/tests.cpp -o CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.s

CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.o: CMakeFiles/Project_2_OOP_Cars.dir/flags.make
CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.o: /home/culbec/OOP/Project-2-OOP-Cars/Sources/UI.cpp
CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.o: CMakeFiles/Project_2_OOP_Cars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/culbec/OOP/Project-2-OOP-Cars/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.o -MF CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.o.d -o CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.o -c /home/culbec/OOP/Project-2-OOP-Cars/Sources/UI.cpp

CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/culbec/OOP/Project-2-OOP-Cars/Sources/UI.cpp > CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.i

CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/culbec/OOP/Project-2-OOP-Cars/Sources/UI.cpp -o CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.s

CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.o: CMakeFiles/Project_2_OOP_Cars.dir/flags.make
CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.o: /home/culbec/OOP/Project-2-OOP-Cars/Sources/Validator.cpp
CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.o: CMakeFiles/Project_2_OOP_Cars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/culbec/OOP/Project-2-OOP-Cars/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.o -MF CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.o.d -o CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.o -c /home/culbec/OOP/Project-2-OOP-Cars/Sources/Validator.cpp

CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/culbec/OOP/Project-2-OOP-Cars/Sources/Validator.cpp > CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.i

CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/culbec/OOP/Project-2-OOP-Cars/Sources/Validator.cpp -o CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.s

CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.o: CMakeFiles/Project_2_OOP_Cars.dir/flags.make
CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.o: /home/culbec/OOP/Project-2-OOP-Cars/main.cpp
CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.o: CMakeFiles/Project_2_OOP_Cars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/culbec/OOP/Project-2-OOP-Cars/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.o -MF CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.o.d -o CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.o -c /home/culbec/OOP/Project-2-OOP-Cars/main.cpp

CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/culbec/OOP/Project-2-OOP-Cars/main.cpp > CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.i

CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/culbec/OOP/Project-2-OOP-Cars/main.cpp -o CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.s

# Object files for target Project_2_OOP_Cars
Project_2_OOP_Cars_OBJECTS = \
"CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.o" \
"CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.o" \
"CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.o" \
"CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.o" \
"CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.o" \
"CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.o" \
"CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.o"

# External object files for target Project_2_OOP_Cars
Project_2_OOP_Cars_EXTERNAL_OBJECTS =

Project_2_OOP_Cars: CMakeFiles/Project_2_OOP_Cars.dir/Sources/Car.cpp.o
Project_2_OOP_Cars: CMakeFiles/Project_2_OOP_Cars.dir/Sources/Repository.cpp.o
Project_2_OOP_Cars: CMakeFiles/Project_2_OOP_Cars.dir/Sources/Service.cpp.o
Project_2_OOP_Cars: CMakeFiles/Project_2_OOP_Cars.dir/Sources/tests.cpp.o
Project_2_OOP_Cars: CMakeFiles/Project_2_OOP_Cars.dir/Sources/UI.cpp.o
Project_2_OOP_Cars: CMakeFiles/Project_2_OOP_Cars.dir/Sources/Validator.cpp.o
Project_2_OOP_Cars: CMakeFiles/Project_2_OOP_Cars.dir/main.cpp.o
Project_2_OOP_Cars: CMakeFiles/Project_2_OOP_Cars.dir/build.make
Project_2_OOP_Cars: CMakeFiles/Project_2_OOP_Cars.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/culbec/OOP/Project-2-OOP-Cars/cmake-build-debug-coverage/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Project_2_OOP_Cars"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project_2_OOP_Cars.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project_2_OOP_Cars.dir/build: Project_2_OOP_Cars
.PHONY : CMakeFiles/Project_2_OOP_Cars.dir/build

CMakeFiles/Project_2_OOP_Cars.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project_2_OOP_Cars.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project_2_OOP_Cars.dir/clean

CMakeFiles/Project_2_OOP_Cars.dir/depend:
	cd /home/culbec/OOP/Project-2-OOP-Cars/cmake-build-debug-coverage && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/culbec/OOP/Project-2-OOP-Cars /home/culbec/OOP/Project-2-OOP-Cars /home/culbec/OOP/Project-2-OOP-Cars/cmake-build-debug-coverage /home/culbec/OOP/Project-2-OOP-Cars/cmake-build-debug-coverage /home/culbec/OOP/Project-2-OOP-Cars/cmake-build-debug-coverage/CMakeFiles/Project_2_OOP_Cars.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project_2_OOP_Cars.dir/depend

