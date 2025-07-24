//FormAI DATASET v1.0 Category: Temperature Converter ; Style: curious
#include <stdio.h>

int main() {
    printf("Welcome to the curious temperature converter!\n");
    printf("This converter can convert Celsius to Fahrenheit and vice versa!\n");

    float celsius, fahrenheit;

    curious_question();
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9/5) + 32;

    printf("The temperature %.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

    curious_fact(fahrenheit);

    curious_question();
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) * 5/9;

    printf("The temperature %.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);

    curious_fact(celsius);

    return 0;
}

void curious_question() {
    printf("What temperature would you like to convert?\n");
}

void curious_fact(float temperature) {
    if (temperature > 100) {
        printf("Did you know that water boils at this temperature at sea level?\n");
    } else if (temperature < 0) {
        printf("Did you know that this temperature is below freezing point of water at sea level?\n");
    } else {
        printf("Did you know that this temperature is quite pleasant for human beings?\n");
    }
}