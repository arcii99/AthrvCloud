//FormAI DATASET v1.0 Category: Smart home automation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    //initialize variables
    int temp, light, humidity, motion;
    
    //generate random values for sensor inputs
    srand(time(0));
    temp = rand() % 101; //temperature range 0-100 degrees Fahrenheit
    light = rand() % 101; //light intensity range 0-100%
    humidity = rand() % 101; //humidity range 0-100%
    motion = rand() % 2; //presence of motion either 0 or 1
    
    //check sensor inputs and perform corresponding actions
    if(temp > 80){
        printf("Temperature is high. Turning on air conditioner...\n");
    }
    else if(temp < 70){
        printf("Temperature is low. Turning on heater...\n");
    }
    else{
        printf("Temperature is normal.\n");
    }
    if(light > 75){
        printf("Light intensity is high. Turning off lights...\n");
    }
    else if(light < 25){
        printf("Light intensity is low. Turning on lights...\n");
    }
    else{
        printf("Light intensity is normal.\n");
    }
    if(humidity > 60){
        printf("Humidity is high. Turning on dehumidifier...\n");
    }
    else if(humidity < 40){
        printf("Humidity is low. Turning on humidifier...\n");
    }
    else{
        printf("Humidity is normal.\n");
    }
    if(motion == 1){
        printf("Motion detected. Turning on security system...\n");
    }
    else{
        printf("No motion detected.\n");
    }
    
    return 0;
}