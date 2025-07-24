//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Cyberpunk
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int max_ram = 16;
    int current_ram = 0;

    printf("WELCOME TO THE CYBERSE\n");
    printf("-----------------------\n");

    while (1) {
        printf("\nCYBERPUNK CPU USAGE MONITOR\n");
        printf("-----------------------------\n");

        current_ram = rand() % max_ram + 1; // generate random ram usage between 0-16

        printf("> SYSTEM RAM USAGE: %d GB\n", current_ram);

        if (current_ram >= max_ram) {
            printf("> SYSTEM OVERLOAD DETECTED, EMERGENCY SHUTDOWN ENGAGED\n");
            break;
        }

        sleep(3); // wait for 3 seconds before checking again
    }

    printf("\nTHANK YOU FOR USING THE CYBERPUNK CPU USAGE MONITOR\n");

    return 0;
}