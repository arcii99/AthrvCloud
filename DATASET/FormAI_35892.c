//FormAI DATASET v1.0 Category: System boot optimizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    printf("Welcome to the C System Boot Optimizer!\n");
    printf("This program will help optimize your system boot time.\n");

    int count = 0;
    int total = 0;

    srand(time(NULL));

    char* boot_options[] = {"Safe Mode", "Start Normally", "Last Known Good Configuration", "Debugging Mode"};

    while (count < 5) {
        int option = rand() % 4;

        total += option;

        printf("Booting %s...\n", boot_options[option]);

        count++;
    }

    float avg_time = total / 5.0;

    printf("Optimization complete!\n");
    printf("Your average boot time is %.2f seconds.\n", avg_time);

    if (avg_time < 10) {
        printf("Your boot time is already optimized. Great job!\n");
    } else {
        printf("Your boot time can be further optimized. Consider disabling unnecessary startup programs or upgrading your hardware.\n");
    }

    return 0;
}