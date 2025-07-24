//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    srand(time(0));
    int cpu = 0;

    printf("Welcome to the Medieval CPU Usage Monitor!\n");
    printf("===========================================\n");

    while(1) {
        printf("\n\nThe current CPU usage is: %d%%\n", cpu);
        printf("===========================================\n");
        printf("Press any key to check the usage again...");

        // Simulate some CPU usage
        int usage = rand() % 100;
        cpu += usage;

        // Cap the usage at 100%
        if(cpu > 100)
            cpu = 100;

        // Wait for some time before checking again
        sleep(1);
        getchar();
    }

    return 0;
}