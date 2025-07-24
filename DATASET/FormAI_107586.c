//FormAI DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>

int main(void) {
  int num1 = 3, num2 = 5;
  printf("What is the sum of %d and %d?\n", num1, num2);
  int answer;
  scanf("%d", &answer);
  
  if (answer == num1 + num2) {
    printf("Correct! Now, what is the product of %d and %d?\n", num1, num2);
    scanf("%d", &answer);
    
    if (answer == num1 * num2) {
      printf("Impressive! One final question. What is %d modulo %d?\n", num1 + num2, num1);
      scanf("%d", &answer);
      
      if (answer == (num1 + num2) % num1) {
        printf("You have solved my arithmetic puzzle. Congratulations!");
      } else {
        printf("Sorry, that is incorrect. Please try again.");
      }
    } else {
      printf("Sorry, that is incorrect. Please try again.");
    }
  } else {
    printf("Sorry, that is incorrect. Please try again.");
  }
  
  return 0;
}