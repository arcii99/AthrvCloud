//FormAI DATASET v1.0 Category: Temperature monitor ; Style: real-life
#include <stdio.h>

/* function prototypes */
float get_temperature();
void print_status(float temperature);

int main() {
    float temperature;

    printf("Temperature Monitor\n\n");

    while (1) {
        temperature = get_temperature();
        print_status(temperature);
    }

    return 0;
}

float get_temperature() {
    float temperature;

    /* replace this with actual temperature reading code */
    printf("Enter temperature value: ");
    scanf("%f", &temperature);

    return temperature;
}

void print_status(float temperature) {
    /* some condition to check if temperature is within acceptable range */
    if (temperature < 10.0) {
        printf("Temperature is too low! Action required.\n\n");
    } else if (temperature >= 10.0 && temperature < 20.0) {
        printf("Temperature is in normal range.\n\n");
    } else if (temperature >= 20.0 && temperature < 25.0) {
        printf("Temperature is slightly high.\n\n");
    } else {
        printf("Temperature is too high! Action required.\n\n");
    }
}