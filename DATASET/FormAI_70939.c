//FormAI DATASET v1.0 Category: Recursive ; Style: excited
#include <stdio.h>
#include <stdlib.h>

void recursiveExcitement(int n) {
  if (n == 0) {
    printf("Woohoo! This is awesome! Let's go again!\n");
    return;
  }
  printf("This recursive function is the best thing ever!\n");
  recursiveExcitement(n-1);
}

int main() {
  int num_excitement;
  printf("How excited are you about this recursive function? (Enter a number): ");
  scanf("%d", &num_excitement);
  printf("\nGet ready to feel the excitement!\n");

  recursiveExcitement(num_excitement);

  printf("\nDid that get you pumped up?! Let's do it again!\n");
  printf("How excited are you this time? (Enter a number): ");
  scanf("%d", &num_excitement);
  printf("\nLet's feel the excitement!\n");

  recursiveExcitement(num_excitement);

  printf("\nWow, that was amazing! I'm feeling more excited than ever! Who's ready for another round?!?!\n");

  return 0;
}