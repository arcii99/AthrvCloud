//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    int ms = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + ms);
}

void printMessage(char* message) {
    for(int i = 0; message[i] != '\0'; i++) {
        printf("%c", message[i]);
        delay(0.05);
    }
    printf("\n");
}

int main() {
    int fuel = 100;
    int oxygen = 100;

    // Starting message
    printMessage("Welcome to the Procedural Space Adventure Game!\n");
    printMessage("You are the captain of the spacecraft \"Goliath\" and your goal is to explore the uncharted galaxy.\n");
    printMessage("You have a crew of 5 and you must manage the resources wisely to complete the mission successfully.\n");
    printMessage("Your spacecraft is equipped with a laboratory to analyze the planets and their compositions.\n");
    printMessage("Good luck, captain!\n\n");

    // Game loop
    while(1) {
        // Print current status
        printf("Fuel: %d\n", fuel);
        printf("Oxygen: %d\n", oxygen);

        // Ask for user input
        printf("Enter planet name to explore: ");
        char planet[20];
        scanf("%s", planet);

        // Randomly generate planet info
        srand(time(0));
        int temperature = rand() % 201 - 100;  // -100 to 100 degrees Celsius
        int atmosphere = rand() % 101;         // 0 to 100 percent
        int water = rand() % 101;              // 0 to 100 percent

        // Analyze planet
        printf("\nAnalyzing planet %s...\n", planet);
        delay(2);
        printf("Temperature: %d C\n", temperature);
        printf("Atmosphere: %d%%\n", atmosphere);
        printf("Water: %d%%\n", water);
        delay(1);

        // Consume resources
        fuel -= 10;
        oxygen -= 5;

        // Check if resources depleted
        if(fuel <= 0 || oxygen <= 0) {
            printf("\nMission failed!\n");
            break;
        }
    }

    return 0;
}