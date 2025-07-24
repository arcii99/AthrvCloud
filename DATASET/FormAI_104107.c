//FormAI DATASET v1.0 Category: Smart home automation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// function prototype
void turnOnLights(int roomId);
void turnOffLights(int roomId);
void adjustTemperature(int roomId, int temperature);

int main()
{
    int livingRoomLights = 0, bedroomLights = 0;
    int livingRoomTemp = 75, bedroomTemp = 70;
    int livingRoomChoice = 0, bedroomChoice = 0;
    
    printf("Welcome to Smart Home Automation System!\n");
    
    do {
        printf("\nMENU\n");
        printf("1. Living Room\n");
        printf("2. Bedroom\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &livingRoomChoice);
        
        switch(livingRoomChoice)
        {
            case 1:
                printf("\nLIVING ROOM\n");
                printf("1. Turn on lights\n");
                printf("2. Turn off lights\n");
                printf("3. Adjust temperature\n");
                printf("Enter your choice: ");
                scanf("%d", &bedroomChoice);
                
                switch(bedroomChoice)
                {
                    case 1:
                        turnOnLights(1);
                        livingRoomLights = 1;
                        printf("Living Room lights are turned on.\n");
                        break;
                    case 2:
                        turnOffLights(1);
                        livingRoomLights = 0;
                        printf("Living Room lights are turned off.\n");
                        break;
                    case 3:
                        printf("Enter new temperature (60-85): ");
                        scanf("%d", &livingRoomTemp);
                        adjustTemperature(1, livingRoomTemp);
                        printf("Living Room temperature is adjusted to %d.\n", livingRoomTemp);
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;
                
            case 2:
                printf("\nBEDROOM\n");
                printf("1. Turn on lights\n");
                printf("2. Turn off lights\n");
                printf("3. Adjust temperature\n");
                printf("Enter your choice: ");
                scanf("%d", &bedroomChoice);
                
                switch(bedroomChoice)
                {
                    case 1:
                        turnOnLights(2);
                        bedroomLights = 1;
                        printf("Bedroom lights are turned on.\n");
                        break;
                    case 2:
                        turnOffLights(2);
                        bedroomLights = 0;
                        printf("Bedroom lights are turned off.\n");
                        break;
                    case 3:
                        printf("Enter new temperature (60-85): ");
                        scanf("%d", &bedroomTemp);
                        adjustTemperature(2, bedroomTemp);
                        printf("Bedroom temperature is adjusted to %d.\n", bedroomTemp);
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;
                
            case 3:
                printf("\nThank you for using Smart Home Automation System!\n");
                break;
                
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    } while(livingRoomChoice != 3);
    
    return 0;
}

// function definition
void turnOnLights(int roomId)
{
    printf("Turning on lights in Room %d...\n", roomId);
    // code to turn on lights in the specified room
}

void turnOffLights(int roomId)
{
    printf("Turning off lights in Room %d...\n", roomId);
    // code to turn off lights in the specified room
}

void adjustTemperature(int roomId, int temperature)
{
    printf("Adjusting temperature in Room %d to %d...\n", roomId, temperature);
    // code to adjust temperature in the specified room
}