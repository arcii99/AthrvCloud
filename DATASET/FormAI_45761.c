//FormAI DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *allocate_memory(size_t size) {
    void *temp = malloc(size);
    if (temp == NULL) {
        printf("Error: Could not allocate memory!");
        exit(1);
    }
    return temp;
}

int main() {
    char *string1 = "Hello, world!";
    char *string2 = allocate_memory(strlen(string1) + 1);
    strcpy(string2, string1);

    printf("Original string: %s\n", string1);
    printf("Copied string: %s\n", string2);

    free(string2);

    return 0;
}