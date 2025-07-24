//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int cpu_usage = 0;
    printf("Welcome to the post-apocalyptic CPU usage monitor.\n");
    printf("Press enter to begin monitoring.\n");
    getchar();
    
    srand(time(NULL));
    
    printf("Monitoring started...\n");
    while (1) {
        cpu_usage = rand() % 101; //random number between 0 and 100
        printf("CPU Usage: %d%%\n", cpu_usage);
        if (cpu_usage >= 80) {
            printf("WARNING: High CPU usage detected!\n");
            printf("Please stop any unnecessary processes to prevent a system failure.\n");
        }
        printf("Press enter to continue monitoring or type 'quit' to exit.\n");
        char input[10];
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "quit\n") == 0) {
            break;
        }
    }
    printf("Monitoring ended.\n");
    return 0;
}