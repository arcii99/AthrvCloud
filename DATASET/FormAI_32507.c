//FormAI DATASET v1.0 Category: Temperature monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TEMP_SENSOR "/sys/class/thermal/thermal_zone0/temp"
#define SLEEP_INTERVAL 5

int main()
{
    FILE *temp_file;

    while (1) {
        temp_file = fopen(TEMP_SENSOR, "r");
        if (temp_file == NULL) {
            printf("Error opening temperature file!\n");
            exit(EXIT_FAILURE);
        }

        double temperature;
        fscanf(temp_file, "%lf", &temperature);
        temperature /= 1000;            // Modify the temperature value to correct scale
        printf("Current CPU temperature: %.2fC\n", temperature);
        fclose(temp_file);

        sleep(SLEEP_INTERVAL);
    }

    return EXIT_SUCCESS;
}