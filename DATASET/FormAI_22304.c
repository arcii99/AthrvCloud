//FormAI DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>

int main() {
    float temp;
    printf("Welcome to the temperature monitor!\n");
    printf("Please enter the current temperature in Celsius: ");
    scanf("%f", &temp);
    printf("\n");

    if(temp < -273.15) {
        printf("Invalid input. Temperature cannot be below absolute zero.\n");
    }
    else if(temp < 0) {
        printf("Brrr, it's cold outside! The temperature is %.2f degrees Celsius.\n", temp);
    }
    else if(temp >= 0 && temp < 20) {
        printf("It's getting warmer! The temperature is %.2f degrees Celsius.\n", temp);
    }
    else if(temp >= 20 && temp < 30) {
        printf("It's a nice day! The temperature is %.2f degrees Celsius.\n", temp);
    }
    else if(temp >= 30 && temp < 40) {
        printf("It's getting hot! The temperature is %.2f degrees Celsius.\n", temp);
    }
    else {
        printf("Wow, it's really hot outside! The temperature is %.2f degrees Celsius.\n", temp);
    }

    return 0;
}