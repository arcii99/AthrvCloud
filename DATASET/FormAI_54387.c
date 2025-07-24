//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

int main() {
    while (1) {
        FILE* fp;
        char buffer[1024];
        double cpu_usage, idle_time, user_time, system_time, nice_time, idle;
        int num_tokens;

        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            printf("Unable to open /proc/stat file!\n");
            exit(1);
        }

        fgets(buffer, sizeof(buffer), fp);
        char* token = strtok(buffer, " ");
        int i = 0;
        while (token != NULL && i < 9) {
            switch (i) {
                case 1:
                    user_time = atof(token);
                    break;
                case 3:
                    system_time = atof(token);
                    break;
                case 4:
                    idle_time = atof(token);
                    break;
                case 5:
                    nice_time = atof(token);
                    break;
            }
            token = strtok(NULL, " ");
            i++;
        }
        fclose(fp);
        idle = idle_time + nice_time;
        cpu_usage = 100 * ((user_time + system_time) / (user_time + system_time + idle));

        printf("CPU usage: %.2f%%\n", cpu_usage);
        usleep(500000);
    }
    return 0;
}