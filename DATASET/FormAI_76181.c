//FormAI DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
    srand(time(NULL)); //set the seed for random numbers
    
    float temperature = 25.00; //initialize the temperature to 25 degrees Celsius
    int precipitation = 0; //initialize the precipitation to 0 millimeters
    
    printf("Welcome to the Weather Simulation Program!\n");
    
    for(int i = 1; i <= 7; i++) { //loop through the week
        printf("Day %d:\n", i);
        int rand_num = rand() % 4; //generate a random number between 0 and 3
        
        if(rand_num == 0) { //25% chance of being sunny
            printf("The weather is sunny today!\n");
            temperature += rand() % 6 - 2; //randomly increase or decrease temperature by 2 to 7 degrees Celsius
            printf("The temperature is %.2f degrees Celsius.\n", temperature);
        }
        else if(rand_num == 1) { //25% chance of being cloudy
            printf("The weather is cloudy today.\n");
            temperature += rand() % 4 - 1; //randomly increase or decrease temperature by 1 to 4 degrees Celsius
            printf("The temperature is %.2f degrees Celsius.\n", temperature);
            precipitation += rand() % 3; //randomly add 0 to 2 millimeters of precipitation
            printf("%d millimeters of precipitation expected today.\n", precipitation);
        }
        else if(rand_num == 2) { //25% chance of being rainy
            printf("The weather is rainy today.\n");
            temperature -= rand() % 3; //randomly decrease temperature by 1 to 3 degrees Celsius
            printf("The temperature is %.2f degrees Celsius.\n", temperature);
            precipitation += rand() % 6 + 5; //randomly add 5 to 10 millimeters of precipitation
            printf("%d millimeters of precipitation expected today.\n", precipitation);
        }
        else { //25% chance of being snowy
            printf("The weather is snowy today.\n");
            temperature -= rand() % 8 - 5; //randomly decrease temperature by 5 to 12 degrees Celsius
            printf("The temperature is %.2f degrees Celsius.\n", temperature);
            precipitation += rand() % 3 + 2; //randomly add 2 to 4 millimeters of precipitation
            printf("%d millimeters of precipitation expected today.\n", precipitation);
        }
        
        printf("\n"); //print a blank line for formatting
    }
    
    printf("Thank you for using the Weather Simulation Program!\n");
    
    return 0;
}