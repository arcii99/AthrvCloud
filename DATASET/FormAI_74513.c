//FormAI DATASET v1.0 Category: Memory management ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

int main(){
   int* ptr;
   int n, i;
 
   printf("Enter number of elements: ");
   scanf("%d",&n);
 
   ptr = (int*)malloc(n * sizeof(int)); 
  
   if(ptr == NULL)
   {
      printf("Memory not allocated.\n");
      exit(0);
   }
   else
   {
      printf("Memory allocated successfully.\n");
 
      for(i=0; i<n; ++i)
      {
         printf("Enter element %d: ",i+1);
         scanf("%d",ptr+i);
      }
 
      printf("The elements entered are: ");
      for(i=0; i<n; ++i)
      {
         printf("%d ",*(ptr+i));
      }

      free(ptr);
      printf("\nMemory freed successfully.\n");
   }
 
   return 0;
}