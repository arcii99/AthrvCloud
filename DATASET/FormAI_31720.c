//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 100

int main() {
    char destination[MAX_STR_LEN];
    float latitude, longitude;
    
    printf("Enter destination name: ");
    fgets(destination, MAX_STR_LEN, stdin);
    
    printf("Enter destination latitude: ");
    scanf("%f", &latitude);
    
    printf("Enter destination longitude: ");
    scanf("%f", &longitude);
    
    printf("\nDestination set to %s at [%f, %f]\n", destination, latitude, longitude);
    
    char action;
    do {
        printf("\nWhat would you like to do? ((M)ove, (S)top, (Q)uit) ");
        scanf(" %c", &action);
        switch (action) {
            case 'M': {
                printf("\nCurrent location is [%f, %f]\n", latitude, longitude);
                printf("Enter new latitude: ");
                scanf("%f", &latitude);
                printf("Enter new longitude: ");
                scanf("%f", &longitude);
                printf("Moved to [%f, %f]\n", latitude, longitude);
                break;
            }
            case 'S': {
                printf("\nStopped at [%f, %f]\n", latitude, longitude);
                break;
            }
            case 'Q': {
                printf("\nExiting navigation simulation...\n");
                exit(0);
            }
            default:
                printf("\nInvalid action! Please try again.\n");
        }
    } while (1);
    
    return 0;
}