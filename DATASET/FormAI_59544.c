//FormAI DATASET v1.0 Category: Temperature Converter ; Style: careful
#include <stdio.h>

/* Function to convert Fahrenheit to Celsius */
float f_to_c(float f) {
    return (f - 32) * 5 / 9;
}

/* Function to convert Celsius to Fahrenheit */
float c_to_f(float c) {
    return c * 9 / 5 + 32;
}

int main() {
    float temp;
    char choice;
    
    printf("Welcome to the temperature converter!\n");
    
    do {
        printf("\nWhat type of conversion do you want to make?\n");
        printf("(F)ahrenheit to Celsius\n");
        printf("(C)elsius to Fahrenheit\n");
        printf("(Q)uit the program\n");
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        
        if (choice == 'F' || choice == 'f') {
            printf("\nEnter the temperature in Fahrenheit: ");
            scanf("%f", &temp);
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius\n", temp, f_to_c(temp));
        }
        else if (choice == 'C' || choice == 'c') {
            printf("\nEnter the temperature in Celsius: ");
            scanf("%f", &temp);
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit\n", temp, c_to_f(temp));
        }
        else if (choice == 'Q' || choice == 'q') {
            printf("\nExiting the program...\n");
        }
        else {
            printf("\nInvalid choice, please try again.\n");
        }
        
    } while (choice != 'Q' && choice != 'q');
    
    return 0;
}