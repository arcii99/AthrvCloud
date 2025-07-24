//FormAI DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>

int main() {
  int number_one, number_two, sum;

  printf("Welcome to the innovative arithmetic example program!\n");
  printf("Please enter your first number: ");
  scanf("%d", &number_one);
  
  printf("Great! Now enter your second number: ");
  scanf("%d", &number_two);
  
  printf("Calculating...\n");
  
  sum = number_one + number_two;
  
  printf("Your innovative result is: \n");
  
  for (int i = 0; i < sum; i++) {
    printf("*");
    if (i % 10 == 0 && i != 0) {
      printf("\n");
    }
  }
  
  printf("\n\nCongratulations on your innovative answer!\n");
  
  return 0;
}