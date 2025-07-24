//FormAI DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>

#define SIZE 10

int search(int arr[], int target){
   for(int i=0; i<SIZE; i++){
      if(arr[i] == target){
         return i;
      }
   }
   return -1;
}

int main(void) {
    int arr[SIZE] = {4, 2, 9, 5, 1, 8, 6, 3, 0, 7};
    int target = 5;
    int result = search(arr, target);
    if(result != -1){
        printf("Element %d found at index %d.\n", target, result);
    }
    else{
        printf("Element not found.\n");
    }
    return 0;
}