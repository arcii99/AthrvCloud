//FormAI DATASET v1.0 Category: Temperature monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *temperatureFile;
    char fileName[20] = "/sys/class/thermal/thermal_zone0/temp";
    char temperature[6];

    while(1) {
        temperatureFile = fopen(fileName, "r");
        if(temperatureFile == NULL) {
            printf("Error: Unable to open the temperature file.\n");
            exit(1);
        }
        fgets(temperature, 6, temperatureFile);
        printf("Current temperature: %s°C\n", temperature);
        fclose(temperatureFile);
        sleep(5); // Get temperature every 5 seconds
    }
    return 0;
}