//FormAI DATASET v1.0 Category: Smart home light control ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char input[100]; // initialize input array
    int brightness = 0; // initialize brightness variable

    printf("Welcome to the Surrealist Smart Home Light Control Program.\n");
    printf("Please enter your desired level of brightness from 0 to 10, or type 'surreal' to enter surreal mode:\n");
    scanf("%s", input);

    if(strcmp(input, "surreal") == 0) { // check if input is surreal
        printf("You have entered the surreal mode of the Smart Home Light Control Program.\n");
        printf("The lights will now be controlled by your subconscious thoughts and desires.\n");
        while(1) {
            brightness = rand() % 11; // assign random value to brightness variable
            printf("The current brightness level is %d.\n", brightness);
            printf("Think about your deepest desires and watch as the lights respond.\n");
            printf("Press enter to continue.\n");
            getchar(); // wait for enter key press
        }
    } else { // if input is not surreal
        brightness = atoi(input); // convert input to integer
        if(brightness >= 0 && brightness <= 10) { // check if input is within range
            printf("The Smart Home Light Control Program has set the brightness level to %d.\n", brightness);
        } else { // if input is out of range
            printf("Invalid input. The Smart Home Light Control Program only accepts levels of brightness from 0 to 10.\n");
        }
    }

    return 0;
}