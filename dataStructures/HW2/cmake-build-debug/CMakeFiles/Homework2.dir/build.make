# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /cygdrive/c/Users/dillo/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/dillo/AppData/Local/JetBrains/CLion2020.1/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/dillo/CLionProjects/Homework2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/dillo/CLionProjects/Homework2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Homework2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Homework2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Homework2.dir/flags.make

CMakeFiles/Homework2.dir/PhysVec.cpp.o: CMakeFiles/Homework2.dir/flags.make
CMakeFiles/Homework2.dir/PhysVec.cpp.o: ../PhysVec.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/dillo/CLionProjects/Homework2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Homework2.dir/PhysVec.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Homework2.dir/PhysVec.cpp.o -c /cygdrive/c/Users/dillo/CLionProjects/Homework2/PhysVec.cpp

CMakeFiles/Homework2.dir/PhysVec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Homework2.dir/PhysVec.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/dillo/CLionProjects/Homework2/PhysVec.cpp > CMakeFiles/Homework2.dir/PhysVec.cpp.i

CMakeFiles/Homework2.dir/PhysVec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Homework2.dir/PhysVec.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/dillo/CLionProjects/Homework2/PhysVec.cpp -o CMakeFiles/Homework2.dir/PhysVec.cpp.s

CMakeFiles/Homework2.dir/main.cpp.o: CMakeFiles/Homework2.dir/flags.make
CMakeFiles/Homework2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/dillo/CLionProjects/Homework2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Homework2.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Homework2.dir/main.cpp.o -c /cygdrive/c/Users/dillo/CLionProjects/Homework2/main.cpp

CMakeFiles/Homework2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Homework2.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/dillo/CLionProjects/Homework2/main.cpp > CMakeFiles/Homework2.dir/main.cpp.i

CMakeFiles/Homework2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Homework2.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/dillo/CLionProjects/Homework2/main.cpp -o CMakeFiles/Homework2.dir/main.cpp.s

# Object files for target Homework2
Homework2_OBJECTS = \
"CMakeFiles/Homework2.dir/PhysVec.cpp.o" \
"CMakeFiles/Homework2.dir/main.cpp.o"

# External object files for target Homework2
Homework2_EXTERNAL_OBJECTS =

Homework2.exe: CMakeFiles/Homework2.dir/PhysVec.cpp.o
Homework2.exe: CMakeFiles/Homework2.dir/main.cpp.o
Homework2.exe: CMakeFiles/Homework2.dir/build.make
Homework2.exe: CMakeFiles/Homework2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/dillo/CLionProjects/Homework2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Homework2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Homework2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Homework2.dir/build: Homework2.exe

.PHONY : CMakeFiles/Homework2.dir/build

CMakeFiles/Homework2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Homework2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Homework2.dir/clean

CMakeFiles/Homework2.dir/depend:
	cd /cygdrive/c/Users/dillo/CLionProjects/Homework2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/dillo/CLionProjects/Homework2 /cygdrive/c/Users/dillo/CLionProjects/Homework2 /cygdrive/c/Users/dillo/CLionProjects/Homework2/cmake-build-debug /cygdrive/c/Users/dillo/CLionProjects/Homework2/cmake-build-debug /cygdrive/c/Users/dillo/CLionProjects/Homework2/cmake-build-debug/CMakeFiles/Homework2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Homework2.dir/depend

