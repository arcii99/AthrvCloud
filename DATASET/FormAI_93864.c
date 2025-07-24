//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

/* A function to get the maximum value in the given array */
int get_max(int arr[], int n) {
   int max = arr[0];
   for(int i=1; i<n; i++) {
      if(arr[i] > max) {
         max = arr[i];
      }
   }
   return max;
}

/* A function to implement bucket sort */
void bucket_sort(int arr[], int n) {
   int max_val = get_max(arr, n);
   int num_of_buckets = max_val/10 + 1;
   int **buckets = (int **)malloc(num_of_buckets * sizeof(int *));
   for(int i=0; i<num_of_buckets; i++) {
      buckets[i] = (int *)malloc(n * sizeof(int)); // allocating memory
   }

   /* Fill buckets with 0's initially. */
   for(int i=0; i<num_of_buckets; i++) {
      for(int j=0; j<n; j++) {
         buckets[i][j] = 0;
      }
   }

   /* Fill buckets */
   for(int i=0; i<n; i++) {
      int j = arr[i]/10;
      int k = i;
      while(buckets[j][k] != 0) {
         k++;
      }
      buckets[j][k] = arr[i];
   }

   /* Sort buckets */
   for(int i=0; i<num_of_buckets; i++) {
      for(int j=0; j<n; j++) {
         for(int k=j+1; buckets[i][k]!=0 && k<n; k++) {
            if(buckets[i][j] > buckets[i][k]) {
               int temp = buckets[i][j];
               buckets[i][j] = buckets[i][k];
               buckets[i][k] = temp;
            }
         }
      }
   }

   /* Concatenate buckets */
   int index = 0;
   for(int i=0; i<num_of_buckets; i++) {
      for(int j=0; j<n; j++) {
         if(buckets[i][j] != 0) {
            arr[index] = buckets[i][j];
            index++;
         }
      }
   }

   /* Free the memory allocated for buckets */
   for(int i=0; i<num_of_buckets; i++) {
      free(buckets[i]);
   }
   free(buckets);
}

int main() {
   int arr[] = {99, 65, 24, 47, 50, 88, 33, 67, 83, 61};
   int n = sizeof(arr)/sizeof(arr[0]);

   printf("Array before sorting:\n");
   for(int i=0; i<n; i++) {
      printf("%d ", arr[i]);
   }

   bucket_sort(arr, n);

   printf("\nArray after sorting:\n");
   for(int i=0; i<n; i++) {
      printf("%d ", arr[i]);
   }

   return 0;
}