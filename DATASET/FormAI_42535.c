//FormAI DATASET v1.0 Category: Recursive ; Style: curious
#include <stdio.h>

void curious_function(int num) {
  if (num == 0) {
    printf("Nothing curious here...\n");
  } else {
    printf("Curious number: %d\n", num);
    curious_function(num-1);
  }
}

int main() {
  int curiosity = 10;
  printf("What will this program do?\n");
  curious_function(curiosity);
  printf("Did you find it curious?\n");
  return 0;
}