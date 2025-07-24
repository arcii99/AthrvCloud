//FormAI DATASET v1.0 Category: Unit converter ; Style: unmistakable
#include <stdio.h>

// Function to convert from km/h to m/s
double kmPerHourToMeterPerSecond(double kmh)
{
    return kmh / 3.6;
}

// Function to convert from m/s to km/h
double meterPerSecondToKmPerHour(double mps)
{
    return mps * 3.6;
}

// Function to convert from miles/h to km/h
double milesPerHourToKmPerHour(double mph)
{
    return mph * 1.60934;
}

// Function to convert from km/h to miles/h
double kmPerHourToMilesPerHour(double kmh)
{
    return kmh / 1.60934;
}

int main()
{
    int choice;
    double input, result;

    printf("Welcome to the Unit Converter\n");

    do {
        printf("\nChoose an option:\n");
        printf("1. Convert km/h to m/s\n");
        printf("2. Convert m/s to km/h\n");
        printf("3. Convert miles/h to km/h\n");
        printf("4. Convert km/h to miles/h\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter speed in km/h: ");
                scanf("%lf", &input);
                result = kmPerHourToMeterPerSecond(input);
                printf("%.2f km/h = %.2f m/s\n", input, result);
                break;

            case 2:
                printf("Enter speed in m/s: ");
                scanf("%lf", &input);
                result = meterPerSecondToKmPerHour(input);
                printf("%.2f m/s = %.2f km/h\n", input, result);
                break;

            case 3:
                printf("Enter speed in miles/h: ");
                scanf("%lf", &input);
                result = milesPerHourToKmPerHour(input);
                printf("%.2f miles/h = %.2f km/h\n", input, result);
                break;

            case 4:
                printf("Enter speed in km/h: ");
                scanf("%lf", &input);
                result = kmPerHourToMilesPerHour(input);
                printf("%.2f km/h = %.2f miles/h\n", input, result);
                break;

            case 5:
                printf("Thank you for using the Unit Converter!\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}