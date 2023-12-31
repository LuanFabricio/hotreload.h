BUILD_FOLDER=build

mkdir -p $BUILD_FOLDER

BINARY_PATH=$BUILD_FOLDER"/main"
FLAGS="-Wall -Wextra"

gcc $FLAGS -o $BINARY_PATH main.c 
