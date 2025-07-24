//FormAI DATASET v1.0 Category: Word Count Tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//function to count words in a string
int countWords(char str[]) {
   int state = 0;
   int wc = 0;  // word count
 
   // Scan all characters one by one
   for (int i = 0; i < strlen(str); i++) {
       // If next character is a separator, set the state as OUT
       if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
           state = 0;
       // If next character is not a separator and state is OUT, then set the state to IN and increment word count
       else if (state == 0) {
           state = 1;
           wc++;
       }
   }
   return wc;
}

int main() {
   char str[100];
   printf("Enter a string: ");
   fgets(str, 100, stdin);
   printf("Number of words = %d", countWords(str));
   return 0;
}