//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sherlock Holmes-style main function
int main() {
    printf("The game is afoot! Let's solve the mystery of the stock market.\n");
    printf("To begin, enter the number of companies you would like to track: ");

    int numCompanies = 0;
    scanf("%d", &numCompanies); // gather user input for number of companies

    printf("Very well, let's track %d companies.\n", numCompanies);

    char** companyNames = malloc(sizeof(char*) * numCompanies); // array of company names
    double* currentPrices = malloc(sizeof(double) * numCompanies); // array of current stock prices
    double* previousDayPrices = malloc(sizeof(double) * numCompanies); // array of previous day's closing stock prices

    // gather data for each company
    for (int i = 0; i < numCompanies; i++) {
        printf("Please enter the name of company %d: ", i+1);
        companyNames[i] = malloc(sizeof(char) * 50); // allocate memory for the company name
        scanf("%49s", companyNames[i]); // gather input for company name
        printf("Thank you. Please enter the current price of %s: ", companyNames[i]);
        scanf("%lf", &currentPrices[i]); // gather input for current price
        printf("Excellent. And what was the previous day's closing price for %s? ", companyNames[i]);
        scanf("%lf", &previousDayPrices[i]); // gather input for previous day's closing price
    }

    // display results
    printf("\n\nDetective, here are the results of our stock market investigation:\n\n");
    printf("%-20s | %-20s | %-20s\n", "COMPANY NAME", "CURRENT PRICE", "PREVIOUS DAY PRICE");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < numCompanies; i++) {
        printf("%-20s | %-20.2lf | %-20.2lf\n", companyNames[i], currentPrices[i], previousDayPrices[i]);
    }

    // free memory
    for (int i = 0; i < numCompanies; i++) {
        free(companyNames[i]);
    }
    free(companyNames);
    free(currentPrices);
    free(previousDayPrices);

    return 0;
}