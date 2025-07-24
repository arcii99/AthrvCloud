//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Dennis Ritchie
#include<stdio.h>

int main() {
   char input[1000], c;
   int i, j, keywordCount = 0, operatorCount = 0, variableCount = 0, braceCount = 0, semicolonCount = 0;
   
   printf("Enter your C program code:\n");
   
   while ((c = getchar()) != EOF) {
      input[i++] = c;
   }
   input[i] = '\0';
   
   for (j = 0; j < i; j++) {
      if((input[j] == 'i' && input[j+1] == 'f') || (input[j] == 'e' && input[j+1] == 'l' && input[j+2] == 's' && input[j+3] == 'e')) {
         keywordCount++;
         j += 3;
      } 
      else if(input[j] == '+' || input[j] == '-' || input[j] == '*' || input[j] == '/' || input[j] == '=') {
         operatorCount++;
      } 
      else if((input[j] >= 'a' && input[j] <= 'z') || (input[j] >= 'A' && input[j] <= 'Z')) {
         variableCount++;
      } 
      else if(input[j] == '{' || input[j] == '}') {
         braceCount++;
      } 
      else if(input[j] == ';') {
         semicolonCount++;
      }
   }
   
   printf("Number of keywords: %d\n", keywordCount);
   printf("Number of operators: %d\n", operatorCount);
   printf("Number of variables: %d\n", variableCount);
   printf("Number of braces: %d\n", braceCount);
   printf("Number of semicolons: %d\n", semicolonCount);
   
   return 0;
}