//FormAI DATASET v1.0 Category: Sorting ; Style: relaxed
#include <stdio.h>

int main() {
  int numbers[] = {23, 1, 67, 14, 89, 5, 98};
  int length = sizeof(numbers) / sizeof(numbers[0]);
  printf("Unsorted Numbers: ");
  for (int i = 0; i < length; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  // Bubble Sort Algorithm Implementation
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (numbers[j] > numbers[j+1]) {
        int temp = numbers[j];
        numbers[j] = numbers[j+1];
        numbers[j+1] = temp;
      }
    }
  }

  printf("Sorted Numbers: ");
  for (int i = 0; i < length; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
  
  return 0;
}