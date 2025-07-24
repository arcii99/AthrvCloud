//FormAI DATASET v1.0 Category: Math exercise ; Style: recursive
#include<stdio.h>

int mathExercise(int n) {
   if(n == 0) { //base case
      return 0;
   } else if(n == 1) { //base case
      return 1;
   } else { //recursive case
      return mathExercise(n-1) + mathExercise(n-2);
   }
}

int main() {
   int n, i;
   printf("Enter the number of terms: ");
   scanf("%d", &n);
   printf("Fibonacci series using recursive function is:\n");
   for(i=0; i<n; i++) {
      printf("%d ", mathExercise(i));
   }
   return 0;
}