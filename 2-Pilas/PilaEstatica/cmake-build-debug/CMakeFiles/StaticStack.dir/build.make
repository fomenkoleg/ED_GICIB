# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "/Users/olegfomenkov/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/olegfomenkov/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5284.51/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/StaticStack.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/StaticStack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StaticStack.dir/flags.make

CMakeFiles/StaticStack.dir/main.c.o: CMakeFiles/StaticStack.dir/flags.make
CMakeFiles/StaticStack.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/StaticStack.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/StaticStack.dir/main.c.o -c "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/main.c"

CMakeFiles/StaticStack.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/StaticStack.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/main.c" > CMakeFiles/StaticStack.dir/main.c.i

CMakeFiles/StaticStack.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/StaticStack.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/main.c" -o CMakeFiles/StaticStack.dir/main.c.s

CMakeFiles/StaticStack.dir/TElemento.c.o: CMakeFiles/StaticStack.dir/flags.make
CMakeFiles/StaticStack.dir/TElemento.c.o: ../TElemento.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/StaticStack.dir/TElemento.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/StaticStack.dir/TElemento.c.o -c "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/TElemento.c"

CMakeFiles/StaticStack.dir/TElemento.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/StaticStack.dir/TElemento.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/TElemento.c" > CMakeFiles/StaticStack.dir/TElemento.c.i

CMakeFiles/StaticStack.dir/TElemento.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/StaticStack.dir/TElemento.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/TElemento.c" -o CMakeFiles/StaticStack.dir/TElemento.c.s

CMakeFiles/StaticStack.dir/TStaticStack.c.o: CMakeFiles/StaticStack.dir/flags.make
CMakeFiles/StaticStack.dir/TStaticStack.c.o: ../TStaticStack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/StaticStack.dir/TStaticStack.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/StaticStack.dir/TStaticStack.c.o -c "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/TStaticStack.c"

CMakeFiles/StaticStack.dir/TStaticStack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/StaticStack.dir/TStaticStack.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/TStaticStack.c" > CMakeFiles/StaticStack.dir/TStaticStack.c.i

CMakeFiles/StaticStack.dir/TStaticStack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/StaticStack.dir/TStaticStack.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/TStaticStack.c" -o CMakeFiles/StaticStack.dir/TStaticStack.c.s

# Object files for target StaticStack
StaticStack_OBJECTS = \
"CMakeFiles/StaticStack.dir/main.c.o" \
"CMakeFiles/StaticStack.dir/TElemento.c.o" \
"CMakeFiles/StaticStack.dir/TStaticStack.c.o"

# External object files for target StaticStack
StaticStack_EXTERNAL_OBJECTS =

StaticStack: CMakeFiles/StaticStack.dir/main.c.o
StaticStack: CMakeFiles/StaticStack.dir/TElemento.c.o
StaticStack: CMakeFiles/StaticStack.dir/TStaticStack.c.o
StaticStack: CMakeFiles/StaticStack.dir/build.make
StaticStack: CMakeFiles/StaticStack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable StaticStack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StaticStack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StaticStack.dir/build: StaticStack
.PHONY : CMakeFiles/StaticStack.dir/build

CMakeFiles/StaticStack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StaticStack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StaticStack.dir/clean

CMakeFiles/StaticStack.dir/depend:
	cd "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack" "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack" "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/cmake-build-debug" "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/cmake-build-debug" "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/3-PIlas/1-StaticStack/cmake-build-debug/CMakeFiles/StaticStack.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/StaticStack.dir/depend
