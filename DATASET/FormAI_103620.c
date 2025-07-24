//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to read the system temperature
double getTemperature() {
    FILE* temperatureFile = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (temperatureFile == NULL) {
        printf("Failed to read the system temperature.\n");
        exit(EXIT_FAILURE);
    }
    char buffer[20];
    fgets(buffer, 20, temperatureFile);
    double temperature = atof(buffer) / 1000.0;
    fclose(temperatureFile);
    return temperature;
}

// Main function to monitor the system temperature
int main(int argc, char** argv) {
    double temperature = 0;
    while (1) {
        temperature = getTemperature();
        if (temperature >= 80) {
            printf("Warning: Temperature is too high! Current temperature: %.2lf C\n", temperature);
        } else if (temperature >= 70) {
            printf("Warning: Temperature is getting high! Current temperature: %.2lf C\n", temperature);
        }
        sleep(5);
    }
    return 0;
}