//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: invasive
#include<stdio.h>
#include<math.h>

int main(){
  double amount,rate,interest,mnth,TotalPayment;
  printf("Welcome to the Mortgage Calculator\n");
  printf("Enter Loan Amount: ");
  scanf("%lf", &amount);
  printf("Enter Interest Rate: ");
  scanf("%lf", &rate);
  printf("Enter Loan Term (in years): ");
  scanf("%lf", &mnth);

  rate= rate/1200;
  mnth= mnth*12;
  interest= pow((1+rate),mnth);

  TotalPayment= (amount*rate*interest)/(interest-1);

  printf("\nMonthly Payment: $%.2f", TotalPayment);
  printf("\nTotal Payment: $%.2f", TotalPayment*mnth);

  printf("\nDo you have another Mortgage to calculate?\nPress 'y' for Yes or 'n' for No: ");
  char choice;
  scanf(" %c", &choice);
  if (choice == 'y'){
      main();
  }
  else{
      printf("\nThank you for choosing our Mortgage Calculator!");
  }
  return 0;
}