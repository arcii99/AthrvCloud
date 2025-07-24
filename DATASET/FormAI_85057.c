//FormAI DATASET v1.0 Category: Educational ; Style: Linus Torvalds
#include <stdio.h>

int main() {
  printf("Hello World!\n");

  int x = 5;
  int y = 10;
  if (x < y) {
    printf("x is less than y\n");
  } else if (x > y) {
    printf("x is greater than y\n");
  } else {
    printf("x is equal to y\n");
  }

  int arr[5] = {1, 2, 3, 4, 5};
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += arr[i];
  }
  printf("The sum of array elements is %d\n", sum);

  char str1[] = "Hello";
  char str2[] = " World";
  strcat(str1, str2);
  printf("%s\n", str1);

  return 0;
}