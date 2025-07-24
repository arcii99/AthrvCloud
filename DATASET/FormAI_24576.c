//FormAI DATASET v1.0 Category: Temperature Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float celsius;
    float fahrenheit;
    int is_celsius;
} Temperature;

Temperature* create_temperature(float temperature, int is_celsius) {
    Temperature* new_temperature = (Temperature*) malloc(sizeof(Temperature));
    if (is_celsius) {
        new_temperature->celsius = temperature;
        new_temperature->fahrenheit = temperature * 1.8 + 32;
    } else {
        new_temperature->fahrenheit = temperature;
        new_temperature->celsius = (temperature - 32) / 1.8;
    }
    new_temperature->is_celsius = is_celsius;
    return new_temperature;
}

void convert_temperature(Temperature* temperature, int target_unit) {
    if ((target_unit == 0 && temperature->is_celsius) || (target_unit == 1 && !temperature->is_celsius)) {
        return;
    }
    if (target_unit == 0) {
        temperature->is_celsius = 1;
        temperature->celsius = (temperature->fahrenheit - 32) / 1.8;
    } else {
        temperature->is_celsius = 0;
        temperature->fahrenheit = temperature->celsius * 1.8 + 32;
    }
}

int main() {
    float temperature_value = 0;
    int is_celsius = 0;
    printf("Enter temperature value: ");
    scanf("%f", &temperature_value);
    printf("Enter unit (0 for Celsius, 1 for Fahrenheit): ");
    scanf("%d", &is_celsius);
    Temperature* temperature = create_temperature(temperature_value, is_celsius);
    printf("Temperature value: %.2f, Unit: %s\n", is_celsius ? temperature->celsius : temperature->fahrenheit, is_celsius ? "Celsius" : "Fahrenheit");
    convert_temperature(temperature, is_celsius ? 1 : 0);
    printf("Converted temperature value: %.2f, Unit: %s\n", is_celsius ? temperature->fahrenheit : temperature->celsius, is_celsius ? "Fahrenheit" : "Celsius");
    free(temperature);
    return 0;
}