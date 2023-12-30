#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define __HOTRELOAD_IMPLEMENTATION
#include "hotreload.h"

extern void __test2();

static uint8_t counter = 0;

bool should_reset() 
{
	counter++;
	return counter == 0;
}

void __test() 
{
	printf("Testing from test!\n");	
}

void __test2()
{
	printf("Testing from test2!\n");
}

int main(void)
{
	bool running = true;

	reset_func_t functions[] = {
		&__test, &__test2,
	};

	hr_init(CALC_SIZEOF(functions), functions);

	while(running) {
		if (should_reset()) {
			hr_reset_all();
		}
	}

	return 0;
}
