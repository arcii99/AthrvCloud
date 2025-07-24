//FormAI DATASET v1.0 Category: Educational ; Style: rigorous
#include<stdio.h>

int main(){
   int a, b, c;
   printf("Enter three numbers separated by space: ");
   scanf("%d %d %d", &a, &b, &c);
   
   // checking if a is greater than b and c
   if (a>b && a>c)
      printf("%d is the largest number.", a);
   
   // checking if b is greater than a and c
   else if (b>a && b>c)
      printf("%d is the largest number.", b);
   
   // if above two conditions are false, then c must be the largest
   else
      printf("%d is the largest number.",c);
      
   return 0;
}