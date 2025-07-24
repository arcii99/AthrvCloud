//FormAI DATASET v1.0 Category: Memory management ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

int main(){
  int n, i, *ptr; //declare variable
  printf("Enter the size of the array: "); 
  scanf("%d", &n); //get size from user

  ptr = (int*) malloc(n * sizeof(int)); //allocating memory dynamically

  if(ptr == NULL)                     
  {
    printf("Error! memory not allocated."); //if memory is not allocated
    exit(0);
  }

  printf("Enter elements of array: \n");
  for(i = 0; i < n; ++i)
  {
    scanf("%d", ptr + i); //taking user input
  }

  printf("The elements of the array are: \n");    
  for(i = 0; i < n; ++i)
  {
    printf("%d ", *(ptr + i)); //printing the elements of array
  }

  free(ptr); //deallocating the memory
  return 0;
}