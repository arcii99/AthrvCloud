//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mathematical
#include <stdio.h>

int main() {
  int user_input;
  printf("Please enter a number: ");
  scanf("%d", &user_input);
  
  if (user_input <= 0) {
    printf("Invalid input. The number must be greater than zero.\n");
    return 1;
  }

  printf("The prime factorization of %d is: ", user_input);

  for (int i = 2; i <= user_input; i++) {
    while (user_input % i == 0) {
      printf("%d ", i);
      user_input /= i;
    }
  }

  printf("\n");
  return 0;
}