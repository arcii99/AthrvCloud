//FormAI DATASET v1.0 Category: Temperature Converter ; Style: excited
#include <stdio.h>

int main() {

//welcome message

printf("Hello and Welcome to the Exciting Celsius Temperature Converter Program!\n\n");

//asking input in Celsius

printf("Please enter a temperature in Celsius: ");
float tempCelsius;
scanf("%f", &tempCelsius);
printf("\n");

//calculating Fahrenheit

float tempFahrenheit = (tempCelsius * 9/5) + 32;
printf("The temperature in Fahrenheit is %.2fF\n\n", tempFahrenheit);

//introducing a twist!

printf("But hold on...we are not done yet!\n\n");

//asking input in Fahrenheit

printf("Now, let's convert it back to Celsius. Please enter a temperature in Fahrenheit: ");
float tempFahrenheit2;
scanf("%f", &tempFahrenheit2);
printf("\n");

//calculating Celsius

float tempCelsius2 = (tempFahrenheit2 - 32) * 5/9;
printf("The temperature in Celsius is %.2fC\n\n", tempCelsius2);

//adding some fun

printf("Woohoo! We did it! Converting temperatures like a pro! Are you excited? I am!\n");

//program end

return 0;
}