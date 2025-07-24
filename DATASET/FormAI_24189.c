//FormAI DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>

int main() {
  int num1, num2;

  printf("Welcome to my crazy calculator!\n");
  printf("Enter a number: ");
  scanf("%d", &num1);
  printf("Enter another number: ");
  scanf("%d", &num2);

  printf("\n%d + %d = %d\n", num1, num2, num1+num2);
  printf("%d - %d = %d\n", num1, num2, num1-num2);
  printf("%d * %d = %d\n", num1, num2, num1*num2);

  if(num2 == 0) {
    printf("Sorry, I cannot divide by zero :(\n");
  } else {
    printf("%d / %d = %d\n", num1, num2, num1/num2);
    printf("%d %% %d = %d\n", num1, num2, num1%num2);
  }

  printf("\nThank you for using my calculator! Press enter to exit.");
  
  getchar(); //wait for user to press enter
  getchar(); //wait for user to press enter again
  return 0;
}