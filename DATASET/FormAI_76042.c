//FormAI DATASET v1.0 Category: Smart home light control ; Style: beginner-friendly
#include <stdio.h>

int main(){
    int lightOn = 0;
    char userInput;

    printf("Welcome to Smart Home Light Control\n");

    while(1){
        printf("Press 'O' to turn on the light, 'F' to turn it off and 'Q' to quit the program\n");
        scanf(" %c", &userInput);

        if(userInput == 'Q' || userInput == 'q'){
            printf("Thank you for using Smart Home Light Control\n");
            break;
        } else if(userInput == 'O' || userInput == 'o'){
            if(lightOn){
                printf("The light is already on!\n");
            } else {
                printf("Turning the light on...\n");
                lightOn = 1;
            }
        } else if(userInput == 'F' || userInput == 'f'){
            if(lightOn){
                printf("Turning the light off...\n");
                lightOn = 0;
            } else {
                printf("The light is already off!\n");
            }
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}