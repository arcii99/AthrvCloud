//FormAI DATASET v1.0 Category: Smart home automation ; Style: immersive
#include <stdio.h>

int main() {
    printf("Welcome to Smart Home Automation!\n");
    printf("Please enter your security code: ");
    
    int securityCode;
    scanf("%d", &securityCode);
    
    if (securityCode == 1234) {
        printf("Access granted!\n\n");
        printf("What would you like to do?\n");
        printf("1. Turn off lights\n");
        printf("2. Control thermostat\n");
        printf("3. Lock doors\n");
        
        int option;
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Lights turned off.\n");
                break;
                
            case 2:
                printf("Please enter desired temperature: ");
                int temp;
                scanf("%d", &temp);
                printf("Thermostat set to %d degrees.\n", temp);
                break;
                
            case 3:
                printf("Doors locked.\n");
                break;
                
            default:
                printf("Invalid option, try again.\n");
                break;
        }
    } else {
        printf("Access denied!\n");
    }
    
    return 0;
}