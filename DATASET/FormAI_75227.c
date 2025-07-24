//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: complete
#include<stdio.h>
#include<math.h>

int main()
{
    float P, R, T, EMI, interest, totalPayment;

    printf("\nEnter the Loan Amount: ");
    scanf("%f", &P);

    printf("\nEnter the Rate of Interest: ");
    scanf("%f", &R);

    printf("\nEnter the Loan Period (in Months): ");
    scanf("%f", &T);

    R = R/(12*100); /* one month interest */

    EMI = (P*R*pow(1+R,T))/(pow(1+R,T)-1);

    interest = EMI*T - P;
    totalPayment = EMI*T;

    printf("\n\nMonthly EMI Payment: %.2f\n", EMI);
    printf("Total Interest Paid: %.2f\n", interest);
    printf("Total Payment (Principal + Interest): %.2f\n", totalPayment);

    return 0;
}