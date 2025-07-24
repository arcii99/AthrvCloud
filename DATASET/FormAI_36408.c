//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: accurate
// Unique C Cat Language Translator
#include <stdio.h>
#include <string.h>

int main()
{
   char cat_language[100] = ""; // initialize cat_language variable
   printf("Enter a sentence in Cat Language (using meows): ");
   fgets(cat_language, sizeof(cat_language), stdin); // read input from console

   // replace meows with human words
   char* words[10][2] = {
      {"meow", "hello"},
      {"meow meow", "how are you"},
      {"meow meow meow", "I am fine"},
      {"meow meow meow meow", "that is great to hear"},
      {"meow meow meow meow meow", "I am hungry"},
      {"meow meow meow meow meow meow", "do you have any food?"},
      {"meow meow meow meow meow meow meow", "where is the food?"},
      {"meow meow meow meow meow meow meow meow", "thank you for the food"},
      {"meow meow meow meow meow meow meow meow meow", "I am sleepy"},
      {"meow meow meow meow meow meow meow meow meow meow", "good night"}
   };

   char human_sentence[100] = ""; //initialize human_sentence variable

   // loop through the meows and append human words to human_sentence
   char* token = strtok(cat_language, " \n");
   while(token != NULL){
      for(int i=0; i<10; i++){
         if(strcmp(token,words[i][0])==0){
            strcat(human_sentence, words[i][1]);
            strcat(human_sentence, " ");
         }
      }
      token = strtok(NULL, " \n");
   }

   printf("The sentence in human language is: %s", human_sentence);

   return 0;
}