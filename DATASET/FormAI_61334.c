//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include <stdio.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm year_2000 = {0};
    year_2000.tm_year = 100;
    year_2000.tm_mday = 1;
    year_2000.tm_mon = 0;
    
    // Set the time to January 1, 2000
    now = mktime(&year_2000);
    
    int age = 30;
    double interest_rate = 0.05;
    double savings_rate = 0.2;
    double savings = 0;
    double current_balance = 0;
    
    for (int i = 0; i < age; i++) {
        // Add savings to the current balance at the beginning of each year
        current_balance += savings;
        
        // Calculate the interest earned on the current balance at the end of each year
        double earned_interest = current_balance * interest_rate;
        current_balance += earned_interest;
        
        // Print out the age, current balance, and savings for each year
        printf("Age %d: Current Balance = $%.2f, Savings = $%.2f\n", i, current_balance, savings);
        
        // Increase savings for the next year
        savings *= (1 + savings_rate);
    }
    
    // Travel forward 50 years
    now += 50 * 365 * 24 * 60 * 60;
    
    struct tm *future_time = localtime(&now);
    printf("\nIn 50 years, it will be %s", asctime(future_time));
    
    return 0;
}