//FormAI DATASET v1.0 Category: Smart home light control ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

// Function to turn the lights on or off
void toggle_lights(bool lights_on) {
    if (lights_on) {
        printf("Lights are now on.\n");
    } else {
        printf("Lights are now off.\n");
    }
}

int main() {
    bool lights_on = false;

    printf("Welcome to Smart Home Light Control!\n");
    toggle_lights(lights_on);

    // Loop through user input
    char user_input;
    while (true) {
        printf("Press 'o' to turn the lights on, 'f' to turn them off, or 'q' to quit: ");
        scanf(" %c", &user_input);

        if (user_input == 'o') {
            lights_on = true;
            toggle_lights(lights_on);
        } else if (user_input == 'f') {
            lights_on = false;
            toggle_lights(lights_on);
        } else if (user_input == 'q') {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}