//FormAI DATASET v1.0 Category: Word Count Tool ; Style: random
#include <stdio.h>
#include <ctype.h>

// function to count words in a string
int countWords(char *str) {
   int state = 0, i = 0, cnt = 0;
   while (str[i]) {
       if (isspace(str[i]))
           state = 0;
       else if (state == 0) {
           state = 1;
           cnt++;
        }
       i++;
   }
   return cnt;
}

int main() {

   // prompt user to input a string
   char str[1000];
   printf("Enter a string to count the words: ");
   fgets(str, 1000, stdin);  // read input from user
   
   // change all capital letters in the string to lowercase
   int i = 0;
   while (str[i]) {
      if (str[i] >= 'A' && str[i] <= 'Z')
         str[i] = tolower(str[i]);
      i++;
   }
   
   // count the number of words in the string
   int count = countWords(str);
   
   // print the output
   printf("\nNumber of words in the string: %d", count);
   
   return 0;
}