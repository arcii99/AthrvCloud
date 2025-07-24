//FormAI DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
#include<stdio.h>

int main()
{
    float cel, fah;
    int choice;
    printf("\n\t\tTemperature Converter\n");
    printf("\n\tEnter your choice:\n\t1. Celsius to Fahrenheit\n\t2. Fahrenheit to Celsius\n\t3. Exit\n\tChoice: ");
    scanf("%d", &choice);
    printf("\n");
    switch(choice)
    {
        case 1: printf("Enter temperature in Celsius: ");
                scanf("%f", &cel);
                fah = (cel*9/5) + 32;
                printf("%.2f Celsius = %.2f Fahrenheit\n", cel, fah);
                break;
        case 2: printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &fah);
                cel = (fah-32)*5/9;
                printf("%.2f Fahrenheit = %.2f Celsius\n", fah, cel);
                break;
        case 3: return 0;
        default: printf("Invalid Choice!\n");
    }
    printf("\n\n");
    main(); //recursive call for main function to keep the program running
    return 0;
}