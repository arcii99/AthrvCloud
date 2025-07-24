//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>

int main()
{
    float principal, rate, time, simple_interest, compound_interest;
    int option;
    
    printf("\n\n\t\t*** Welcome to the Cyberpunk Mortgage Calculator ***\n\n");
    
    do{
        printf("\n\n\t\t********** MENU **********");
        printf("\n\n\t1. Calculate Simple Interest");
        printf("\n\t2. Calculate Compound Interest");
        printf("\n\t3. Exit");
        printf("\n\n\tEnter your choice (1-3): ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                printf("\n\tEnter the principal amount: ");
                scanf("%f", &principal);
                
                printf("\n\tEnter the rate of interest: ");
                scanf("%f", &rate);
                
                printf("\n\tEnter the time period (in years): ");
                scanf("%f", &time);
                
                simple_interest = (principal * rate * time) / 100;
                printf("\n\tThe simple interest is: %f", simple_interest);
                break;
                
            case 2:
                printf("\n\tEnter the principal amount: ");
                scanf("%f", &principal);
                
                printf("\n\tEnter the rate of interest: ");
                scanf("%f", &rate);
                
                printf("\n\tEnter the time period (in years): ");
                scanf("%f", &time);
                
                compound_interest = principal * pow(1 + rate/100, time) - principal;
                printf("\n\tThe compound interest is: %f", compound_interest);
                break;
                
            case 3:
                printf("\n\tThank you for using Cyberpunk Mortgage Calculator\n");
                break;
                
            default:
                printf("\n\tInvalid Choice! Please enter a valid choice (1-3)\n");
                break;
        }
        
    }while(option != 3);
    
    return 0;
}