//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: genious
#include<stdio.h>
#include<math.h>

int main(){

    float principal, rate, time, emi, interest, totalPayment;
    printf("Enter the Principal Amount: ");
    scanf("%f",&principal);
    printf("Enter the Rate of Interest(p.a.): ");
    scanf("%f",&rate);
    printf("Enter the time(in years) to pay back the loan: ");
    scanf("%f",&time);

    rate=rate/(12*100);
    time=time*12;
    emi=(principal*rate*(pow(1+rate,time)))/(pow(1+rate,time)-1);

    printf("\nMonthly EMI: %.2f",emi);

    totalPayment=emi*time;
    printf("\nTotal Payment: %.2f",totalPayment);

    interest=totalPayment-principal;
    printf("\nTotal Interest: %.2f",interest);

    return 0;
}