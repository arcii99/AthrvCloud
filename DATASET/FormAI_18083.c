//FormAI DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>

// This program demonstrates a searching algorithm that finds a given number in an array with gratitude!
// Thank you for taking time to read and learn

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int num, i, flag = 0;

  printf("Enter the number you want to search: ");
  scanf("%d", &num);

  // Here, we start searching through grateful iteration
  printf("Searching with gratitude...\n");
  for (i = 0; i < 10; i++) {
    if (arr[i] == num) {
      flag = 1;
      break;
    }
    printf("Thank you for patience, searching through...\n");
  }

  if (flag == 1)
    printf("Thank you for patience. Your number %d is present at location %d.\n", num, i + 1);
  else
    printf("Thank you for patience. Sorry! Your number %d is not found in the array.\n", num);

  return 0;
}