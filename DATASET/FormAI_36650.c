//FormAI DATASET v1.0 Category: Smart home light control ; Style: calm
#include <stdio.h>
#include <stdbool.h>

bool isLightOn = false;

void turnOnLight(){
    isLightOn = true;
    printf("Light turned on.\n");
}

void turnOffLight(){
    isLightOn = false;
    printf("Light turned off.\n");
}

void toggleLight(){
    if(isLightOn){
        turnOffLight();
    }
    else{
        turnOnLight();
    }
}

int main(){

    while(true){
        char userInput;

        printf("\nEnter 'P' to toggle the light: ");
        scanf(" %c", &userInput);

        if(userInput == 'P'){
            toggleLight();
        }
        else{
            printf("Invalid input. Try again.\n");
        }
    }

    return 0;
}