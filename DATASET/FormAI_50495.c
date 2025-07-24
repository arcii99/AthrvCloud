//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main(){

  int data[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; //data set of 10 integers
  int sum = 0;
  float mean = 0.0;
  int max = 0;
  int min = 0;

  //Calculating the sum of all elements
  for (int i = 0; i < 10; i++){
    sum += data[i];
  }

  //Calculating the mean of the data set
  mean = (float)sum / 10;

  //Calculating the maximum and minimum values in the data set
  max = data[0];
  min = data[0];

  for (int i = 0; i < 10; i++){
    if (data[i] > max){
      max = data[i];
    }
    if (data[i] < min){
      min = data[i];
    }
  }

  printf("Data Set: ");
  for (int i = 0; i < 10; i++){
    printf("%d ", data[i]);
  }

  printf("\n\n");

  printf("Sum of all elements: %d\n", sum);
  printf("Mean of the data set: %.2f\n", mean);
  printf("Maximum value in the data set: %d\n", max);
  printf("Minimum value in the data set: %d\n", min);

  return 0;
}