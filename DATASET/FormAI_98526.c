//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000

typedef struct {
    int a;
    int b;
    char c[256];
} custom_struct;

custom_struct array[ARRAY_SIZE];

int main() {
    int i;
    custom_struct *temp;

    // Initialization of array
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i].a = i;
        array[i].b = ARRAY_SIZE - i - 1;
        sprintf(array[i].c, "This is struct %d", i);
    }

    // Critical component
    for (i = 0; i < ARRAY_SIZE; i++) {
        temp = &array[i];
        printf("Struct %d: a=%d, b=%d, c=%s\n", i, temp->a, temp->b, temp->c);
    }

    return 0;
}