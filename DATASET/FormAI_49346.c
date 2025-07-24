//FormAI DATASET v1.0 Category: Smart home automation ; Style: minimalist
#include <stdio.h>

int main() {
    int door_status = 0;
    int lights_status = 0;
    int temperature = 24;
    printf("Welcome to Smart Home Automation\n");

    while(1) {
        // check for user input
        char input;
        printf("Enter a command (d/l/t/o): ");
        scanf(" %c", &input);

        // process the input
        switch(input) {
            case 'd': 
                if(door_status == 0) {
                    printf("Door unlocked\n");
                    door_status = 1;
                } else {
                    printf("Door locked\n");
                    door_status = 0;
                }
                break;
            case 'l': 
                if(lights_status == 0) {
                    printf("Lights turned on\n");
                    lights_status = 1;
                } else {
                    printf("Lights turned off\n");
                    lights_status = 0;
                }
                break;
            case 't': 
                printf("Current temperature: %d\n", temperature);
                break;
            case 'o': 
                printf("Exiting Smart Home Automation\n");
                return 0;
            default:
                printf("Invalid command\n");
        }
    }
}