//FormAI DATASET v1.0 Category: Fractal Generation ; Style: recursive
#include <stdio.h>

int fractal(int level, int num, int spaces) {
  if (level == 0) {
    for (int i = 0; i < spaces; i++) {
      printf(" ");
    }
    printf("%d\n", num);
    return 0;
  }
  fractal(level-1, num-3*level, spaces+(level*2)+1);
  for (int i = 0; i < spaces; i++) {
    printf(" ");
  }
  printf("%d\n", num);
  fractal(level-1, num+3*level, spaces+(level*2)+1);
}

int main() {
  int level;
  printf("Enter the number of levels: ");
  scanf("%d", &level);
  fractal(level, 0, 0);
  return 0;
}