//FormAI DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>

void recurse(int countdown) {

  if (countdown > 0) {
    for (int i = 0; i < countdown; i++) {
      printf("*");
    }
    printf("\n");
    recurse(countdown - 1);
    for (int i = 0; i < countdown; i++) {
      printf("*");
    }
    printf("\n");
    for (int i = 0; i < countdown; i++) {
      printf("-");
    }
    printf("\n");
  }
  else {
    printf("End of recursion!\n");
  }
}

int main() {

  int countdown = 7;
  recurse(countdown);
  
  return 0;
}