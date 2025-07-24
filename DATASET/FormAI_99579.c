//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int *ptr;
    int i = 0;

    while (1) {
        ptr = malloc(1024 * sizeof(int)); // Allocate one kilobyte of memory
        if (ptr == NULL) {
            printf("Out of memory at %dMB!\n", i);
            break;
        }
        else {
            i++;
            printf("Allocated %dMB of memory\n", i);
            sleep(1); // Pause for one second
        }
        free(ptr); // Release the memory
    }

    return 0;
}