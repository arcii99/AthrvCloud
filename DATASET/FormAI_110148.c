//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long long ram_usage = 0;
    char *mem_block = NULL;
    const unsigned long long block_size = 1024 * 1024;

    printf("RAM usage monitor running...\n");
    
    while (1) {
        mem_block = malloc(block_size);
        if (mem_block != NULL) {
            ram_usage += block_size;
            printf("Current RAM usage: %llu MB\n", ram_usage / (1024 * 1024));
        }
        else {
            printf("Could not allocate more memory!\n");
            break;
        }
    }
    
    free(mem_block);
    mem_block = NULL;
    
    return 0;
}