//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
#include <stdio.h>

int recursive_sum(int arr[], int size) {

  if (size == 1) {
    return arr[0];
  } else if (size == 0) {
    return 0;
  } else {
    int lastElement = arr[size - 1];
    int sum = recursive_sum(arr, size - 1);
    return sum + lastElement;
  }

}

int main(){

  int myArr[] = {1, 2, 3, 4, 5};
  int size = sizeof(myArr) / sizeof(myArr[0]);
  int sum = recursive_sum(myArr, size);

  printf("The sum of the array is: %d\n", sum);

  return 0;

}