//FormAI DATASET v1.0 Category: Sorting ; Style: Dennis Ritchie
#include <stdio.h>

void selectionSort(int arr[], int n) {
   int i, j, indexMin, temp;
   for (i = 0; i < n-1; i++) {
      indexMin = i;
      for (j = i + 1; j < n; j++) {
         if (arr[j] < arr[indexMin]) {
            indexMin = j;
         }
      }
      if (indexMin != i) {
         temp = arr[i];
         arr[i] = arr[indexMin];
         arr[indexMin] = temp;
      }
   }
}
void display(int arr[], int n){
   int i;
   for (i=0; i < n; i++)
      printf("%d ", arr[i]);
   printf("\n");
}
int main(){
   int arr[] = {15, 56, 3, 2, 8, 67, 9, 20, 37};
   int n = sizeof(arr)/sizeof(arr[0]);
   printf("Original array: ");
   display(arr, n);
   selectionSort(arr, n);
   printf("Sorted array in Ascending Order: ");
   display(arr, n);
   return 0;
}