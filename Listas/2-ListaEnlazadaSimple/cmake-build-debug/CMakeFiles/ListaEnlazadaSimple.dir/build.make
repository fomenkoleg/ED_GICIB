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
CMAKE_SOURCE_DIR = /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ListaEnlazadaSimple.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ListaEnlazadaSimple.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ListaEnlazadaSimple.dir/flags.make

CMakeFiles/ListaEnlazadaSimple.dir/main.c.o: CMakeFiles/ListaEnlazadaSimple.dir/flags.make
CMakeFiles/ListaEnlazadaSimple.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ListaEnlazadaSimple.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ListaEnlazadaSimple.dir/main.c.o -c /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/main.c

CMakeFiles/ListaEnlazadaSimple.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ListaEnlazadaSimple.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/main.c > CMakeFiles/ListaEnlazadaSimple.dir/main.c.i

CMakeFiles/ListaEnlazadaSimple.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ListaEnlazadaSimple.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/main.c -o CMakeFiles/ListaEnlazadaSimple.dir/main.c.s

CMakeFiles/ListaEnlazadaSimple.dir/listaEnlazadaDinamica.c.o: CMakeFiles/ListaEnlazadaSimple.dir/flags.make
CMakeFiles/ListaEnlazadaSimple.dir/listaEnlazadaDinamica.c.o: ../listaEnlazadaDinamica.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ListaEnlazadaSimple.dir/listaEnlazadaDinamica.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ListaEnlazadaSimple.dir/listaEnlazadaDinamica.c.o -c /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/listaEnlazadaDinamica.c

CMakeFiles/ListaEnlazadaSimple.dir/listaEnlazadaDinamica.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ListaEnlazadaSimple.dir/listaEnlazadaDinamica.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/listaEnlazadaDinamica.c > CMakeFiles/ListaEnlazadaSimple.dir/listaEnlazadaDinamica.c.i

CMakeFiles/ListaEnlazadaSimple.dir/listaEnlazadaDinamica.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ListaEnlazadaSimple.dir/listaEnlazadaDinamica.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/listaEnlazadaDinamica.c -o CMakeFiles/ListaEnlazadaSimple.dir/listaEnlazadaDinamica.c.s

CMakeFiles/ListaEnlazadaSimple.dir/tElemento.c.o: CMakeFiles/ListaEnlazadaSimple.dir/flags.make
CMakeFiles/ListaEnlazadaSimple.dir/tElemento.c.o: ../tElemento.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ListaEnlazadaSimple.dir/tElemento.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ListaEnlazadaSimple.dir/tElemento.c.o -c /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/tElemento.c

CMakeFiles/ListaEnlazadaSimple.dir/tElemento.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ListaEnlazadaSimple.dir/tElemento.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/tElemento.c > CMakeFiles/ListaEnlazadaSimple.dir/tElemento.c.i

CMakeFiles/ListaEnlazadaSimple.dir/tElemento.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ListaEnlazadaSimple.dir/tElemento.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/tElemento.c -o CMakeFiles/ListaEnlazadaSimple.dir/tElemento.c.s

# Object files for target ListaEnlazadaSimple
ListaEnlazadaSimple_OBJECTS = \
"CMakeFiles/ListaEnlazadaSimple.dir/main.c.o" \
"CMakeFiles/ListaEnlazadaSimple.dir/listaEnlazadaDinamica.c.o" \
"CMakeFiles/ListaEnlazadaSimple.dir/tElemento.c.o"

# External object files for target ListaEnlazadaSimple
ListaEnlazadaSimple_EXTERNAL_OBJECTS =

ListaEnlazadaSimple: CMakeFiles/ListaEnlazadaSimple.dir/main.c.o
ListaEnlazadaSimple: CMakeFiles/ListaEnlazadaSimple.dir/listaEnlazadaDinamica.c.o
ListaEnlazadaSimple: CMakeFiles/ListaEnlazadaSimple.dir/tElemento.c.o
ListaEnlazadaSimple: CMakeFiles/ListaEnlazadaSimple.dir/build.make
ListaEnlazadaSimple: CMakeFiles/ListaEnlazadaSimple.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable ListaEnlazadaSimple"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ListaEnlazadaSimple.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ListaEnlazadaSimple.dir/build: ListaEnlazadaSimple
.PHONY : CMakeFiles/ListaEnlazadaSimple.dir/build

CMakeFiles/ListaEnlazadaSimple.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ListaEnlazadaSimple.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ListaEnlazadaSimple.dir/clean

CMakeFiles/ListaEnlazadaSimple.dir/depend:
	cd /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/cmake-build-debug /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/cmake-build-debug /Users/olegfomenkov/Documents/GitHub/ED_GICIB/Listas/2-ListaEnlazadaSimple/cmake-build-debug/CMakeFiles/ListaEnlazadaSimple.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ListaEnlazadaSimple.dir/depend

