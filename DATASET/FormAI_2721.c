//FormAI DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main() {
   int n, i, j, k;
   printf("Enter the number of elements\n");
   scanf("%d", &n); // taking input from the user
   int arr[n]; // declaring an array of size n

   // taking input elements to the array
   for(i = 0; i < n; i++){
      printf("Enter element %d\n", i+1);
      scanf("%d", &arr[i]);
   }

   // printing all the elements of the array
   printf("\nInput array is:\n");
   for(i = 0; i < n; i++){
      printf("%d ", arr[i]);
   }
   // applying data mining here
   for(i = 0; i < n-2; i++){
      for(j = i+1; j < n-1; j++){
         for(k = j+1; k < n; k++){
            if((arr[i] + arr[j] + arr[k]) == 0) { // checking the addition of three elements equal to 0
               printf("\nFound triplet: %d %d %d\n", arr[i], arr[j], arr[k]);
            }
         }
      }
   }

   return 0;
}