//FormAI DATASET v1.0 Category: Unit converter ; Style: realistic
// C program to convert units
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    float input_val, converted_val;
    char input_unit[10], output_unit[10];

    printf("Enter the value to be converted: ");
    scanf("%f", &input_val);
    printf("Enter input unit: ");
    scanf("%s", input_unit);
    printf("Enter output unit: ");
    scanf("%s", output_unit);

    if(strcmp(input_unit, "km") == 0 && strcmp(output_unit, "mi") == 0)
    {
        converted_val = input_val * 0.621371; // kilometer to miles conversion
        printf("%.2f km is equal to %.2f mi\n", input_val, converted_val);
    }
    else if(strcmp(input_unit, "mi") == 0 && strcmp(output_unit, "km") == 0)
    {
        converted_val = input_val * 1.60934; // miles to kilometer conversion
        printf("%.2f mi is equal to %.2f km\n", input_val, converted_val);
    }
    else if(strcmp(input_unit, "m") == 0 && strcmp(output_unit, "ft") == 0)
    {
        converted_val = input_val * 3.28084; // meters to feet conversion
        printf("%.2f m is equal to %.2f ft\n", input_val, converted_val);
    }
    else if(strcmp(input_unit, "ft") == 0 && strcmp(output_unit, "m") == 0)
    {
        converted_val = input_val * 0.3048; // feet to meters conversion
        printf("%.2f ft is equal to %.2f m\n", input_val, converted_val);
    }
    else
    {
        printf("Invalid conversion\n");
    }

    return 0;
}