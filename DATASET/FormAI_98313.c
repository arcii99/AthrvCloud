//FormAI DATASET v1.0 Category: Smart home light control ; Style: Dennis Ritchie
#include <stdio.h>

int main() {

    int lightStatus = 0; // 0 for off, 1 for on
    
    printf("Welcome to Smart Home Light Control\n");
    
    while (1) {
        printf("Current Light Status: %d\n", lightStatus);
        printf("Enter 1 to turn on the light, 0 to turn off the light: ");
        
        int input;
        scanf("%d", &input);
        
        if (input == 1) {
            if (lightStatus == 0) {
            
                // send signal to turn on light 
                
                printf("Turning on the light...\n");
                lightStatus = 1;
            
            } else {
                printf("The light is already on.\n");
            }
        } else if (input == 0) {
            if (lightStatus == 1) {
                
                // send signal to turn off light 
                
                printf("Turning off the light...\n");
                lightStatus = 0;
                
            } else {
                printf("The light is already off.\n");
            }
        } else {
            printf("Invalid input.\n");
        }
    }
    
    return 0;
}