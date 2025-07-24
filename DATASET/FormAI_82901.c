//FormAI DATASET v1.0 Category: Educational ; Style: complete
#include <stdio.h>

int main() {
   // declare variables
   int num, i, isPrime = 1;

   // ask user for input
   printf("Enter a positive integer: ");
   scanf("%d", &num);

   // check if number is prime
   for (i = 2; i <= num/2; ++i) {
      if (num % i == 0) {
        isPrime = 0;
        break;
      }
   }

   // print result
   if (isPrime) {
      printf("%d is a prime number\n", num);
   } else {
      printf("%d is not a prime number\n", num);
   }

   // calculate and print factorial of number
   int fact = 1, j;
   for (j = num; j > 0; j--) {
      fact *= j;
   }
   printf("The factorial of %d is %d\n", num, fact);

   // declare and initialize array
   int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

   // find sum and average of elements in array
   int sum = 0, k;
   float avg;
   for (k = 0; k < 10; k++) {
      sum += arr[k];
   }
   avg = (float) sum / 10;

   printf("The sum of elements in the array is %d\n", sum);
   printf("The average of elements in the array is %.2f\n", avg);

   return 0;
}