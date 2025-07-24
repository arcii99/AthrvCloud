//FormAI DATASET v1.0 Category: Text processing ; Style: accurate
#include <stdio.h>
#include <string.h>

int main() {
   char str[1000];
   int i = 0, count = 0, flag = 0;
   
   printf("Enter a string: ");
   fgets(str, sizeof(str), stdin);  // read input from user
   
   while(str[i] != '\n') {  // loop through each character of string
      if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {  // check if character is a letter
         flag = 1;
         count++;
      } else if(flag == 1) {  // end of the word
         printf("Word length: %d\n", count);
         count = 0;
         flag = 0;
      }
      i++;
   }
   
   if(flag == 1) {  // end of the last word
      printf("Word length: %d\n", count);
   }
   
   return 0;
}