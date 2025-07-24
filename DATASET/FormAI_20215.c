//FormAI DATASET v1.0 Category: Sorting ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

/* Define a custom data type to store the number and its original index */
typedef struct {
  int number;
  int index;
} NumberWithIndex;

/* The comparison function for qsort */
int compareNumbers(const void * a, const void * b) {
  NumberWithIndex *numberA = (NumberWithIndex *)a;
  NumberWithIndex *numberB = (NumberWithIndex *)b;
  return (numberA->number - numberB->number);
}

/* Merge two sorted arrays into a new sorted array */
void merge(NumberWithIndex *arr, int left, int middle, int right) {
  NumberWithIndex *mergedArray = (NumberWithIndex*)malloc((right-left+1)*sizeof(NumberWithIndex));
  int leftIndex = left;
  int rightIndex = middle + 1;
  int mergedIndex = 0;

  while (leftIndex <= middle && rightIndex <= right) {
    if (arr[leftIndex].number <= arr[rightIndex].number) {
      mergedArray[mergedIndex] = arr[leftIndex];
      leftIndex++;
    } else {
      mergedArray[mergedIndex] = arr[rightIndex];
      rightIndex++;
    }
    mergedIndex++;
  }

  while (leftIndex <= middle) {
    mergedArray[mergedIndex] = arr[leftIndex];
    leftIndex++;
    mergedIndex++;
  }

  while (rightIndex <= right) {
    mergedArray[mergedIndex] = arr[rightIndex];
    rightIndex++;
    mergedIndex++;
  }

  for (int i = 0; i < mergedIndex; i++) {
    arr[left+i] = mergedArray[i];
  }

  free(mergedArray);
}

/* Recursive implementation of merge sort */
void mergeSort(NumberWithIndex *arr, int left, int right) {
  if (left == right) {
    return;
  }
  int middle = (left + right) / 2;
  mergeSort(arr, left, middle);
  mergeSort(arr, middle+1, right);
  merge(arr, left, middle, right);
}

int main() {
  srand(time(NULL));
  NumberWithIndex numbers[ARRAY_SIZE];
  printf("Original array: ");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    numbers[i].number = rand() % 100;
    numbers[i].index = i;
    printf("%d ", numbers[i].number);
  }
  printf("\n");

  /* Sort the array using quicksort */
  qsort(numbers, ARRAY_SIZE, sizeof(NumberWithIndex), compareNumbers);
  printf("Sorted array using quicksort: ");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", numbers[i].number);
  }
  printf("\n");

  /* Sort the array using merge sort */
  mergeSort(numbers, 0, ARRAY_SIZE-1);
  printf("Sorted array using merge sort: ");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", numbers[i].number);
  }
  printf("\n");

  /* Print the sorted array along with their original indices */
  printf("Array with original indices: ");
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("(%d, %d) ", numbers[i].number, numbers[i].index);
  }
  printf("\n");

  return 0;
}