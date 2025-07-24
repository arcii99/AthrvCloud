//FormAI DATASET v1.0 Category: Data recovery tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
   int data_limit, num_items, i;
   int *data_array;
 
   printf("Enter the number of data items to be recovered: ");
   scanf("%d", &num_items);

   data_array = (int*) malloc(num_items * sizeof(int));
 
   if(data_array == NULL) {
      printf("Error: Could not allocate memory.");
      exit(1);
   }
 
   printf("Enter the maximum limit on the data values: ");
   scanf("%d", &data_limit);
 
   printf("Enter the data items (separated by spaces): \n");
   for(i = 0; i < num_items; i++) {
      scanf("%d", &data_array[i]);
   }

   printf("Retrieving data... \n\nRecovered Data:\n");

   for(i = 0; i < num_items; i++) {
       if(data_array[i] <= data_limit) {
           printf("%d ", data_array[i]);
       }
   }

   free(data_array); 
   return 0;
}