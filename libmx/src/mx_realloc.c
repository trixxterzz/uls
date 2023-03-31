#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t new_size) {
    size_t current;
    void *new;
    if (ptr == 0) {
	    return malloc(new_size);
    }
    current = malloc_size(ptr);
    if (new_size <= current){
	    return ptr;
    }
    new = malloc(new_size);
    mx_memcpy(new, ptr, current);
    free(ptr);
    return new;
}
