//FormAI DATASET v1.0 Category: Smart home automation ; Style: energetic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define LIGHT_PIN 17 // GPIO pin for the lights
#define FAN_PIN 18 // GPIO pin for the fan
#define TEMPERATURE_THRESHOLD 25 // threshold temperature in degree Celsius

void turn_on_light(bool on) {
    // code to turn on/off the lights
}

void turn_on_fan(bool on) {
    // code to turn on/off the fan
}

int read_temperature() {
    // code to read temperature from sensor
    srand(time(NULL));
    return (rand() % 10) + 20; // generate random temperature between 20 and 29 degree Celsius
}

int main() {
    int temperature = read_temperature();
    if(temperature >= TEMPERATURE_THRESHOLD) {
        printf("Temperature is too high! Turning on the fan.\n");
        turn_on_fan(true);
    }
    else {
        printf("Temperature is normal. Turning on the lights.\n");
        turn_on_light(true);
    }
    return 0;
}