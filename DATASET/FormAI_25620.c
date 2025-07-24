//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

int main() {
  int arr[MAX_SIZE];

  // Generate 1 million random integers between 0 and 1000
  for (int i = 0; i < MAX_SIZE; i++) {
    arr[i] = rand() % 1001;
  }

  int max_num = 0;
  int max_count = 0;

  // Find the most common integer in the array
  for (int i = 0; i < MAX_SIZE; i++) {
    int count = 1;

    for (int j = i + 1; j < MAX_SIZE; j++) {
      if (arr[i] == arr[j]) {
        count++;
      }
    }

    if (count > max_count) {
      max_count = count;
      max_num = arr[i];
    }
  }

  printf("The most common integer in the array is %d, it appears %d times\n", max_num, max_count);

  return 0;
}