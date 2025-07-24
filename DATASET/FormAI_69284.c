//FormAI DATASET v1.0 Category: Temperature monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TEMP_SENSOR_PIN 14

int main(int argc, char*argv[]) {
    FILE *temp_file;
    float temp_c, temp_f;
    int temp_value;

    // read sensor data every 5 seconds
    while (1) {
        // open the file with the temperature sensor data
        temp_file = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
        if (!temp_file) {
            printf("Error opening file \n");
            exit(1);
        }

        // read the temperature sensor data from the file
        fscanf(temp_file, "%d", &temp_value);

        // close the file
        fclose(temp_file);

        // convert the temperature from millidegrees Celsius to Celsius
        temp_c = (float)temp_value/1000;

        // convert the temperature from Celsius to Fahrenheit
        temp_f = temp_c * 9/5 + 32;

        // print the temperature in both Celsius and Fahrenheit
        printf("Temperature: %.2f C / %.2f F\n", temp_c, temp_f);

        // wait 5 seconds before reading the sensor data again
        sleep(5);
    }

    return 0;
}