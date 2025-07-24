//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the %d elements of the array: ", n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int sum = 0;
  int idx = 0;
  int selected[n];

  while(sum < n) {
    int max_val = 0;
    int max_idx = -1;

    for(int i = 0; i < n; i++) {
      if(arr[i] > max_val && selected[i] == 0) {
        max_val = arr[i];
        max_idx = i;
      }
    }

    selected[max_idx] = 1;
    sum++;

    if(sum % 2 == 1) {
      idx++;
      printf("Selected element %d has value %d\n", idx, max_val);
    }
  }

  printf("Total sum of selected elements is %d\n", idx);

  return 0;
}