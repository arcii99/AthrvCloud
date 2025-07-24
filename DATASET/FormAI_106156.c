//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {

   char c[50];

   printf("Enter a sentence in C Cat Language: ");
   fgets(c, sizeof(c), stdin);

   if(strstr(c, "meow")) {
      printf("Translation: Hello!\n");
   }
   else if(strstr(c, "purr")) {
      printf("Translation: I am happy.\n");
   }
   else if(strstr(c, "hiss")) {
      printf("Translation: I am angry.\n");
   }
   else if(strstr(c, "mrow")) {
      printf("Translation: Can I have food?\n");
   }
   else if(strstr(c, "stare")) {
      printf("Translation: I am curious.\n");
   }
   else if(strstr(c, "nap")) {
      printf("Translation: I am sleepy.\n");
   }
   else if(strstr(c, "scratch")) {
      printf("Translation: I am itchy.\n");
   }
   else {
      printf("Translation: I don't understand what you're saying.\n");
   }

   return 0;
}