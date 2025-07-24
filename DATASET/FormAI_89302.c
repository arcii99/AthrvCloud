//FormAI DATASET v1.0 Category: Funny ; Style: expert-level
#include <stdio.h>

int main() 
{
     printf("Welcome to the expert-level C fun program!\n\n");
     printf("Let's create a memory leak with a recursive function.\n");
     printf("Don't try this at home, folks.\n\n");

     while(1) // Loop forever
     {
          char *leak = (char*)malloc(sizeof(char)*1000000); // Allocate memory
          printf("Allocated 1MB at address: %p\n", leak);

          // Recursive call
          main();
     }

     return 0;
}