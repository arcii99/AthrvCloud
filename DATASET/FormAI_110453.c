//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_RAM_USAGE 100
#define MIN_RAM_USAGE 0

int main() {
    int current_ram_usage = 50;
    int previous_ram_usage = 0;
    int i;

    while(1) {
        system("clear");
        previous_ram_usage = current_ram_usage;
        current_ram_usage = rand() % MAX_RAM_USAGE + MIN_RAM_USAGE;

        printf("Current RAM Usage: ");
        for(i = 0; i < current_ram_usage; i++) {
            printf("|");
        }
        printf("%d%%\n\n", current_ram_usage);

        if(current_ram_usage > previous_ram_usage) {
            printf("Alert! RAM usage has increased!\n");
        }
        else if(current_ram_usage < previous_ram_usage) {
            printf("RAM usage has decreased.\n");
        }
        else {
            printf("RAM usage has remained the same.\n");
        }

        sleep(1);
    }

    return 0;
}