//FormAI DATASET v1.0 Category: Smart home automation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    time_t t;
    srand((unsigned) time(&t)); //initialize random number generator

    int temperature = rand() % 100; //generate random number between 0-99 for temperature

    int light_sensor_value = rand() % 100; //generate random number between 0-99 for light sensor value

    printf("Current Temperature: %d\n", temperature);
    printf("Current Light Sensor Value: %d\n", light_sensor_value);

    if (temperature > 25) //if temperature is above 25 degree Celsius turn on air conditioner
    {
        printf("Air Conditioner Turned ON\n");
    } else
    {
        printf("Air Conditioner Turned OFF\n");
    }

    if (light_sensor_value < 50) //if light sensor value is below 50 turn on lights
    {
        printf("Lights Turned ON\n");
    } else
    {
        printf("Lights Turned OFF\n");
    }
    
    return 0;
}