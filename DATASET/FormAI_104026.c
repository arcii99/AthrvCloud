//FormAI DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

void fatal_error_handler(char* message)
{
    fprintf(stderr, "FATAL ERROR: %s\n", message);
    exit(1);
}

void null_pointer_handler(void* pointer, char* message)
{
    if(pointer == NULL)
    {
        fprintf(stderr, "NULL POINTER ERROR: %s\n", message);
        exit(1);
    }
}

void overflow_handler(int value1, int value2, char* message)
{
    int result;
    if(__builtin_sadd_overflow(value1, value2, &result))
    {
        fprintf(stderr, "ARITHMETIC OVERFLOW ERROR: %s\n", message);
        exit(1);
    }
}

int main()
{
    char* message = "The quick brown fox jumps over the lazy dog";
    char* null_pointer = NULL;
    int val1 = 1000000000;
    int val2 = 1000000000;

    null_pointer_handler(message, "Pointer should not be null");
    null_pointer_handler(null_pointer, "Pointer should not be null");

    overflow_handler(val1, val2, "Overflow occurred in computation");

    printf("Success: No errors occurred\n");

    return 0;
}