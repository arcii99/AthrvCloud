//FormAI DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>

int main() {
    float temp_c, temp_f, kg, lbs, km, mi, cm, in;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter a temperature in Celsius: ");
    scanf("%f", &temp_c);
    
    // Celsius to Fahrenheit Conversion Formula
    temp_f = (temp_c * 1.8) + 32;
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temp_c, temp_f);
    
    printf("Enter a weight in kilograms: ");
    scanf("%f", &kg);
    
    // Kilograms to Pounds Conversion Formula
    lbs = kg * 2.20462;
    printf("%.2f kilograms is equal to %.2f pounds.\n", kg, lbs);
    
    printf("Enter a distance in kilometers: ");
    scanf("%f", &km);
    
    // Kilometers to Miles Conversion Formula
    mi = km * 0.621371;
    printf("%.2f kilometers is equal to %.2f miles.\n", km, mi);
    
    printf("Enter a length in centimeters: ");
    scanf("%f", &cm);
    
    // Centimeters to Inches Conversion Formula
    in = cm * 0.393701;
    printf("%.2f centimeters is equal to %.2f inches.\n", cm, in);

    return 0;
}