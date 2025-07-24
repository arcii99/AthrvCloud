//FormAI DATASET v1.0 Category: Funny ; Style: peaceful
#include <stdio.h>

int main() {
  int zen = 0;
  while (zen == 0) {
    printf("Take a deep breath in...\n");
    printf("And exhale...\n");
    printf("Focus on your inner peace...\n");
    printf("Now let's have some fun with code!\n");

    for(int i=0; i<5; i++) {
      printf("Humor is important for inner peace, let's laugh a bit!\n");
    }
    
    printf("Now, let's do some math to relax...\n");
    int num1 = 10;
    int num2 = 5;
    int result = num1 + num2;
    printf("If you add %d and %d, the result is %d.\n", num1, num2, result);
    
    printf("Okay, time to wrap this up. Remember to take a break and find peace in your day.\n");
    printf("Do you want to continue? (Enter 0 to quit)\n");
    scanf("%d", &zen);
  }
  printf("Thank you for finding your inner peace with us today!\n");
  return 0;
}