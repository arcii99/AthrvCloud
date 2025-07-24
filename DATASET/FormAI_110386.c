//FormAI DATASET v1.0 Category: Smart home automation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
    int temperature = 25;
    int lights = 0;
    int security = 1;
    
    printf("Welcome to the Smart Home Automation System.\n\n");

    printf("Current temperature is %d degrees Celsius.\n", temperature);
    printf("Would you like to change the temperature? (1 for yes, 0 for no) ");
    scanf("%d", &temperature);
    printf("\n");

    if (temperature < 20 || temperature > 30) {
        printf("Temperature is out of range. Adjusting to default 25 degrees Celsius.\n");
        temperature = 25;
    }

    printf("Current lights are %s.\n", lights ? "on" : "off");
    printf("Would you like to turn on/off the lights? (1 for on, 0 for off) ");
    scanf("%d", &lights);
    printf("\n");

    printf("Current security system is %s.\n", security ? "on" : "off");
    printf("Would you like to turn on/off the security system? (1 for on, 0 for off) ");
    scanf("%d", &security);
    printf("\n");

    printf("Smart Home Automation System Summary:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Lights: %s\n", lights ? "on" : "off");
    printf("Security System: %s\n", security ? "on" : "off");

    return 0;
}