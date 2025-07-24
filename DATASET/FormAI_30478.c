//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: medieval
#include <stdio.h>

int main(void) {
  double principle, rate, years;
  double monthly_payment, total_interest, total_payment;
  
  printf("Greetings, adventurer! I am the mortgage calculator of King's Landing.\n");
  printf("Pray tell, how much is the amount of your mortgage? (in gold coins): ");
  scanf("%lf", &principle);
  
  printf("And what is the annual interest rate for this quest? (in percentage): ");
  scanf("%lf", &rate);
  rate /= 1200; // convert annual rate to monthly rate
  
  printf("Finally, how many years shall you embark on this journey? ");
  scanf("%lf", &years);
  years *= 12; // convert years to months
  
  // calculate monthly payment, total interest, and total payment using formula
  monthly_payment = principle * rate / (1 - 1 / pow(1 + rate, years));
  total_payment = monthly_payment * years;
  total_interest = total_payment - principle;
  
  // print out the results to the adventurer
  printf("\n\nYour monthly payment as a warrior shall be: %.2lf gold coins\n", monthly_payment);
  printf("Your total payment after %d months in the kingdom of King's Landing shall be: %.2lf gold coins\n", (int)years, total_payment);
  printf("But beware, for the interest alone on this quest shall amount to: %.2lf gold coins\n", total_interest);
  
  printf("\nBest of luck, adventurer!\n");
  
  return 0;
}