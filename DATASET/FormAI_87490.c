//FormAI DATASET v1.0 Category: Educational ; Style: interoperable
#include <stdio.h>

// function prototypes
void printMenu();
double convertToFahrenheit(double);
double convertToCelsius(double);
double determineWindChill(double, double);

// main function
int main() {
    int choice;
    double temp, windSpeed, result;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temp);
                result = convertToFahrenheit(temp);
                printf("Temperature in Fahrenheit: %.2lf degrees.\n", result);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temp);
                result = convertToCelsius(temp);
                printf("Temperature in Celsius: %.2lf degrees.\n", result);
                break;
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temp);
                printf("Enter wind speed in meters per second: ");
                scanf("%lf", &windSpeed);
                result = determineWindChill(temp, windSpeed);
                printf("Wind chill: %.2lf degrees Celsius.\n", result);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
    return 0;
}

// function to print menu options
void printMenu() {
    printf("\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Calculate wind chill\n");
    printf("4. Quit\n");
    printf("\n");
}

// function to convert temperature from Celsius to Fahrenheit
double convertToFahrenheit(double temp) {
    double result = (temp * 9/5) + 32;
    return result;
}

// function to convert temperature from Fahrenheit to Celsius
double convertToCelsius(double temp) {
    double result = (temp - 32) * 5/9;
    return result;
}

// function to determine wind chill
double determineWindChill(double temp, double windSpeed) {
    double result = 13.12 + (0.6215 * temp) - (11.37 * pow(windSpeed, 0.16)) + (0.3965 * temp * pow(windSpeed, 0.16));
    return result;
}