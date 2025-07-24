//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

void energy(int n) {

   if(n == 0) {
       printf("You have no energy left!\n");
       return;
   }

   printf("You have %d energy left! Let's use it up!\n", n);
   energy(n-1);
}

int main() {
   int n;
   printf("How much energy do you have?\n");
   scanf("%d", &n);
   energy(n);
   return 0;
}