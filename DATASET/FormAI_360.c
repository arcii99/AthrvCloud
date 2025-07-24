//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shocked
#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("Please enter the temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 1.8) + 32;

    printf("\n%f degrees Celsius is %f degrees Fahrenheit\n", celsius, fahrenheit);

    if(fahrenheit > 100) {
        printf("Oh my god, it's boiling out there! Stay hydrated and keep cool!\n");
    } else if(fahrenheit > 80) {
        printf("Wow, it's really hot. Make sure to drink plenty of water.\n");
    } else if(fahrenheit < 32) {
        printf("Brrr, it's freezing outside! Bundle up!\n");
    } else if(fahrenheit < 60) {
        printf("It's a bit chilly, but still nice outside. Bring a light jacket.\n");
    } else {
        printf("The temperature is just right. Enjoy your day!\n");
    }

    return 0;
}