//FormAI DATASET v1.0 Category: Data mining ; Style: creative
#include <stdio.h>

int main() {
  int arr[5] = {1, 5, 7, 3, 9};

  // loop through each element in the array
  for(int i = 0; i < 5; i++) {
    printf("%d ", arr[i]);

    // if the current element is greater than 5
    if(arr[i] > 5) {
      printf("(greater than 5!)");
    }
    printf("\n");
  }

  return 0;
}