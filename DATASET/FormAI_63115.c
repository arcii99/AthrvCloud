//FormAI DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>

/* function prototypes */
double tempConversion(double temp, char fromUnit, char toUnit);
double lengthConversion(double length, char fromUnit, char toUnit);
double massConversion(double mass, char fromUnit, char toUnit);
void displayMenu(void);

/* main function */
int main(void)
{
    char choice;
    double input, output;
    char fromUnit, toUnit;

    do
    {
        displayMenu();
        scanf(" %c", &choice);

        switch (choice)
        {
            case '1':   // temperature conversion
                printf("\nTemperature conversion: \n");
                printf("Enter the temperature: ");
                scanf("%lf", &input);
                printf("Enter the input unit (F/C): ");
                scanf(" %c", &fromUnit);
                printf("Enter the output unit (F/C): ");
                scanf(" %c", &toUnit);
                output = tempConversion(input, fromUnit, toUnit);
                printf("%.2lf %c = %.2lf %c\n", input, fromUnit, output, toUnit);
                break;

            case '2':   // length conversion
                printf("\nLength conversion: \n");
                printf("Enter the length: ");
                scanf("%lf", &input);
                printf("Enter the input unit (M/KM/FT/IN): ");
                scanf(" %c", &fromUnit);
                printf("Enter the output unit (M/KM/FT/IN): ");
                scanf(" %c", &toUnit);
                output = lengthConversion(input, fromUnit, toUnit);
                printf("%.2lf %c = %.2lf %c\n", input, fromUnit, output, toUnit);
                break;

            case '3':   // mass conversion
                printf("\nMass conversion: \n");
                printf("Enter the mass: ");
                scanf("%lf", &input);
                printf("Enter the input unit (KG/G/LB/OZ): ");
                scanf(" %c", &fromUnit);
                printf("Enter the output unit (KG/G/LB/OZ): ");
                scanf(" %c", &toUnit);
                output = massConversion(input, fromUnit, toUnit);
                printf("%.2lf %c = %.2lf %c\n", input, fromUnit, output, toUnit);
                break;

            case '4':   // exit program
                printf("\nThank you for using the converter!\n");
                break;

            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
                break;
        }

    } while (choice != '4');

    return 0;
}

/* function to display the menu */
void displayMenu(void)
{
    printf("\nC Unit Converter\n");
    printf("----------------\n");
    printf("1. Temperature Conversion (Fahrenheit / Celsius)\n");
    printf("2. Length Conversion (Meters / Kilometers / Feet / Inches)\n");
    printf("3. Mass Conversion (Kilograms / Grams / Pounds / Ounces)\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}


/* function for temperature conversion */
double tempConversion(double temp, char fromUnit, char toUnit)
{
    if (fromUnit == 'F' && toUnit == 'C')  // Fahrenheit to Celsius
    {
        return (temp - 32) * 5 / 9;
    }
    else if (fromUnit == 'C' && toUnit == 'F')  // Celsius to Fahrenheit
    {
        return (temp * 9 / 5) + 32;
    }
    else  // invalid conversion
    {
        printf("\nInvalid temperature conversion!\n");
        return -1;
    }
}

/* function for length conversion */
double lengthConversion(double length, char fromUnit, char toUnit)
{
    if (fromUnit == 'M' && toUnit == 'KM')  // meter to kilometer
    {
        return length / 1000;
    }
    else if (fromUnit == 'KM' && toUnit == 'M')  // kilometer to meter
    {
        return length * 1000;
    }
    else if (fromUnit == 'M' && toUnit == 'FT')  // meter to foot
    {
        return length * 3.281;
    }
    else if (fromUnit == 'FT' && toUnit == 'M')  // foot to meter
    {
        return length / 3.281;
    }
    else if (fromUnit == 'FT' && toUnit == 'IN')  // foot to inch
    {
        return length * 12;
    }
    else if (fromUnit == 'IN' && toUnit == 'FT')  // inch to foot
    {
        return length / 12;
    }
    else if (fromUnit == 'KM' && toUnit == 'FT')  // kilometer to foot
    {
        return length * 3281;
    }
    else if (fromUnit == 'FT' && toUnit == 'KM')  // foot to kilometer
    {
        return length / 3281;
    }
    else if (fromUnit == 'KM' && toUnit == 'IN')  // kilometer to inch
    {
        return length * 39370;
    }
    else if (fromUnit == 'IN' && toUnit == 'KM')  // inch to kilometer
    {
        return length / 39370;
    }
    else  // invalid conversion
    {
        printf("\nInvalid length conversion!\n");
        return -1;
    }
}

/* function for mass conversion */
double massConversion(double mass, char fromUnit, char toUnit)
{
    if (fromUnit == 'KG' && toUnit == 'G')  // kilogram to gram
    {
        return mass * 1000;
    }
    else if (fromUnit == 'G' && toUnit == 'KG')  // gram to kilogram
    {
        return mass / 1000;
    }
    else if (fromUnit == 'KG' && toUnit == 'LB')  // kilogram to pound
    {
        return mass * 2.205;
    }
    else if (fromUnit == 'LB' && toUnit == 'KG')  // pound to kilogram
    {
        return mass / 2.205;
    }
    else if (fromUnit == 'KG' && toUnit == 'OZ')  // kilogram to ounce
    {
        return mass * 35.274;
    }
    else if (fromUnit == 'OZ' && toUnit == 'KG')  // ounce to kilogram
    {
        return mass / 35.274;
    }
    else if (fromUnit == 'G' && toUnit == 'LB')  // gram to pound
    {
        return mass * 0.00220462;
    }
    else if (fromUnit == 'LB' && toUnit == 'G')  // pound to gram
    {
        return mass / 0.00220462;
    }
    else if (fromUnit == 'G' && toUnit == 'OZ')  // gram to ounce
    {
        return mass * 0.035274;
    }
    else if (fromUnit == 'OZ' && toUnit == 'G')  // ounce to gram
    {
        return mass / 0.035274;
    }
    else  // invalid conversion
    {
        printf("\nInvalid mass conversion!\n");
        return -1;
    }
}