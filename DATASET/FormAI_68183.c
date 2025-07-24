//FormAI DATASET v1.0 Category: Syntax parsing ; Style: realistic
#include <stdio.h>
#include <string.h>

int main() {
   char str[100], keywords[50][50] = {"int", "float", "double", "char", "if", "else", "return", "break", "continue"};
   int i, j, flag;

   printf("Enter a C code: ");
   fgets(str, sizeof(str), stdin);

   i = 0;
   while(str[i] != '\0') {
      char word[50];
      int w = 0;

      while(str[i] != ' ' && str[i] != ';' && str[i] != '(' && str[i] != ')' && str[i] != '{' && str[i] != '}' && str[i] != '\n' && str[i] != '\t' && str[i] != '\r' && str[i] != '\v' && str[i] != '\f' && str[i] != '\0') {
         word[w] = str[i];
         w++;
         i++;
      }

      word[w] = '\0';

      flag = 0;
      for(j = 0; j < 9; j++) {
         if(strcmp(word, keywords[j]) == 0) {
            printf("%s is a keyword.\n", word);
            flag = 1;
            break;
         }
      }

      if(flag == 0) {
         printf("%s is not a keyword.\n", word);
      }

      if(str[i] == '\0') {
         break;
      }

      i++;
   }

   return 0;
}