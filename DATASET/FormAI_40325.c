//FormAI DATASET v1.0 Category: Smart home automation ; Style: calm
#include <stdio.h>

int main() {
    // Smart home automation program that controls lights and temperature
    
    int lights = 0;
    int temperature = 70;
    
    printf("Welcome to your smart home!\n");
    
    while(1){
        printf("Enter 'l' to toggle lights (current state: %s)\n", (lights == 0) ? "off" : "on");
        printf("Enter 't' to adjust temperature (current setting: %i)\n", temperature);
        printf("Enter 'q' to quit\n");
        
        char input;
        scanf(" %c", &input);
        
        if(input == 'l'){
            lights = !lights;
            printf("Lights are now %s\n", (lights == 0) ? "off" : "on");
        } else if(input == 't'){
            printf("Enter desired temperature:\n");
            scanf("%i", &temperature);
            printf("Temperature set to %i\n", temperature);
        } else if(input == 'q'){
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
    
    return 0;
}