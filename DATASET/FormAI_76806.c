//FormAI DATASET v1.0 Category: Temperature monitor ; Style: protected
#include<stdio.h>
#include<stdlib.h>

#define MAX_TEMP 100.0
#define MIN_TEMP 0.0

int main(){
    float currentTemp = 0, highestTemp = 0, lowestTemp = MAX_TEMP, sum = 0;
    int numTemp = 0;

    printf("Welcome to the Temperature Monitor!\n\n");
    printf("Please enter the current temperature (0-100): ");
    scanf("%f",&currentTemp);

    while(currentTemp >= MIN_TEMP && currentTemp <= MAX_TEMP){

        if(currentTemp > highestTemp){
            highestTemp = currentTemp;
        }

        if(currentTemp < lowestTemp){
            lowestTemp = currentTemp;
        }

        sum += currentTemp;
        numTemp++;

        printf("\nCurrent Temperature: %.1f\n",currentTemp);
        printf("Highest Temperature: %.1f\n",highestTemp);
        printf("Lowest Temperature: %.1f\n",lowestTemp);
        printf("Average Temperature: %.1f\n\n",sum/numTemp);

        printf("Please enter the current temperature (0-100): ");
        scanf("%f",&currentTemp);
    }

    printf("\n\nExiting the Temperature Monitor. Thank you for using!\n");

    return 0;
}