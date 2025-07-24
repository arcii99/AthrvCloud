//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ada Lovelace
#include <stdio.h>

void decimal_to_binary(int decimal_num){
   int binary_num[1000], i = 0;
   while(decimal_num > 0){
      binary_num[i] = decimal_num % 2;
      decimal_num = decimal_num / 2;
      i++;
   }
   for(int j = i-1;j >= 0;j--)
      printf("%d", binary_num[j]);
}

int main(){
   int decimal_num;
   printf("Enter a decimal number: ");
   scanf("%d", &decimal_num);
   printf("Binary equivalent is: ");
   decimal_to_binary(decimal_num);
   return 0;
}