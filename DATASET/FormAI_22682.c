//FormAI DATASET v1.0 Category: Smart home light control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Function for turning on/off the light
bool toggleLight(bool isOn){
    if(isOn){
        printf("Turning off the light...\n");
        return false;
    } else {
        printf("Turning on the light...\n");
        return true;
    }
}

int main(){

    bool isLightOn = false;
    int userChoice;

    //Loop until user chooses to exit
    do{
        printf("Enter your choice:\n");
        printf("1. Turn Light %s\n", isLightOn ? "Off" : "On");
        printf("2. Exit\n");

        scanf("%d", &userChoice);

        switch(userChoice){
            case 1:
                isLightOn = toggleLight(isLightOn);
                break;

            case 2:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while(userChoice != 2);

    return 0;
}