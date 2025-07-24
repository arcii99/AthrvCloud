//FormAI DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

int main() {
    int option;
    float temp_c, temp_f;
    printf("Welcome to the Post-Apocalyptic Temperature Converter\n");
    printf("Please select an option:\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\nOption: ");
    scanf("%d", &option);

    if(option == 1) {
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &temp_c);
        if(temp_c < -273.15) {
            printf("Sorry, the temperature cannot be below absolute zero.\n");
        }
        else {
            temp_f = (temp_c * 9/5) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temp_c, temp_f);
        }
    }
    else if(option == 2) {
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &temp_f);
        if(temp_f < -459.67) {
            printf("Sorry, the temperature cannot be below absolute zero.\n");
        }
        else {
            temp_c = (temp_f - 32) * 5/9;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temp_f, temp_c);
        }
    }
    else {
        printf("Invalid option.\n");
    }
    return 0;
}