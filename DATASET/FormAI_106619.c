//FormAI DATASET v1.0 Category: Searching algorithm ; Style: scientific
#include <stdio.h>
#include <stdbool.h>

int Binary_Search(int arr[], int left, int right, int x) {
  while (left<=right) {
    int mid = left+(right-left)/2;
    if (arr[mid] == x)
      return mid;
    if (arr[mid] < x)
      left = mid+1;
    else
      right = mid-1;
  }
  return -1;
}

int Interpolation_Search(int arr[], int n, int x) {
  int lo=0, hi=(n-1);
  while (lo<=hi && x>=arr[lo] && x<=arr[hi]) {
    if (lo == hi) {
      if (arr[lo] == x)
        return lo;
      return -1;
    }
    int pos = lo+((double)(hi-lo)/(arr[hi]-arr[lo]))*(x-arr[lo]);
    if (arr[pos] == x)
      return pos;
    if (arr[pos] > x)
      hi = pos-1;
    else
      lo = pos+1;
  }
  return -1;
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 11};
  int n = sizeof(arr)/sizeof(arr[0]);
  int x = 7;

  int result_binary = Binary_Search(arr, 0, n-1, x);
  if (result_binary == -1)
    printf("Element is not present in array (Binary Search)\n");
  else
    printf("Element is present at index %d (Binary Search)\n", result_binary);

  int result_interpolation = Interpolation_Search(arr, n, x);
  if (result_interpolation == -1)
    printf("Element is not present in array (Interpolation Search)\n");
  else
    printf("Element is present at index %d (Interpolation Search)\n", result_interpolation);

  return 0;
}