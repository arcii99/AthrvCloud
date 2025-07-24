//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

void swap(int* x, int* y) {
   int temp = *x;
   *x = *y;
   *y = temp;
}

void heapify(int arr[], int n, int i) {
   int largest = i;
   int l = 2 * i + 1;
   int r = 2 * i + 2;
   if (l < n && arr[l] > arr[largest])
      largest = l;
   if (r < n && arr[r] > arr[largest])
      largest = r;
   if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
   }
}
void heapSort(int arr[], int n) {
   for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
   for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
   }
}
void printArray(int arr[], int n) {
   for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
}
int main() {
   int arr[10],n;
   printf("enter size: ");
   scanf("%d",&n);
   printf("Enter elements: ");
   for(int i=0;i<n;i++)
      scanf("%d",&arr[i]);
   printf("Given array is : ");
   printArray(arr, n);
   heapSort(arr, n);
   printf("\nSorted array is: ");
   printArray(arr, n);
}