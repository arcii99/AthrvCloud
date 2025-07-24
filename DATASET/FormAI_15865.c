//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int *p, size = 100000000, i = 0;

    p = (int*)malloc(sizeof(int) * size); // allocate memory

    while (1) {
        p[i] = 0; // use memory
        i = (i + 1) % size; // cycle through allocated memory

        // sleep for 1 second and print current RAM usage
        sleep(1);
        printf("Current RAM usage: %ld\n", sizeof(int) * (long)size);
    }

    free(p); // free memory
    return 0;
}