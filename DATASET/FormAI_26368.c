//FormAI DATASET v1.0 Category: Smart home automation ; Style: standalone
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Smart Home Devices
bool isLightOn = false;
bool isACOn = false;
bool isTVOn = false;

// Functions to control Smart Home devices
void turnOnLight()
{
    isLightOn = true;
    printf("The lights have been turned on.\n");
}

void turnOffLight()
{
    isLightOn = false;
    printf("The lights have been turned off.\n");
}

void turnOnAC()
{
    isACOn = true;
    printf("The AC has been turned on.\n");
}

void turnOffAC()
{
    isACOn = false;
    printf("The AC has been turned off.\n");
}

void turnOnTV()
{
    isTVOn = true;
    printf("The TV has been turned on.\n");
}

void turnOffTV()
{
    isTVOn = false;
    printf("The TV has been turned off.\n");
}

// Main program
int main()
{
    // Welcome message
    printf("Welcome to your Smart Home Automation System!\n");

    // User input loop
    bool isRunning = true;
    char input[10];
    while(isRunning)
    {
        // Ask for user input
        printf("What would you like to do?\n");
        printf("[1] Turn the lights on\n");
        printf("[2] Turn the lights off\n");
        printf("[3] Turn the AC on\n");
        printf("[4] Turn the AC off\n");
        printf("[5] Turn the TV on\n");
        printf("[6] Turn the TV off\n");
        printf("[7] Quit\n");
        printf("Enter your choice: ");
        fgets(input, 10, stdin);

        // Process user input
        switch(atoi(input))
        {
            case 1:
                if(isLightOn)
                {
                    printf("The lights are already on!\n");
                }
                else
                {
                    turnOnLight();
                }
                break;
            case 2:
                if(!isLightOn)
                {
                    printf("The lights are already off!\n");
                }
                else
                {
                    turnOffLight();
                }
                break;
            case 3:
                if(isACOn)
                {
                    printf("The AC is already on!\n");
                }
                else
                {
                    turnOnAC();
                }
                break;
            case 4:
                if(!isACOn)
                {
                    printf("The AC is already off!\n");
                }
                else
                {
                    turnOffAC();
                }
                break;
            case 5:
                if(isTVOn)
                {
                    printf("The TV is already on!\n");
                }
                else
                {
                    turnOnTV();
                }
                break;
            case 6:
                if(!isTVOn)
                {
                    printf("The TV is already off!\n");
                }
                else
                {
                    turnOffTV();
                }
                break;
            case 7:
                printf("Goodbye!\n");
                isRunning = false;
                break;
            default:
                printf("Invalid choice. Please choose a number between 1 and 7.\n");
        }
    }

    // End of program
    return 0;
}