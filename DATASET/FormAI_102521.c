//FormAI DATASET v1.0 Category: Smart home automation ; Style: careful
#include <stdio.h>
#include <stdbool.h>

// Define functions for each appliance
bool light(bool status) {
    if(status) {
        printf("The light is on.\n");
    }
    else {
        printf("The light is off.\n");
    }
    return !status;
}

bool fan(bool status) {
    if(status) {
        printf("The fan is on.\n");
    }
    else {
        printf("The fan is off.\n");
    }
    return !status;
}

bool ac(bool status) {
    if(status) {
        printf("The air conditioner is on.\n");
    }
    else {
        printf("The air conditioner is off.\n");
    }
    return !status;
}

int main() {
    // Initialize all appliances to off
    bool lightStatus = false;
    bool fanStatus = false;
    bool acStatus = false;
    
    // User interface loop
    while(true) {
        printf("What appliance would you like to toggle? (light/fan/ac)\n");
        char input[4];
        scanf("%3s", input);
        
        // Toggle appliance and update status
        if(strcmp(input, "lig") == 0) {
            lightStatus = light(lightStatus);
        }
        else if(strcmp(input, "fan") == 0) {
            fanStatus = fan(fanStatus);
        }
        else if(strcmp(input, "ac ") == 0) {
            acStatus = ac(acStatus);
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }
    return 0;
}