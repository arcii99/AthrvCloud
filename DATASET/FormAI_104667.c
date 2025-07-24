//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    char buf[1024];

    while(1) {
        FILE *fp = popen("ps aux | awk '{sum += $4} END {print sum}'", "r");
        float usage = 0.0;

        if (fp == NULL) {
            printf("Error: Unable to open command\n");
            exit(1);
        }

        while (fgets(buf, sizeof(buf), fp) != NULL) {
            usage = strtof(buf, NULL);
            // paranoid check to make sure we don't have more than 100% usage
            if (usage > 100.0) {
                printf("Warning: RAM usage above 100%% detected!\n");
                exit(1);
            }
        }

        printf("Current RAM usage: %.2f%%\n", usage);
        pclose(fp);
        sleep(5);
    }

    return 0;
}