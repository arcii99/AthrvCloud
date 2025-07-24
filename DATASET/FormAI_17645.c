//FormAI DATASET v1.0 Category: Educational ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
   printf("Welcome to our ephemeral style C program!\n\n");
   
   // Generate a random number
   int randNum = rand() % 10 + 1;
   printf("Random Number: %d\n\n", randNum);
   
   // Declare an array of characters
   char message[] = "Hello, World!";
   
   // Loop through the array and print each character
   for (int i = 0; i <= sizeof(message); i++) {
      printf("%c", message[i]);
   }
   printf("\n\n");
   
   // Declare a variable and assign it a value
   int x = 5;
   
   // Use a ternary operator to print a message based on whether x is less than or greater than 10
   printf("%s\n\n", (x < 10) ? "x is less than 10" : "x is greater than 10");
   
   // Declare a function that takes two integers as arguments and returns their sum
   int add(int a, int b) {
      return a + b;
   }
   
   // Call the function and print the result
   printf("3 + 5 = %d\n\n", add(3, 5));
   
   // Declare a structure
   struct Car {
      char make[20];
      char model[20];
      int year;
   };
   
   // Declare a variable of type Car and initialize its values
   struct Car myCar = {"Honda", "Civic", 2020};
   
   // Print the values of the myCar variable
   printf("Make: %s\nModel: %s\nYear: %d\n\n", myCar.make, myCar.model, myCar.year);
   
   // Declare a pointer and use it to store the address of x
   int *ptr = &x;
   
   // Print the value of x and the address of x using the pointer
   printf("Value of x: %d\nAddress of x: %p\n\n", *ptr, ptr);
   
   // Use a switch statement to print a message based on the value of randNum
   switch(randNum) {
      case 1 :
         printf("Random Number is 1\n");
         break;
      case 2 :
         printf("Random Number is 2\n");
         break;
      case 3 :
         printf("Random Number is 3\n");
         break;
      case 4 :
         printf("Random Number is 4\n");
         break;
      case 5 :
         printf("Random Number is 5\n");
         break;
      case 6 :
         printf("Random Number is 6\n");
         break;
      case 7 :
         printf("Random Number is 7\n");
         break;
      case 8 :
         printf("Random Number is 8\n");
         break;
      case 9 : 
         printf("Random Number is 9\n");
         break;
      case 10 :
         printf("Random Number is 10\n");
         break;          
   }
   
   return 0;
}