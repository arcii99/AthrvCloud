//FormAI DATASET v1.0 Category: Text processing ; Style: safe
#include <stdio.h>
#include <string.h>

int main() {
   char str[1000], keyword[10];
   int count = 0, i;

   printf("Enter text: ");
   fgets(str, sizeof(str), stdin);

   printf("\nEnter keyword to count: ");
   scanf("%s", keyword);

   for(i=0;i<strlen(str);i++) {
       if(str[i] == keyword[0]) {
           if(strncmp(&str[i], keyword, strlen(keyword)) == 0) {
               count++;
           }
       }
   }

   printf("\nTotal occurrences of keyword '%s' is %d", keyword, count);

   return 0;
}