//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: automated
#include <stdio.h>
#include <string.h>

// Function to convert a character to Morse code
char* toMorse(char c) {
   switch (c) {
      case 'a': 
         return ".-";
      case 'b': 
         return "-...";
      case 'c': 
         return "-.-.";
      case 'd': 
         return "-..";
      case 'e': 
         return ".";
      case 'f': 
         return "..-.";
      case 'g': 
         return "--.";
      case 'h': 
         return "....";
      case 'i': 
         return "..";
      case 'j': 
         return ".---";
      case 'k': 
         return "-.-";
      case 'l': 
         return ".-..";
      case 'm': 
         return "--";
      case 'n': 
         return "-.";
      case 'o': 
         return "---";
      case 'p': 
         return ".--.";
      case 'q': 
         return "--.-";
      case 'r': 
         return ".-.";
      case 's': 
         return "...";
      case 't': 
         return "-";
      case 'u': 
         return "..-";
      case 'v': 
         return "...-";
      case 'w': 
         return ".--";
      case 'x': 
         return "-..-";
      case 'y': 
         return "-.--";
      case 'z': 
         return "--..";
      case ' ': 
         return "/";
      default:
         return "";
   }
}

int main() {
   char message[100];
   printf("Enter the message to be converted to Morse code: ");
   gets(message); // NOTE: gets() is not safe to use but is used here for simplicity
   int len = strlen(message);
   printf("Morse code translation: ");
   for (int i=0; i<len; i++) {
      char c = message[i];
      if (c >= 'a' && c <= 'z') {
         printf("%s ", toMorse(c));
      }
   }
   return 0;
}