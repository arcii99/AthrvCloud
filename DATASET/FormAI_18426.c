//FormAI DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("I can't believe what I just saw!\n");
    printf("This program is an absolute disaster!\n");
    printf("I don't even know where to begin!\n");

    int* ptr = NULL;
    printf("First, we need to allocate some memory. Let's see...\n");
    ptr = (int*)malloc(10 * sizeof(int));
    if (ptr == NULL) {
        printf("Oh no! malloc failed! We're in big trouble now...\n");
        return 1;
    }
    printf("Phew! That was a close one. We got our memory.\n");

    printf("Now, let's try to access some memory we don't own...\n");
    ptr[15] = 42;
    printf("BOOM! Segmentation fault! We just crashed the program.\n");
    printf("I told you this was a disaster!\n");

    printf("But wait, there's more!\n");
    printf("Let's try to free some memory that wasn't allocated...\n");
    int* not_allocated = NULL;
    free(not_allocated);
    printf("Yikes! That just caused a heap corruption. We're in deep trouble now.\n");

    printf("Okay, let's try to salvage this mess.\n");
    printf("We need to free our allocated memory before we exit...\n");
    free(ptr);
    printf("Phew! Disaster averted. We freed our memory.\n");

    printf("I need to go lie down after that experience...\n");
    return 0;
}