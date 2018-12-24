mkdir build
cd build
conan install ..
cmake .. -G "Visual Studio 14 2015 Win64"
cmake --build .. --config "Debug"
