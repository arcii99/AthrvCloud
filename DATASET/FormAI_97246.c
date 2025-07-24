//FormAI DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int option = 0;
    float temp, length, weight;
    printf("Welcome to the Multivariable Unit Converter!\n\n");

    while(option != 4) {
        printf("Please select an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Feet to Meters\n");
        printf("3. Pounds to Kilograms\n");
        printf("4. Exit\n");

        scanf("%d",&option);

        switch(option) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f",&temp);
                printf("%.2f Celsius is %.2f Fahrenheit\n\n",temp,((9.0/5.0)*temp)+32);
                 break;
            case 2:
                printf("Enter length in feet: ");
                scanf("%f",&length);
                printf("%.2f feet is %.2f meters\n\n",length,length/3.281);
                break;
            case 3:
                printf("Enter weight in pounds: ");
                scanf("%f",&weight);
                printf("%.2f pounds is %.2f kilograms\n\n",weight,weight/2.205);
                 break;
            case 4:
                printf("Exiting Multivariable Unit Converter....\n");
                exit(0);
            default:
                printf("Invalid option selected, please try again\n\n");
        }
    }
    return 0;
}