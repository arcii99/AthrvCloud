//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int mem_used = 0;
    int total_mem = 100;
    int cpu_usage = 20;

    while (1) {
        // simulate some random memory usage
        int ram_usage = rand() % 100;

        // update the total memory usage
        mem_used += ram_usage;

        // check if we're about to run out of memory
        if (mem_used > total_mem) {
            printf("OH NO, WE'RE RUNNING OUT OF MEMORY! ABORT ALL MISSIONS!!\n");
            break;
        }

        // check if our CPU usage is too high
        if (cpu_usage > 80) {
            printf("OUR CPU USAGE IS TOO HIGH!! SOMEONE GO MAKE A POT OF COFFEE!\n");
        }

        // print some funny messages
        if (ram_usage < 10) {
            printf("RAM usage is too low, let's pump up those numbers!\n");
        } else if (ram_usage > 90) {
            printf("RAM usage is through the roof! Quick, turn off all the lights to save power!\n");
        }

        // sleep for a bit to simulate doing some work
        sleep(1);
    }

    return 0;
}