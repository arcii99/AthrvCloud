//FormAI DATASET v1.0 Category: Syntax parsing ; Style: medieval
#include <stdio.h>

int main() {
   char input[50];
   int i, count = 0;

   printf("Ahoy! Thou shall enter thy sentence: ");
   fgets(input, sizeof(input), stdin);

   for(i=0; input[i]!='\0'; i++) {
      if(input[i]=='c' || input[i]=='C') {
         count++;
      }
   }

   printf("\nVerily, thou hath used the letter C %d times in thy sentence. \n", count);
   printf("Now, let me parse thy sentence in medieval style: \n");

   for(int j=0; input[j]!='\0'; j++) {
        if(input[j] == '{') printf("\"Hark!\" ye olde wizard shouted. \"I see the start of a function.\"\n");
        else if(input[j] == '}') printf("\"Methinks this be the end of a function. \" sayeth the wizard cautiously.\n");
        else if(input[j] == '(') printf("\"Marry, this doth indicate we are beginning an argument list.\" saith the scholar knowledgably.\n");
        else if(input[j] == ')') printf("\"Lo, the argument list doth come to an end.\" quoth the sage grandiosely.\n");
        else if(input[j] == ';') printf("\"A semicolon be Here!\" exclameth the jester foolishly.\n");
        else if((input[j] >= 'a' && input[j] <= 'z') || (input[j] >= 'A' && input[j] <= 'Z')) printf("%c",input[j]);
        else printf("%c",input[j]);
   }

   return 0;
}