//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: immersive
#include<stdio.h>
#include<math.h>

#define PI 3.14159265

int main()
{
    // Welcome message
    printf("Hello and welcome to the Circuit Simulator!\n");

    // Variables for user input
    char choice = ' ';
    int resistor = 0;
    int capacitor = 0;
    int voltage = 0;

    // Loop for user input
    while(choice != 'q') {
        // Display menu
        printf("\nPlease choose an option:\n");
        printf("a. Calculate current through resistor\n");
        printf("b. Calculate voltage across capacitor\n");
        printf("q. Quit\n");

        // Read user input
        scanf(" %c", &choice);

        // Switch statement for menu options
        switch(choice) {
            case 'a':
                // Prompt user for resistor value and voltage
                printf("\nEnter resistor value in ohms: ");
                scanf("%d", &resistor);
                printf("Enter voltage in volts: ");
                scanf("%d", &voltage);

                // Calculate current through resistor
                double current = (double) voltage / resistor;
                printf("\nThe current through the resistor is: %.2f amperes\n", current);

                break;

            case 'b':
                // Prompt user for capacitor value and voltage
                printf("\nEnter capacitor value in microfarads: ");
                scanf("%d", &capacitor);
                printf("Enter voltage in volts: ");
                scanf("%d", &voltage);

                // Convert capacitor value to farads
                double farads = (double) capacitor / 1000000;

                // Calculate voltage across capacitor
                double voltageCapacitor = voltage * (1 - exp(-(1 / (farads * 1000 * 1e-6) * 1e-3) / (50 * PI)));

                printf("\nThe voltage across the capacitor is: %.2f volts\n", voltageCapacitor);

                break;

            case 'q':
                // Quit program
                printf("\nThank you for using the Circuit Simulator!\n");
                break;

            default:
                // Prompt user for valid input
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}