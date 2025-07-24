//FormAI DATASET v1.0 Category: Data validation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
This program takes user input for age and hourly wage,
and checks that the input is valid before computing
the user's weekly pay.

Valid inputs:
- Age must be a positive integer
- Wage must be a positive float

*/

int main() {
    // declare variables
    int age;
    float wage, weeklyPay;

    // get user input for age
    printf("Please enter your age: ");
    if(scanf("%d", &age) != 1 || age < 1) {
        printf("Invalid input. Age must be a positive integer.\n");
        exit(1);
    }

    // get user input for wage
    printf("Please enter your hourly wage: ");
    if(scanf("%f", &wage) != 1 || wage < 0) {
        printf("Invalid input. Wage must be a positive float.\n");
        exit(1);
    }

    // calculate weekly pay
    weeklyPay = wage * 40;

    // output results
    printf("Your weekly pay is: $%.2f\n", weeklyPay);

    return 0;
}