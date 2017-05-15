Benjamin A. Slack
CS5310, a0
05.15.17
benjamin.slack@wmich.edu

Grader:
This project was developed with CLion using MingW64 and
uses CMake to create its build files. If you'll not be
grading and testing in windows, you'll need to install
CMake and then generate the appropriate build  files using
the CMakeLists.txts files in the project.

In addition, if you intend to compile the unit testing
part, you'll need to use CMake to build Google's testing
framework as well. A binary version for windows x64 will be
attached as well as the source. Applications statically
compiled and should rely on any linking.

The project's executables, a0.exe & test_sorts.exe, do the
following:

a0.exe will run sorts on random lists of integers
of lengths from 2 to 100; it will then generate a CSV file
with the resulting timing in nanoseconds of those sorts;
during execution, standard out will also reflect those
timings as well as the contents of the list pre and post
sort when the number of the lists is equal to 10.

test_sorts.exe will run unit tests on sorts::selectionSort
, checking a reversed list as well as an empty one. Output
will consist of the results of the test.
