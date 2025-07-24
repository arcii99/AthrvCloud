//FormAI DATASET v1.0 Category: Smart home automation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaration of variables
    int temperature;
    int lights;
    int music;

    // Prompt the user for input
    printf("Welcome to our smart home!\n");
    printf("Please enter the desired temperature (in Celsius): ");
    scanf("%d", &temperature);
    printf("Please enter the desired lighting level (from 0 to 100): ");
    scanf("%d", &lights);
    printf("Please enter the desired music level (from 0 to 100): ");
    scanf("%d", &music);

    // Set the temperature, lights, and music based on user input
    if (temperature < 18) {
        printf("It's a cold night tonight...\n");
        printf("Setting temperature to %d degrees.\n", temperature);
    } else if (temperature >= 18 && temperature < 25) {
        printf("It's a comfortable night tonight...\n");
        printf("Setting temperature to %d degrees.\n", temperature);
    } else {
        printf("It's a warm night tonight...\n");
        printf("Setting temperature to %d degrees.\n", temperature);
    }

    printf("Setting lighting level to %d percent.\n", lights);
    printf("Setting music level to %d percent.\n", music);

    // Display a romantic message to the user
    printf("Our smart home automation system is designed to make your life easier,\n");
    printf("but there's one thing it can't automate...\n");
    printf("The warmth of your smile, the light of your eyes,\n");
    printf("The gentle melody of your laughter, and the softness of your sighs.\n");
    printf("These are the things that truly make a home sweet home.\n");

    return 0;
}