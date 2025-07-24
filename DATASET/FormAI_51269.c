//FormAI DATASET v1.0 Category: Temperature Converter ; Style: secure
#include <stdio.h>

int main() {
    float temp;
    char choice;

    printf("Enter the temperature:\n");
    scanf("%f", &temp);

    printf("Is the temperature in Celsius (C) or Fahrenheit (F)?\n");
    scanf("%s", &choice);

    if (choice == 'C' || choice == 'c') {
        float f = (temp * 9/5) + 32;
        printf("Temperature in Fahrenheit: %.2fF\n", f);
    }
    else if (choice == 'F' || choice == 'f') {
        float c = (temp - 32) * 5/9;
        printf("Temperature in Celsius: %.2fC\n", c);
    }
    else {
        printf("Invalid input. Please enter 'C' for Celsius or 'F' for Fahrenheit.\n");
    }

    return 0;
}