//FormAI DATASET v1.0 Category: Smart home automation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>

int main() {

    // Starting the Sherlock Holmes style smart home automation program
    printf("Elementary, my dear Watson! Let's automate your smart home!\n");

    // Defining the variables for the different smart home devices
    bool livingRoomLightsOn = false;
    bool bedroomLightsOn = false;
    bool kitchenLightsOn = false;

    // Defining the variable for the current temperature
    int currentTemperature = 20;

    // Displaying the current temperature
    printf("The current temperature in your home is %d degrees Celsius.\n", currentTemperature);

    // Turning on the living room lights
    livingRoomLightsOn = true;

    // Displaying the status of the living room lights
    if (livingRoomLightsOn) {
        printf("The living room lights are now on.\n");
    } else {
        printf("The living room lights are now off.\n");
    }

    // Turning on the kitchen lights
    kitchenLightsOn = true;

    // Displaying the status of the kitchen lights
    if (kitchenLightsOn) {
        printf("The kitchen lights are now on.\n");
    } else {
        printf("The kitchen lights are now off.\n");
    }

    // Turning on the bedroom lights
    bedroomLightsOn = true;

    // Displaying the status of the bedroom lights
    if (bedroomLightsOn) {
        printf("The bedroom lights are now on.\n");
    } else {
        printf("The bedroom lights are now off.\n");
    }

    // Increasing the temperature by 5 degrees
    currentTemperature += 5;

    // Displaying the updated temperature
    printf("The current temperature in your home is now %d degrees Celsius.\n", currentTemperature);

    // Turning off the bedroom lights
    bedroomLightsOn = false;

    // Displaying the status of the bedroom lights
    if (bedroomLightsOn) {
        printf("The bedroom lights are now on.\n");
    } else {
        printf("The bedroom lights are now off.\n");
    }

    // Turning off the living room lights
    livingRoomLightsOn = false;

    // Displaying the status of the living room lights
    if (livingRoomLightsOn) {
        printf("The living room lights are now on.\n");
    } else {
        printf("The living room lights are now off.\n");
    }

    // Turning off the kitchen lights
    kitchenLightsOn = false;

    // Displaying the status of the kitchen lights
    if (kitchenLightsOn) {
        printf("The kitchen lights are now on.\n");
    } else {
        printf("The kitchen lights are now off.\n");
    }

    // Lowering the temperature by 3 degrees
    currentTemperature -= 3;

    // Displaying the updated temperature
    printf("The current temperature in your home is now %d degrees Celsius.\n", currentTemperature);

    // The program has successfully completed the smart home automation process
    printf("Well done, Watson! The smart home automation process has been completed successfully!\n");

    return 0;
}