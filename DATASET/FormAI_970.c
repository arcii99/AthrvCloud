//FormAI DATASET v1.0 Category: Scientific ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num1, num2, product;

  printf("Welcome to the hilarious multiplication program!\n");
  printf("Please enter the first number: ");
  scanf("%d", &num1);

  printf("Great! Now enter the second number: ");
  scanf("%d", &num2);

  product = num1 * num2;

  printf("Hold on to your hats, folks! The answer is...\n");

  // Code for funny output begins.
  int i;
  for(i = 0; i < 5; i++) {
    printf("%d\n", product);
    product += 69;
  }

  printf("That's not all, folks! Let's take the square root of the answer...\n");
  printf("Wait for it...\n");
  printf("Wait for it...\n");
  printf("You guessed it! It's %f!\n", sqrt(product));

  printf("Thanks for using our program! We hope you had as much fun as we did.\n");

  return 0;
}