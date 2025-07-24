//FormAI DATASET v1.0 Category: Temperature monitor ; Style: high level of detail
#include <stdio.h>

int main() {
    float temp;
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &temp);
    if (temp < -273.15) {
        printf("Invalid temperature: temperature cannot be less than -273.15\n");
    }
    else {
        float fahrenheit = (temp * 9 / 5) + 32;
        printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
        if (temp < 0) {
            printf("It is freezing cold!\n");
        }
        else if (temp < 10) {
            printf("It is very cold\n");
        }
        else if (temp < 20) {
            printf("It is cold\n");
        }
        else if (temp < 30) {
            printf("It is warm\n");
        }
        else {
            printf("It is hot\n");
        }
    }
    return 0;
}