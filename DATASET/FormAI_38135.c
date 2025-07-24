//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scientific
#include<stdio.h>

/*
 * This program monitors the temperature 
 * in a laboratory experiment and outputs the 
 * temperature in Celsius and Fahrenheit
 */

int main(){
    float temp_celsius, temp_fahren;

    printf("Enter the temperature in Celsius: ");
    scanf("%f",&temp_celsius);

    temp_fahren = (temp_celsius * 9/5) + 32;

    printf("Temperature in Celsius: %f\n",temp_celsius);
    printf("Temperature in Fahrenheit: %f\n",temp_fahren);

    // Check if temperature is within safe range for human exposure
    if(temp_celsius < 18){
        printf("Warning: Temperature is below safe range for human exposure\n");
    } else if(temp_celsius > 30){
        printf("Warning: Temperature is above safe range for human exposure\n");
    } else{
        printf("Temperature is within safe range for human exposure\n");
    }

    return 0;
}