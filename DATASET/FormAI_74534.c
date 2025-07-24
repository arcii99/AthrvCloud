//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int read_memory_usage(double* mem_usage_perc) {
    FILE* stream = popen("free | grep Mem | awk '{print $3/$2 * 100.0}'", "r");
    if (stream == NULL) {
        printf("Failed to execute command\n");
        return -1;
    }
    char output[20];
    fgets(output, 20, stream);
    pclose(stream);
    *mem_usage_perc = atof(output);
    return 0;
}

int main() {
    printf("Executing unique C RAM usage monitor example program.\n");
    printf("This program will monitor RAM usage every 5 seconds, and output a puzzle for you to solve.\n");
    printf("Can you guess the word spelled out by the memory usage percentages over time?\n");

    double mem_usage_perc = 0.0;

    while(1) {
        read_memory_usage(&mem_usage_perc);

        if(mem_usage_perc < 20.0) {
            printf("X");
        }
        else if(mem_usage_perc < 40.0) {
            printf("Y");
        }
        else if(mem_usage_perc < 60.0) {
            printf("Z");
        }
        else if(mem_usage_perc < 80.0) {
            printf("W");
        }
        else {
            printf("V");
        }

        fflush(stdout);
        sleep(5);
    }
    return 0;
}