//FormAI DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i, j, k, temperature[7][24], rain[7], wind[7];
    char* day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    srand(time(NULL)); // set seed for random generator

    // Generate random temperature for each day of the week
    for(i=0; i<7; i++){
        printf("Temperature for %s:\n", day[i]);
        for(j=0; j<24; j++){
            temperature[i][j] = rand()%30; // generate temperature between 0 and 30 degrees Celsius
            printf("%d ", temperature[i][j]);
        }
        printf("\n");
    }

    // Generate random rainfall for each day of the week
    printf("\n\nRainfall:\n");
    for(i=0; i<7; i++){
        rain[i] = rand()%50; // generate rainfall between 0 and 50 millimeters
        printf("%s: %d mm\n", day[i], rain[i]);
    }

    // Generate random windspeed for each day of the week
    printf("\n\nWindspeed:\n");
    for(i=0; i<7; i++){
        wind[i] = rand()%40; // generate windspeed between 0 and 40 kilometers per hour
        printf("%s: %d km/h\n", day[i], wind[i]);
    }

    return 0;
}