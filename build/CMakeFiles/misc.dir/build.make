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
CMAKE_SOURCE_DIR = /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/build

# Include any dependencies generated for this target.
include CMakeFiles/misc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/misc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/misc.dir/flags.make

CMakeFiles/misc.dir/tests/test_misc.c.o: CMakeFiles/misc.dir/flags.make
CMakeFiles/misc.dir/tests/test_misc.c.o: ../tests/test_misc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/misc.dir/tests/test_misc.c.o"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/misc.dir/tests/test_misc.c.o   -c /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/tests/test_misc.c

CMakeFiles/misc.dir/tests/test_misc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/misc.dir/tests/test_misc.c.i"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/tests/test_misc.c > CMakeFiles/misc.dir/tests/test_misc.c.i

CMakeFiles/misc.dir/tests/test_misc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/misc.dir/tests/test_misc.c.s"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/tests/test_misc.c -o CMakeFiles/misc.dir/tests/test_misc.c.s

CMakeFiles/misc.dir/tests/test_misc.c.o.requires:

.PHONY : CMakeFiles/misc.dir/tests/test_misc.c.o.requires

CMakeFiles/misc.dir/tests/test_misc.c.o.provides: CMakeFiles/misc.dir/tests/test_misc.c.o.requires
	$(MAKE) -f CMakeFiles/misc.dir/build.make CMakeFiles/misc.dir/tests/test_misc.c.o.provides.build
.PHONY : CMakeFiles/misc.dir/tests/test_misc.c.o.provides

CMakeFiles/misc.dir/tests/test_misc.c.o.provides.build: CMakeFiles/misc.dir/tests/test_misc.c.o


CMakeFiles/misc.dir/src/logic.c.o: CMakeFiles/misc.dir/flags.make
CMakeFiles/misc.dir/src/logic.c.o: ../src/logic.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/misc.dir/src/logic.c.o"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/misc.dir/src/logic.c.o   -c /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/src/logic.c

CMakeFiles/misc.dir/src/logic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/misc.dir/src/logic.c.i"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/src/logic.c > CMakeFiles/misc.dir/src/logic.c.i

CMakeFiles/misc.dir/src/logic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/misc.dir/src/logic.c.s"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/src/logic.c -o CMakeFiles/misc.dir/src/logic.c.s

CMakeFiles/misc.dir/src/logic.c.o.requires:

.PHONY : CMakeFiles/misc.dir/src/logic.c.o.requires

CMakeFiles/misc.dir/src/logic.c.o.provides: CMakeFiles/misc.dir/src/logic.c.o.requires
	$(MAKE) -f CMakeFiles/misc.dir/build.make CMakeFiles/misc.dir/src/logic.c.o.provides.build
.PHONY : CMakeFiles/misc.dir/src/logic.c.o.provides

CMakeFiles/misc.dir/src/logic.c.o.provides.build: CMakeFiles/misc.dir/src/logic.c.o


CMakeFiles/misc.dir/src/graphic.c.o: CMakeFiles/misc.dir/flags.make
CMakeFiles/misc.dir/src/graphic.c.o: ../src/graphic.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/misc.dir/src/graphic.c.o"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/misc.dir/src/graphic.c.o   -c /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/src/graphic.c

CMakeFiles/misc.dir/src/graphic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/misc.dir/src/graphic.c.i"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/src/graphic.c > CMakeFiles/misc.dir/src/graphic.c.i

CMakeFiles/misc.dir/src/graphic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/misc.dir/src/graphic.c.s"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/src/graphic.c -o CMakeFiles/misc.dir/src/graphic.c.s

CMakeFiles/misc.dir/src/graphic.c.o.requires:

.PHONY : CMakeFiles/misc.dir/src/graphic.c.o.requires

CMakeFiles/misc.dir/src/graphic.c.o.provides: CMakeFiles/misc.dir/src/graphic.c.o.requires
	$(MAKE) -f CMakeFiles/misc.dir/build.make CMakeFiles/misc.dir/src/graphic.c.o.provides.build
.PHONY : CMakeFiles/misc.dir/src/graphic.c.o.provides

CMakeFiles/misc.dir/src/graphic.c.o.provides.build: CMakeFiles/misc.dir/src/graphic.c.o


CMakeFiles/misc.dir/src/misc.c.o: CMakeFiles/misc.dir/flags.make
CMakeFiles/misc.dir/src/misc.c.o: ../src/misc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/misc.dir/src/misc.c.o"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/misc.dir/src/misc.c.o   -c /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/src/misc.c

CMakeFiles/misc.dir/src/misc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/misc.dir/src/misc.c.i"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/src/misc.c > CMakeFiles/misc.dir/src/misc.c.i

CMakeFiles/misc.dir/src/misc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/misc.dir/src/misc.c.s"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/src/misc.c -o CMakeFiles/misc.dir/src/misc.c.s

CMakeFiles/misc.dir/src/misc.c.o.requires:

.PHONY : CMakeFiles/misc.dir/src/misc.c.o.requires

CMakeFiles/misc.dir/src/misc.c.o.provides: CMakeFiles/misc.dir/src/misc.c.o.requires
	$(MAKE) -f CMakeFiles/misc.dir/build.make CMakeFiles/misc.dir/src/misc.c.o.provides.build
.PHONY : CMakeFiles/misc.dir/src/misc.c.o.provides

CMakeFiles/misc.dir/src/misc.c.o.provides.build: CMakeFiles/misc.dir/src/misc.c.o


CMakeFiles/misc.dir/unity/src/unity.c.o: CMakeFiles/misc.dir/flags.make
CMakeFiles/misc.dir/unity/src/unity.c.o: ../unity/src/unity.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/misc.dir/unity/src/unity.c.o"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/misc.dir/unity/src/unity.c.o   -c /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/unity/src/unity.c

CMakeFiles/misc.dir/unity/src/unity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/misc.dir/unity/src/unity.c.i"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/unity/src/unity.c > CMakeFiles/misc.dir/unity/src/unity.c.i

CMakeFiles/misc.dir/unity/src/unity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/misc.dir/unity/src/unity.c.s"
	/usr/bin/gcc-7 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/unity/src/unity.c -o CMakeFiles/misc.dir/unity/src/unity.c.s

CMakeFiles/misc.dir/unity/src/unity.c.o.requires:

.PHONY : CMakeFiles/misc.dir/unity/src/unity.c.o.requires

CMakeFiles/misc.dir/unity/src/unity.c.o.provides: CMakeFiles/misc.dir/unity/src/unity.c.o.requires
	$(MAKE) -f CMakeFiles/misc.dir/build.make CMakeFiles/misc.dir/unity/src/unity.c.o.provides.build
.PHONY : CMakeFiles/misc.dir/unity/src/unity.c.o.provides

CMakeFiles/misc.dir/unity/src/unity.c.o.provides.build: CMakeFiles/misc.dir/unity/src/unity.c.o


# Object files for target misc
misc_OBJECTS = \
"CMakeFiles/misc.dir/tests/test_misc.c.o" \
"CMakeFiles/misc.dir/src/logic.c.o" \
"CMakeFiles/misc.dir/src/graphic.c.o" \
"CMakeFiles/misc.dir/src/misc.c.o" \
"CMakeFiles/misc.dir/unity/src/unity.c.o"

# External object files for target misc
misc_EXTERNAL_OBJECTS =

../out/misc: CMakeFiles/misc.dir/tests/test_misc.c.o
../out/misc: CMakeFiles/misc.dir/src/logic.c.o
../out/misc: CMakeFiles/misc.dir/src/graphic.c.o
../out/misc: CMakeFiles/misc.dir/src/misc.c.o
../out/misc: CMakeFiles/misc.dir/unity/src/unity.c.o
../out/misc: CMakeFiles/misc.dir/build.make
../out/misc: CMakeFiles/misc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable ../out/misc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/misc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/misc.dir/build: ../out/misc

.PHONY : CMakeFiles/misc.dir/build

CMakeFiles/misc.dir/requires: CMakeFiles/misc.dir/tests/test_misc.c.o.requires
CMakeFiles/misc.dir/requires: CMakeFiles/misc.dir/src/logic.c.o.requires
CMakeFiles/misc.dir/requires: CMakeFiles/misc.dir/src/graphic.c.o.requires
CMakeFiles/misc.dir/requires: CMakeFiles/misc.dir/src/misc.c.o.requires
CMakeFiles/misc.dir/requires: CMakeFiles/misc.dir/unity/src/unity.c.o.requires

.PHONY : CMakeFiles/misc.dir/requires

CMakeFiles/misc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/misc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/misc.dir/clean

CMakeFiles/misc.dir/depend:
	cd /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2 /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2 /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/build /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/build /media/harithalsafi/DATA/Education/University/University-Year-1/Programming-Project/comp1921/coursework_2/build/CMakeFiles/misc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/misc.dir/depend

