# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\stage\jetbrains\clion-2021.2.1\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\stage\jetbrains\clion-2021.2.1\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\var\workspace\dcl113-2021-sep-16\module04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\var\workspace\dcl113-2021-sep-16\module04\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/exercise02.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/exercise02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exercise02.dir/flags.make

CMakeFiles/exercise02.dir/exercise02.cpp.obj: CMakeFiles/exercise02.dir/flags.make
CMakeFiles/exercise02.dir/exercise02.cpp.obj: ../exercise02.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\var\workspace\dcl113-2021-sep-16\module04\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exercise02.dir/exercise02.cpp.obj"
	D:\opt\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\exercise02.dir\exercise02.cpp.obj -c D:\var\workspace\dcl113-2021-sep-16\module04\exercise02.cpp

CMakeFiles/exercise02.dir/exercise02.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exercise02.dir/exercise02.cpp.i"
	D:\opt\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\var\workspace\dcl113-2021-sep-16\module04\exercise02.cpp > CMakeFiles\exercise02.dir\exercise02.cpp.i

CMakeFiles/exercise02.dir/exercise02.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exercise02.dir/exercise02.cpp.s"
	D:\opt\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\var\workspace\dcl113-2021-sep-16\module04\exercise02.cpp -o CMakeFiles\exercise02.dir\exercise02.cpp.s

# Object files for target exercise02
exercise02_OBJECTS = \
"CMakeFiles/exercise02.dir/exercise02.cpp.obj"

# External object files for target exercise02
exercise02_EXTERNAL_OBJECTS =

exercise02.exe: CMakeFiles/exercise02.dir/exercise02.cpp.obj
exercise02.exe: CMakeFiles/exercise02.dir/build.make
exercise02.exe: CMakeFiles/exercise02.dir/linklibs.rsp
exercise02.exe: CMakeFiles/exercise02.dir/objects1.rsp
exercise02.exe: CMakeFiles/exercise02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\var\workspace\dcl113-2021-sep-16\module04\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable exercise02.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\exercise02.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exercise02.dir/build: exercise02.exe
.PHONY : CMakeFiles/exercise02.dir/build

CMakeFiles/exercise02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\exercise02.dir\cmake_clean.cmake
.PHONY : CMakeFiles/exercise02.dir/clean

CMakeFiles/exercise02.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\var\workspace\dcl113-2021-sep-16\module04 D:\var\workspace\dcl113-2021-sep-16\module04 D:\var\workspace\dcl113-2021-sep-16\module04\cmake-build-debug D:\var\workspace\dcl113-2021-sep-16\module04\cmake-build-debug D:\var\workspace\dcl113-2021-sep-16\module04\cmake-build-debug\CMakeFiles\exercise02.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exercise02.dir/depend
