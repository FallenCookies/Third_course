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
CMAKE_SOURCE_DIR = D:\ClionProjects\Third_course\Third_priority_collection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ClionProjects\Third_course\Third_priority_collection\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Third_priority_collection.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Third_priority_collection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Third_priority_collection.dir/flags.make

CMakeFiles/Third_priority_collection.dir/main.cpp.obj: CMakeFiles/Third_priority_collection.dir/flags.make
CMakeFiles/Third_priority_collection.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ClionProjects\Third_course\Third_priority_collection\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Third_priority_collection.dir/main.cpp.obj"
	C:\dev\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Third_priority_collection.dir\main.cpp.obj -c D:\ClionProjects\Third_course\Third_priority_collection\main.cpp

CMakeFiles/Third_priority_collection.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Third_priority_collection.dir/main.cpp.i"
	C:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ClionProjects\Third_course\Third_priority_collection\main.cpp > CMakeFiles\Third_priority_collection.dir\main.cpp.i

CMakeFiles/Third_priority_collection.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Third_priority_collection.dir/main.cpp.s"
	C:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ClionProjects\Third_course\Third_priority_collection\main.cpp -o CMakeFiles\Third_priority_collection.dir\main.cpp.s

# Object files for target Third_priority_collection
Third_priority_collection_OBJECTS = \
"CMakeFiles/Third_priority_collection.dir/main.cpp.obj"

# External object files for target Third_priority_collection
Third_priority_collection_EXTERNAL_OBJECTS =

Third_priority_collection.exe: CMakeFiles/Third_priority_collection.dir/main.cpp.obj
Third_priority_collection.exe: CMakeFiles/Third_priority_collection.dir/build.make
Third_priority_collection.exe: CMakeFiles/Third_priority_collection.dir/linklibs.rsp
Third_priority_collection.exe: CMakeFiles/Third_priority_collection.dir/objects1.rsp
Third_priority_collection.exe: CMakeFiles/Third_priority_collection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ClionProjects\Third_course\Third_priority_collection\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Third_priority_collection.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Third_priority_collection.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Third_priority_collection.dir/build: Third_priority_collection.exe

.PHONY : CMakeFiles/Third_priority_collection.dir/build

CMakeFiles/Third_priority_collection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Third_priority_collection.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Third_priority_collection.dir/clean

CMakeFiles/Third_priority_collection.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ClionProjects\Third_course\Third_priority_collection D:\ClionProjects\Third_course\Third_priority_collection D:\ClionProjects\Third_course\Third_priority_collection\cmake-build-debug D:\ClionProjects\Third_course\Third_priority_collection\cmake-build-debug D:\ClionProjects\Third_course\Third_priority_collection\cmake-build-debug\CMakeFiles\Third_priority_collection.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Third_priority_collection.dir/depend

