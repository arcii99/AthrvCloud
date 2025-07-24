//FormAI DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>

int main() {
  int arr[100], n, i, search, flag = 0;
  
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter %d elements: ", n);

  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter the element to search: ");
  scanf("%d", &search);

  for (i = 0; i < n; i++) {
    if (arr[i] == search) {
      printf("%d found at position %d.\n", search, i+1);
      flag = 1;
      break;
    }
  }

  if (flag == 0) {
    printf("%d is not present in the array.\n", search);
  }

  return 0;
}