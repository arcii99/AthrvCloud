//FormAI DATASET v1.0 Category: Temperature Converter ; Style: recursive
#include <stdio.h>

float fahrToCelsius(float fahr);

int main() {
    float max_fahr = 300;
    float min_fahr = 0;
    float step_fahr = 20;

    printf("Fahr\tCelsius\n");
    printf("---------------\n");

    int i = 0;
    for (float fahr = max_fahr; fahr >= min_fahr; fahr -= step_fahr) {
        printf("%3.0f\t%6.1f\n", fahr, fahrToCelsius(fahr));
    }
}

float fahrToCelsius(float fahr) {
    if (fahr <= 0) {
        return -273.15; // absolute zero
    } else {
        return (5.0 / 9.0) * (fahr - 32) + fahrToCelsius(fahr - 20);
    }
}