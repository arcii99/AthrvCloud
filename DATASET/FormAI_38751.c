//FormAI DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>  
#include <stdlib.h>  
  
int main()  
{  
   int *ptr, i, n, sum = 0;  
  
   printf("Enter number of elements: ");  
   scanf("%d", &n);  
  
   ptr = (int*) malloc(n * sizeof(int));  // allocate memory dynamically  
  
   if(ptr == NULL)                     
   {  
       printf("Error! Memory not allocated.");  
       exit(0);  
   }  
  
   printf("Enter elements of array: \n");  
   for(i = 0; i < n; ++i)  
   {  
       scanf("%d", ptr + i);   // taking input from user  
       sum += *(ptr + i);      // calculating sum  
   }  
  
   printf("Sum = %d", sum);  
  
   free(ptr);  // deallocating the memory  
  
   return 0;  
}