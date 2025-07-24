//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h> // Include Standard Input/Output Header
#include <stdlib.h> // Include Standard Library Header

void main() { // Main Function
  float income, expenses, tax, net_income, savings; // Declare Variables 

  printf("Enter your monthly income: "); // Display Message
  scanf("%f", &income); // Read Input
  
  printf("\nEnter your monthly expenses: "); // Display Message
  scanf("%f", &expenses); // Read Input
  
  tax = income * 0.2; // Calculate Tax
  net_income = income - tax; // Calculate Net Income
  savings = net_income - expenses; // Calculate Savings
  
  printf("\nYour monthly tax is: $%.2f", tax); // Display Tax
  printf("\nYour monthly net income is: $%.2f", net_income); // Display Net Income
  printf("\nYour monthly savings is: $%.2f", savings); // Display Savings

  if (savings > 0) { // Check Savings is Greater than 0
    printf("\n\nYou are saving money every month! Good Job!"); // Display Message
  }
  else if (savings == 0) { // Check Savings is Equal to 0
    printf("\n\nYou are breaking even every month. Keep it up!"); // Display Message
  }
  else { // Savings is Less than 0
    printf("\n\nYou are spending more money than you are making. You need to cut back on expenses."); // Display Message
  }

  printf("\n\n"); // Display Empty Line

  system("PAUSE"); // Pause Console Window
}