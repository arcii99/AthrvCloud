//FormAI DATASET v1.0 Category: Scientific ; Style: happy
#include <stdio.h>

int main() {
  printf("Welcome to the happiest C program ever!\n");
  printf("We are going to calculate the average of three numbers.\n\n");
  
  float num1, num2, num3;
  
  printf("Please enter the first number: ");
  scanf("%f", &num1);
  printf("\nGood job! Now the second number: ");
  scanf("%f", &num2);
  printf("\nExcellent! The last number: ");
  scanf("%f", &num3);

  float average = (num1 + num2 + num3) / 3;
  
  printf("\nWOW, you are doing great! Now let me calculate the average for you...\n");
  printf("Drumroll please...\n");
  printf("...\n");
  printf("The average of %f, %f and %f is: %f\n", num1, num2, num3, average);

  printf("\nCongratulations, you have successfully calculated the average!\n");
  printf("You are a mathematical genius!\n");
  printf("Thank you for using the happiest C program ever.\n");

  return 0;
}