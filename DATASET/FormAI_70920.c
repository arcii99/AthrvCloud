//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    while(1) {
        // Get current CPU usage
        char* cmd = "top -bn1 | grep 'Cpu(s)' | sed 's/.*, \\([0-9.]*\\)%* id.*/\\1/'";
        FILE* fp = popen(cmd, "r");
        if(fp == NULL) {
            printf("Error: failed to run command\n");
            exit(1);
        }

        char buf[10];
        if(fgets(buf, sizeof(buf), fp) == NULL) {
            printf("Error: failed to read command output\n");
            exit(1);
        }

        float cpu_usage = strtof(buf, NULL);
        pclose(fp);

        // Print current CPU usage
        printf("Current CPU usage: %.2f%%\n", cpu_usage);

        // Wait for 1 second
        sleep(1);
    }

    return 0;
}