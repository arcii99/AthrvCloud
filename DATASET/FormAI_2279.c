//FormAI DATASET v1.0 Category: Searching algorithm ; Style: statistical
/* Statistical Searching Algorithm */
/* By [Your-Name] */

#include <stdio.h>
#include <stdlib.h>

/* Function to generate random array */
void generateArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++)
    arr[i] = rand() % 21 + 10;
}

/* Function to print array elements */
void printArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

/* Function to find mode of the array */
int findMode(int arr[], int n) {
  int i, j, mode, count, maxCount = 0;

  for (i = 0; i < n; i++) {
    count = 0;

    for (j = 0; j < n; j++) {
      if (arr[j] == arr[i])
        count++;
    }

    if (count > maxCount) {
      maxCount = count;
      mode = arr[i];
    }
  }

  return mode;
}

/* Function to perform statistical search */
int statisticalSearch(int arr[], int n, int x) {
  int i, j, equal, less, greater;
  int mode = findMode(arr, n);

  /* Check if the mode is equal to the element */
  if (mode == x)
    return mode;

  equal = 0;
  less = 0;
  greater = 0;

  /* Count the number of elements that are less than, equal to, and greater than the mode */
  for (i = 0; i < n; i++) {
    if (arr[i] < mode)
      less++;
    else if (arr[i] > mode)
      greater++;
    else
      equal++;
  }

  /* Determine the new search range based on the counts */
  if (x < mode)
    return arr[less + (equal + 1) / 2 - 1];
  else
    return arr[less + equal + (greater + 1) / 2 - 1];
}

/* Main Function */
int main() {
  int n = 10;
  int arr[n];
  int x = 15;

  /* Generate random array and print it */
  generateArray(arr, n);
  printf("Generated array:\n");
  printArray(arr, n);

  /* Perform statistical search and print the result */
  printf("Searching for %d...\n", x);
  int result = statisticalSearch(arr, n, x);
  printf("Result: %d\n", result);

  return 0;
}