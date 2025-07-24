//FormAI DATASET v1.0 Category: Weather simulation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_DAYS 30
#define MAX_HOURS 24

int main(){
    int temperature[MAX_DAYS][MAX_HOURS];
    int precipitation[MAX_DAYS][MAX_HOURS];
    int i, j;
    srand(time(NULL));
    for(i=0; i<MAX_DAYS; i++){
        for(j=0; j<MAX_HOURS; j++){
            temperature[i][j] = rand()%50; // Generate random temperature between 0 to 50 degree Celsius
            precipitation[i][j] = rand()%100; // Generate random precipitation level between 0 to 100 millimeters
        }
    }
    // Print out the simulation results
    printf("Weather simulation for %d days\n", MAX_DAYS);
    printf("=======================================\n");
    printf("Day\tHour\tTemperature\tPrecipitation\n");
    for(i=0; i<MAX_DAYS; i++){
        for(j=0; j<MAX_HOURS; j++){
            printf("%d\t%d\t%dC\t\t%dmm\n", i+1, j, temperature[i][j], precipitation[i][j]);
        }
    }
    return 0;
}