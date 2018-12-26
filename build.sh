mkdir build
cd build
conan install .. --settings arch=x86_64 build_type=Debug

unamestr=`uname`
echo "$unamestr"
if [[ "$unamestr" == "Darwin" ]]; then
  echo Darwin
  cmake .. -G Xcode
else
  echo Another Os
  cmake .. -G "Visual Studio 14 2015 Win64"
  #cmake .. -G "Visual Studio 14 2015"
  #cmake ..
fi
cmake --build . --config "Debug"
