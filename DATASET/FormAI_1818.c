//FormAI DATASET v1.0 Category: Temperature Converter ; Style: light-weight
#include <stdio.h>

void clear_input_buffer();

int main() {
    char input;
    double temp, converted_temp;

    do {
        printf("Convert from Celsius (C) or Fahrenheit (F)?: ");
        scanf("%c", &input);
        clear_input_buffer();
    } while (input != 'C' && input != 'c' && input != 'F' && input != 'f');

    if (input == 'C' || input == 'c') {
        printf("Enter temperature in Celsius: ");
        scanf("%lf", &temp);
        clear_input_buffer();
        converted_temp = (temp * 9 / 5) + 32;
        printf("%.1lf C = %.1lf F\n", temp, converted_temp);
    } else {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%lf", &temp);
        clear_input_buffer();
        converted_temp = (temp - 32) * 5 / 9;
        printf("%.1lf F = %.1lf C\n", temp, converted_temp);
    }

    return 0;
}

void clear_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}