//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: thoughtful
#include <stdio.h>

int main()
{
    float principal, rate, time, emi;
    printf("Enter the Principal amount (in Rs): ");
    scanf("%f", &principal);
    printf("Enter the Rate of Interest (in %%): ");
    scanf("%f", &rate);
    printf("Enter the Loan Tenure (in years): ");
    scanf("%f", &time);

    float r = rate / 100 / 12;
    float n = time * 12;
    emi = (principal * r * pow(1 + r, n)) / (pow(1 + r, n) - 1);

    printf("\nEMI : %.2f\n", emi);
    printf("--------------------------------------\n");
    printf("Details of Monthly Payment for %0.2f years \n", time);
    printf("--------------------------------------\n");
    printf("Principal Amount:         %.2f Rs\n", principal);
    printf("Interest Rate:            %.2f %%\n", rate);
    printf("Number of Months:         %.0f months\n", n);
    printf("EMI:                      %.2f Rs\n", emi);
    printf("--------------------------------------\n");

    float interest;
    printf("\nDo You want to calculate Total Interest and Total Payment? Y / N \n");
    char choice = getchar();
    if (choice == 'Y' || choice == 'y')
    {
        interest = (emi * n) - principal;
        printf("Total Interest:           %.2f Rs\n", interest);
        printf("Total Payment:            %.2f Rs\n", (emi * n));
    }
    else
    {
        printf("Have a nice day!");
        return 0;
    }
}