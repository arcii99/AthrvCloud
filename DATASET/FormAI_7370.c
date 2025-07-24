//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include<stdio.h>

float CtoF(float c);
float CtoK(float c);

int main(){
    float celsius, fahrenheit, kelvin;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = CtoF(celsius);
    kelvin = CtoK(celsius);

    printf("%.2f°C = %.2f°F\n", celsius, fahrenheit);
    printf("%.2f°C = %.2fK\n", celsius, kelvin);

    return 0;
}

float CtoF(float c){
    float f = (c * 9/5) + 32.0;
    return f;
}

float CtoK(float c){
    float k = c + 273.15;
    return k;
}