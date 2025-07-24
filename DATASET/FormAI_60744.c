//FormAI DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choiceFrom, choiceTo;
    double inputValue, outputValue;

    // Display the menu
    printf("Choose the type of value to be converted:\n");
    printf("1. Length\n2. Mass\n3. Temperature\n4. Exit\n");

    // Get the user's choice
    int menuChoice;
    scanf("%d", &menuChoice);

    // Handle the user's choice
    switch (menuChoice)
    {
        case 1:
            printf("\nLength Menu\n");
            printf("1. Millimeter\n2. Centimeter\n3. Meter\n4. Kilometer\n");

            scanf("%d", &choiceFrom);

            printf("Enter the value to be converted: ");
            scanf("%lf", &inputValue);

            printf("Choose the type of length to convert to:\n");
            printf("1. Millimeter\n2. Centimeter\n3. Meter\n4. Kilometer\n");

            scanf("%d", &choiceTo);

            // Convert from millimeters
            switch (choiceFrom)
            {
                case 1:
                    switch (choiceTo)
                    {
                        case 1:
                            outputValue = inputValue;
                            break;
                        case 2:
                            outputValue = inputValue / 10;
                            break;
                        case 3:
                            outputValue = inputValue / 1000;
                            break;
                        case 4:
                            outputValue = inputValue / 1000000;
                            break;
                        default:
                            printf("Invalid choice.\n");
                            exit(1);
                    }
                    break;
                // Convert from centimeters
                case 2:
                    switch (choiceTo)
                    {
                        case 1:
                            outputValue = inputValue * 10;
                            break;
                        case 2:
                            outputValue = inputValue;
                            break;
                        case 3:
                            outputValue = inputValue / 100;
                            break;
                        case 4:
                            outputValue = inputValue / 100000;
                            break;
                        default:
                            printf("Invalid choice.\n");
                            exit(1);
                    }
                    break;
                // Convert from meters
                case 3:
                    switch (choiceTo)
                    {
                        case 1:
                            outputValue = inputValue * 1000;
                            break;
                        case 2:
                            outputValue = inputValue * 100;
                            break;
                        case 3:
                            outputValue = inputValue;
                            break;
                        case 4:
                            outputValue = inputValue / 1000;
                            break;
                        default:
                            printf("Invalid choice.\n");
                            exit(1);
                    }
                    break;
                // Convert from kilometers
                case 4:
                    switch (choiceTo)
                    {
                        case 1:
                            outputValue = inputValue * 1000000;
                            break;
                        case 2:
                            outputValue = inputValue * 100000;
                            break;
                        case 3:
                            outputValue = inputValue * 1000;
                            break;
                        case 4:
                            outputValue = inputValue;
                            break;
                        default:
                            printf("Invalid choice.\n");
                            exit(1);
                    }
                    break;
                default:
                    printf("Invalid choice.\n");
                    exit(1);
            }
            printf("%.4lf\n", outputValue);
            break;

        // Mass menu
        case 2:
            printf("\nMass Menu\n");
            printf("1. Grams\n2. Kilograms\n3. Pounds\n4. Ounces\n");

            scanf("%d", &choiceFrom);

            printf("Enter the value to be converted: ");
            scanf("%lf", &inputValue);

            printf("Choose the type of mass to convert to:\n");
            printf("1. Grams\n2. Kilograms\n3. Pounds\n4. Ounces\n");

            scanf("%d", &choiceTo);

            // Convert from grams
            switch (choiceFrom)
            {
                case 1:
                    switch (choiceTo)
                    {
                        case 1:
                            outputValue = inputValue;
                            break;
                        case 2:
                            outputValue = inputValue / 1000;
                            break;
                        case 3:
                            outputValue = inputValue * 0.00220462;
                            break;
                        case 4:
                            outputValue = inputValue * 0.035274;
                            break;
                        default:
                            printf("Invalid choice.\n");
                            exit(1);
                    }
                    break;
                // Convert from kilograms
                case 2:
                    switch (choiceTo)
                    {
                        case 1:
                            outputValue = inputValue * 1000;
                            break;
                        case 2:
                            outputValue = inputValue;
                            break;
                        case 3:
                            outputValue = inputValue * 2.20462;
                            break;
                        case 4:
                            outputValue = inputValue * 35.274;
                            break;
                        default:
                            printf("Invalid choice.\n");
                            exit(1);
                    }
                    break;
                // Convert from pounds
                case 3:
                    switch (choiceTo)
                    {
                        case 1:
                            outputValue = inputValue / 0.00220462;
                            break;
                        case 2:
                            outputValue = inputValue / 2.20462;
                            break;
                        case 3:
                            outputValue = inputValue;
                            break;
                        case 4:
                            outputValue = inputValue * 16;
                            break;
                        default:
                            printf("Invalid choice.\n");
                            exit(1);
                    }
                    break;
                // Convert from ounces
                case 4:
                    switch (choiceTo)
                    {
                        case 1:
                            outputValue = inputValue / 0.035274;
                            break;
                        case 2:
                            outputValue = inputValue / 35.274;
                            break;
                        case 3:
                            outputValue = inputValue / 16;
                            break;
                        case 4:
                            outputValue = inputValue;
                            break;
                        default:
                            printf("Invalid choice.\n");
                            exit(1);
                    }
                    break;
                default:
                    printf("Invalid choice.\n");
                    exit(1);
            }
            printf("%.4lf\n", outputValue);
            break;

        // Temperature menu
        case 3:
            printf("\nTemperature Menu\n");
            printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n");

            scanf("%d", &choiceFrom);

            printf("Enter the value to be converted: ");
            scanf("%lf", &inputValue);

            printf("Choose the type of temperature to convert to:\n");
            printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n");

            scanf("%d", &choiceTo);

            // Convert from Celsius
            switch (choiceFrom)
            {
                case 1:
                    switch (choiceTo)
                    {
                        case 1:
                            outputValue = inputValue;
                            break;
                        case 2:
                            outputValue = (inputValue * 1.8) + 32;
                            break;
                        case 3:
                            outputValue = inputValue + 273.15;
                            break;
                        default:
                            printf("Invalid choice.\n");
                            exit(1);
                    }
                    break;
                // Convert from Fahrenheit
                case 2:
                    switch (choiceTo)
                    {
                        case 1:
                            outputValue = (inputValue - 32) * (5.0/9.0);
                            break;
                        case 2:
                            outputValue = inputValue;
                            break;
                        case 3:
                            outputValue = (inputValue + 459.67) * (5.0/9.0);
                            break;
                        default:
                            printf("Invalid choice.\n");
                            exit(1);
                    }
                    break;
                // Convert from Kelvin
                case 3:
                    switch (choiceTo)
                    {
                        case 1:
                            outputValue = inputValue - 273.15;
                            break;
                        case 2:
                            outputValue = (inputValue * 1.8) - 459.67;
                            break;
                        case 3:
                            outputValue = inputValue;
                            break;
                        default:
                            printf("Invalid choice.\n");
                            exit(1);
                    }
                    break;
                default:
                    printf("Invalid choice.\n");
                    exit(1);
            }
            printf("%.4lf\n", outputValue);
            break;

        // Exit the program
        case 4:
            printf("Goodbye.\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
            exit(1);
    }

    return 0;
}