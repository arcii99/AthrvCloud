//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_USAGE 100

int main(void){
    int counter = 0;
    int usage = 0;
    int total = 0;
    int avg = 0;
    int max = 0;
    int min = 101;
    time_t t;

    // Medieval intro
    printf("Welcome to the CPU usage monitor, brave knight!\n");
    printf("Let us embark on a journey of discovery and measure the usage of the mighty processor in your castle...\n\n");

    while (1) {
        sleep(1);
        time(&t);

        // Measure CPU usage
        usage = rand() % 101;

        // Update total
        total += usage;

        // Update average
        avg = total / (++counter);

        // Update max
        if (usage > max) {
            max = usage;
        }

        // Update min
        if (usage < min) {
            min = usage;
        }

        // Medieval output
        printf("At the strike of %s", ctime(&t));
        printf("The CPU usage is %d%%\n", usage);
        printf("The average usage is %d%%\n", avg);
        printf("The maximum usage is %d%%\n", max);
        printf("The minimum usage is %d%%\n\n", min);

        // If usage exceeds the maximum limit, alert the knight
        if (usage > MAX_USAGE) {
            printf("Dear knight, the usage has exceeded the maximum limit of %d%%!\n", MAX_USAGE);
            printf("Take action immediately to prevent any damage to the processor.\n");
        }
    }

    return 0;
}