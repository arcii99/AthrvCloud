//FormAI DATASET v1.0 Category: Scientific ; Style: energetic
#include <stdio.h>

int main() {
  // Get user input for a positive integer
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  // Check if it is a prime number
  int flag = 0;
  for(int i = 2; i < n; i++) {
    if(n % i == 0) {
      flag = 1;
      break;
    }
  }

  // Print the result
  if(n == 1) {
    printf("1 is not a prime number.\n");
  } else if(flag == 0) {
    printf("%d is a prime number!\n", n);
  } else {
    printf("%d is NOT a prime number.\n", n);
  }

  return 0;
}