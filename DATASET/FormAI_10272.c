//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RAM_SIZE 4096

void generate_load(int size) {
    char *ptr = malloc(size * sizeof(char));
    if (ptr == NULL) {
        printf("Error: Not enough memory\n");
        exit(1);
    }
    memset(ptr, 'A', size);
    sleep(1);
    free(ptr);
}

int main() {
    int i, usage;
    for (i = 0; i < 10; i++) {
        generate_load(RAM_SIZE / 10);
        FILE *fp = fopen("/proc/meminfo", "r");
        if (fp == NULL) {
            printf("Error: Unable to open /proc/meminfo\n");
            exit(1);
        }
        char line[256];
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, "MemFree") != NULL) {
                int free_mem = atoi(line + strlen("MemFree:"));
                usage = RAM_SIZE - free_mem;
            }
        }
        fclose(fp);
        printf("RAM usage: %d KB\n", usage);
    }
    return 0;
}