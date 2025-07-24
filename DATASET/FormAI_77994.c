//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CPU_LIMIT 90.0
#define REFRESH_RATE 2

void print_loading_animation();

int main() {
    float cpu_usage;
    while(1) {
        system("clear");
        cpu_usage = rand() % 100;
        printf("Current CPU Usage: %.2f%%\n\n", cpu_usage);
        if(cpu_usage > CPU_LIMIT) {
            printf("WARNING: CPU USAGE ABOVE %f%%!!!\n", CPU_LIMIT);
            print_loading_animation();
        }
        sleep(REFRESH_RATE);
    }
    return 0;
}

void print_loading_animation() {
    printf("RUNNING CPU THROTTLING.......\n\n");
    for(int i=0; i<5; i++) {
        printf("|         |");
        sleep(1);
        printf("\r");
        printf("\\         /");
        sleep(1);
        printf("\r");
        printf("|         |");
        sleep(1);
        printf("\r");
        printf("/         \\");
        sleep(1);
        printf("\r");
    }
    printf("\n\nThrottling successful. CPU usage below %f%%.\n", CPU_LIMIT);
}