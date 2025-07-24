//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
#include<stdio.h>

//function to calculate compound interest
float compound_interest(float principle_amt, float rate_of_interest, float time_period)
{
    return principle_amt * pow((1 + rate_of_interest/100), time_period);
}

//function to calculate simple interest
float simple_interest(float principle_amt, float rate_of_interest, float time_period)
{
    return (principle_amt * rate_of_interest * time_period) / 100;
}

//main function
int main()
{
    float principle_amt, rate_of_interest, time_period;
    int option;
    
    printf("Welcome to Personal Finance Planner\n");
    printf("----------------------------------\n");
    
    //loop until user decides to exit
    while(1)
    {
        printf("Choose an option\n");
        printf("1. Calculate Compound Interest\n");
        printf("2. Calculate Simple Interest\n");
        printf("3. Exit\n");
        printf("Option: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                printf("Enter principle amount: ");
                scanf("%f", &principle_amt);
                printf("Enter rate of interest: ");
                scanf("%f", &rate_of_interest);
                printf("Enter time period: ");
                scanf("%f", &time_period);
                
                printf("Total amount with compound interest: %.2f\n", compound_interest(principle_amt, rate_of_interest, time_period));
                break;
                
            case 2:
                printf("Enter principle amount: ");
                scanf("%f", &principle_amt);
                printf("Enter rate of interest: ");
                scanf("%f", &rate_of_interest);
                printf("Enter time period: ");
                scanf("%f", &time_period);
                
                printf("Total amount with simple interest: %.2f\n", simple_interest(principle_amt, rate_of_interest, time_period));
                break;
                
            case 3:
                printf("Thank you for using Personal Finance Planner\n");
                return 0;
                
            default:
                printf("Invalid option. Please try again\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}