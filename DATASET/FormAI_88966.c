//FormAI DATASET v1.0 Category: System boot optimizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function to generate random integers */
int random_generator(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); /* seeding the random number generator */
    int boot_time = random_generator(30, 60); /* generating random boot time between 30 to 60 seconds */
    printf("\nYour system's boot time is currently set to %d seconds.\n\n", boot_time);
    printf("Optimizing system boot time...\n\n");
    int optimized_boot_time = boot_time - random_generator(5, 15); /* optimizing boot time by subtracting random value between 5 to 15 seconds */
    printf("System boot time optimized to %d seconds.\n\n", optimized_boot_time);
    printf("Saving optimized boot time to system settings...\n\n");
    /* code to save the optimized boot time to system settings goes here */
    printf("Boot time has been successfully optimized!\n\n");
    return 0;
}