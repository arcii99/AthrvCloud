//FormAI DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>

int main()
{
    int option;
    printf("Select an option: \n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &option);
    float temp;
    switch (option) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp);
            printf("%.2f Celsius is %.2f Fahrenheit\n", temp, (temp * 9/5) + 32);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp);
            printf("%.2f Fahrenheit is %.2f Celsius\n", temp, (temp - 32) * 5/9);
            break;
        default:
            printf("Invalid option\n");
    }
    return 0;
}