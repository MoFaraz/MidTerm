# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mopha\Desktop\First_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mopha\Desktop\First_Project\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/First_Project4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/First_Project4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/First_Project4.dir/flags.make

CMakeFiles/First_Project4.dir/test4.cpp.obj: CMakeFiles/First_Project4.dir/flags.make
CMakeFiles/First_Project4.dir/test4.cpp.obj: ../test4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mopha\Desktop\First_Project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/First_Project4.dir/test4.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\First_Project4.dir\test4.cpp.obj -c C:\Users\mopha\Desktop\First_Project\test4.cpp

CMakeFiles/First_Project4.dir/test4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/First_Project4.dir/test4.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mopha\Desktop\First_Project\test4.cpp > CMakeFiles\First_Project4.dir\test4.cpp.i

CMakeFiles/First_Project4.dir/test4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/First_Project4.dir/test4.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mopha\Desktop\First_Project\test4.cpp -o CMakeFiles\First_Project4.dir\test4.cpp.s

# Object files for target First_Project4
First_Project4_OBJECTS = \
"CMakeFiles/First_Project4.dir/test4.cpp.obj"

# External object files for target First_Project4
First_Project4_EXTERNAL_OBJECTS =

First_Project4.exe: CMakeFiles/First_Project4.dir/test4.cpp.obj
First_Project4.exe: CMakeFiles/First_Project4.dir/build.make
First_Project4.exe: CMakeFiles/First_Project4.dir/linklibs.rsp
First_Project4.exe: CMakeFiles/First_Project4.dir/objects1.rsp
First_Project4.exe: CMakeFiles/First_Project4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mopha\Desktop\First_Project\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable First_Project4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\First_Project4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/First_Project4.dir/build: First_Project4.exe

.PHONY : CMakeFiles/First_Project4.dir/build

CMakeFiles/First_Project4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\First_Project4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/First_Project4.dir/clean

CMakeFiles/First_Project4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mopha\Desktop\First_Project C:\Users\mopha\Desktop\First_Project C:\Users\mopha\Desktop\First_Project\cmake-build-debug C:\Users\mopha\Desktop\First_Project\cmake-build-debug C:\Users\mopha\Desktop\First_Project\cmake-build-debug\CMakeFiles\First_Project4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/First_Project4.dir/depend

