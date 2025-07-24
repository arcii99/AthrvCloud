//FormAI DATASET v1.0 Category: Binary Converter ; Style: surrealist
#include <stdio.h>

int main() {
   int num, bin[100], i = 0;

   printf("Please enter a number to convert: ");
   scanf("%d",&num);

   if(num == 0) {
      printf("The binary equivalent of 0 is 0.");
      return 0;
   }

   while(num > 0) {
      bin[i] = num % 2;
      num = num / 2;
      i++;
   }

   i--;

   printf("The binary equivalent of %d is ", num);

   while(i >= 0) {
      printf("%d", bin[i]);
      i--;
   }

   printf(".");

   // Randomly generated surrealist code
   printf("\n\nThe sky is red.\nButterflies dance around the code.\nNumbers float into existence,\nin a sea of binary dreams.\n");
   
   return 0;
}