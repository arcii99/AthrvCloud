//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    pid_t pid;
    char buffer[BUFFER_SIZE], *cmd;
    float user_time, sys_time, total_time;

    printf("CPU USAGE MONITOR\n\n");

    printf("Enter process ID: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    pid = strtol(buffer, NULL, 10);

    while (1) {
        sprintf(buffer, "/proc/%d/stat", pid);
        FILE *stat_file = fopen(buffer, "r");

        if (stat_file == NULL) {
            printf("Invalid process ID!\n");
            exit(1);
        }

        fgets(buffer, BUFFER_SIZE, stat_file);
        fclose(stat_file);

        cmd = strtok(buffer, " ");
        for (int i = 0; i < 12; i++) {
            cmd = strtok(NULL, " ");
        }

        user_time = strtof(strtok(NULL, " "), NULL) / sysconf(_SC_CLK_TCK);
        sys_time = strtof(strtok(NULL, " "), NULL) / sysconf(_SC_CLK_TCK);
        total_time = user_time + sys_time;

        printf("\e[1;1H\e[2J");

        printf("PROCESS DETAILS\n");
        printf("ID: %d\n", pid);
        printf("COMMAND: %s\n", cmd);
        printf("USER TIME: %.2f seconds\n", user_time);
        printf("SYSTEM TIME: %.2f seconds\n", sys_time);
        printf("TOTAL TIME: %.2f seconds\n", total_time);

        sleep(1);
    }

    return 0;
}