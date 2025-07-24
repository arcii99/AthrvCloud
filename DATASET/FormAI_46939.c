//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TEMP_SENSOR "/sys/class/thermal/thermal_zone0/temp"
#define MAX_TEMP 100

int main(int argc, char *argv[])
{
    FILE *temp_sensor_file;
    char temp_string[10];
    double temp_celsius;

    printf("Temperature Monitor\n");
    printf("-------------------\n");

    while (1)
    {
        temp_sensor_file = fopen(TEMP_SENSOR, "r");
        if (temp_sensor_file == NULL)
        {
            printf("Failed to open temperature sensor file!\n");
            exit(EXIT_FAILURE);
        }

        fgets(temp_string, sizeof(temp_string), temp_sensor_file);
        fclose(temp_sensor_file);

        temp_celsius = atof(temp_string) / 1000;

        printf("Current temperature: %.2f C\n", temp_celsius);

        if (temp_celsius > MAX_TEMP)
        {
            printf("WARNING: Temperature is too high!\n");
        }

        sleep(1);
    }

    return 0;
}