//FormAI DATASET v1.0 Category: Smart home automation ; Style: funny
#include <stdio.h>

int main()
{
    printf("Hi there! Welcome to my smart home automation system.\n");
    printf("Let's see what I can do!\n");

    int temperature = 25;
    int lights = 0;

    printf("The current temperature is %d degrees Celcius.\n", temperature);
    printf("The lights are currently turned %s.\n", lights ? "on" : "off");

    // Let's turn on the lights
    printf("Turning on the lights...\n");
    lights = 1;
    printf("The lights are now turned %s.\n", lights ? "on" : "off");

    // Let's set a new temperature
    printf("Setting a new temperature...\n");
    temperature = 21;
    printf("The new temperature is now %d degrees Celcius.\n", temperature);

    // Uh oh, there's a problem
    printf("Oh no, something's wrong!\n");
    printf("Error code: ");

    // Here's some random error code for the fun of it
    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
    }

    printf("\n");
    printf("Don't worry, it's just a joke. Everything is working perfectly fine!\n");

    return 0;
}