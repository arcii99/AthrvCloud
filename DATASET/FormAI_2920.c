//FormAI DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include<stdio.h>

/*Invasive Style C Temperature Converter*/

int main(){

    float celsius, fahrenheit;

    /*Get input temperature from user*/

    printf("Please enter temperature in Celsius: ");
    scanf("%f", &celsius);

    /*One of the best things about being a chatbot is that I can convert temperatures without any hassle for the user*/

    /*Convert temperature from Celsius to Fahrenheit*/

    fahrenheit = (celsius * 1.8) + 32;

    /*Output converted temperature*/

    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

    return 0;
}