//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed for random number generator

    // Welcome message
    printf("Welcome to the Sherlock Holmes Internet Speed Test Application\n");

    // Prompt user for their name
    printf("Please enter your name: ");
    char name[50];
    fgets(name, sizeof(name), stdin);

    // Start testing the internet speed
    printf("Testing your internet speed, %s\n", name);

    // Generate a random number between 1 and 100 to simulate the internet speed
    int internet_speed = rand() % 100 + 1;
    printf("Your internet speed is %d Mbps\n", internet_speed);

    // Analyzing the internet speed test result
    if (internet_speed >= 80) {
        printf("Excellent! Your internet speed is extremely fast.\n");
    } else if (internet_speed >= 50 && internet_speed < 80) {
        printf("Good job! Your internet speed is pretty fast.\n");
    } else if (internet_speed >= 30 && internet_speed < 50) {
        printf("Hmm, your internet speed is a bit slow. Consider upgrading your internet plan.\n");
    } else {
        printf("Oh no, your internet speed is very slow. You might want to contact your internet service provider for help.\n");
    }

    return 0;
}