//FormAI DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>

int main() {

    /* This program calculates the average electricity consumption of a household */

    float currentReading, prevReading, avgConsumption; // variables for current and previous readings, and average consumption
    int numMonths; // variable for number of months

    // prompt the user for inputs
    printf("Enter the current reading for electricity meter: ");
    scanf("%f", &currentReading);

    printf("Enter the previous reading for electricity meter: ");
    scanf("%f", &prevReading);

    printf("Enter the number of months for which bills are being calculated: ");
    scanf("%d", &numMonths);

    // calculate the total units consumed and average consumption
    float totalUnits = currentReading - prevReading;
    avgConsumption = totalUnits / numMonths;

    // check if the average consumption is within acceptable range
    if (avgConsumption <= 300) {
        printf("Your average electricity consumption is %.2f units per month, which is within acceptable range.\n", avgConsumption);
    } else {
        printf("Your average electricity consumption is %.2f units per month, which is higher than the acceptable range.\n", avgConsumption);
    }

    // calculate the total bill amount
    float totalAmount = totalUnits * 6.5; // assuming a rate of Rs. 6.5 per unit

    // check if the bill amount is within acceptable range
    if (totalAmount <= 5000) {
        printf("Your total bill amount for %d months is Rs. %.2f, which is within acceptable range.\n", numMonths, totalAmount);
    } else {
        printf("Your total bill amount for %d months is Rs. %.2f, which is higher than the acceptable range.\n", numMonths, totalAmount);
    }

    return 0;
}