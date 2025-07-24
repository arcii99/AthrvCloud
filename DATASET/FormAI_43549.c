//FormAI DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program simulates a temperature monitoring system. */

int main() {
    
    int current_temp, min_temp, max_temp;
    char choice;
    time_t t;
    srand((unsigned) time(&t));             // Seeding the random function
    
    // Initializing the minimum and maximum temperature
    min_temp = 0;
    max_temp = 100;
    
    printf("\n*******************************************\n");
    printf("*           Temperature Monitor           *\n");
    printf("*******************************************\n");
    
    do {
        // Simulating current temperature
        current_temp = (rand() % (max_temp - min_temp + 1)) + min_temp;
        
        printf("\nCurrent temperature: %d\n", current_temp);
        
        // Checking if temperature crosses the limits
        if(current_temp < 20){
            printf("\n!!! WARNING !!! Temperature is too low.\n");         
        }
        
        if(current_temp > 80){
            printf("\n!!! WARNING !!! Temperature is too high.\n");         
        }
        
        // Asking user for next action
        printf("\nDo you want to see the temperature again? (y/n): ");
        scanf(" %c", &choice);
        
    } while(choice == 'y' || choice == 'Y');  
    
    printf("\nGoodbye!\n");
    
    return 0;
}