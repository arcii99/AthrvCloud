//FormAI DATASET v1.0 Category: Temperature monitor ; Style: romantic
#include <stdio.h>

int main() {
    float temperature;

    printf("My darling, let me check your temperature.\n");
    printf("Please enter the temperature in Celsius: ");
    scanf("%f", &temperature);

    if (temperature < 36.5) {
        printf("Oh my love, you are colder than a winter's day\n");
    } else if (temperature >= 36.5 && temperature < 37.5) {
        printf("My sweet one, your temperature is just perfect\n");
    } else if (temperature >= 37.5 && temperature < 38.5) {
        printf("My dear, it seems your temperature is elevated\n");
    } else if (temperature >= 38.5) {
        printf("Oh no, my love, your temperature is dangerously high\n");
    }

    return 0;
}