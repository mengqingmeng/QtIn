# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mqm/WORKSPACE/CODE/cpp/QtIn/DirModeEx

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mqm/WORKSPACE/CODE/cpp/QtIn/build-DirModeEx-Qt_6_2_4_for_macOS-Debug

# Include any dependencies generated for this target.
include CMakeFiles/DirModeEx.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DirModeEx.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DirModeEx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DirModeEx.dir/flags.make

CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.o: CMakeFiles/DirModeEx.dir/flags.make
CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.o: DirModeEx_autogen/mocs_compilation.cpp
CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.o: CMakeFiles/DirModeEx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mqm/WORKSPACE/CODE/cpp/QtIn/build-DirModeEx-Qt_6_2_4_for_macOS-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.o -MF CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.o -c /Users/mqm/WORKSPACE/CODE/cpp/QtIn/build-DirModeEx-Qt_6_2_4_for_macOS-Debug/DirModeEx_autogen/mocs_compilation.cpp

CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mqm/WORKSPACE/CODE/cpp/QtIn/build-DirModeEx-Qt_6_2_4_for_macOS-Debug/DirModeEx_autogen/mocs_compilation.cpp > CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.i

CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mqm/WORKSPACE/CODE/cpp/QtIn/build-DirModeEx-Qt_6_2_4_for_macOS-Debug/DirModeEx_autogen/mocs_compilation.cpp -o CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.s

CMakeFiles/DirModeEx.dir/main.cpp.o: CMakeFiles/DirModeEx.dir/flags.make
CMakeFiles/DirModeEx.dir/main.cpp.o: /Users/mqm/WORKSPACE/CODE/cpp/QtIn/DirModeEx/main.cpp
CMakeFiles/DirModeEx.dir/main.cpp.o: CMakeFiles/DirModeEx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mqm/WORKSPACE/CODE/cpp/QtIn/build-DirModeEx-Qt_6_2_4_for_macOS-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DirModeEx.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DirModeEx.dir/main.cpp.o -MF CMakeFiles/DirModeEx.dir/main.cpp.o.d -o CMakeFiles/DirModeEx.dir/main.cpp.o -c /Users/mqm/WORKSPACE/CODE/cpp/QtIn/DirModeEx/main.cpp

CMakeFiles/DirModeEx.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DirModeEx.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mqm/WORKSPACE/CODE/cpp/QtIn/DirModeEx/main.cpp > CMakeFiles/DirModeEx.dir/main.cpp.i

CMakeFiles/DirModeEx.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DirModeEx.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mqm/WORKSPACE/CODE/cpp/QtIn/DirModeEx/main.cpp -o CMakeFiles/DirModeEx.dir/main.cpp.s

CMakeFiles/DirModeEx.dir/MainWindow.cpp.o: CMakeFiles/DirModeEx.dir/flags.make
CMakeFiles/DirModeEx.dir/MainWindow.cpp.o: /Users/mqm/WORKSPACE/CODE/cpp/QtIn/DirModeEx/MainWindow.cpp
CMakeFiles/DirModeEx.dir/MainWindow.cpp.o: CMakeFiles/DirModeEx.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mqm/WORKSPACE/CODE/cpp/QtIn/build-DirModeEx-Qt_6_2_4_for_macOS-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DirModeEx.dir/MainWindow.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DirModeEx.dir/MainWindow.cpp.o -MF CMakeFiles/DirModeEx.dir/MainWindow.cpp.o.d -o CMakeFiles/DirModeEx.dir/MainWindow.cpp.o -c /Users/mqm/WORKSPACE/CODE/cpp/QtIn/DirModeEx/MainWindow.cpp

CMakeFiles/DirModeEx.dir/MainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DirModeEx.dir/MainWindow.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mqm/WORKSPACE/CODE/cpp/QtIn/DirModeEx/MainWindow.cpp > CMakeFiles/DirModeEx.dir/MainWindow.cpp.i

CMakeFiles/DirModeEx.dir/MainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DirModeEx.dir/MainWindow.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mqm/WORKSPACE/CODE/cpp/QtIn/DirModeEx/MainWindow.cpp -o CMakeFiles/DirModeEx.dir/MainWindow.cpp.s

# Object files for target DirModeEx
DirModeEx_OBJECTS = \
"CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/DirModeEx.dir/main.cpp.o" \
"CMakeFiles/DirModeEx.dir/MainWindow.cpp.o"

# External object files for target DirModeEx
DirModeEx_EXTERNAL_OBJECTS =

DirModeEx.app/Contents/MacOS/DirModeEx: CMakeFiles/DirModeEx.dir/DirModeEx_autogen/mocs_compilation.cpp.o
DirModeEx.app/Contents/MacOS/DirModeEx: CMakeFiles/DirModeEx.dir/main.cpp.o
DirModeEx.app/Contents/MacOS/DirModeEx: CMakeFiles/DirModeEx.dir/MainWindow.cpp.o
DirModeEx.app/Contents/MacOS/DirModeEx: CMakeFiles/DirModeEx.dir/build.make
DirModeEx.app/Contents/MacOS/DirModeEx: /Users/mqm/WORKSPACE/QT/6.2.4/macos/lib/QtWidgets.framework/Versions/A/QtWidgets
DirModeEx.app/Contents/MacOS/DirModeEx: /Users/mqm/WORKSPACE/QT/6.2.4/macos/lib/QtGui.framework/Versions/A/QtGui
DirModeEx.app/Contents/MacOS/DirModeEx: /Users/mqm/WORKSPACE/QT/6.2.4/macos/lib/QtCore.framework/Versions/A/QtCore
DirModeEx.app/Contents/MacOS/DirModeEx: CMakeFiles/DirModeEx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mqm/WORKSPACE/CODE/cpp/QtIn/build-DirModeEx-Qt_6_2_4_for_macOS-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable DirModeEx.app/Contents/MacOS/DirModeEx"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DirModeEx.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DirModeEx.dir/build: DirModeEx.app/Contents/MacOS/DirModeEx
.PHONY : CMakeFiles/DirModeEx.dir/build

CMakeFiles/DirModeEx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DirModeEx.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DirModeEx.dir/clean

CMakeFiles/DirModeEx.dir/depend:
	cd /Users/mqm/WORKSPACE/CODE/cpp/QtIn/build-DirModeEx-Qt_6_2_4_for_macOS-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mqm/WORKSPACE/CODE/cpp/QtIn/DirModeEx /Users/mqm/WORKSPACE/CODE/cpp/QtIn/DirModeEx /Users/mqm/WORKSPACE/CODE/cpp/QtIn/build-DirModeEx-Qt_6_2_4_for_macOS-Debug /Users/mqm/WORKSPACE/CODE/cpp/QtIn/build-DirModeEx-Qt_6_2_4_for_macOS-Debug /Users/mqm/WORKSPACE/CODE/cpp/QtIn/build-DirModeEx-Qt_6_2_4_for_macOS-Debug/CMakeFiles/DirModeEx.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DirModeEx.dir/depend
