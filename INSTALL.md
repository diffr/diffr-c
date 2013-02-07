Installation Instructions
=========================
This program is written under C++, built using CMake, and tested using GoogleTest.  
To build, you will need:
* a C compiler such as GCC installed and set in the CC environment variable.
* a C++ compiler such a G++ installed and set in the CXX environment variable.
* CMake (http://www.cmake.org/cmake/resources/software.html) installed and accessible in the PATH environment variable i.e. installed in /usr/local/bin, with /usr/local/bin in $PATH.
Optionally install:
* lcov if you wish to generate lcov coverage reports.
* cobertura,python,gcovr if you wish to generate cobertura coverage reports (for jenkins). 

#### Building

For best results:
1. Run "mkdir build".  
2. Run "cd build".  
3. Run "cmake .." to create the Makefile.  
4. Run "make" to build.  

#### Installation

Optionally:
* Run "make install" to install the program.

#### Testing

1. Run "mkdir build"
2. Run "cd build"
3. Run "cmake -D TESTING=FAST .." to create the Makefile with most tests enabled, or run "cmake -D TESTING=ALL .." to enable integration tests as well.
4. Run "make" to build.
5. Run "make test" to run tests.

#### Coverage reports

1. Run "mkdir build"
2. Run "cd build"
3. Run "cmake .. -DCOVERAGE=LCOV -DTESTING=ALL" to create the Makefile and output using lcov, or "cmake .. -DCOVERAGE=COBERTURA -DTESTING=ALL" to use cobertura instead.
4. Run "make" to build.
5. Run "make coverage" to run tests and generate a coverage report.

#### Running

* Run "./diffr" to run the program from within the build directory, or if installed, just run "diffr".
* Run "./patchr" to run the program from within the build directory, or if installed, just run "patchr".

