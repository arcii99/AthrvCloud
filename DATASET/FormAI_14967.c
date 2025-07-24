//FormAI DATASET v1.0 Category: Smart home light control ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// function to turn on/off the lights based on the sensor reading
void toggle_lights(char sensor_reading) {
    if (sensor_reading == '1') {
        printf("Lights turned on.\n");
    } else if (sensor_reading == '0') {
        printf("Lights turned off.\n");
    } else {
        printf("Invalid sensor reading.\n");
    }
}

int main() {
    char sensor_reading;

    printf("Welcome to the Smart Home Light Control System.\n");
    printf("Please enter the sensor reading (0/1): ");
    scanf("%c", &sensor_reading);
    
    toggle_lights(sensor_reading);

    return 0;
}