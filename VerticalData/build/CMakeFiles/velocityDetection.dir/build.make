# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_SOURCE_DIR = /home/pi/CME_495/Project/CME_495/VerticalData

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/CME_495/Project/CME_495/VerticalData/build

# Include any dependencies generated for this target.
include CMakeFiles/velocityDetection.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/velocityDetection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/velocityDetection.dir/flags.make

CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o: CMakeFiles/velocityDetection.dir/flags.make
CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o: ../src/velocityTracking.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/CME_495/Project/CME_495/VerticalData/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o -c /home/pi/CME_495/Project/CME_495/VerticalData/src/velocityTracking.cpp

CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/CME_495/Project/CME_495/VerticalData/src/velocityTracking.cpp > CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.i

CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/CME_495/Project/CME_495/VerticalData/src/velocityTracking.cpp -o CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.s

CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o.requires:
.PHONY : CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o.requires

CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o.provides: CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o.requires
	$(MAKE) -f CMakeFiles/velocityDetection.dir/build.make CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o.provides.build
.PHONY : CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o.provides

CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o.provides.build: CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o

CMakeFiles/velocityDetection.dir/src/Height.cpp.o: CMakeFiles/velocityDetection.dir/flags.make
CMakeFiles/velocityDetection.dir/src/Height.cpp.o: ../src/Height.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/CME_495/Project/CME_495/VerticalData/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/velocityDetection.dir/src/Height.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/velocityDetection.dir/src/Height.cpp.o -c /home/pi/CME_495/Project/CME_495/VerticalData/src/Height.cpp

CMakeFiles/velocityDetection.dir/src/Height.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/velocityDetection.dir/src/Height.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/CME_495/Project/CME_495/VerticalData/src/Height.cpp > CMakeFiles/velocityDetection.dir/src/Height.cpp.i

CMakeFiles/velocityDetection.dir/src/Height.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/velocityDetection.dir/src/Height.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/CME_495/Project/CME_495/VerticalData/src/Height.cpp -o CMakeFiles/velocityDetection.dir/src/Height.cpp.s

CMakeFiles/velocityDetection.dir/src/Height.cpp.o.requires:
.PHONY : CMakeFiles/velocityDetection.dir/src/Height.cpp.o.requires

CMakeFiles/velocityDetection.dir/src/Height.cpp.o.provides: CMakeFiles/velocityDetection.dir/src/Height.cpp.o.requires
	$(MAKE) -f CMakeFiles/velocityDetection.dir/build.make CMakeFiles/velocityDetection.dir/src/Height.cpp.o.provides.build
.PHONY : CMakeFiles/velocityDetection.dir/src/Height.cpp.o.provides

CMakeFiles/velocityDetection.dir/src/Height.cpp.o.provides.build: CMakeFiles/velocityDetection.dir/src/Height.cpp.o

CMakeFiles/velocityDetection.dir/src/output.c.o: CMakeFiles/velocityDetection.dir/flags.make
CMakeFiles/velocityDetection.dir/src/output.c.o: ../src/output.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/CME_495/Project/CME_495/VerticalData/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/velocityDetection.dir/src/output.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/velocityDetection.dir/src/output.c.o   -c /home/pi/CME_495/Project/CME_495/VerticalData/src/output.c

CMakeFiles/velocityDetection.dir/src/output.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/velocityDetection.dir/src/output.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/pi/CME_495/Project/CME_495/VerticalData/src/output.c > CMakeFiles/velocityDetection.dir/src/output.c.i

CMakeFiles/velocityDetection.dir/src/output.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/velocityDetection.dir/src/output.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/pi/CME_495/Project/CME_495/VerticalData/src/output.c -o CMakeFiles/velocityDetection.dir/src/output.c.s

CMakeFiles/velocityDetection.dir/src/output.c.o.requires:
.PHONY : CMakeFiles/velocityDetection.dir/src/output.c.o.requires

CMakeFiles/velocityDetection.dir/src/output.c.o.provides: CMakeFiles/velocityDetection.dir/src/output.c.o.requires
	$(MAKE) -f CMakeFiles/velocityDetection.dir/build.make CMakeFiles/velocityDetection.dir/src/output.c.o.provides.build
.PHONY : CMakeFiles/velocityDetection.dir/src/output.c.o.provides

CMakeFiles/velocityDetection.dir/src/output.c.o.provides.build: CMakeFiles/velocityDetection.dir/src/output.c.o

CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o: CMakeFiles/velocityDetection.dir/flags.make
CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o: ../src/VerticalData.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/CME_495/Project/CME_495/VerticalData/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o -c /home/pi/CME_495/Project/CME_495/VerticalData/src/VerticalData.cpp

CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/CME_495/Project/CME_495/VerticalData/src/VerticalData.cpp > CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.i

CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/CME_495/Project/CME_495/VerticalData/src/VerticalData.cpp -o CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.s

CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o.requires:
.PHONY : CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o.requires

CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o.provides: CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o.requires
	$(MAKE) -f CMakeFiles/velocityDetection.dir/build.make CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o.provides.build
.PHONY : CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o.provides

CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o.provides.build: CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o

CMakeFiles/velocityDetection.dir/src/sensor.c.o: CMakeFiles/velocityDetection.dir/flags.make
CMakeFiles/velocityDetection.dir/src/sensor.c.o: ../src/sensor.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/CME_495/Project/CME_495/VerticalData/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/velocityDetection.dir/src/sensor.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/velocityDetection.dir/src/sensor.c.o   -c /home/pi/CME_495/Project/CME_495/VerticalData/src/sensor.c

CMakeFiles/velocityDetection.dir/src/sensor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/velocityDetection.dir/src/sensor.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/pi/CME_495/Project/CME_495/VerticalData/src/sensor.c > CMakeFiles/velocityDetection.dir/src/sensor.c.i

CMakeFiles/velocityDetection.dir/src/sensor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/velocityDetection.dir/src/sensor.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/pi/CME_495/Project/CME_495/VerticalData/src/sensor.c -o CMakeFiles/velocityDetection.dir/src/sensor.c.s

CMakeFiles/velocityDetection.dir/src/sensor.c.o.requires:
.PHONY : CMakeFiles/velocityDetection.dir/src/sensor.c.o.requires

CMakeFiles/velocityDetection.dir/src/sensor.c.o.provides: CMakeFiles/velocityDetection.dir/src/sensor.c.o.requires
	$(MAKE) -f CMakeFiles/velocityDetection.dir/build.make CMakeFiles/velocityDetection.dir/src/sensor.c.o.provides.build
.PHONY : CMakeFiles/velocityDetection.dir/src/sensor.c.o.provides

CMakeFiles/velocityDetection.dir/src/sensor.c.o.provides.build: CMakeFiles/velocityDetection.dir/src/sensor.c.o

CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o: CMakeFiles/velocityDetection.dir/flags.make
CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o: ../src/TimedData.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/CME_495/Project/CME_495/VerticalData/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o -c /home/pi/CME_495/Project/CME_495/VerticalData/src/TimedData.cpp

CMakeFiles/velocityDetection.dir/src/TimedData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/velocityDetection.dir/src/TimedData.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/CME_495/Project/CME_495/VerticalData/src/TimedData.cpp > CMakeFiles/velocityDetection.dir/src/TimedData.cpp.i

CMakeFiles/velocityDetection.dir/src/TimedData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/velocityDetection.dir/src/TimedData.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/CME_495/Project/CME_495/VerticalData/src/TimedData.cpp -o CMakeFiles/velocityDetection.dir/src/TimedData.cpp.s

CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o.requires:
.PHONY : CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o.requires

CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o.provides: CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o.requires
	$(MAKE) -f CMakeFiles/velocityDetection.dir/build.make CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o.provides.build
.PHONY : CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o.provides

CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o.provides.build: CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o

CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o: CMakeFiles/velocityDetection.dir/flags.make
CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o: ../src/VelocityData.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/CME_495/Project/CME_495/VerticalData/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o -c /home/pi/CME_495/Project/CME_495/VerticalData/src/VelocityData.cpp

CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/pi/CME_495/Project/CME_495/VerticalData/src/VelocityData.cpp > CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.i

CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/pi/CME_495/Project/CME_495/VerticalData/src/VelocityData.cpp -o CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.s

CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o.requires:
.PHONY : CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o.requires

CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o.provides: CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o.requires
	$(MAKE) -f CMakeFiles/velocityDetection.dir/build.make CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o.provides.build
.PHONY : CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o.provides

CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o.provides.build: CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o

# Object files for target velocityDetection
velocityDetection_OBJECTS = \
"CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o" \
"CMakeFiles/velocityDetection.dir/src/Height.cpp.o" \
"CMakeFiles/velocityDetection.dir/src/output.c.o" \
"CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o" \
"CMakeFiles/velocityDetection.dir/src/sensor.c.o" \
"CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o" \
"CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o"

# External object files for target velocityDetection
velocityDetection_EXTERNAL_OBJECTS =

velocityDetection: CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o
velocityDetection: CMakeFiles/velocityDetection.dir/src/Height.cpp.o
velocityDetection: CMakeFiles/velocityDetection.dir/src/output.c.o
velocityDetection: CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o
velocityDetection: CMakeFiles/velocityDetection.dir/src/sensor.c.o
velocityDetection: CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o
velocityDetection: CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o
velocityDetection: CMakeFiles/velocityDetection.dir/build.make
velocityDetection: CMakeFiles/velocityDetection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable velocityDetection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/velocityDetection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/velocityDetection.dir/build: velocityDetection
.PHONY : CMakeFiles/velocityDetection.dir/build

CMakeFiles/velocityDetection.dir/requires: CMakeFiles/velocityDetection.dir/src/velocityTracking.cpp.o.requires
CMakeFiles/velocityDetection.dir/requires: CMakeFiles/velocityDetection.dir/src/Height.cpp.o.requires
CMakeFiles/velocityDetection.dir/requires: CMakeFiles/velocityDetection.dir/src/output.c.o.requires
CMakeFiles/velocityDetection.dir/requires: CMakeFiles/velocityDetection.dir/src/VerticalData.cpp.o.requires
CMakeFiles/velocityDetection.dir/requires: CMakeFiles/velocityDetection.dir/src/sensor.c.o.requires
CMakeFiles/velocityDetection.dir/requires: CMakeFiles/velocityDetection.dir/src/TimedData.cpp.o.requires
CMakeFiles/velocityDetection.dir/requires: CMakeFiles/velocityDetection.dir/src/VelocityData.cpp.o.requires
.PHONY : CMakeFiles/velocityDetection.dir/requires

CMakeFiles/velocityDetection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/velocityDetection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/velocityDetection.dir/clean

CMakeFiles/velocityDetection.dir/depend:
	cd /home/pi/CME_495/Project/CME_495/VerticalData/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/CME_495/Project/CME_495/VerticalData /home/pi/CME_495/Project/CME_495/VerticalData /home/pi/CME_495/Project/CME_495/VerticalData/build /home/pi/CME_495/Project/CME_495/VerticalData/build /home/pi/CME_495/Project/CME_495/VerticalData/build/CMakeFiles/velocityDetection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/velocityDetection.dir/depend

