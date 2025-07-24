//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//function to calculate future value of investment using compound interest formula
float Future_value_of_Investment(float, float, int);

//function to calculate present value of investment using present value formula
float Present_value_of_Investment(float, float, int);

//function to calculate monthly payment of loan using payment formula
float Monthly_Payment(float, float, int);

//function to calculate total payment of loan using payment formula
float Total_Payment(float, float, int);

int main()
{
    int choice, term;
    float amount, interest_rate, monthly_payment, total_payment;

    printf("Welcome to Personal Finance Planner!\n");
    printf("Please select an option:\n");
    printf("1. Calculate Future Value of Investment\n");
    printf("2. Calculate Present Value of Investment\n");
    printf("3. Calculate Monthly Payment of Loan\n");
    printf("4. Calculate Total Payment of Loan\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter initial amount: $");
            scanf("%f", &amount);
            printf("Enter interest rate: ");
            scanf("%f", &interest_rate);
            printf("Enter term (in years): ");
            scanf("%d", &term);
            printf("Future value of investment is $%.2f\n", Future_value_of_Investment(amount, interest_rate, term));
            break;
        
        case 2:
            printf("Enter future amount: $");
            scanf("%f", &amount);
            printf("Enter interest rate: ");
            scanf("%f", &interest_rate);
            printf("Enter term (in years): ");
            scanf("%d", &term);
            printf("Present value of investment is $%.2f\n", Present_value_of_Investment(amount, interest_rate, term));
            break;

        case 3:
            printf("Enter loan amount: $");
            scanf("%f", &amount);
            printf("Enter interest rate: ");
            scanf("%f", &interest_rate);
            printf("Enter term (in years): ");
            scanf("%d", &term);
            monthly_payment = Monthly_Payment(amount, interest_rate, term);
            printf("Monthly payment of loan is $%.2f\n", monthly_payment);
            break;

        case 4:
            printf("Enter loan amount: $");
            scanf("%f", &amount);
            printf("Enter interest rate: ");
            scanf("%f", &interest_rate);
            printf("Enter term (in years): ");
            scanf("%d", &term);
            total_payment = Total_Payment(amount, interest_rate, term);
            printf("Total payment of loan is $%.2f\n", total_payment);
            break;

        default:
            printf("Invalid choice! Please try again.\n");
    }

    return 0;
}

float Future_value_of_Investment(float amount, float interest_rate, int term)
{
    float future_value;
    future_value = amount * pow(1 + interest_rate/100, term);
    return future_value;
}

float Present_value_of_Investment(float amount, float interest_rate, int term)
{
    float present_value;
    present_value = amount / pow(1 + interest_rate/100, term);
    return present_value;
}

float Monthly_Payment(float amount, float interest_rate, int term)
{
    float monthly_payment;
    float monthly_interest_rate = interest_rate/1200;
    monthly_payment = amount * monthly_interest_rate / (1 - pow(1 + monthly_interest_rate, -(term*12)));
    return monthly_payment;
}

float Total_Payment(float amount, float interest_rate, int term)
{
    float total_payment;
    float monthly_interest_rate = interest_rate/1200;
    total_payment = Monthly_Payment(amount, interest_rate, term) * term * 12;
    return total_payment;
}