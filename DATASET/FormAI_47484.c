//FormAI DATASET v1.0 Category: Random ; Style: innovative
#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>  

int main() {  
   int i, rand_num;  
   srand(time(0)); // seeding the random number generator with current time  
   
   printf("Welcome to the Random Number Generator Program!\n");  
   printf("This program will generate 10 random numbers between 1 and 100.\n");  
   
   for(i = 1; i <= 10; i++) {  
      rand_num = rand() % 100 + 1; // generating a random number between 1 and 100  
      printf("Random Number %d: %d\n", i, rand_num);  
   }  

   printf("Thank you for using the Random Number Generator Program!");  
   
   return 0;  
}