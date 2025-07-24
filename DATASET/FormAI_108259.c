//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <string.h>
#include <time.h>

// Function to calculate the future date according to the user's input
void calculateFutureDate(int years, int months, int days, struct tm current_date, struct tm *future_date) {
    time_t current = mktime(&current_date);
    time_t future = current + (years * 365 + months * 30 + days) * 86400; // converting years, months, and days into seconds
    
    *future_date = *localtime(&future);
}

int main() {
    struct tm present_date, future_date;
    char input[20];
    int years, months, days;
    
    printf("Welcome to the Time Travel Simulator!\n\n");
    
    // Getting the current date
    time_t t = time(NULL);
    present_date = *localtime(&t);
    
    // Asking for user input
    printf("Enter the number of years, months, and days you want to travel into the future.\n");
    printf("Years: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &years);
    printf("Months: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &months);
    printf("Days: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &days);
    
    // Calculating the future date
    calculateFutureDate(years, months, days, present_date, &future_date);
    
    // Displaying the results
    printf("\nYou have traveled %d years, %d months, and %d days into the future!\n", years, months, days);
    printf("Current date: %02d/%02d/%04d\n", present_date.tm_mday, present_date.tm_mon + 1, present_date.tm_year + 1900);
    printf("Future date: %02d/%02d/%04d\n", future_date.tm_mday, future_date.tm_mon + 1, future_date.tm_year + 1900);
    
    return 0;
}