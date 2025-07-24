//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
  int num, i, flag, count = 0;
  printf("Welcome to the Prime Number Generator!\n");
  printf("Enter a positive integer.\n");
  scanf("%d", &num);
  int prime_num[num];
  for(i = 2; i <= num; i++) {
    flag = 0;
    for(int j = 2; j <= sqrt(i); j++) {
      if(i % j == 0) {
        flag = 1;
        break;
      }
    }
    if(flag == 0) {
      prime_num[count] = i;
      count++;
    }
  }
  printf("The Prime Numbers less than or equal to %d are:\n", num);
  for(int k = 0; k < count; k++) {
    printf("%d ", prime_num[k]);
  }
  printf("\nThank you for using the Prime Number Generator!\n");
  return 0;
}