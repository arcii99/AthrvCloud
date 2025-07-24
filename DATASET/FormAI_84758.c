//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    float tempC;
    FILE *thermalFile;

    while (1) {
        thermalFile = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
        if (thermalFile == NULL) {
            printf("Error opening temperature file\n");
            exit(1);
        }
        fscanf(thermalFile, "%f", &tempC);
        fclose(thermalFile);

        printf("Current CPU temperature: %.2fC \n", tempC/1000.0);
        sleep(1);
    }
    return 0;
}