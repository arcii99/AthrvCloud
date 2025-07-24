//FormAI DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

/*Artistic C Searching Algorithm Example*/

void search(int *array, int size, int value){
   int found = 0;
   for(int i = 0; i < size; i++){
      if(array[i] == value){
        found = 1;
        printf("Value %d found at index %d.\n", value, i);
        break; //Exit the loop if the value is found
      }
   }
   if(found != 1){
      printf("Value not found in the array.\n");
   }
}

int main(){
   int length, key, index;
   printf("Enter the length of the array: ");
   scanf("%d", &length);
   int *arr = (int*)calloc(length, sizeof(int)); //Allocate memory for the array
   printf("Enter the elements of the array: ");
   for (int i = 0; i < length; i++){
      scanf("%d", &arr[i]);
   }
   printf("Enter key to search for: ");
   scanf("%d", &key);
   search(arr, length, key);
   free(arr); //Free the allocated memory
   return 0;
}