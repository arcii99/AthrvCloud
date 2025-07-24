//FormAI DATASET v1.0 Category: Data recovery tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct file {
   char name[50];
   int size;
   char data[100];
};

int main() {
   struct file *ptr;
   int n, i;

   printf("Enter the number of files: ");
   scanf("%d", &n);

   ptr = (struct file*)malloc(n * sizeof(struct file)); // allocating memory dynamically

   if(ptr == NULL) { // checking if memory allocation was successful or not
      printf("Error! memory not allocated.");
      exit(0);
   }

   printf("Enter the details of each file:\n");

   for(i = 0; i < n; ++i) {
      printf("File %d\n", i+1);
      
      printf("Name: ");
      scanf("%s", (ptr+i)->name);

      printf("Size: ");
      scanf("%d", &(ptr+i)->size);

      printf("Data: ");
      scanf("%s", (ptr+i)->data);
   }

   printf("\nThe files in the system are:\n");
   for(i = 0; i < n; ++i) {
      printf("Name: %s\n", (ptr+i)->name);
      printf("Size: %d\n", (ptr+i)->size);
      printf("Data: %s\n\n", (ptr+i)->data);
   }

   free(ptr); // freeing up the allocated memory

   return 0;
}