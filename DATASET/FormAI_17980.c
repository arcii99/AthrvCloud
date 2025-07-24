//FormAI DATASET v1.0 Category: Recursive ; Style: futuristic
#include <stdio.h>

int recursive_function(int n) {
  if(n == 0) {
    return 0;
  }
  else {
    return n + recursive_function(n-1);
  }
}

int main() {
  int num = 10;

  printf("The sum of the first %d natural numbers is: %d\n", num, recursive_function(num));
  
  return 0;
}