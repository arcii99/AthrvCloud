//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RAM_SIZE 1024*1024 // 1 MB

int main()
{
    int *ram = (int*) malloc(RAM_SIZE);
    memset(ram, 0, RAM_SIZE);

    int mem_usage = 0;
    int max_mem_usage = 0;
    int num_ops = 0;

    printf("Running C RAM Usage Monitor...\n");

    while (1) {
        int new_mem_usage = 0;

        for (int i = 0; i < RAM_SIZE / sizeof(int); i++) {
            if (ram[i] != 0) {
                new_mem_usage++;
            }
        }

        if (new_mem_usage != mem_usage) {
            char message[100];
            sprintf(message, "Memory usage: %d / %d", new_mem_usage, RAM_SIZE / sizeof(int));
            printf("%s\n", message);

            if (new_mem_usage > max_mem_usage) {
                max_mem_usage = new_mem_usage;
            }

            mem_usage = new_mem_usage;
        }

        num_ops++;

        if (num_ops % 100000000 == 0) {
            printf("Max memory usage: %d / %d\n", max_mem_usage, RAM_SIZE / sizeof(int));
        }
    }

    free(ram);
    return 0;
}