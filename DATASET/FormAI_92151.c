//FormAI DATASET v1.0 Category: Temperature Converter ; Style: excited
#include<stdio.h>

int main()
{
    printf("Welcome to the exciting Temperature Converter!\n");
    printf("Enter 1 for converting Celsius to Fahrenheit\n");
    printf("Enter 2 for converting Fahrenheit to Celsius\n");
    
    int choice;
    scanf("%d",&choice);
    
    if(choice==1)
    {
        float cel, fah;
        printf("Enter temperature in Celsius: ");
        scanf("%f",&cel);
        fah = (cel * 9/5) + 32;
        printf("Temperature in Fahrenheit = %f°F\n", fah);
    }
    else if(choice==2)
    {
        float fah, cel;
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f",&fah);
        cel = (fah - 32) * 5/9;
        printf("Temperature in Celsius = %f°C\n", cel);
    }
    else
    {
        printf("Invalid choice entered. Please enter either 1 or 2.\n");
    }
    
    printf("Thank you for using the exciting Temperature Converter!");
    return 0;
}