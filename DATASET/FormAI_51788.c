//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* textToMorseCode(char*);

int main() {
   char message[100];
   
   printf("Type a message to convert to Morse code: ");
   fgets(message, 100, stdin);

   char* converted_message = textToMorseCode(message);
   printf("The message in Morse code: %s\n", converted_message);
   
   free(converted_message);
   return 0;
}

char* textToMorseCode(char* text) {
   int i, j;

   char* morseCode[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                     ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
                     "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", 
                     ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

   int textLength = strlen(text);
   char* convertedMessage = (char*) malloc(sizeof(char) * textLength * 8);

   for(i=0; i<textLength; i++) {
      if(text[i] == ' ') {
         strcat(convertedMessage, " / ");
      }
      else {
         for(j=0; j<36; j++) {
            if(text[i] == 'A' + j || text[i] == 'a' + j) {
               strcat(convertedMessage, morseCode[j]);
               strcat(convertedMessage, " ");
            }
         }
      }
   }

   return convertedMessage;
}