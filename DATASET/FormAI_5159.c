//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAXTEMP 50.0
#define MINTEMP -20.0

float getTemperature(){
    float temp = (float)(rand()%700)/10.0 - 20.0;
    return temp;
}

int main(){
    srand(time(NULL));
    float currentTemp = getTemperature();

    // assuming sensor inputs are read every 10 seconds
    while(1){
        sleep(10);
        float newTemp = getTemperature();
        if(newTemp >= MAXTEMP || newTemp <= MINTEMP){
            printf("!!! WARNING: Temperature out of range !!!\n");
        }
        if(newTemp > currentTemp+2.0){
            printf("Temperature increased by %.2f degrees Celsius.\n", newTemp-currentTemp);
        }else if(newTemp < currentTemp-2.0){
            printf("Temperature decreased by %.2f degrees Celsius.\n", currentTemp-newTemp);
        }
        currentTemp = newTemp;
    }
    return 0;
}