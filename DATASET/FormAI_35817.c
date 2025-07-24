//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int i;
    float usage, idle, sum;
    char *cpu_stats = malloc(sizeof(char) * 256);

    printf("Welcome to my happy CPU usage monitor program! Sit back, relax, and watch the magic happen!\n");

    for (i = 0; i < 10; i++) {
        FILE *file = fopen("/proc/stat", "r");
        fgets(cpu_stats, 256, file);

        fclose(file);

        sscanf(cpu_stats, "cpu %*d %*d %*d %*d %*d %*d %*d %*d %*d %f", &idle);

        sum = 0;
        for (int j = 0; j < 10; j++) {
            file = fopen("/proc/stat", "r");
            fgets(cpu_stats, 256, file);

            fclose(file);

            sscanf(cpu_stats, "cpu %*d %*d %*d %*d %*d %*d %*d %*d %*d %f", &usage);
            sum += usage;
            sleep(1);
        }

        printf("Total CPU usage over the past 10 seconds: %.2f %%\n", (sum - (idle * 10)) / 10);
    }

    printf("Thanks for using my happy CPU usage monitor program!\n");
    free(cpu_stats);

    return 0;
}