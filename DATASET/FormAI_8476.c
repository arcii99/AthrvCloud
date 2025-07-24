//FormAI DATASET v1.0 Category: Weather simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // Seed the random number generator with current time

    int currentTemp = (rand() % 80) - 40; // Generate a random temperature between -40 and 40
    printf("Current temperature is %d degrees Celsius.\n", currentTemp);

    if(currentTemp < 0){
        printf("Brrr! It's freezing outside.\n");
    }
    else if(currentTemp > 30){
        printf("Phew, it's way too hot outside.\n");
    }
    else{
        printf("The weather is just perfect today.\n");
    }

    int precipitationChance = rand() % 100; // Generate a random number between 0 and 99
    if(precipitationChance < 10){ // 10% chance of precipitation
        int precipitationType = rand() % 2; // Generate a random number between 0 and 1
        if(precipitationType == 0){ // Rain
            printf("Looks like it's going to rain today. Don't forget your umbrella!\n");
        }
        else{ // Snow
            printf("Looks like it's going to snow today. Stay warm!\n");
        }
    }
    else{
        printf("No precipitation today. Enjoy the sunshine!\n");
    }

    return 0; // Exit the program
}