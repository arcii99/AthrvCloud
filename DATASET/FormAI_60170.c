//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {

    float salary, rent, groceries, bills, fuel, savings;
    
    // Collect user inputs
    printf("Please enter your monthly salary: ");
    scanf("%f", &salary);
    
    printf("Please enter your monthly rent/mortgage payment: ");
    scanf("%f", &rent);
    
    printf("Please enter your monthly grocery budget: ");
    scanf("%f", &groceries);
    
    printf("Please enter your monthly bills (e.g. utilities, subscriptions): ");
    scanf("%f", &bills);
    
    printf("Please enter your average monthly fuel expenses: ");
    scanf("%f", &fuel);
    
    // Calculate savings based on inputs
    savings = salary - (rent + groceries + bills + fuel);
    
    // Display results
    printf("\nBased on your inputs, your monthly savings are $%.2f.\n\n", savings);
    
    // Determine if savings are above or below average
    if (savings > 500) {
        printf("Congratulations! Your savings are higher than the national average.\n");
    } else {
        printf("Unfortunately, your savings are below the national average. Here are some tips to save more:\n\n");
        
        printf("-Reduce your grocery bill by using coupons or buying generic brands.\n");
        printf("-Use public transportation or carpool to save on fuel expenses.\n");
        printf("-Examine your bills and see if there are any subscriptions or services you can cancel or reduce.\n");
    }
    
    return 0;
}