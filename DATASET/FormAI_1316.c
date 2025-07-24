//FormAI DATASET v1.0 Category: Educational ; Style: peaceful
#include <stdio.h>

int main() {
  int count = 1;
  while(count <= 10) {
    printf("I am at peace, iteration number %d.\n", count);
    count++;
  }

  printf("\n");

  float num1 = 2.5, num2 = 3.8;
  printf("The sum of %f and %f is %f.\n", num1, num2, (num1+num2));

  printf("\n");

  int num_array[5] = {1, 2, 3, 4, 5};
  int i, sum = 0;
  for(i=0; i<5; i++) {
    sum += num_array[i];
  }
  printf("The sum of the numbers in the array is %d.\n", sum);

  printf("\n");

  int num = 10;
  printf("The value of num before the function is %d.\n", num);
  changeNum(num);
  printf("The value of num after the function is %d.\n", num);

  return 0;
}

void changeNum(int x) {
  x = 20;
  printf("The value of x inside the function is %d.\n", x);
}