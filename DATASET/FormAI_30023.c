//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

int maxSubsetSum(int arr[], int n) {
   int incl = arr[0];
   int excl = 0;

   for (int i = 1; i < n; i++) {
      int temp = incl;
      incl = (excl + arr[i] > incl) ? (excl + arr[i]) : incl;
      excl = temp;
   }

   return incl;
}

int main() {
   int arr[] = {1, 7, 3, 8, 4, 5};
   int n = sizeof(arr) / sizeof(arr[0]);

   printf("Highest subset sum: %d\n", maxSubsetSum(arr, n));

   return 0;
}