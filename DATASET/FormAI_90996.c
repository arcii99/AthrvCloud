//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: unmistakable
#include<stdio.h>
#include<math.h>

int main()
{
    float P, R, T, A, I, EMI;
    printf("\nEnter the Principal (P) amount: ");
    scanf("%f", &P);
    printf("\nEnter the Annual Interest Rate (R): ");
    scanf("%f", &R);
    printf("\nEnter the Time Period in years (T): ");
    scanf("%f", &T);

    //Formula for Calculating Interest
    I = (P * R * T) / 100;

    //Formula for Calculating Total Loan Amount
    A = P + I;

    //Formula for Calculating EMI
    EMI = A / (T * 12);

    printf("\n\nThe Principal (P) amount = %f", P);
    printf("\nThe Annual Interest Rate (R) = %f", R);
    printf("\nThe Time Period in years (T) = %f", T);
    printf("\nThe Interest Amount (I) = %f", I);
    printf("\nThe Total Loan Amount (A) = %f", A);
    printf("\nThe Monthly EMI = %f", EMI);
    return 0;
}