# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\ClionProjects\Third_course\Third_split_into_sentenses

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ClionProjects\Third_course\Third_split_into_sentenses\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Third_split_into_sentenses.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Third_split_into_sentenses.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Third_split_into_sentenses.dir/flags.make

CMakeFiles/Third_split_into_sentenses.dir/main.cpp.obj: CMakeFiles/Third_split_into_sentenses.dir/flags.make
CMakeFiles/Third_split_into_sentenses.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ClionProjects\Third_course\Third_split_into_sentenses\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Third_split_into_sentenses.dir/main.cpp.obj"
	C:\dev\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Third_split_into_sentenses.dir\main.cpp.obj -c D:\ClionProjects\Third_course\Third_split_into_sentenses\main.cpp

CMakeFiles/Third_split_into_sentenses.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Third_split_into_sentenses.dir/main.cpp.i"
	C:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ClionProjects\Third_course\Third_split_into_sentenses\main.cpp > CMakeFiles\Third_split_into_sentenses.dir\main.cpp.i

CMakeFiles/Third_split_into_sentenses.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Third_split_into_sentenses.dir/main.cpp.s"
	C:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ClionProjects\Third_course\Third_split_into_sentenses\main.cpp -o CMakeFiles\Third_split_into_sentenses.dir\main.cpp.s

# Object files for target Third_split_into_sentenses
Third_split_into_sentenses_OBJECTS = \
"CMakeFiles/Third_split_into_sentenses.dir/main.cpp.obj"

# External object files for target Third_split_into_sentenses
Third_split_into_sentenses_EXTERNAL_OBJECTS =

Third_split_into_sentenses.exe: CMakeFiles/Third_split_into_sentenses.dir/main.cpp.obj
Third_split_into_sentenses.exe: CMakeFiles/Third_split_into_sentenses.dir/build.make
Third_split_into_sentenses.exe: CMakeFiles/Third_split_into_sentenses.dir/linklibs.rsp
Third_split_into_sentenses.exe: CMakeFiles/Third_split_into_sentenses.dir/objects1.rsp
Third_split_into_sentenses.exe: CMakeFiles/Third_split_into_sentenses.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ClionProjects\Third_course\Third_split_into_sentenses\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Third_split_into_sentenses.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Third_split_into_sentenses.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Third_split_into_sentenses.dir/build: Third_split_into_sentenses.exe

.PHONY : CMakeFiles/Third_split_into_sentenses.dir/build

CMakeFiles/Third_split_into_sentenses.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Third_split_into_sentenses.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Third_split_into_sentenses.dir/clean

CMakeFiles/Third_split_into_sentenses.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ClionProjects\Third_course\Third_split_into_sentenses D:\ClionProjects\Third_course\Third_split_into_sentenses D:\ClionProjects\Third_course\Third_split_into_sentenses\cmake-build-debug D:\ClionProjects\Third_course\Third_split_into_sentenses\cmake-build-debug D:\ClionProjects\Third_course\Third_split_into_sentenses\cmake-build-debug\CMakeFiles\Third_split_into_sentenses.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Third_split_into_sentenses.dir/depend

