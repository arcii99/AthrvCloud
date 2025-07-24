//FormAI DATASET v1.0 Category: Smart home automation ; Style: excited
#include <stdio.h>
#include <stdbool.h>

int main() {
    int temperature = 25;
    bool lightsOn = false;
    bool alarmActivated = false;
    
    printf("Welcome to the Smart Home Automation System!\n");
    
    printf("Current temperature is set to %d degrees Celsius.\n", temperature);
    
    printf("Do you want to change the temperature? (y/n): ");
    char input;
    scanf("%c", &input);
    if(input == 'y') {
        printf("Enter the new temperature in Celsius: ");
        scanf("%d", &temperature);
        printf("New temperature is set to %d degrees Celsius.\n", temperature);
    }
    
    printf("Do you want to turn on the lights? (y/n): ");
    scanf(" %c", &input);
    if(input == 'y') {
        lightsOn = true;
        printf("Lights are turned on.\n");
    }
    
    printf("Do you want to activate the alarm? (y/n): ");
    scanf(" %c", &input);
    if(input == 'y') {
        alarmActivated = true;
        printf("Alarm is activated.\n");
    }
    
    printf("Current status:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Lights: %s\n", lightsOn ? "On" : "Off");
    printf("Alarm: %s\n", alarmActivated ? "Activated" : "Not Activated");
    
    return 0;
}