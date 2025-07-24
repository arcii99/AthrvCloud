//FormAI DATASET v1.0 Category: Recursive ; Style: curious
#include <stdio.h>

void curious_function(int n) {
  if(n > 0) {
    curious_function(n-1);
    printf("%d \n", n);
    curious_function(n-1);
  }
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  curious_function(n);

  return 0;
}