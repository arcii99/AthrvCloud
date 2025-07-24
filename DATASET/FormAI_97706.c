//FormAI DATASET v1.0 Category: Smart home light control ; Style: beginner-friendly
#include <stdio.h>

//Declare Light Control Function
void lightControl(int lightNum, int lightState){
    if(lightState == 1){
        printf("Light %d is On!\n", lightNum);
    }
    else if(lightState == 0){
        printf("Light %d is Off!\n", lightNum);
    }
    else{
        printf("Invalid Light Control Code!\n");
    }
}

int main(){
    //Initialize Smart Home Control Variables
    int livingRoomLightState = 0;
    int bedroomLightState = 0;
    int kitchenLightState = 0;
    int livingRoomLightNum = 1;
    int bedroomLightNum = 2;
    int kitchenLightNum = 3;

    //Welcome Message
    printf("Welcome to Smart Home Light Control!\n");

    //Loop User Input for Light Control
    while(1){
        //Display Light Options
        printf("\nWhich Light would you like to Control?\n");
        printf("1. Living Room Light\n");
        printf("2. Bedroom Light\n");
        printf("3. Kitchen Light\n");
        
        //Take User's Light Choice
        int lightChoice;
        scanf("%d", &lightChoice);
        
        //Display Light State
        printf("Light %d is Currently %s.\n", lightChoice, (lightChoice == 1 ? livingRoomLightState ? "On" : "Off" : lightChoice == 2 ? bedroomLightState ? "On" : "Off" : kitchenLightState ? "On" : "Off"));
        
        //Display Light Control Options
        printf("What would you like to do?\n");
        printf("1. Turn %s On\n", (lightChoice == 1 ? "Living Room Light" : lightChoice == 2 ? "Bedroom Light" : "Kitchen Light"));
        printf("2. Turn %s Off\n", (lightChoice == 1 ? "Living Room Light" : lightChoice == 2 ? "Bedroom Light" : "Kitchen Light"));
        printf("3. Exit\n");

        //Take User's Light Control Choice
        int lightControlChoice;
        scanf("%d", &lightControlChoice);

        //Execute Light Control
        switch(lightControlChoice){
            case 1: //Turn Light On
                if(lightChoice == 1){
                    livingRoomLightState = 1;
                    lightControl(livingRoomLightNum, livingRoomLightState);
                }
                else if(lightChoice == 2){
                    bedroomLightState = 1;
                    lightControl(bedroomLightNum, bedroomLightState);
                }
                else{
                    kitchenLightState = 1;
                    lightControl(kitchenLightNum, kitchenLightState);
                }
                break;
            case 2: //Turn Light Off
                if(lightChoice == 1){
                    livingRoomLightState = 0;
                    lightControl(livingRoomLightNum, livingRoomLightState);
                }
                else if(lightChoice == 2){
                    bedroomLightState = 0;
                    lightControl(bedroomLightNum, bedroomLightState);
                }
                else{
                    kitchenLightState = 0;
                    lightControl(kitchenLightNum, kitchenLightState);
                }
                break;
            case 3: //Exit Program
                printf("Thank you for using Smart Home Light Control!\n");
                return 0;
            default: //Invalid Choice
                printf("Invalid Light Control Choice!\n");
        }
    }
}