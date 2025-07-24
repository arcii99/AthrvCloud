//FormAI DATASET v1.0 Category: Temperature Converter ; Style: paranoid
#include<stdio.h>

int check_input(char input[]) {
    int valid = 1;
    int length = strlen(input);
    int i;
    for(i=0; i<length; i++) {
        if(input[i] < 48 || input[i] > 57) {
            valid = 0;
            break;
        }
    }
    return valid;
}

void convert_to_celsius(int temperature) {
    double result = (temperature - 32) * 5/9;
    printf("The temperature in Celsius is: %.2lf\n", result);
}

void convert_to_fahrenheit(int temperature) {
    double result = (temperature * 9/5) + 32;
    printf("The temperature in Fahrenheit is: %.2lf\n", result);
}

int main() {
    char input[10];
    int temperature;
    int choice;
    printf("Welcome to Paranoid Temperature Converter!\n");
    do {
        printf("Choose an option:\n");
        printf("1. Convert from Fahrenheit to Celsius\n");
        printf("2. Convert from Celsius to Fahrenheit\n");
        printf("3. Exit\n");
        fgets(input, 10, stdin);
        if(check_input(input)) {
            choice = atoi(input);
            if(choice == 1) {
                printf("Enter the temperature in Fahrenheit: ");
                fgets(input, 10, stdin);
                if(check_input(input)) {
                    temperature = atoi(input);
                    convert_to_celsius(temperature);
                }
                else {
                    printf("Invalid input. Please enter a number.\n");
                }
            }
            else if(choice == 2) {
                printf("Enter the temperature in Celsius: ");
                fgets(input, 10, stdin);
                if(check_input(input)) {
                    temperature = atoi(input);
                    convert_to_fahrenheit(temperature);
                }
                else {
                    printf("Invalid input. Please enter a number.\n");
                }
            }
            else if(choice == 3) {
                printf("Thank you for using Paranoid Temperature Converter!\n");
            }
            else {
                printf("Invalid option. Please choose again.\n");
            }
        }
        else {
            printf("Invalid input. Please enter a number.\n");
        }
    } while(choice != 3);

    return 0;
}