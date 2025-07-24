//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int coffee = 0;
  int cake = 0;
  int croissant = 0;
  int total = 0;
  printf("Welcome to our romantic cafe!\n");
  printf("Please enter the number of coffees you had: ");
  scanf("%d", &coffee);
  printf("Please enter the number of cakes you had: ");
  scanf("%d", &cake);
  printf("Please enter the number of croissants you had: ");
  scanf("%d", &croissant);
  total = (coffee * 2) + (cake * 3) + (croissant * 2);
  printf("Your total bill is: %d\n", total);
  printf("Thank you for visiting our cafe!\n");
  return 0;
}