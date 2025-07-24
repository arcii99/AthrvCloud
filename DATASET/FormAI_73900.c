//FormAI DATASET v1.0 Category: Temperature Converter ; Style: intelligent
#include <stdio.h>

float farenToCel(float faren);
float celToFaren(float cel);

int main() {
    float temp;
    char unit;

    printf("Enter the temperature with unit (c/f): ");
    scanf("%f%c", &temp, &unit);

    if (unit == 'c' || unit == 'C') { // if input temperature is in Celsius
        float faren = celToFaren(temp); // convert Celsius to Fahrenheit
        printf("%.2fC is equivalent to %.2fF", temp, faren);
    }
    else if (unit == 'f' || unit == 'F') { // if input temperature is in Fahrenheit
        float cel = farenToCel(temp); // convert Fahrenheit to Celsius
        printf("%.2fF is equivalent to %.2fC", temp, cel);
    }
    else { // if input temperature is neither in Celsius nor in Fahrenheit
        printf("Invalid input unit! Please enter temperature unit as c or f.");
    }

    return 0; // exit the program
}

float celToFaren(float cel) {
    float faren = (cel * 9 / 5) + 32; // formula for Celsius to Fahrenheit conversion
    return faren; // return the converted temperature
}

float farenToCel(float faren) {
    float cel = (faren - 32) * 5 / 9; // formula for Fahrenheit to Celsius conversion
    return cel; // return the converted temperature
}