//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int used_memory = 0;
    int available_memory = 1024; 
    int max_memory = 1024;

    while (1) {
        used_memory = rand() % available_memory;
        if (used_memory > max_memory) {
            printf("Enigma machine malfunction detected! RAM usage exceeded maximum capacity.\n");
            break;
        }
        printf("Current RAM usage is %d kilobytes out of %d available kilobytes.\n", used_memory, available_memory);
        sleep(1);
    }

    return 0;
}