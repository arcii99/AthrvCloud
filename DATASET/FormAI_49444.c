//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
   printf("Welcome to C RAM Usage Monitor Program\n");
   
   int i = 0;
   
   while(1) {
       char* p = malloc(1024000); // allocate 1 MB of memory
       if (p == NULL) {
           printf("Out of memory!\n");
           break;
       }
       printf("Malloced 1 MB of memory #%d\n", i++);
       sleep(1); // wait for 1 second
       free(p); // free the memory
       printf("Freed 1 MB of memory #%d\n", i++);
       sleep(1); // wait for 1 second
   }
   
   printf("Exiting the C RAM Usage Monitor Program\n");
   
   return 0;
}