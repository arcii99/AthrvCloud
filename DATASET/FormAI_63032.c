//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: authentic
#include <stdio.h>
#include <string.h>

int main () {

   char cCat[100];
   int i, j, n;

   printf("Enter the C Cat language code : ");
   gets(cCat);

   n = strlen(cCat);

   for(i=0; i<n; i++) {
      if(cCat[i] == 'p' && cCat[i+1] == 'u' && cCat[i+2] == 'r' && cCat[i+3] == 'r') {
         printf("Meow\n");
         i = i + 3;
      } else if(cCat[i] == 'h' && cCat[i+1] == 'i' && cCat[i+2] == 's' && cCat[i+3] == 's') {
         printf("Hiss\n");
         i = i + 3;
      } else if(cCat[i] == 'm' && cCat[i+1] == 'e' && cCat[i+2] == 'o' && cCat[i+3] == 'w') {
         printf("Purr\n");
         i = i + 3;
      } else if(cCat[i] == 's' && cCat[i+1] == 'e' && cCat[i+2] == 'e' && cCat[i+3] == 'k') {
         printf("Hello Human\n");
         i = i + 3;
      } else if(cCat[i] == 'c' && cCat[i+1] == 'l' && cCat[i+2] == 'e' && cCat[i+3] == 'a' && cCat[i+4] == 'n') {
         printf("Clean Yourself Human\n");
         i = i + 4;
      } else {
         printf("%c", cCat[i]);
      }
   }

   return 0;
}