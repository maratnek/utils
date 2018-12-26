mkdir build
cd build
conan install .. -s build_type=Debug
conan install .. -s build_type=Release

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
