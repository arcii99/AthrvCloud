//FormAI DATASET v1.0 Category: System boot optimizer ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

// Function to optimize system boot time
void bootOptimizer()
{
    // Define variables to hold required information
    int numProcesses, numServices, numDevices;

    // Prompt user for input
    printf("Enter number of processes running at boot: ");
    scanf("%d", &numProcesses);
    printf("Enter number of services running at boot: ");
    scanf("%d", &numServices);
    printf("Enter number of devices connected at boot: ");
    scanf("%d", &numDevices);

    // Calculate time taken to boot system based on number of processes, services and devices
    int bootTime = (numProcesses * 2) + (numServices * 3) + (numDevices * 4);

    // Display optimized boot time to user
    printf("Optimized boot time is: %d seconds", bootTime);
}

int main()
{
    // Call bootOptimizer function to optimize system boot time
    bootOptimizer();

    return 0;
}