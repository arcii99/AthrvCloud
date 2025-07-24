//FormAI DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r);
void merge_sort(int arr[], int l, int r);

int main(void) {
  int arr[] = {9, 5, 1, 3, 7, 2, 8, 4, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  printf("Unsorted array:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  merge_sort(arr, 0, n - 1);
  
  printf("\n\nSorted array:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}

void merge(int arr[], int l, int m, int r) 
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  
  int L[n1], R[n2];
  
  for (i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }
  
  i = 0;
  j = 0;
  k = l;
  
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int l, int r)
{
  if (l < r) {
    int m = l + (r - l) / 2;
    
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    
    merge(arr, l, m, r);
  }
}