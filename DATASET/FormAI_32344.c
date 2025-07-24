//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("My darling, I wrote you a CPU usage monitor.\n");
    printf("It's a small program to help you keep an eye on your computer's CPU usage.\n");
    printf("I know you're always worried about your computer's performance, so I made this just for you.\n");
    printf("Please don't hesitate to run it whenever you need to see how much processing power your computer is using.\n");

    printf("\nPress any key to start the monitor...\n");
    getchar();

    time_t start, end;
    double cpu_time_used = 0;

    start = clock(); //start timer

    while (1) {
        end = clock(); // stop timer
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // calculate CPU time used
        printf("CPU usage: %f%%\n", cpu_time_used * 100);
    }

    return 0;
}