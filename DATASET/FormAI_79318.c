//FormAI DATASET v1.0 Category: Smart home automation ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int temp_sensor, light_sensor, gas_sensor;
    int fan = 0, light = 0;

    srand(time(0));

    printf("Smart Home Automation\n");

    while(1) {
        temp_sensor = rand() % 50;
        light_sensor = rand() % 2;
        gas_sensor = rand() % 2;

        printf("\nTemperature Sensor Reading: %d degrees Celsius\n", temp_sensor);
        printf("Light Sensor Reading: %s\n", light_sensor ? "ON" : "OFF");
        printf("Gas Sensor Reading: %s\n", gas_sensor ? "LEAK DETECTED" : "SAFE");

        if(temp_sensor > 30) {
            printf("ALERT: Temperature is exceeding 30 degrees Celsius.\n");
            fan = 1;
        } else {
            fan = 0;
        }

        if(gas_sensor) {
            printf("ALERT: Gas leak detected in the room.\n");
            fan = 1;
            light = 1;
        } else {
            light = 0;
        }

        if(light_sensor) {
            printf("Light is already ON.\n");
        } else if(!light_sensor && !gas_sensor) {
            printf("Turning ON the lights.\n");
            light = 1;
        }

        if(fan) {
            printf("Turning ON the fan.\n");
        } else {
            printf("Turning OFF the fan.\n");
        }

        if(light) {
            printf("Turning ON the lights.\n");
        } else {
            printf("Turning OFF the lights.\n");
        }

        printf("============================\n");

        // Pause for 5 seconds
        sleep(5);
    }

    return 0;
}