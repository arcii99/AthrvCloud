//FormAI DATASET v1.0 Category: Memory management ; Style: puzzling
#include<stdio.h> 
  
int main() 
{ 
   int *ptr, *ptr1, *ptr2; 
   
   // Allocate memory for ptr
   ptr = (int*)malloc(5*sizeof(int)); 
  
   // Make ptr puzzle
   *ptr = 1; *(ptr + 1) = 2; *(ptr + 2) = 3; *(ptr + 3) = 4; *(ptr + 4) = 5; 
  
   // Print the puzzle
   printf("The puzzle is:  %d ", *ptr++);
   printf("%d ", *ptr+2);
   printf("%d ", *ptr1++);
   printf("%d ", *++ptr1);
   printf("%d ", *ptr2++);
   printf("%d", *ptr1+2);
   
   // Deallocate memory
   free(ptr); 
  
   return 0; 
}