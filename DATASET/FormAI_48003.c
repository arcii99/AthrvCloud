//FormAI DATASET v1.0 Category: Unit converter ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

int main(){
    int option;
    float value, output;

    printf("\nChoose an option:");
    printf("\n1. Convert Kilometers to Miles");
    printf("\n2. Convert Miles to Kilometers");
    printf("\n3. Convert Celsius to Fahrenheit");
    printf("\nEnter your choice:");

    scanf("%d", &option);

    switch(option){
        case 1:
            printf("\nEnter kilometers:");
            scanf("%f", &value);
            output = value * 0.621371;
            printf("\n%f kilometers is equal to %f miles", value, output);
            break;

        case 2:
            printf("\nEnter miles:");
            scanf("%f", &value);
            output = value * 1.60934;
            printf("\n%f miles is equal to %f kilometers", value, output);
            break;

        case 3:
            printf("\nEnter Celsius:");
            scanf("%f", &value);
            output = (value * 1.8) + 32;
            printf("\n%f degrees Celsius is equal to %f degrees Fahrenheit", value, output);
            break;

        default:
            printf("\nInvalid choice");
            break;
    }

    return 0;
}