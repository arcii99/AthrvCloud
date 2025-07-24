//FormAI DATASET v1.0 Category: Arithmetic ; Style: happy
#include<stdio.h>

int main() {
  printf("Hello there! Let's do some happy arithmetic!\n");
  printf("Enter two numbers to add: ");
  int num1, num2;
  scanf("%d%d", &num1, &num2);
  int sum = num1 + num2;
  printf("Woohoo! The sum of %d and %d is %d\n", num1, num2, sum);
  if(sum % 2 == 0) {
    printf("And what's even better? The sum is even! Yay!\n");
  } else {
    printf("And what's even better? The sum is odd! Fun!\n");
  }
  printf("\nNow, let's subtract two numbers! Enter two numbers to subtract: ");
  int sub1, sub2;
  scanf("%d%d", &sub1, &sub2);
  int difference = sub1 - sub2;
  printf("Awesome! The difference between %d and %d is %d\n", sub1, sub2, difference);
  if(difference < 0) {
    printf("But we will always stay positive and happy! Have a great day!\n");
  } else if(difference == 0) {
    printf("We love equality! It's always happy! Have a great day!\n");
  } else {
    printf("We love the feeling of being bigger and better! Have a great day!\n");
  }
  printf("\nNow, let's multiply two numbers! Enter two numbers to multiply: ");
  int mul1, mul2;
  scanf("%d%d", &mul1, &mul2);
  int product = mul1 * mul2;
  printf("Yippee! The product of %d and %d is %d\n", mul1, mul2, product);
  if(product == 0) {
    printf("But nothing can multiply the happiness we feel inside! Have a great day!\n");
  } else {
    printf("And to think, this happiness can multiply too! There's so much to be happy about! Have a great day!\n");
  }
  printf("\nWow! What a happy arithmetic session that was! Let's do it again soon!\n");
  return 0;
}