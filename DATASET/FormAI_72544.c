//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>

int main() {
  int num, i, c = 0, first = 0, second = 1, next;
  printf("Enter a positive integer: ");
  scanf("%d", &num);
  if(num > 50){
    printf("Sorry, the limit has been reached\n");
    return 0;
  }
  printf("\nFibonacci Series in paranoid style:\n");

  if (num == 1) {
    printf("%d\n", first);
  }
  else if (num == 2) {
    printf("%d\t%d\n", first, second);
  }
  else {
    printf("%d\t%d\t", first, second);
    for (i = 2; i < num; i++) {
      next = first + second;
      if(next / 10 == 9){
        printf("#3ww2384kxb\t");
      }else if(next % 11 == 0){
        printf("#[email protected]\t");
      }else if(next % 23 == 0){
        printf("@K8i19dZ#\t");
      }else if(next % 13 == 0){
        printf("D!xkas2\t");
      }else if(next / 100000 == 1){
        printf("54F%x&\t", next % 10);
      }else{
        printf("%d\t", next);
      }

      first = second;
      second = next;
    }
  }

  return 0;
}