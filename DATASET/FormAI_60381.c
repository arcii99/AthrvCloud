//FormAI DATASET v1.0 Category: Data mining ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Hello! Let's go on a data mining adventure!\n");

  int data[10] = {4, 9, 23, 10, 3, 17, 8, 2, 15, 21};
  int i, sum = 0;
  float avg;

  printf("\nHere is our dataset: ");
  for(i = 0; i < 10; i++){
    printf("%d ", data[i]);
  }

  printf("\n\nLet's find the sum of our dataset!\n");
  for(i = 0; i < 10; i++){
    sum += data[i];
  }
  printf("The sum of our dataset is: %d\n", sum);

  printf("\nNow, let's find the average of our dataset!\n");
  avg = (float)sum / 10;
  printf("The average of our dataset is: %.2f\n", avg);

  printf("\nFinally, let's find the maximum value in our dataset!\n");
  int max = data[0];
  for(i = 1; i < 10; i++){
    if(data[i] > max){
      max = data[i];
    }
  }
  printf("The maximum value in our dataset is: %d\n", max);

  printf("\nWhat a fun data mining adventure! See you next time!\n");

  return 0;
}