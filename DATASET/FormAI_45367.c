//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_LENGTH 1024
 
int main() {
    while(1) {
        FILE* fp1 = popen("ps -eo pid,%cpu --no-headers | sort -k 2 -rn", "r");
        char* line = malloc(MAX_LENGTH);
        char* pid = malloc(10);
        char* cpu = malloc(10);
        double total_cpu = 0;
        printf("PID\tCPU Usage\n");
        while(fgets(line, MAX_LENGTH, fp1)) {
            sscanf(line, "%s %s", pid, cpu);
            double cpu_usage = atof(cpu);
            printf("%s\t%.2f%%\n", pid, cpu_usage);
            total_cpu += cpu_usage;
        }
        printf("Total CPU Usage: %.2f%%\n", total_cpu);
        pclose(fp1);
        free(line);
        free(pid);
        free(cpu);
        sleep(1);
    }
    return 0;
}