//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: active
#include <stdio.h>
#include <string.h>

char* c_to_cat(char* c_string) {
   int length = strlen(c_string);
   char* cat_string = calloc((length+1)*3, sizeof(char));
   
   for(int i = 0; i < length; i++) {
      if(c_string[i] == 'C') {
         strcat(cat_string, "Meow");
      } else if(c_string[i] == 'c') {
         strcat(cat_string, "meow");
      } else {
         char temp[2];
         temp[0] = c_string[i];
         temp[1] = '\0';
         strcat(cat_string, temp);
      }
      
      if(i != length - 1) {
         strcat(cat_string, " ");
      }
   }
   
   return cat_string;
}

int main() {
   char c_string[] = "Hello C Cat Language Translator";
   
   char* cat_string = c_to_cat(c_string);
   
   printf("%s\n", cat_string);
   
   free(cat_string);
   
   return 0;
}