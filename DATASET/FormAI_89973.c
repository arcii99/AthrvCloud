//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char destination[20], choice;
    float latitude, longitude;
    srand(time(NULL));
    
    printf("Welcome to the GPS Navigation Simulation!\n");
    printf("What is your destination? ");
    scanf("%s", destination);
    printf("Great! Let's get started.\n");
    
    while(1) {
        printf("\nCurrent location: %f, %f", latitude, longitude);
        printf("\nDo you want to travel towards %s? (Y/N) ", destination);
        scanf(" %c", &choice);
        
        if(choice == 'Y' || choice == 'y') {
            float change_lat = (float)(rand() % 10)/1000;
            float change_long = (float)(rand() % 10)/1000;
            latitude += change_lat;
            longitude += change_long;
            printf("\nTravelling towards %s...", destination);
            printf("\nNew location: %f, %f", latitude, longitude);
            
            if(latitude >= 25.0 && latitude <= 25.5 && longitude >= 55.0 && longitude <= 55.5) {
                printf("\nCongratulations, you have reached %s! Have a nice day.", destination);
                break;
            }
        }
        else if(choice == 'N' || choice == 'n') {
            printf("\nOkay, have a nice day.");
            break;
        }
        else {
            printf("\nInvalid choice. Please choose Y/N.");
        }
    }
    
    return 0;
}