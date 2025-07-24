//FormAI DATASET v1.0 Category: Recursive ; Style: visionary
#include <stdio.h>

int vision(int x) {
  if (x < 10) {
    printf("I see a bright future ahead!\n");
  } else if (x < 20) {
    printf("I see some challenges ahead, but nothing you can't handle!\n");
  } else if (x < 30) {
    printf("I see some tough decisions ahead, brace yourself!\n");
  } else if (x < 40) {
    printf("I see a mid-life crisis, don't fret, it happens to the best of us!\n");
  } else {
    printf("I see a new beginning, embrace change!\n");
  }
  if (x >= 50) {
    return 0;
  } else {
    return vision(x + 10);
  }
}

int main() {
  printf("I am a visionary program. What do you want me to see?\n");
  int age;
  scanf("%d", &age);
  vision(age);
  return 0;
}