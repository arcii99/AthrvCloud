//FormAI DATASET v1.0 Category: Temperature monitor ; Style: happy
#include<stdio.h>

int main() {
    printf("Hello! Welcome to the Temperature Monitor Program!\n");
    float temperature;
    int isFahrenheit;
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &temperature);
    printf("Is the temperature in Fahrenheit? (0 for no, 1 for yes): ");
    scanf("%d", &isFahrenheit);
    if(isFahrenheit == 1) {
        temperature = ((temperature - 32) * 5) / 9;
    }
    if(temperature >= 28) {
        printf("Wow, it's hot outside! Don't forget to drink water!\n");
    }
    else if(temperature <= 5) {
        printf("Oh no, it's freezing outside! Make sure to wear warm clothes! \n");
    }
    else {
        printf("The temperature outside is just perfect! Enjoy your day! \n");
    }
    return 0;
}