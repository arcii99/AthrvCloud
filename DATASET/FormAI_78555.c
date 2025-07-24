//FormAI DATASET v1.0 Category: Temperature Converter ; Style: ultraprecise
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    printf("This program converts temperatures from Celsius to Fahrenheit.\n");

    // keep running until the user wants to exit
    while (1) {
        printf("\nEnter temperature in Celsius (or type 'exit' to end the program): ");
        char input[10];
        scanf("%s", input); // get user input

        // check if user wants to exit
        if (strcmp(input, "exit") == 0) {
            printf("\nExiting program...");
            break;
        }

        // convert input to float
        celsius = atof(input);

        // calculate Fahrenheit equivalent
        fahrenheit = (celsius * (9.0 / 5.0)) + 32.0;

        // print output
        printf("%.1f degrees Celsius is equal to %.1f degrees Fahrenheit.\n", celsius, fahrenheit);
    }

    return 0;
}