//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: grateful
#include <stdio.h>
#include <string.h>

int main()
{
   char cat_sound[] = "*meow*";
   char user_input[100];
   int translate_counter = 0;

   printf("Welcome! I am your C Cat Language Translator. \n");
   printf("Please input a sentence that you would like me to translate into C Cat Language: \n");

   fgets(user_input, sizeof(user_input), stdin);
   strtok(user_input, "\n"); // remove trailing newline character

   printf("\nYour translated sentence is: \n");

   for (int i = 0; i < strlen(user_input); i++)
   {
      char current_char = user_input[i];

      if (current_char == ' ')
      {
         printf(" ");
         continue;
      }

      printf("%c", cat_sound[translate_counter]);

      translate_counter++;

      if (translate_counter >= strlen(cat_sound))
      {
         translate_counter = 0;
      }
   }

   printf("\n\nThank you for using the C Cat Language Translator. Goodbye!\n");

   return 0;
}