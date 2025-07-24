//FormAI DATASET v1.0 Category: Memory management ; Style: excited
//Let's start by including the necessary libraries
#include<stdio.h>
#include<stdlib.h>

//Now, let's create some magic with our memory allocation

int main()
{
  //We'll start by allocating memory using malloc
  int *ptr = (int*)malloc(sizeof(int)*5);
  
  //In case the memory allocation fails, we'll use a condition to exit the program
  if(ptr == NULL)
  {
    printf("Memory allocation failed! Exiting program...\n");
    return 1;
  }
  
  //Now, let's assign some values to our allocated memory
  for(int i = 0; i < 5; i++)
  {
    *(ptr+i) = i+1;
  }
  
  //Printing the values of our allocated memory
  printf("The values of our allocated memory are:\n");
  for(int i = 0; i < 5; i++)
  {
    printf("%d  ", *(ptr+i));
  }
  printf("\n");
  
  //Now, let's try reallocating memory using realloc
  ptr = (int*)realloc(ptr,sizeof(int)*10);
  
  //Again, in case of memory allocation failure, we'll exit the program
  if(ptr == NULL)
  {
    printf("Memory allocation failed! Exiting program...\n");
    return 1;
  }
  
  //Assigning some more values to the reallocated memory
  for(int i = 5; i < 10; i++)
  {
    *(ptr+i) = i+1;
  }
  
  //Printing the values of our reallocated memory
  printf("The values of our reallocated memory are:\n");
  for(int i = 0; i < 10; i++)
  {
    printf("%d  ", *(ptr+i));
  }
  
  //Now, we'll free the allocated memory using free
  free(ptr);
  
  //Finally, we'll return 0 as the program executed successfully
  return 0;
}