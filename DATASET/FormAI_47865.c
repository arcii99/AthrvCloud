//FormAI DATASET v1.0 Category: Text Summarizer ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
   char input_string[200], output_string[200];
   printf("Enter a text to be summarized:\n");
   scanf("%[^\n]%*c", input_string);

   int length = strlen(input_string);

   if (length <= 50) {
       strcpy(output_string, input_string);
   } else {
       int counter = 0;
       for (int i = 0; i < length; i++) {
           if (input_string[i] == '.') {
               counter++;
           }
           if (counter == 2) {
               strncpy(output_string, input_string, i + 1);
               break;
           }
       }
       strcat(output_string, " ...");
   }

   printf("Original text:\n%s\n\n", input_string);
   printf("Summarized text:\n%s\n", output_string);

   return 0;
}