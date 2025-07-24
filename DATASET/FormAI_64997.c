//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: all-encompassing
#include<stdio.h>
#include<math.h>

int main(){

  float loan_amount, interest_rate, monthly_payment, total_payment, total_interest;
  int term;

  //Taking user input
  printf("Enter loan amount: ");
  scanf("%f", &loan_amount);
  printf("Enter term in years: ");
  scanf("%d", &term);
  printf("Enter interest rate: ");
  scanf("%f", &interest_rate);
  printf("Enter monthly payment: ");
  scanf("%f", &monthly_payment);

  //Calculating monthly interest rate
  float monthly_interest_rate = interest_rate / (12 * 100);

  //Calculating monthly loan payment using formula
  float loan_payment = (loan_amount * monthly_interest_rate * pow(1 + monthly_interest_rate, term * 12)) / (pow(1 + monthly_interest_rate, term * 12) - 1);

  //Calculating total payment, total interest and remaining balance
  total_payment = loan_payment * term * 12;
  total_interest = total_payment - loan_amount;
  float remaining_balance = loan_amount;

  //Printing the loan report
  printf("\n\t\tLoan Report\n\n");
  printf("Loan Amount: %.2f\n", loan_amount);
  printf("Term: %d years\n", term);
  printf("Interest Rate: %.2f%\n", interest_rate);
  printf("Monthly Payment: %.2f\n\n", monthly_payment);

  printf("----------------------------------------------------------------\n");
  printf("|   Payment #\t|   Payment Amount\t|   Principal\t|   Interest\t|   Balance\t|\n");
  printf("----------------------------------------------------------------\n");

  int i;
  for(i=1; i<=(term*12); i++){

    float interest = remaining_balance * monthly_interest_rate;
    float principal = loan_payment - interest;

    //Checking if remaining balance is less than loan payment
    if(remaining_balance < loan_payment){

      loan_payment = remaining_balance + interest;
      principal = remaining_balance;

    }

    remaining_balance = remaining_balance - principal;

    printf("|   %d\t\t|   %.2f\t\t\t|   %.2f\t\t|   %.2f\t\t|   %.2f\t\t|\n", i, loan_payment, principal, interest, remaining_balance);

    //Checking if remaining balance is zero
    if(remaining_balance == 0){
      break;
    }

  }

  printf("----------------------------------------------------------------\n");

  printf("\nTotal Payment: %.2f\n", total_payment);
  printf("Total Interest: %.2f\n", total_interest);

  return 0;
}