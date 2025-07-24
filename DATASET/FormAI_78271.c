//FormAI DATASET v1.0 Category: Searching algorithm ; Style: interoperable
#include <stdio.h>

int interpolationSearch(int arr[], int n, int x) {
  int lo = 0;
  int hi = n - 1;
  while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
    if (lo == hi) {
      if (arr[lo] == x) return lo;
      return -1;
    }
    int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
    if (arr[pos] == x) return pos;
    if (arr[pos] < x) lo = pos + 1;
    else hi = pos - 1;
  }
  return -1;
}

int main() {
  int arr[] = {2, 3, 4, 10, 40};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 10;
  int index = interpolationSearch(arr, n, x);
  if (index != -1) printf("Element found at index %d", index);
  else printf("Element not found");
  return 0;
}