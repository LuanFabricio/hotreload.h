#ifndef __HOTRELOAD_H
#define __HOTRELOAD_H

#include <stdlib.h>

#define CALC_SIZEOF(x) sizeof(x)/sizeof(x[0])

typedef void (*reset_func_t)(void);

void hr_init(size_t len, const reset_func_t *functions);
void hr_reset_all();

#endif // __HOTRELOAD_H

#ifdef __HOTRELOAD_IMPLEMENTATION
#include <stdarg.h>

static size_t reset_functions_len;
static reset_func_t* reset_functions;

void hr_init(size_t len, const reset_func_t *functions) 
{
	reset_functions_len = len;

	reset_functions = malloc(sizeof(reset_func_t) * len);

	for (size_t i = 0; i < len; i++) {
		reset_functions[i] = functions[i];
	}
}

void hr_reset_all() 
{
	for (size_t i = 0; i < reset_functions_len; i++) {
		reset_functions[i]();
	}
}

void hr_end()
{
	reset_functions_len = 0;

	if (reset_functions) {
		free(reset_functions);
	}
}

#endif // __HOTRELOAD_IMPLEMENTATION
