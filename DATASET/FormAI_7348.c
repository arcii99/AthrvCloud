//FormAI DATASET v1.0 Category: Smart home automation ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

int main(){
    int temperature = 25, humidity = 60, brightness = 80;
    int temperatureThreshold = 30, humidityThreshold = 70, brightnessThreshold = 90;
    int AC = 0, Light = 0, Fan = 0;
    
    printf("Current Climate: Temperature = %dC, Humidity = %d%%, Brightness = %d%%\n", temperature, humidity, brightness);
    
    // AC control
    if (temperature > temperatureThreshold) {
        printf("Temperature above threshold. Turning on AC...\n");
        AC = 1;
    }
    else{
        printf("Temperature below threshold. Turning off AC...\n");
        AC = 0;
    }
    
    // Light control
    if (brightness < brightnessThreshold) {
        printf("Brightness level below threshold. Turning on Light...\n");
        Light = 1;
    }
    else{
        printf("Brightness level above threshold. Turning off Light...\n");
        Light = 0;
    }
    
    // Fan control
    if (humidity > humidityThreshold) {
        printf("Humidity level above threshold. Turning on Fan...\n");
        Fan = 1;
    }
    else{
        printf("Humidity level below threshold. Turning off Fan...\n");
        Fan = 0;
    }
    
    printf("AC = %d, Light = %d, Fan = %d\n", AC, Light, Fan);
    
    return 0;
}