//FormAI DATASET v1.0 Category: Bitwise operations ; Style: all-encompassing
#include<stdio.h>

int bitwise_or(int num1, int num2){
   return num1 | num2; //Bitwise OR operation
}

int bitwise_and(int num1, int num2){
   return num1 & num2; //Bitwise AND operation
}

int bitwise_xor(int num1, int num2){
   return num1 ^ num2; //Bitwise XOR operation
}

int main(){
   int num1 = 15; //1111 in binary
   int num2 = 7;  //0111 in binary

   printf("Bitwise OR: %d\n", bitwise_or(num1, num2));   //1111 | 0111 = 1111
   printf("Bitwise AND: %d\n", bitwise_and(num1, num2)); //1111 & 0111 = 0111
   printf("Bitwise XOR: %d\n", bitwise_xor(num1, num2)); //1111 ^ 0111 = 1000

   num1 = 10; //1010 in binary
   num2 = 6;  //0110 in binary

   printf("Bitwise OR: %d\n", bitwise_or(num1, num2));   //1010 | 0110 = 1110
   printf("Bitwise AND: %d\n", bitwise_and(num1, num2)); //1010 & 0110 = 0010
   printf("Bitwise XOR: %d\n", bitwise_xor(num1, num2)); //1010 ^ 0110 = 1100

   num1 = 23; //10111 in binary
   num2 = 15; //01111 in binary

   printf("Bitwise OR: %d\n", bitwise_or(num1, num2));   //10111 | 01111 = 11111
   printf("Bitwise AND: %d\n", bitwise_and(num1, num2)); //10111 & 01111 = 0011
   printf("Bitwise XOR: %d\n", bitwise_xor(num1, num2)); //10111 ^ 01111 = 1100

   return 0;
}