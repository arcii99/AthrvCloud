//FormAI DATASET v1.0 Category: Unit converter ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

void main(){
    int option;
    float value;
    printf("Welcome to the Unit Converter!\n");
    while(1){
        printf("\nSelect an option:\n1. Meter to Feet\n2. Fahrenheit to Celsius\n3. Gallons to Liters\n4. Exit\n");
        scanf("%d", &option);
        if(option == 4){
            printf("Thanks for using the Unit Converter!\n");
            exit(0);
        }
        printf("Enter the value to be converted: ");
        scanf("%f", &value);
        switch(option){
            case 1: 
                printf("%.2f meters is equal to %.2f feet\n", value, value * 3.28084);
                break;
            case 2:
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", value, (value - 32) * (5.0/9.0));
                break;
            case 3:
                printf("%.2f gallons is equal to %.2f liters\n", value, value * 3.78541);
                break;
            default:
                printf("Invalid option selected\n");
                break;
        }
    }
}