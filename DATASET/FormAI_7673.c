//FormAI DATASET v1.0 Category: System boot optimizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int boot_time = 0;
    srand( time(NULL) );
    printf("Starting C System Boot Optimizer...\n");
    printf("Analyzing system performance...\n");

    // Simulate booting process
    printf("Booting system...\n");
    for (int i = 1; i <= 10; i++) {
        printf("Completing step %d of 10...\n", i);
        int rand_num = rand() % 10 + 1;
        boot_time += rand_num;
        printf("Step %d completed in %d seconds.\n", i, rand_num);
    }

    // Check if boot time is optimal
    if (boot_time <= 30) {
        printf("Congratulations! Your system boot time is optimal at %d seconds.\n", boot_time);
    } else {
        printf("WARNING: Your system boot time is longer than the optimal time of 30 seconds.\n");
        printf("Trying to optimize boot time...\n");
        int rand_num = rand() % 10 + 1;
        int new_boot_time = boot_time - rand_num;
        printf("After optimizing, your system boot time is now %d seconds.\n", new_boot_time);
        printf("Please wait while changes are saved...\n");
        printf("Changes saved! Your system will reboot now...\n");
        for (int i = 1; i <= 5; i++) {
            printf("System shutting down in %d seconds...\n", i);
        }
        printf("System shutdown complete. Rebooting now...\n");
        printf("Your system is now running with an optimized boot time of %d seconds.\n", new_boot_time);
    }
    return 0;
}