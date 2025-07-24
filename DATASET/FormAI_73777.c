//FormAI DATASET v1.0 Category: Smart home automation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int temperature = rand() % 100;
    int light = rand() % 2;
    int music = rand() % 2;

    printf("Welcome to Surreal Smart Home Automation!\n");
    printf("Current Temperature: %d degrees Celsius\n", temperature);
    printf("Current Lighting: %s\n", light == 1 ? "On" : "Off");
    printf("Current Music: %s\n", music == 1 ? "On" : "Off");

    printf("Would you like to adjust the temperature? (Y/N)\n");
    char response[10];
    scanf("%s", response);
    if (response[0] == 'Y' || response[0] == 'y') {
        int new_temp;
        printf("Enter new temperature: ");
        scanf("%d", &new_temp);
        printf("Adjusting temperature to %d degrees Celsius...\n", new_temp);
        temperature = new_temp;
    }

    printf("Would you like to turn the lights on or off? (Y/N)\n");
    scanf("%s", response);
    if (response[0] == 'Y' || response[0] == 'y') {
        printf("Turning %s lights...\n", light == 1 ? "off" : "on");
        light = light == 1 ? 0 : 1;
    }

    printf("Would you like to turn the music on or off? (Y/N)\n");
    scanf("%s", response);
    if (response[0] == 'Y' || response[0] == 'y') {
        printf("Turning %s music...\n", music == 1 ? "off" : "on");
        music = music == 1 ? 0 : 1;
    }

    printf("Updated settings:\n");
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Lighting: %s\n", light == 1 ? "On" : "Off");
    printf("Music: %s\n", music == 1 ? "On" : "Off");

    printf("Thank you for trusting Surreal Smart Home Automation!\n");
    return 0;
}