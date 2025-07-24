//FormAI DATASET v1.0 Category: Temperature monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TEMP 150

bool is_valid_temp(float temp) {
    if (temp < -273.15 || temp > MAX_TEMP) {
        return false;
    }
    return true;
}

void print_warning() {
    printf("Warning: Temperature out of acceptable range (-273.15 to %d)\n", MAX_TEMP);
}

int main() {
    float temperature;
    char input[10];
    bool valid_input = false;

    printf("Welcome to the Temperature Monitor!\n");

    while (!valid_input) {
        printf("Please enter the temperature in Celsius: ");
        fgets(input, 10, stdin);
        int len = strlen(input);
        if (input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        temperature = atof(input);
        valid_input = is_valid_temp(temperature);
        if (!valid_input) {
            print_warning();
        }
    }

    printf("The temperature is %.2f degrees Celsius.\n", temperature);

    return 0;
}