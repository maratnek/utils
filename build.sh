mkdir build
cd build
conan install ..

unamestr=`uname`
if [[ "$unamestr" == "Darwin" ]]; then
  echo Darwin
  cmake .. -G Xcode
else
  echo Another Os
  cmake .. -G "Visual Studio 14 2015 Win64"
fi
cmake --build .. --config "Debug"
