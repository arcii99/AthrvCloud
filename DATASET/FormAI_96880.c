//FormAI DATASET v1.0 Category: Smart home light control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Creating random values for light brightness
    srand(time(NULL));
    int bedroomLightBright = rand() % 101;
    int kitchenLightBright = rand() % 101;
    int livingRoomLightBright = rand() % 101;

    // Welcome message
    printf("Hello and welcome to our Smart Home Light Control System!\n");

    // Printing current light brightness levels
    printf("Current light brightness:\n");
    printf(" - Bedroom: %d%%\n", bedroomLightBright);
    printf(" - Kitchen: %d%%\n", kitchenLightBright);
    printf(" - Living Room: %d%%\n", livingRoomLightBright);

    // Asking for user input
    printf("Please enter desired light brightness level:\n");
    int desiredBright;
    scanf("%d", &desiredBright);

    // Verifying input is between 0 and 100
    if (desiredBright < 0 || desiredBright > 100) {
        printf("Invalid input. Please enter a number between 0 and 100.\n");
        return 1;
    }

    // If input is valid, adjusting brightness levels and printing new values
    printf("Adjusting light brightness levels...\n");
    bedroomLightBright = desiredBright;
    kitchenLightBright = desiredBright;
    livingRoomLightBright = desiredBright;
    printf("New light brightness:\n");
    printf(" - Bedroom: %d%%\n", bedroomLightBright);
    printf(" - Kitchen: %d%%\n", kitchenLightBright);
    printf(" - Living Room: %d%%\n", livingRoomLightBright);

    // Funny farewell message
    printf("Thank you for using our Smart Home Light Control System! If you're feeling sleepy, why not try switching to our Bedtime Mode?\n");

    return 0;
}