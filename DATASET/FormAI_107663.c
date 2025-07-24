//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: modular
#include <stdio.h>

// function to calculate checksum
int getChecksum(int arr[], int n) {
   int sum = 0;
   for(int i=0; i<n; i++) {
      sum += arr[i];
   }
   return sum % 256;
}

int main() {
   int n;
   printf("Enter the number of elements in the array: ");
   scanf("%d", &n);

   int arr[n];
   printf("Enter the elements of the array: ");
   for(int i=0; i<n; i++) {
      scanf("%d", &arr[i]);
   }

   int checksum = getChecksum(arr, n);
   printf("The checksum of the array is: %d\n", checksum);
   
   return 0;
}