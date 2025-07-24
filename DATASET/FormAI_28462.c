//FormAI DATASET v1.0 Category: Sorting ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *x, int *y) {
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

void bubble_sort(int arr[], int n) {
   int i, j;
   for(i = 0; i < n; i++) {
      for(j = 0; j < n-i-1; j++) {
         if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
      }
   }
}

void insertion_sort(int arr[], int n) {
   int i, key, j;
   for (i = 1; i < n; i++) {
      key = arr[i];
      j = i - 1;
      while (j >= 0 && arr[j] > key) {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = key;
   }
}

void selection_sort(int arr[], int n) {
   int i, j, min_idx;
   for (i = 0; i < n-1; i++) {
      min_idx = i;
      for (j = i+1; j < n; j++)
         if (arr[j] < arr[min_idx])
            min_idx = j;
      swap(&arr[min_idx], &arr[i]);
   }
}

void quick_sort(int arr[], int low, int high) {
   if (low < high) {
      int pi = partition(arr, low, high);
      quick_sort(arr, low, pi - 1);
      quick_sort(arr, pi + 1, high);
   }
}

int partition(int arr[], int low, int high) {
   int pivot = arr[high];
   int i = (low - 1);
   int j;
   for (j = low; j <= high - 1; j++) {
      if (arr[j] < pivot) {
         i++;
         swap(&arr[i], &arr[j]);
      }
   }
   swap(&arr[i + 1], &arr[high]);
   return (i + 1);
}

void merge_sort(int arr[], int l, int r) {
   if (l < r) {
      int m = l + (r - l) / 2;
      merge_sort(arr, l, m);
      merge_sort(arr, m + 1, r);
      merge(arr, l, m, r);
   }
}

void merge(int arr[], int l, int m, int r) {
   int i, j, k;
   int n1 = m - l + 1;
   int n2 = r - m;
   int L[n1], R[n2];
   for (i = 0; i < n1; i++)
      L[i] = arr[l + i];
   for (j = 0; j < n2; j++)
      R[j] = arr[m + 1 + j];
   i = 0;
   j = 0;
   k = l;
   while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
         arr[k] = L[i];
         i++;
      }
      else {
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

void heap_sort(int arr[], int n) {
   int i;
   for (i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
   for (i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
   }
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

int main() {
   int n, i;
   clock_t start, end;

   printf("Enter the number of elements in the array: ");
   scanf("%d", &n);

   int arr[n], arr_b[n], arr_i[n], arr_s[n], arr_q[n], arr_m[n], arr_h[n];

   for (i = 0; i < n; i++) {
      arr[i] = rand() % 1000;
      arr_b[i] = arr[i];
      arr_i[i] = arr[i];
      arr_s[i] = arr[i];
      arr_q[i] = arr[i];
      arr_m[i] = arr[i];
      arr_h[i] = arr[i];
   }

   printf("Original array:\n");
   for (i = 0; i < n; i++)
      printf("%d ", arr[i]);
   printf("\n");

   start = clock();
   bubble_sort(arr_b, n);
   end = clock();
   printf("Bubble Sort:\n");
   for (i = 0; i < n; i++)
      printf("%d ", arr_b[i]);
   printf("\nTime taken: %f\n", ((double) (end - start))/CLOCKS_PER_SEC);

   start = clock();
   insertion_sort(arr_i, n);
   end = clock();
   printf("Insertion Sort:\n");
   for (i = 0; i < n; i++)
      printf("%d ", arr_i[i]);
   printf("\nTime taken: %f\n", ((double) (end - start))/CLOCKS_PER_SEC);

   start = clock();
   selection_sort(arr_s, n);
   end = clock();
   printf("Selection Sort:\n");
   for (i = 0; i < n; i++)
      printf("%d ", arr_s[i]);
   printf("\nTime taken: %f\n", ((double) (end - start))/CLOCKS_PER_SEC);

   start = clock();
   quick_sort(arr_q, 0, n-1);
   end = clock();
   printf("Quick Sort:\n");
   for (i = 0; i < n; i++)
      printf("%d ", arr_q[i]);
   printf("\nTime taken: %f\n", ((double) (end - start))/CLOCKS_PER_SEC);

   start = clock();
   merge_sort(arr_m, 0, n-1);
   end = clock();
   printf("Merge Sort:\n");
   for (i = 0; i < n; i++)
      printf("%d ", arr_m[i]);
   printf("\nTime taken: %f\n", ((double) (end - start))/CLOCKS_PER_SEC);

   start = clock();
   heap_sort(arr_h, n);
   end = clock();
   printf("Heap Sort:\n");
   for (i = 0; i < n; i++)
      printf("%d ", arr_h[i]);
   printf("\nTime taken: %f\n", ((double) (end - start))/CLOCKS_PER_SEC);

   return 0;
}