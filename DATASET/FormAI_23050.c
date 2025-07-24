//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Alan Touring
#include<stdio.h>

void main(){
  double principal, rate, time, emi, interest, totalAmt;

  printf("Please enter the loan amount in CAD:\n");
  scanf("%lf", &principal);

  printf("Please enter the interest rate per annum:\n");
  scanf("%lf", &rate);

  printf("Please enter the loan period in years:\n");
  scanf("%lf", &time);

  rate/=1200; //Conversion of annual rate to monthly rate
  time*=12; //Conversion of loan period from years to months

  emi = principal*rate*(pow((1+rate),time))/(pow((1+rate),time)-1);
  interest = emi*time-principal;
  totalAmt = emi*time;

  printf("The EMI (Equated Monthly Installment) is %.2lf CAD per month.\n",emi);
  printf("The total interest charged over the loan period is %.2lf CAD.\n",interest);
  printf("The total amount which you need to pay will be %.2lf CAD.\n", totalAmt);
}