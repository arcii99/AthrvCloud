//FormAI DATASET v1.0 Category: Temperature Converter ; Style: satisfied
#include<stdio.h>

int main(){

    int choice;
    float c_temp, f_temp;

    printf("\t\tTemperature Converter: Celsius to Fahrenheit or Fahrenheit to Celsius\n");
    printf("Enter 1 for Celsius to Fahrenheit or 2 for Fahrenheit to Celsius: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &c_temp);

        f_temp = (c_temp * 9/5) + 32;

        printf("%.2f degree Celsius = %.2f degree Fahrenheit\n", c_temp, f_temp);
    }
    else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &f_temp);

        c_temp = (f_temp - 32) * 5/9;

        printf("%.2f degree Fahrenheit = %.2f degree Celsius\n", f_temp, c_temp);
    }
    else {
        printf("Invalid input. Please enter either 1 or 2\n");
    }

    return 0;
}