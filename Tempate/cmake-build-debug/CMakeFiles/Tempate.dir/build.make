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
CMAKE_SOURCE_DIR = D:\ClionProjects\Third_course\Tempate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ClionProjects\Third_course\Tempate\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tempate.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tempate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tempate.dir/flags.make

CMakeFiles/Tempate.dir/main.cpp.obj: CMakeFiles/Tempate.dir/flags.make
CMakeFiles/Tempate.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ClionProjects\Third_course\Tempate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tempate.dir/main.cpp.obj"
	C:\dev\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Tempate.dir\main.cpp.obj -c D:\ClionProjects\Third_course\Tempate\main.cpp

CMakeFiles/Tempate.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tempate.dir/main.cpp.i"
	C:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ClionProjects\Third_course\Tempate\main.cpp > CMakeFiles\Tempate.dir\main.cpp.i

CMakeFiles/Tempate.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tempate.dir/main.cpp.s"
	C:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ClionProjects\Third_course\Tempate\main.cpp -o CMakeFiles\Tempate.dir\main.cpp.s

CMakeFiles/Tempate.dir/parse.cpp.obj: CMakeFiles/Tempate.dir/flags.make
CMakeFiles/Tempate.dir/parse.cpp.obj: ../parse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ClionProjects\Third_course\Tempate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tempate.dir/parse.cpp.obj"
	C:\dev\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Tempate.dir\parse.cpp.obj -c D:\ClionProjects\Third_course\Tempate\parse.cpp

CMakeFiles/Tempate.dir/parse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tempate.dir/parse.cpp.i"
	C:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ClionProjects\Third_course\Tempate\parse.cpp > CMakeFiles\Tempate.dir\parse.cpp.i

CMakeFiles/Tempate.dir/parse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tempate.dir/parse.cpp.s"
	C:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ClionProjects\Third_course\Tempate\parse.cpp -o CMakeFiles\Tempate.dir\parse.cpp.s

CMakeFiles/Tempate.dir/search_server.cpp.obj: CMakeFiles/Tempate.dir/flags.make
CMakeFiles/Tempate.dir/search_server.cpp.obj: ../search_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ClionProjects\Third_course\Tempate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Tempate.dir/search_server.cpp.obj"
	C:\dev\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Tempate.dir\search_server.cpp.obj -c D:\ClionProjects\Third_course\Tempate\search_server.cpp

CMakeFiles/Tempate.dir/search_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tempate.dir/search_server.cpp.i"
	C:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ClionProjects\Third_course\Tempate\search_server.cpp > CMakeFiles\Tempate.dir\search_server.cpp.i

CMakeFiles/Tempate.dir/search_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tempate.dir/search_server.cpp.s"
	C:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ClionProjects\Third_course\Tempate\search_server.cpp -o CMakeFiles\Tempate.dir\search_server.cpp.s

# Object files for target Tempate
Tempate_OBJECTS = \
"CMakeFiles/Tempate.dir/main.cpp.obj" \
"CMakeFiles/Tempate.dir/parse.cpp.obj" \
"CMakeFiles/Tempate.dir/search_server.cpp.obj"

# External object files for target Tempate
Tempate_EXTERNAL_OBJECTS =

Tempate.exe: CMakeFiles/Tempate.dir/main.cpp.obj
Tempate.exe: CMakeFiles/Tempate.dir/parse.cpp.obj
Tempate.exe: CMakeFiles/Tempate.dir/search_server.cpp.obj
Tempate.exe: CMakeFiles/Tempate.dir/build.make
Tempate.exe: CMakeFiles/Tempate.dir/linklibs.rsp
Tempate.exe: CMakeFiles/Tempate.dir/objects1.rsp
Tempate.exe: CMakeFiles/Tempate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ClionProjects\Third_course\Tempate\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Tempate.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tempate.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tempate.dir/build: Tempate.exe

.PHONY : CMakeFiles/Tempate.dir/build

CMakeFiles/Tempate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tempate.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Tempate.dir/clean

CMakeFiles/Tempate.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ClionProjects\Third_course\Tempate D:\ClionProjects\Third_course\Tempate D:\ClionProjects\Third_course\Tempate\cmake-build-debug D:\ClionProjects\Third_course\Tempate\cmake-build-debug D:\ClionProjects\Third_course\Tempate\cmake-build-debug\CMakeFiles\Tempate.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tempate.dir/depend

