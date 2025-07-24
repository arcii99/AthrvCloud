//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: thoughtful
#include <stdio.h>

int main() {
   int input;
   int checksum = 0;

   printf("Enter the number of integers you want to calculate: ");
   scanf("%d", &input);

   int array[input];

   printf("Enter the integers: ");
   for(int i = 0; i < input; i++) {
      scanf("%d", &array[i]);
   }

   for(int i = 0; i < input; i++) {
      if(i % 2 == 0) {
         checksum += array[i] * 3;
      } else {
         checksum += array[i];
      }
   }

   checksum = (10 - (checksum % 10)) % 10;

   printf("The checksum is: %d\n", checksum);

   return 0;
}