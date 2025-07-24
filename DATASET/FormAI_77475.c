//FormAI DATASET v1.0 Category: Syntax parsing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
   char input[1000], *token;
   int num_tokens = 0;
 
   printf("Enter a C program:\n");
   fgets(input, sizeof(input), stdin); // get program input from user
 
   token = strtok(input, " "); // tokenize the input string based on spaces

   while(token != NULL){ // loop through tokens
      num_tokens++;

      if(strcmp(token, "int") == 0){ // if token is 'int'
         printf("int i = 0;\n"); // generate code to initialize integer variable 'i'
      }
 
      else if(strcmp(token, "float") == 0){ // if token is 'float'
         printf("float f = 0.0;\n"); // generate code to initialize float variable 'f'
      }

      else if(strcmp(token, "char") == 0){ // if token is 'char'
         printf("char c = 'a';\n"); // generate code to initialize char variable 'c'
      }

      else if(strcmp(token, "if") == 0){ // if token is 'if'
         printf("if(i == 0){\n\tprintf(\"i is zero!\\n\");\n}\n"); // generate code for conditional statement
      }

      else if(strcmp(token, "for") == 0){ // if token is 'for'
         printf("for(int j = 0; j < 10; j++){\n\tprintf(\"j = %d\\n\", j);\n}\n"); // generate code for a for loop
      }

      else{ // if token does not match any of the C keywords
         printf("Unknown token: %s\n", token);
      }

      token = strtok(NULL, " "); // get next token in string
   }

   printf("Parsed %d tokens.\n", num_tokens); // print number of tokens parsed
 
   return 0;
}