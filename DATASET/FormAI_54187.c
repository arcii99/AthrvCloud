//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  printf("Enter the number of elements\n");
  scanf("%d", &n);
  int *arr = (int *) malloc(n * sizeof(int));

  printf("Enter the elements\n");
  for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  int sum = 0;
  int max_sum = 0;
  int start_index = 0;
  int end_index = 0;

  for(int i = 0; i < n; i++) {
    sum += arr[i];

    if(sum < 0) {
      sum = 0;
      start_index = i + 1;
    } else if(sum > max_sum) {
      max_sum = sum;
      end_index = i;
    }
  }

  printf("Maximum contiguous sum is %d\n", max_sum);
  printf("Starting index: %d\n", start_index);
  printf("Ending index: %d\n", end_index);

  free(arr);

  return 0;
}