//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void print_graph(int cpu_usage) {
    printf("\n\nCPU USAGE GRAPH\n\n");
    printf("    ");

    for (int i = 0; i < cpu_usage; i++) {
        printf("%d%% ", i+1);
    }
    printf("\n\n");

    for (int i = 0; i < 5; i++) {
        printf(" %d%% ", cpu_usage-(5-i));
        for (int j = 0; j < cpu_usage; j++) {
            if (j >= cpu_usage-(5-i)) {
                printf(" █ ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

int main() {
    int cpu_usage;
    srand(time(0)); // Seed for random number generation

    while(1) {
        cpu_usage = rand() % 101;
        print_graph(cpu_usage);
        printf("\n\nCPU Usage: %d%%\n", cpu_usage);
        sleep(1); // Delay for 1 second
        system("clear"); // Clear console screen on Linux/Mac OS
        // Use system("cls") for Windows
    }

    return 0;
}