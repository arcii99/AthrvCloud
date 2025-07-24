//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int mem_size = 1024;
    int *ptr = (int*)malloc(mem_size * sizeof(int));
    int used_mem = 0;
    while(1) {
        int num = rand() % 100 + 1;
        if(used_mem + num > mem_size) {
            printf("Out of memory!\n");
            break;
        } else {
            printf("Allocating %d bytes of memory...\n", num);
            used_mem += num;
            sleep(1);
        }
    }
    free(ptr);
    return 0;
}