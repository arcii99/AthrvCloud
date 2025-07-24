//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char cpu_info[1024], *cpu_usage, *token;
    int cpu_total_time[2][8], cpu_diff_time[2][8], i = 0, j;
    double usage;

    while (1) {
        fp = fopen("/proc/stat", "r");
        fgets(cpu_info, sizeof(cpu_info), fp);
        fclose(fp);

        token = strtok(cpu_info, " ");
        for (j = 0; j < 8; j++) {
            token = strtok(NULL, " ");
            cpu_total_time[i][j] = atoi(token);
        }

        if (i == 0) {
            i = 1;
            sleep(1);
            continue;
        }

        for (j = 0; j < 8; j++) {
            cpu_diff_time[1][j] = cpu_total_time[1][j] - cpu_total_time[0][j];
        }

        usage = (double)(cpu_diff_time[1][0] + cpu_diff_time[1][1] + cpu_diff_time[1][2] + cpu_diff_time[1][3] + cpu_diff_time[1][4] + cpu_diff_time[1][5] + cpu_diff_time[1][6]) / (double)(cpu_diff_time[1][0] + cpu_diff_time[1][1] + cpu_diff_time[1][2] + cpu_diff_time[1][3] + cpu_diff_time[1][4] + cpu_diff_time[1][5] + cpu_diff_time[1][6] + cpu_diff_time[1][7]);

        cpu_usage = malloc(100 * sizeof(char));
        sprintf(cpu_usage, "Current CPU usage: %.2lf%%", usage * 100);
        printf("%s\n", cpu_usage);
        free(cpu_usage);

        memmove(cpu_total_time[0], cpu_total_time[1], sizeof(cpu_total_time[1]));
        i = 0;
    }

    return 0;
}