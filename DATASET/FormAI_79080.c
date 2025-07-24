//FormAI DATASET v1.0 Category: Smart home light control ; Style: protected
#include <stdio.h>
#include <stdbool.h>

// Function to turn the light on or off
void toggle_light(bool *light_status) {
    *light_status = !(*light_status);
}

int main() {
    bool living_room_light = false;
    bool kitchen_light = false;
    char input;

    while (true) {
        printf("\nAvailable commands: l (living room), k (kitchen), q (quit)\n");
        printf("Enter command: ");
        scanf(" %c", &input);

        switch (input) {
            case 'l':
                toggle_light(&living_room_light);
                printf("Living room light turned %s\n", living_room_light ? "on" : "off");
                break;

            case 'k':
                toggle_light(&kitchen_light);
                printf("Kitchen light turned %s\n", kitchen_light ? "on" : "off");
                break;

            case 'q':
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid command, please try again.\n");
                break;
        }
    }
}