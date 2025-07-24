//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {
    float temperature;
    int count = 0;
    FILE *fptr;

    if ((fptr = fopen("temperature_log.txt", "w")) == NULL) {
        printf("Error! unable to create file");
        exit(1);
    }

    printf("Welcome to the temperature monitoring system!\n");
    printf("Please input the current temperature in Celsius: ");

    while (1) {
        scanf("%f", &temperature);

        if (temperature < -273.15) {
            printf("Invalid temperature! Kelvin scale has no values below -273.15C.\n");
            printf("Please input the current temperature in Celsius: ");
            continue;
        }

        fprintf(fptr, "%f\n", temperature);
        count++;

        if (count == 10) {
            break;
        }

        printf("Temperature logged! Please input the current temperature in Celsius: ");
    }

    printf("Temperature monitoring complete! %d temperatures logged. Press any key to exit.", count);

    fclose(fptr);

    return 0;
}