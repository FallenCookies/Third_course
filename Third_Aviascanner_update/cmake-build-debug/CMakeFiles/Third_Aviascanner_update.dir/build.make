# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.6\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.6\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\vlad\CLionProjects\Third_Aviascanner_update

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\vlad\CLionProjects\Third_Aviascanner_update\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Third_Aviascanner_update.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Third_Aviascanner_update.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Third_Aviascanner_update.dir/flags.make

CMakeFiles/Third_Aviascanner_update.dir/main.cpp.obj: CMakeFiles/Third_Aviascanner_update.dir/flags.make
CMakeFiles/Third_Aviascanner_update.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\vlad\CLionProjects\Third_Aviascanner_update\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Third_Aviascanner_update.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Third_Aviascanner_update.dir\main.cpp.obj -c C:\Users\vlad\CLionProjects\Third_Aviascanner_update\main.cpp

CMakeFiles/Third_Aviascanner_update.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Third_Aviascanner_update.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\vlad\CLionProjects\Third_Aviascanner_update\main.cpp > CMakeFiles\Third_Aviascanner_update.dir\main.cpp.i

CMakeFiles/Third_Aviascanner_update.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Third_Aviascanner_update.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\vlad\CLionProjects\Third_Aviascanner_update\main.cpp -o CMakeFiles\Third_Aviascanner_update.dir\main.cpp.s

CMakeFiles/Third_Aviascanner_update.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Third_Aviascanner_update.dir/main.cpp.obj.requires

CMakeFiles/Third_Aviascanner_update.dir/main.cpp.obj.provides: CMakeFiles/Third_Aviascanner_update.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Third_Aviascanner_update.dir\build.make CMakeFiles/Third_Aviascanner_update.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Third_Aviascanner_update.dir/main.cpp.obj.provides

CMakeFiles/Third_Aviascanner_update.dir/main.cpp.obj.provides.build: CMakeFiles/Third_Aviascanner_update.dir/main.cpp.obj


# Object files for target Third_Aviascanner_update
Third_Aviascanner_update_OBJECTS = \
"CMakeFiles/Third_Aviascanner_update.dir/main.cpp.obj"

# External object files for target Third_Aviascanner_update
Third_Aviascanner_update_EXTERNAL_OBJECTS =

Third_Aviascanner_update.exe: CMakeFiles/Third_Aviascanner_update.dir/main.cpp.obj
Third_Aviascanner_update.exe: CMakeFiles/Third_Aviascanner_update.dir/build.make
Third_Aviascanner_update.exe: CMakeFiles/Third_Aviascanner_update.dir/linklibs.rsp
Third_Aviascanner_update.exe: CMakeFiles/Third_Aviascanner_update.dir/objects1.rsp
Third_Aviascanner_update.exe: CMakeFiles/Third_Aviascanner_update.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\vlad\CLionProjects\Third_Aviascanner_update\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Third_Aviascanner_update.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Third_Aviascanner_update.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Third_Aviascanner_update.dir/build: Third_Aviascanner_update.exe

.PHONY : CMakeFiles/Third_Aviascanner_update.dir/build

CMakeFiles/Third_Aviascanner_update.dir/requires: CMakeFiles/Third_Aviascanner_update.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Third_Aviascanner_update.dir/requires

CMakeFiles/Third_Aviascanner_update.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Third_Aviascanner_update.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Third_Aviascanner_update.dir/clean

CMakeFiles/Third_Aviascanner_update.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\vlad\CLionProjects\Third_Aviascanner_update C:\Users\vlad\CLionProjects\Third_Aviascanner_update C:\Users\vlad\CLionProjects\Third_Aviascanner_update\cmake-build-debug C:\Users\vlad\CLionProjects\Third_Aviascanner_update\cmake-build-debug C:\Users\vlad\CLionProjects\Third_Aviascanner_update\cmake-build-debug\CMakeFiles\Third_Aviascanner_update.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Third_Aviascanner_update.dir/depend

