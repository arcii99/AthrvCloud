//FormAI DATASET v1.0 Category: Unit converter ; Style: Ada Lovelace
#include<stdio.h>

int main()
{
    float length_cm, length_m, length_km, weight_g, weight_kg, temp_c, temp_f;
    int choice;

    printf("Welcome to the Unit Converter:\n");
    printf("1. Convert Length\n2. Convert Weight\n3. Convert Temperature\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter Length in Centimeters: ");
            scanf("%f", &length_cm);

            length_m = length_cm / 100;
            length_km = length_cm / 100000;

            printf("Length in Meters: %.2f m\n", length_m);
            printf("Length in Kilometers: %.2f km\n", length_km);
            break;

        case 2:
            printf("Enter Weight in Grams: ");
            scanf("%f", &weight_g);

            weight_kg = weight_g / 1000;

            printf("Weight in Kilograms: %.2f kg\n", weight_kg);
            break;

        case 3:
            printf("Enter Temperature in Celsius: ");
            scanf("%f", &temp_c);

            temp_f = (temp_c * 9/5) + 32;

            printf("Temperature in Fahrenheit: %.2f F\n", temp_f);
            break;

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}