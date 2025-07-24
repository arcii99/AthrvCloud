//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int prev_mem = 0;
    while(1) {
        char buffer[1024];
        int curr_mem, total_mem;
        FILE* fp = popen("free | grep Mem", "r");
        fgets(buffer, 1024, fp);
        sscanf(buffer, "Mem: %d %d %d %d %d %d", &total_mem, &prev_mem, &curr_mem);
        pclose(fp);
        
        printf("Current RAM usage: %d MB\n", curr_mem/1024);
        
        if (prev_mem > curr_mem) {
            printf("RAM usage decreased!\n");
        }
        else if (prev_mem < curr_mem) {
            printf("RAM usage increased!\n");
        }
        else {
            printf("RAM usage unchanged...\n");
        }
        
        for (int i = 0; i < 10; i++) {
            printf("%c[1A", 27);
            printf("%c[2K", 27);
        }
        usleep(1000 * 1000); // wait 1 second
    }
    return 0;
}