//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include <stdio.h>

/* Temperature converter function */
float convert_temperature(float temperature, char unit) {
    if (unit == 'F') {
        return (temperature - 32.0) * 5.0 / 9.0;
    } else if (unit == 'C') {
        return temperature * 9.0 / 5.0 + 32.0;
    } else {
        printf("Invalid unit.\n");
        return 0.0;
    }
}

int main() {
    float temperature;
    char unit;

    printf("Enter the temperature: ");
    scanf("%f %c", &temperature, &unit);

    printf("Temperature in Celsius: %.2f\n", convert_temperature(temperature, unit));

    return 0;
}