//FormAI DATASET v1.0 Category: Temperature monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *thermal_file;
    char path[100];
    float temp;
    
    // loop to continuously monitor temperature
    while (1) {
        // set path to thermal zone file
        sprintf(path, "/sys/class/thermal/thermal_zone0/temp");
        // open thermal zone file
        thermal_file = fopen(path, "r");
        if (thermal_file == NULL) {
            printf("Error: Could not open thermal zone file\n");
            exit(1);
        }
        // read temperature from file
        fscanf(thermal_file, "%f", &temp);
        // close thermal zone file
        fclose(thermal_file);
        // convert temperature from millidegrees Celsius to degrees Celsius
        temp /= 1000;
        // print temperature to console
        printf("CPU Temperature: %.1f°C\n", temp);
        // wait for 1 second
        sleep(1);
    }
    return 0;
}