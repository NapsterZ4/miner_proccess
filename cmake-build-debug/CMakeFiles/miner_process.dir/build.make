# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/98/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/98/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/napster/LEAD University/Sistemas operativos/miner_proccess"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/napster/LEAD University/Sistemas operativos/miner_proccess/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/miner_process.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/miner_process.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/miner_process.dir/flags.make

CMakeFiles/miner_process.dir/main.c.o: CMakeFiles/miner_process.dir/flags.make
CMakeFiles/miner_process.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/napster/LEAD University/Sistemas operativos/miner_proccess/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/miner_process.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/miner_process.dir/main.c.o   -c "/mnt/napster/LEAD University/Sistemas operativos/miner_proccess/main.c"

CMakeFiles/miner_process.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/miner_process.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/napster/LEAD University/Sistemas operativos/miner_proccess/main.c" > CMakeFiles/miner_process.dir/main.c.i

CMakeFiles/miner_process.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/miner_process.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/napster/LEAD University/Sistemas operativos/miner_proccess/main.c" -o CMakeFiles/miner_process.dir/main.c.s

# Object files for target miner_process
miner_process_OBJECTS = \
"CMakeFiles/miner_process.dir/main.c.o"

# External object files for target miner_process
miner_process_EXTERNAL_OBJECTS =

miner_process: CMakeFiles/miner_process.dir/main.c.o
miner_process: CMakeFiles/miner_process.dir/build.make
miner_process: CMakeFiles/miner_process.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/napster/LEAD University/Sistemas operativos/miner_proccess/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable miner_process"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/miner_process.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/miner_process.dir/build: miner_process

.PHONY : CMakeFiles/miner_process.dir/build

CMakeFiles/miner_process.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/miner_process.dir/cmake_clean.cmake
.PHONY : CMakeFiles/miner_process.dir/clean

CMakeFiles/miner_process.dir/depend:
	cd "/mnt/napster/LEAD University/Sistemas operativos/miner_proccess/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/napster/LEAD University/Sistemas operativos/miner_proccess" "/mnt/napster/LEAD University/Sistemas operativos/miner_proccess" "/mnt/napster/LEAD University/Sistemas operativos/miner_proccess/cmake-build-debug" "/mnt/napster/LEAD University/Sistemas operativos/miner_proccess/cmake-build-debug" "/mnt/napster/LEAD University/Sistemas operativos/miner_proccess/cmake-build-debug/CMakeFiles/miner_process.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/miner_process.dir/depend
