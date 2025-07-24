//FormAI DATASET v1.0 Category: Temperature monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TEMP_READINGS 10

int main() {
    int i, num_readings;
    float temp, avg_temp = 0.0;
    char temp_str[20];

    printf("Welcome to the Temperature Monitor!\n\n");

    do {
        printf("Please enter the number of temperature readings (up to 10): ");
        fgets(temp_str, sizeof(temp_str), stdin);
        num_readings = atoi(temp_str);
    } while(num_readings <= 0 || num_readings > MAX_TEMP_READINGS);

    printf("\n");

    for(i = 0; i < num_readings; i++) {
        printf("Reading #%d: ", i+1);
        fgets(temp_str, sizeof(temp_str), stdin);
        temp = atof(temp_str);

        if(temp < -273.15) {
            printf("Invalid temperature entered. Temperature must be above absolute zero.\n\n");
            i--;
        }
        else {
            avg_temp += temp;
        }
    }

    avg_temp /= num_readings;

    printf("\nAverage temperature over %d readings: %.2f\n", num_readings, avg_temp);

    return 0;
}