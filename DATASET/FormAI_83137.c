//FormAI DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float temp;
    int count = 0;
    char response = 'y';

    printf("Welcome to the temperature monitor.\n");

    while (response == 'y') {
        printf("Enter the current temperature: ");
        scanf("%f", &temp);
        
        if (temp > 50) {
            printf("Warning: Temperature is too high!\n");
            count++;
        } 
        else if (temp < -10) {
            printf("Warning: Temperature is too low!\n");
            count++;
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &response);
    }

    printf("Thank you for using the temperature monitor.\n");
    
    if (count >= 3) {
        printf("Alarm! The temperature is unstable!\n");
        return EXIT_FAILURE;
    }
    else {
        printf("The temperature is stable.\n");
        return EXIT_SUCCESS;
    }
}