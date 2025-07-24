//FormAI DATASET v1.0 Category: Text processing ; Style: shocked
#include <stdio.h>

int main() {
   char input[100];

   printf("Enter a sentence: ");
   fgets(input, 100, stdin);   // read input from user

   printf("Processed sentence: ");
   for(int i = 0; input[i] != '\0'; i++) {
       if(input[i] >= 'A' && input[i] <= 'Z') {  // convert uppercase letters to lowercase
           input[i] = input[i] + 32;
       } else if(input[i] >= 'a' && input[i] <= 'z') { // convert lowercase letters to uppercase
           input[i] = input[i] - 32;
       } else if(input[i] == ' ') {  // replace spaces with underscores
           input[i] = '_';
       } else if(input[i] == '\n') {  // remove newline character
           input[i] = '\0';
       }
       printf("%c", input[i]);  // print processed character
   }

   return 0;
}