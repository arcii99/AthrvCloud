//FormAI DATASET v1.0 Category: Unit converter ; Style: detailed
#include<stdio.h>

int main()
{
    int choice;
    float value;
    printf("*********Unit Converter*********\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("5. Exit\n");
    printf("Enter the conversion type (1-5): ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &value);
            printf("%.2f degree Celsius is equal to %.2f degree Fahrenheit.", value, ((9*value)/5)+32);
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &value);
            printf("%.2f degree Fahrenheit is equal to %.2f degree Celsius.", value, (5*(value-32))/9);
            break;
        case 3:
            printf("Enter the distance in Kilometers: ");
            scanf("%f", &value);
            printf("%.2f Kilometers is equal to %.2f Miles.", value, value/1.609);
            break;
        case 4:
            printf("Enter the distance in Miles: ");
            scanf("%f", &value);
            printf("%.2f Miles is equal to %.2f Kilometers.", value, value*1.609);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}