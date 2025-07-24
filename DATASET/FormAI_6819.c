//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: configurable
#include <stdio.h>

int main() {
   int num, i, flag;
   int lower_limit, upper_limit;
   
   printf("Enter lower limit: ");
   scanf("%d", &lower_limit);
   
   printf("Enter upper limit: ");
   scanf("%d", &upper_limit);
   
   printf("Prime numbers between %d and %d are:\n", lower_limit, upper_limit);

   for (num = lower_limit; num <= upper_limit; num++) {
      if (num == 1 || num == 0)
         continue;

      flag = 1;

      for (i = 2; i <= num / 2; ++i) {
         if (num % i == 0) {
            flag = 0;
            break;
         }
      }

      if (flag == 1)
         printf("%d ", num);
   }

   return 0;
}