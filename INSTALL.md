Installation Instructions
=========================
This program is written under C++, built using CMake, and tested using GoogleTest.  
To build, you will need:
* a C compiler such as GCC installed and set in the CC environment variable.
* a C++ compiler such a G++ installed and set in the CXX environment variable.
* CMake (http://www.cmake.org/cmake/resources/software.html) installed and accessible in the PATH environment variable i.e. installed in /usr/local/bin, with /usr/local/bin in $PATH.
* GoogleTest v1.5+ (http://code.google.com/p/googletest/) installed and accessible in the PATH environment variable i.e. installed in /usr/local/include and /usr/local/lib, with /usr/local/include and /usr/local/lib in $PATH.

#### Building

For best results:
1. Run "mkdir build".  
2. Run "cd build".  
3. Run "cmake .." to create the Makefile.  
4. Run "make" to build.  

Optionally:
* Run "make install" to install the program.  

#### Testing

* Run "ctest" to run all tests.  

#### Running

* Run "./diffr-c" to run the program from within the build directory, or if installed, just run "diffr-c".  

