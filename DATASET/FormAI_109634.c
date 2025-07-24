//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

#define INTERVAL 1

int main() {
    int usage[5] = {0};
    struct sysinfo memInfo;

    for (;;) {
        usage[0] = usage[1];
        usage[1] = usage[2];
        usage[2] = usage[3];
        usage[3] = usage[4];

        sysinfo(&memInfo);
        usage[4] = (int) ((memInfo.totalram - memInfo.freeram) * 100 / memInfo.totalram);

        printf("\033[2J");   // Clear terminal screen
        printf("\033[0;0H"); // Set cursor to top-left corner

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("Current Time: %02d:%02d:%02d\n\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
        printf("                                   MEMORY USAGE\n");
        printf("---------------------------------------------------------------------------------\n");
        printf("  %2d%% |  %2d%% |  %2d%% |  %2d%% |  %2d%%\n", usage[0], usage[1], usage[2], usage[3], usage[4]);
        printf("---------------------------------------------------------------------------------\n");

        sleep(INTERVAL);
    }

    return 0;
}