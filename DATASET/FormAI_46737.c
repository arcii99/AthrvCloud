//FormAI DATASET v1.0 Category: Educational ; Style: beginner-friendly
// This is a simple program to generate a multiplication table up to a number provided by the user

#include <stdio.h>

int main() {
   int number, limit;
   printf("Enter a number to generate the multiplication table: ");
   scanf("%d", &number);
   printf("Enter the limit of the multiplication table: ");
   scanf("%d", &limit);

   for(int i = 1; i <= limit; i++){
     printf("%d x %d = %d \n", number, i, number*i);
   }
   
   return 0;
}