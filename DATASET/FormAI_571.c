//FormAI DATASET v1.0 Category: Memory management ; Style: curious
#include<stdio.h>
#include<stdlib.h>

int main(){
   int *p = NULL;
   p = (int*) malloc(5 * sizeof(int));
   int i = 0;
   printf("Enter the 5 integers that you want to store in dynamic memory: \n"); 
   for(i = 0; i < 5; i++) {
       scanf("%d",&p[i]);
   }
   printf("The 5 integers that you have entered are: \n");
   for(i = 0; i < 5; i++) {
       printf("%d ",p[i]);
   }
   printf("\n");
   printf("Total memory occupied by the 5 integers in dynamic memory is %d bytes.\n", 5 * sizeof(int));
   
   p = (int*) realloc(p, 10 * sizeof(int));
   printf("Enter 5 more integers that you want to add to the dynamic memory: \n");
   for(i = 5; i < 10; i++){
       scanf("%d",&p[i]);
   }
   printf("The 10 integers that you have entered are: \n");
   for(i = 0; i < 10; i++){
       printf("%d ",p[i]);
   }
   printf("\n");
   printf("Total memory occupied by the 10 integers in dynamic memory is %d bytes.\n", 10 * sizeof(int));
   
   free(p);
   printf("The memory has been freed successfully.\n");
   printf("Total memory occupied by the 10 integers after freeing the memory is 0 bytes.\n");
   return 0;
}