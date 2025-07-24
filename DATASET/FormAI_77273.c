//FormAI DATASET v1.0 Category: Binary Converter ; Style: protected
#include<stdio.h>

//function to convert decimal to binary
void decToBinary(int n)
{
   int binaryNum[1000];
   int i = 0;
   while (n > 0) {
      binaryNum[i] = n % 2;
      n = n / 2;
      i++;
   }

   //printing binary number in reverse order
   for (int j = i - 1; j >= 0; j--)
      printf("%d", binaryNum[j]);
}

//function to convert binary to decimal
int binaryToDecimal(int n)
{
   int decimalNumber = 0, i = 0, remainder;
   while (n!=0) {
      remainder = n % 10;
      n /= 10;
      decimalNumber += remainder * pow(2,i);
      ++i;
   }
   return decimalNumber;
}

//main function
int main()
{
   int choice, decimalNumber, binaryNumber;

   //menu
   printf("Choose an option:\n");
   printf("1. Decimal to Binary Conversion\n");
   printf("2. Binary to Decimal Conversion\n");
   scanf("%d", &choice);

   switch(choice)
   {
      //decimal to binary conversion
      case 1:
         printf("Enter a decimal number: ");
         scanf("%d", &decimalNumber);
         printf("The binary conversion of %d is: ", decimalNumber);
         decToBinary(decimalNumber);
         break;

      //binary to decimal conversion
      case 2:
         printf("Enter a binary number: ");
         scanf("%d", &binaryNumber);
         printf("The decimal conversion of %d is: %d", binaryNumber, binaryToDecimal(binaryNumber));
         break;

      //invalid input
      default:
         printf("Invalid choice!");
   }

   return 0;
}