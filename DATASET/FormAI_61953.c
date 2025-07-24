//FormAI DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>  
#include <stdlib.h>  

int main() {  

   char command[1000];  
   printf("Enter the Linux command you want to execute:\n");  
   fgets(command, sizeof(command), stdin); // Get user input from stdin  
   system(command); // Execute the command using the system function  
   
   return 0;  
}