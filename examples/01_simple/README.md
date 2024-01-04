# How to start?
To compile the program you just need to run
```
./build.sh
```
then a build folder will be generated, there are your **main program** and the **shared object** `test2.so`.

To start the program you just need to run
```
./build/main
```
then a text will be printed in your terminal.

# How to test?
To test you just need to run the program and change the code in `test2.c`.

Something like replace the current code with
```c
#include <stdio.h>

void test2_a()
{
	printf("Bye!\n");
}
```

After do that you can run `./build.sh debug` and press Enter on the running program.
