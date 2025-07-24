//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#define MAX_CPU_TEMP 100 // Maximum CPU temperature

int main() {
    int cpu_temp = 0;
    srand(time(0)); // Randomize seed value
    while(1) {
        cpu_temp = rand() % MAX_CPU_TEMP; // Generate random CPU temperature
        printf("CPU Usage: %d%% | CPU Temperature: %d°C\n", cpu_temp, cpu_temp + 30); // Print CPU usage and temperature
        if(cpu_temp >= 90) { // If CPU temperature exceeds 90°C, warn the user
            printf("WARNING: High CPU temperature!\n");
            printf("Please find a way to cool down the CPU.\n");
            system("shutdown -h now"); // Initiate system shutdown to prevent damage to the CPU
        }
        sleep(1); // Wait for 1 second before updating the CPU usage and temperature again
    }
    return 0;
}