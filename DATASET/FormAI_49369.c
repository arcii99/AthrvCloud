//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: scientific
#include<stdio.h>
#include<math.h>

int main()
{
    float P, N, R, EMI, Interest_amount, Total_amount;

    printf("Enter the Principal amount: ");
    scanf("%f",&P);

    printf("Enter the Time period in years: ");
    scanf("%f",&N);

    printf("Enter the Rate of interest: ");
    scanf("%f",&R);

    R = R/(12*100); //rate of interest in monthly
    N = N*12; //time period in months

    EMI = (P*R*pow(1+R,N))/(pow(1+R,N)-1);

    Interest_amount = EMI*N-P;

    Total_amount = EMI*N;

    printf("Loan Details:\n");
    printf("Principal amount: %.2f\n",P);
    printf("Rate of interest: %.2f%%\n",R*12*100);
    printf("Time period: %.0f years\n",N/12);
    printf("Monthly EMI: %.2f\n",EMI);
    printf("Total Interest Amount: %.2f\n",Interest_amount);
    printf("Total Amount (Principal + Interest): %.2f\n",Total_amount);

    return 0;
}