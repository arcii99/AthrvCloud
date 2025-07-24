//FormAI DATASET v1.0 Category: Unit converter ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float number;
    int choice;
    printf("Enter the number you want to convert: ");
    scanf("%f", &number);
    printf("Select the corresponding input unit\n");
    printf("1: Celsius\n2: Fahrenheit\n3: Kelvin\n4: Miles\n5: Kilometers\n6: Meters\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("%.2f Celsius is equivalent to %.2f Fahrenheit and %.2f Kelvin\n", number, (number*1.8)+32, number+273.15);
            break;
        case 2:
            printf("%.2f Fahrenheit is equivalent to %.2f Celsius and %.2f Kelvin\n", number, (number-32)/1.8, (number+459.67)/1.8);
            break;
        case 3:
            printf("%.2f Kelvin is equivalent to %.2f Celsius and %.2f Fahrenheit\n", number, number-273.15, (number*1.8)-459.67);
            break;
        case 4:
            printf("%.2f Miles is equivalent to %.2f Kilometers and %.2f Meters\n", number, number*1.609, number*1609.344);
            break;
        case 5:
            printf("%.2f Kilometers is equivalent to %.2f Miles and %.2f Meters\n", number, number*0.6214, number*1000);
            break;
        case 6:
            printf("%.2f Meters is equivalent to %.2f Miles and %.2f Kilometers\n", number, number*0.000621, number/1000);
            break;
        default:
            printf("Invalid choice entered\n");
    }

    return 0;
}