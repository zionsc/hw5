# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/codio/workspace/hw5/hw5_tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/codio/workspace/hw5/hw5_tests

# Utility rule file for debug-Schedule.SimpleNoSolNoAvail2.

# Include the progress variables for this target.
include schedwork_tests/CMakeFiles/debug-Schedule.SimpleNoSolNoAvail2.dir/progress.make

schedwork_tests/CMakeFiles/debug-Schedule.SimpleNoSolNoAvail2:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/codio/workspace/hw5/hw5_tests/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Debugging Schedule.SimpleNoSolNoAvail2 with GDB..."
	cd /home/codio/workspace/hw5 && gdb --args /home/codio/workspace/hw5/hw5_tests/schedwork_tests/schedwork_tests --gtest_filter=Schedule.SimpleNoSolNoAvail2

debug-Schedule.SimpleNoSolNoAvail2: schedwork_tests/CMakeFiles/debug-Schedule.SimpleNoSolNoAvail2
debug-Schedule.SimpleNoSolNoAvail2: schedwork_tests/CMakeFiles/debug-Schedule.SimpleNoSolNoAvail2.dir/build.make

.PHONY : debug-Schedule.SimpleNoSolNoAvail2

# Rule to build all files generated by this target.
schedwork_tests/CMakeFiles/debug-Schedule.SimpleNoSolNoAvail2.dir/build: debug-Schedule.SimpleNoSolNoAvail2

.PHONY : schedwork_tests/CMakeFiles/debug-Schedule.SimpleNoSolNoAvail2.dir/build

schedwork_tests/CMakeFiles/debug-Schedule.SimpleNoSolNoAvail2.dir/clean:
	cd /home/codio/workspace/hw5/hw5_tests/schedwork_tests && $(CMAKE_COMMAND) -P CMakeFiles/debug-Schedule.SimpleNoSolNoAvail2.dir/cmake_clean.cmake
.PHONY : schedwork_tests/CMakeFiles/debug-Schedule.SimpleNoSolNoAvail2.dir/clean

schedwork_tests/CMakeFiles/debug-Schedule.SimpleNoSolNoAvail2.dir/depend:
	cd /home/codio/workspace/hw5/hw5_tests && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/codio/workspace/hw5/hw5_tests /home/codio/workspace/hw5/hw5_tests/schedwork_tests /home/codio/workspace/hw5/hw5_tests /home/codio/workspace/hw5/hw5_tests/schedwork_tests /home/codio/workspace/hw5/hw5_tests/schedwork_tests/CMakeFiles/debug-Schedule.SimpleNoSolNoAvail2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : schedwork_tests/CMakeFiles/debug-Schedule.SimpleNoSolNoAvail2.dir/depend

