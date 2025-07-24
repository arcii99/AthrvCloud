//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAM_SIZE 1024 // Maximum RAM size of our system

// Function declaration
int getRamUsage(int);
void displayRamUsage(int);

int main(){
    int ramUsage;

    printf("Welcome to RAM Usage Monitor!\n");

    // Seed for random numbers
    srand(time(0));

    while(1){
        ramUsage = getRamUsage(MAX_RAM_SIZE); // Get the RAM usage

        displayRamUsage(ramUsage); // Display RAM usage

        // Sleep for one second
        sleep(1);
    }

    return 0;
}

// Function to get the RAM Usage
int getRamUsage(int maxRamSize){
    int ramUsage = rand() % maxRamSize; // Random RAM usage

    return ramUsage;
}

// Function to display RAM usage
void displayRamUsage(int ramUsage){
    int i;

    // Clear screen
    system("clear");

    // Print the RAM usage bar
    printf("RAM Usage Monitor\n");
    printf("-----------------\n");
    printf("RAM Usage: ");

    for(i = 0; i < ramUsage/10; i++){
        printf("|");
    }

    printf(" %d%%\n", ramUsage);

    // Print the RAM usage percentage
    printf("RAM Usage Percentage: %d%%\n", ramUsage);
}