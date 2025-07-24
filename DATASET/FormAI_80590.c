//FormAI DATASET v1.0 Category: Recursive ; Style: Sherlock Holmes
#include<stdio.h>

int findSum(int num) {
   if(num == 1) {
      return 1;
   }
   else {
      return num + findSum(num - 1);
   }
}

int main() {

   int num = 10;
   int sum;

   sum = findSum(num);

   printf("The sum of first %d natural numbers is %d", num, sum);
   return 0;
}