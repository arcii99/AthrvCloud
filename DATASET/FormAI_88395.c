//FormAI DATASET v1.0 Category: Smart home automation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 50

typedef struct {
    int id;
    char name[MAX_INPUT];
    int status;
} Appliance;

int main() {
    // initialize appliances
    Appliance light = { 0, "Light", 0 };
    Appliance fan = { 1, "Fan", 0 };
    Appliance tv = { 2, "TV", 0 };
    Appliance ac = { 3, "AC", 0 };
    
    // prompt for input
    char input[MAX_INPUT];
    printf("Enter command: ");
    fgets(input, MAX_INPUT, stdin);

    // convert input to uppercase for easier comparison
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // parse input
    if (strstr(input, "LIGHT")) {
        light.status = !light.status;
        printf("%s turned %s\n", light.name, light.status ? "ON" : "OFF");
    } else if (strstr(input, "FAN")) {
        fan.status = !fan.status;
        printf("%s turned %s\n", fan.name, fan.status ? "ON" : "OFF");
    } else if (strstr(input, "TV")) {
        tv.status = !tv.status;
        printf("%s turned %s\n", tv.name, tv.status ? "ON" : "OFF");
    } else if (strstr(input, "AC")) {
        ac.status = !ac.status;
        printf("%s turned %s\n", ac.name, ac.status ? "ON" : "OFF");
    } else {
        printf("Invalid input\n");
    }

    return 0;
}