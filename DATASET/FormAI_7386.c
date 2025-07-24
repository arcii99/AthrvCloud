//FormAI DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdbool.h>

// Function to turn on/off the light
void light(bool on) {
    if(on) {
        printf("Light turned on.\n");
    } else {
        printf("Light turned off.\n");
    }
}

// Function to adjust thermostat temperature
void temperature(int temp) {
    printf("Thermostat adjusted to %d degrees Celsius.\n", temp);
}

int main() {
    bool isLightOn = false;
    int currentTemperature = 25;
    
    // Initial state
    printf("Welcome to Smart Home Automation!\n");
    printf("Light is turned off.\n");
    printf("Current temperature is %d degrees Celsius.\n", currentTemperature);
    
    // User inputs
    char userInput;
    printf("Press 'L' to turn on the light or 'D' to turn off it. Press 'T' to set the temperature: ");
    scanf(" %c", &userInput);
    
    // Execute user's command
    switch(userInput) {
        case 'L':
            light(true);
            isLightOn = true;
            break;
        case 'D':
            light(false);
            isLightOn = false;
            break;
        case 'T':
            int newTemp;
            printf("Enter new temperature (in Celsius): ");
            scanf("%d", &newTemp);
            temperature(newTemp);
            currentTemperature = newTemp;
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }
    
    // Final state
    printf("Smart Home Automation successfully executed.\n");
    printf("Light is turned %s.\n", isLightOn ? "on" : "off");
    printf("Current temperature is %d degrees Celsius.\n", currentTemperature);
    
    return 0;
}