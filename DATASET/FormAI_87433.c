//FormAI DATASET v1.0 Category: Data mining ; Style: enthusiastic
#include <stdio.h>

int main() {
   int arr[5] = {3, 6, 9, 12, 15}; // sample data

   // Let's find the sum of all even numbers in the array
   int sum = 0; // initialize the sum to zero
   for (int i = 0; i < 5; i++) {
       if (arr[i] % 2 == 0) {
           sum += arr[i]; // add the even number to the sum
       }
   }
   printf("The sum of all even numbers in the array is: %d", sum);

   return 0;
}