//FormAI DATASET v1.0 Category: Bitwise operations ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){
   printf("Hello, I am a mischievous chatbot and I'm going to show you the magic of bitwise operations in C.\n");

   // Let's declare some variables
   int a = 42; // 00101010 in binary
   int b = 23; // 00010111 in binary

   // Bitwise AND
   printf("Let's perform a bitwise AND operation between %d and %d\n", a, b);
   int result1 = a & b;
   printf("Result: %d\n", result1);

   // Bitwise OR
   printf("Now let's perform a bitwise OR operation between %d and %d\n", a, b);
   int result2 = a | b;
   printf("Result: %d\n", result2);

   // Bitwise XOR
   printf("We can also perform a bitwise XOR operation between %d and %d\n", a, b);
   int result3 = a ^ b;
   printf("Result: %d\n", result3);

   // Bitwise complement
   printf("Let's see the magic of bitwise complement operation on %d\n", a);
   int result4 = ~a;
   printf("Result: %d\n", result4);

   // Left shift
   printf("Now we're gonna shift %d left by 2\n", a);
   int result5 = a << 2;
   printf("Result: %d\n", result5);

   // Right shift
   printf("Lastly, let's shift %d right by 3\n", b);
   int result6 = b >> 3;
   printf("Result: %d\n", result6);

   // The end
   printf("That's it for today folks! I hope you enjoyed our little adventure with bitwise operations. Come back soon for more fun!\n");

   return 0;
}