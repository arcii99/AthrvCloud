//FormAI DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>

int main(){
    int choice;
    float value,result;

    printf("\nWelcome to the Unit Converter");
    printf("\n----------------------------\n");

    printf("\n1. Length Conversion (meters to feet)");
    printf("\n2. Temperature Conversion (celsius to fahrenheit)");
    printf("\n3. Volume Conversion (liters to gallons)");
    printf("\nSelect a conversion type (1/2/3): ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("\nEnter the value to convert (meters): ");
            scanf("%f",&value);
            result = value * 3.281;
            printf("%.2f meters = %.2f feet\n",value,result);
            break;

        case 2:
            printf("\nEnter the value to convert (celsius): ");
            scanf("%f",&value);
            result = (value * 9/5) + 32;
            printf("%.2f celsius = %.2f fahrenheit\n",value,result);
            break;

        case 3:
            printf("\nEnter the value to convert (liters): ");
            scanf("%f",&value);
            result = value * 0.264172;
            printf("%.2f liters = %.2f gallons\n",value,result);
            break;

        default:
            printf("Invalid choice. Please select 1/2/3 only.");
    }

    printf("\nThank you for using the Unit Converter!");
    return 0;
}