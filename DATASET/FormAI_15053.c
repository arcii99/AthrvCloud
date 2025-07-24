//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void displayCPUusage(int* count) {
    system("clear");
    printf("Recursive CPU Usage Monitor\n\n");
    printf("Current CPU usage: %d%%\n", rand() % 101);
    printf("Monitoring CPU usage for %d seconds...\n", (*count));
    if((*count)-- > 0) {
        sleep(1);
        displayCPUusage(count);
    } else {
        printf("\nCPU monitoring complete.\n");
    }
}

int main() {
    int count = 10; // number of seconds to monitor CPU usage
    printf("Press any key to start CPU usage monitor.\n");
    getchar(); // wait for user input
    displayCPUusage(&count);
    return 0;
}