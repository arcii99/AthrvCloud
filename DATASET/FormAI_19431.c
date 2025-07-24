//FormAI DATASET v1.0 Category: HTML beautifier ; Style: excited
#include <stdio.h>
#include <string.h>

void beautify(char *htmlCode) {
   int indent = 0;
   int len = strlen(htmlCode);
   int i = 0;
   int lastChar;

   while(i < len) {
       if(htmlCode[i] == '<') {
           if(htmlCode[i+1] == '/') {
               indent -= 2;
           }
           lastChar = 1;
           printf("\n%*c%c", indent, ' ', htmlCode[i]);
           indent += 2;
           i++;
           while(htmlCode[i] != '>' && i < len) {
               printf("%c", htmlCode[i]);
               i++;
           } 
           printf(">");
           lastChar = 0;
       } else if (htmlCode[i] == '>') {
           printf("%c\n", htmlCode[i]);
           lastChar = 1;
       } else {
           if(lastChar == 1) {
               printf("%*c", indent, ' ');
           }
           printf("%c", htmlCode[i]);
           lastChar = 0;
       }
       i++;
   }
}

int main() {
   char htmlCode[1000];
   printf("Enter your ugly HTML code: ");
   fgets(htmlCode, 1000, stdin);
   beautify(htmlCode);
   return 0;
}