BUILD_FOLDER=build
OBJ_FOLDER=$BUILD_FOLDER"/objs"

mkdir -p $BUILD_FOLDER
mkdir -p $OBJ_FOLDER

BINARY_PATH=$BUILD_FOLDER"/main"
FLAGS="-Wall -Wextra"

SHARED_OUTPUT=$OBJ_FOLDER"/test2.so"

gcc -o $SHARED_OUTPUT $FLAGS -fPIC -shared test2.c

if [[ $1 != *"debug"* ]]; then
	gcc $FLAGS -o $BINARY_PATH main.c
fi
