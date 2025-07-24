//FormAI DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>

int invasive_search(int arr[], int n, int search_value){
   int i = 0;
   while (i < n){
      if (arr[i] == search_value) {
         return i;
      }
      i++;
   }
   
   int temp = arr[n-1];
   arr[n-1] = search_value;
   i = 0;
   while (arr[i] != search_value){
      i++;
   }
   
   arr[n-1] = temp;
   
   if ((i < n-1) || (arr[n-1] == search_value)){
      return i;
   }
   return -1;
}

int main(){
   int arr[] = {2, 5, 1, 6, 3};
   int n = sizeof(arr)/sizeof(arr[0]);
   int search_val = 6;
   int result_index = invasive_search(arr, n, search_val);

   if (result_index == -1) {
      printf("Value not found in array.\n");
   }
   else {
      printf("Value found at index %d.\n", result_index);
   }
   
   return 0;
}