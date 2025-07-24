//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: creative
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to CPU Usage Monitor!\n");
    printf("Press Ctrl + C to exit at any time.\n");
    
    FILE *fp;
    char path[1024];

    while(1) {
        fp = popen("top -b -n 1 | grep 'Cpu(s)' | awk '{print $2 + $4}'", "r");
        if (fp == NULL) {
            printf("Failed to run top command.\n");
            exit(1);
        }

        fgets(path, 1024, fp);
        printf("Current CPU Usage: %s", path);
        pclose(fp);

        sleep(2);
    }

    return 0;
}