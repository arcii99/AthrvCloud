//FormAI DATASET v1.0 Category: Smart home light control ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int light_switch = 0;
    int user_choice = 0;

    printf("Welcome to Smart Home Light Control.\n");

    while (1) {
        printf("\nPlease select an option:\n1. Turn on/off the light\n2. Exit the program\n");
        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                if (light_switch == 0) {
                    printf("\nTurning on the light.\n");
                    // Code to turn on the light
                    light_switch = 1;
                } else {
                    printf("\nTurning off the light.\n");
                    // Code to turn off the light
                    light_switch = 0;
                }
                break;
            case 2:
                printf("\nExiting the program.\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}