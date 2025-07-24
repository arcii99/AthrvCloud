//FormAI DATASET v1.0 Category: Unit converter ; Style: statistical
#include<stdio.h>

/* This program converts units from metric to imperial and vice versa*/

int main(){

    float input_val, output_val;
    char unit_type;

    printf("Welcome to the Unit Converter Program! \n\n");
    printf("Please enter the input value: ");
    scanf("%f", &input_val);

    printf("Please enter the unit type (m for metric, i for imperial): ");
    scanf(" %c", &unit_type);

    if(unit_type == 'm'){ // if input unit is metric
        printf("\nInput value in metric: %.2f\n", input_val);
        printf("Converted value in imperial: %.2f feet\n", input_val * 3.28);
        output_val = input_val * 3.28;
    }
    else if(unit_type == 'i'){ // if input unit is imperial
        printf("\nInput value in imperial: %.2f feet\n", input_val);
        printf("Converted value in metric: %.2f meters\n", input_val * 0.3048);
        output_val = input_val * 0.3048;
    }
    else{ // if invalid input unit is entered
        printf("Invalid unit type! Please enter 'm' for metric or 'i' for imperial. \n");
        return 0;
    }

    printf("\nThank you for using the Unit Converter Program! \n\n");
    printf("The input value was: %.2f\n", input_val);
    printf("The converted value is: %.2f \n", output_val);

    return 0;
}