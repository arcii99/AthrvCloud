//FormAI DATASET v1.0 Category: Smart home automation ; Style: happy
#include <stdio.h>

int main () {
    printf("Welcome to Happy Home Automation!\n");
    int lights = 0, temperature = 25, washer = 0, dryer = 0;
    while(1){
        printf("Enter command: ");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "lights") == 0){
            lights = !lights;
            if (lights) printf("Lights turned on.\n");
            else printf("Lights turned off.\n");
        }
        else if (strcmp(command, "temperature") == 0){
            int temp;
            printf("Enter temperature: ");
            scanf("%d", &temp);
            temperature = temp;
            printf("Temperature set to %d°C\n", temperature);
        }
        else if (strcmp(command, "washer") == 0){
            washer = !washer;
            if (washer) printf("Washer started.\n");
            else printf("Washer stopped.\n");
        }
        else if (strcmp(command, "dryer") == 0){
            dryer = !dryer;
            if (dryer) printf("Dryer started.\n");
            else printf("Dryer stopped.\n");
        }
        else if (strcmp(command, "exit") == 0){
            printf("Goodbye!\n");
            break;
        }
        else{
            printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}