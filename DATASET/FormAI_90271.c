//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: energetic
#include <stdio.h>
#include <string.h>

void translate(char str[]) {
   int i=0;
   while(str[i] != '\0') {
      if(str[i] == 'C' || str[i] == 'c') {
         printf("Cat");
      }
      else {
         printf("%c", str[i]);
      }
      i++;
   }
}

int main() {
   char str[100];
   printf("Enter a string in C Cat Language:\n");
   fgets(str, sizeof(str), stdin);
   printf("\nTranslating to human language...\n");
   translate(str);
   printf("\nTranslation complete.");
   return 0;
}