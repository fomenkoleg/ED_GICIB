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
CMAKE_SOURCE_DIR = "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ListaEstatica.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ListaEstatica.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ListaEstatica.dir/flags.make

CMakeFiles/ListaEstatica.dir/main.c.o: CMakeFiles/ListaEstatica.dir/flags.make
CMakeFiles/ListaEstatica.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ListaEstatica.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ListaEstatica.dir/main.c.o -c "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/main.c"

CMakeFiles/ListaEstatica.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ListaEstatica.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/main.c" > CMakeFiles/ListaEstatica.dir/main.c.i

CMakeFiles/ListaEstatica.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ListaEstatica.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/main.c" -o CMakeFiles/ListaEstatica.dir/main.c.s

CMakeFiles/ListaEstatica.dir/TElemento.c.o: CMakeFiles/ListaEstatica.dir/flags.make
CMakeFiles/ListaEstatica.dir/TElemento.c.o: ../TElemento.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ListaEstatica.dir/TElemento.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ListaEstatica.dir/TElemento.c.o -c "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/TElemento.c"

CMakeFiles/ListaEstatica.dir/TElemento.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ListaEstatica.dir/TElemento.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/TElemento.c" > CMakeFiles/ListaEstatica.dir/TElemento.c.i

CMakeFiles/ListaEstatica.dir/TElemento.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ListaEstatica.dir/TElemento.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/TElemento.c" -o CMakeFiles/ListaEstatica.dir/TElemento.c.s

CMakeFiles/ListaEstatica.dir/TListaEstatica.c.o: CMakeFiles/ListaEstatica.dir/flags.make
CMakeFiles/ListaEstatica.dir/TListaEstatica.c.o: ../TListaEstatica.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ListaEstatica.dir/TListaEstatica.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ListaEstatica.dir/TListaEstatica.c.o -c "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/TListaEstatica.c"

CMakeFiles/ListaEstatica.dir/TListaEstatica.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ListaEstatica.dir/TListaEstatica.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/TListaEstatica.c" > CMakeFiles/ListaEstatica.dir/TListaEstatica.c.i

CMakeFiles/ListaEstatica.dir/TListaEstatica.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ListaEstatica.dir/TListaEstatica.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/TListaEstatica.c" -o CMakeFiles/ListaEstatica.dir/TListaEstatica.c.s

# Object files for target ListaEstatica
ListaEstatica_OBJECTS = \
"CMakeFiles/ListaEstatica.dir/main.c.o" \
"CMakeFiles/ListaEstatica.dir/TElemento.c.o" \
"CMakeFiles/ListaEstatica.dir/TListaEstatica.c.o"

# External object files for target ListaEstatica
ListaEstatica_EXTERNAL_OBJECTS =

ListaEstatica: CMakeFiles/ListaEstatica.dir/main.c.o
ListaEstatica: CMakeFiles/ListaEstatica.dir/TElemento.c.o
ListaEstatica: CMakeFiles/ListaEstatica.dir/TListaEstatica.c.o
ListaEstatica: CMakeFiles/ListaEstatica.dir/build.make
ListaEstatica: CMakeFiles/ListaEstatica.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable ListaEstatica"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ListaEstatica.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ListaEstatica.dir/build: ListaEstatica
.PHONY : CMakeFiles/ListaEstatica.dir/build

CMakeFiles/ListaEstatica.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ListaEstatica.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ListaEstatica.dir/clean

CMakeFiles/ListaEstatica.dir/depend:
	cd "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica" "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica" "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/cmake-build-debug" "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/cmake-build-debug" "/Users/olegfomenkov/CLionProjects/2.1-ED 2Q/2-Listas/1-ListaEstatica/cmake-build-debug/CMakeFiles/ListaEstatica.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ListaEstatica.dir/depend

