#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define __HOTRELOAD_IMPLEMENTATION
#include "../hotreload.h"

static uint32_t counter = 0;

bool should_reset() 
{
	counter++;
	if (counter == 99999999) {
		counter = 0;
		return true;
	}
	return false;
}

void __reset_func() 
{
	printf("Testing from reset_func!\n");	
}

typedef void (*func_test2_t)(void);
static void* shared_ptr2 = NULL;
func_test2_t func_test2_a_ptr;

void __reset_func2()
{
	const char* filepath = "build/objs/test2.so";
	shared_ptr2 = hr_reset_file(filepath, shared_ptr2);

	const char* func_a_name = "test2_a";
	func_test2_a_ptr = hr_reset_function(shared_ptr2, func_a_name);

	func_test2_a_ptr();
}

int main(void)
{
	bool running = true;

	reset_func_t functions[] = {
		&__reset_func, &__reset_func2,
	};

	hr_init(CALC_SIZEOF(functions), functions);

	char loop_char;
	while(running) {
		hr_reset_all();

		scanf("%c", &loop_char);
		running = loop_char != 'q';
	}

	hr_end();

	return 0;
}
