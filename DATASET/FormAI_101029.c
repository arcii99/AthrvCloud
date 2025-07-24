//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    while(1) {
        int current_cpu_usage = rand() % 101;
        printf("Current CPU usage: %d%%\n", current_cpu_usage);
        if(current_cpu_usage > 90) {
            printf("OH NO! CPU usage is over 90%%. This can't be happening! Quick, find a way to reduce it!\n");
        }
        else if(current_cpu_usage > 50) {
            printf("Uh-oh, CPU usage is getting high. We need to find a way to optimize our code. Let's get to work!\n");
        }
        else {
            printf("Phew, CPU usage is still under control. Keep up the good work!\n");
        }
        printf("----------------------------------------------\n");
        sleep(1);
    }

    return 0;
}