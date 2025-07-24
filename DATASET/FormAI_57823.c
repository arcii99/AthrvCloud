//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main() {
    int totalRAM = 0;
    int usedRAM = 0;
    char line[1000];
    FILE *fp;

    printf("C RAM Usage Monitor\n");
    printf("--------------------\n");

    while(1) {
        fp = fopen("/proc/meminfo", "r");
        if (fp == NULL){
            printf("Error reading /proc/meminfo\n");
            return 1;
        }

        while (fgets(line, sizeof(line), fp)) {
            if (sscanf(line, "MemTotal: %d kB", &totalRAM) == 1) {}
            if (sscanf(line, "Active: %d kB", &usedRAM) == 1) {}
        }

        fclose(fp);

        printf("Total RAM: %d KB\n", totalRAM);
        printf("Used RAM: %d KB\n", usedRAM);
        printf("Free RAM: %d KB\n", totalRAM-usedRAM);

        printf("--------------------\n");

        system("sleep 1");
    }

    return 0;
}