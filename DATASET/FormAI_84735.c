//FormAI DATASET v1.0 Category: Smart home light control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to turn on the lights
void turnOnLights() {
    printf("Lights turned on!\n");
}

// function to turn off the lights
void turnOffLights() {
    printf("Lights turned off!\n");
}

int main() {
    char input[50];

    // initialize random seed
    srand(time(NULL));

    printf("Welcome to Smart Home Light Control!\n\n");

    while (1) {
        // generate a random number between 0 and 1
        int randNum = rand() % 2;

        // ask for user input
        printf("What would you like me to do? (turn on/off the lights)\n");
        fgets(input, 50, stdin);

        // check if the user wants to turn on the lights
        if (strstr(input, "on")) {
            turnOnLights();
        }

        // check if the user wants to turn off the lights
        else if (strstr(input, "off")) {
            turnOffLights();
        }

        // if the user input is invalid, respond with a random message
        else {
            if (randNum == 0) {
                printf("I'm sorry, I didn't understand that.\n");
            }
            else {
                printf("I'm afraid I can't do that.\n");
            }
        }
    }

    return 0;
}