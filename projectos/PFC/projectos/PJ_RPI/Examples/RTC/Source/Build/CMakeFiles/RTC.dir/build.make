# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/pi/Desktop/projectos/PJ_RPI/Examples/RTC/Source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Desktop/projectos/PJ_RPI/Examples/RTC/Source/Build

# Include any dependencies generated for this target.
include CMakeFiles/RTC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RTC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RTC.dir/flags.make

CMakeFiles/RTC.dir/main.c.o: CMakeFiles/RTC.dir/flags.make
CMakeFiles/RTC.dir/main.c.o: ../main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/Desktop/projectos/PJ_RPI/Examples/RTC/Source/Build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/RTC.dir/main.c.o"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/RTC.dir/main.c.o   -c /home/pi/Desktop/projectos/PJ_RPI/Examples/RTC/Source/main.c

CMakeFiles/RTC.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/RTC.dir/main.c.i"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/pi/Desktop/projectos/PJ_RPI/Examples/RTC/Source/main.c > CMakeFiles/RTC.dir/main.c.i

CMakeFiles/RTC.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/RTC.dir/main.c.s"
	/usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/pi/Desktop/projectos/PJ_RPI/Examples/RTC/Source/main.c -o CMakeFiles/RTC.dir/main.c.s

CMakeFiles/RTC.dir/main.c.o.requires:
.PHONY : CMakeFiles/RTC.dir/main.c.o.requires

CMakeFiles/RTC.dir/main.c.o.provides: CMakeFiles/RTC.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/RTC.dir/build.make CMakeFiles/RTC.dir/main.c.o.provides.build
.PHONY : CMakeFiles/RTC.dir/main.c.o.provides

CMakeFiles/RTC.dir/main.c.o.provides.build: CMakeFiles/RTC.dir/main.c.o

# Object files for target RTC
RTC_OBJECTS = \
"CMakeFiles/RTC.dir/main.c.o"

# External object files for target RTC
RTC_EXTERNAL_OBJECTS =

RTC: CMakeFiles/RTC.dir/main.c.o
RTC: CMakeFiles/RTC.dir/build.make
RTC: CMakeFiles/RTC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable RTC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RTC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RTC.dir/build: RTC
.PHONY : CMakeFiles/RTC.dir/build

CMakeFiles/RTC.dir/requires: CMakeFiles/RTC.dir/main.c.o.requires
.PHONY : CMakeFiles/RTC.dir/requires

CMakeFiles/RTC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RTC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RTC.dir/clean

CMakeFiles/RTC.dir/depend:
	cd /home/pi/Desktop/projectos/PJ_RPI/Examples/RTC/Source/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Desktop/projectos/PJ_RPI/Examples/RTC/Source /home/pi/Desktop/projectos/PJ_RPI/Examples/RTC/Source /home/pi/Desktop/projectos/PJ_RPI/Examples/RTC/Source/Build /home/pi/Desktop/projectos/PJ_RPI/Examples/RTC/Source/Build /home/pi/Desktop/projectos/PJ_RPI/Examples/RTC/Source/Build/CMakeFiles/RTC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RTC.dir/depend

