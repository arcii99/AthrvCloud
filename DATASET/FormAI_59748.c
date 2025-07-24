//FormAI DATASET v1.0 Category: Smart home light control ; Style: systematic
#include <stdio.h>

// Function to turn on/off the light based on input from user
void light_control(int is_light_on) {
    if(is_light_on) {
        printf("Light is turned ON.\n");
    } else {
        printf("Light is turned OFF.\n");
    }
}

int main() {
    int user_input = 0;
    int is_light_on = 0;

    printf("Welcome to Smart Home Light Control!\n");
    printf("Enter 1 to turn on the light, 0 to turn off the light.\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &user_input);

        if(user_input == 1) {
            if(!is_light_on) {
                is_light_on = 1;
                light_control(is_light_on);
            } else {
                printf("The light is already ON.\n");
            }
        } else if(user_input == 0) {
            if(is_light_on) {
                is_light_on = 0;
                light_control(is_light_on);
            } else {
                printf("The light is already OFF.\n");
            }
        } else {
            printf("Invalid input. Please enter either 1 or 0.\n");
        }
    }

    return 0;
}