//FormAI DATASET v1.0 Category: System boot optimizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOOT_TIME 10 // the number of seconds the computer takes to boot

void display_loading_bar(int percent) {
    printf("[");
    for (int i = 0; i < 50; i++) {
        if (i < percent / 2) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%\n", percent);
}

int main() {
    int boot_time_elapsed = 0;
    int boot_time_savings = 0;
    int optimizations_applied = 0;
    bool optimizations_possible = true;

    printf("Starting boot optimizer...\n");

    while (boot_time_elapsed < BOOT_TIME) {
        int percent_complete = (boot_time_elapsed * 100) / BOOT_TIME;
        display_loading_bar(percent_complete);

        if (optimizations_possible) {
            // apply optimization
            int optimization_time_saved = rand() % 5 + 1;
            boot_time_savings += optimization_time_saved;
            optimizations_applied++;
            printf("Applied optimization #%d, saved %d seconds\n", optimizations_applied, optimization_time_saved);
        }

        // increment boot time
        int boot_time_increment = rand() % 3 + 1;
        boot_time_elapsed += boot_time_increment;

        // check if optimizations are no longer possible
        if (optimizations_applied >= 5 || boot_time_savings >= 10) {
            optimizations_possible = false;
        }
    }

    printf("Boot optimization complete\n");
    printf("Total optimizations applied: %d\n", optimizations_applied);
    printf("Total boot time savings: %d seconds\n", boot_time_savings);

    return 0;
}