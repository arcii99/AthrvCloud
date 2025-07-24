//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertToMorse(char letter);

int main() {
   char message[100];
   int i;
   
   printf("Enter the message you want to convert to Morse Code:\n");
   fgets(message, 100, stdin);
   // Remove newline characters from input string
   message[strcspn(message, "\n")] = 0;

   printf("\nMorse Code:\n");
   for(i = 0; i < strlen(message); i++) {
      if(isalpha(message[i])) {
         convertToMorse(toupper(message[i]));
      } else if(message[i] == ' ') {
         printf(" ");
      } else {
         printf("\nInvalid character: %c\n", message[i]);
         printf("Morse Code conversion stopped.\n");
         return 0;
      }
      printf(" ");
   }

   printf("\nMorse Code conversion completed.\n");
   return 0;
}

void convertToMorse(char letter) {
   switch(letter) {
      case 'A':
         printf(".-");
         break;
      case 'B':
         printf("-...");
         break;
      case 'C':
         printf("-.-.");
         break;
      case 'D':
         printf("-..");
         break;
      case 'E':
         printf(".");
         break;
      case 'F':
         printf("..-.");
         break;
      case 'G':
         printf("--.");
         break;
      case 'H':
         printf("....");
         break;
      case 'I':
         printf("..");
         break;
      case 'J':
         printf(".---");
         break;
      case 'K':
         printf("-.-");
         break;
      case 'L':
         printf(".-..");
         break;
      case 'M':
         printf("--");
         break;
      case 'N':
         printf("-.");
         break;
      case 'O':
         printf("---");
         break;
      case 'P':
         printf(".--.");
         break;
      case 'Q':
         printf("--.-");
         break;
      case 'R':
         printf(".-.");
         break;
      case 'S':
         printf("...");
         break;
      case 'T':
         printf("-");
         break;
      case 'U':
         printf("..-");
         break;
      case 'V':
         printf("...-");
         break;
      case 'W':
         printf(".--");
         break;
      case 'X':
         printf("-..-");
         break;
      case 'Y':
         printf("-.--");
         break;
      case 'Z':
         printf("--..");
         break;
      default:
         printf("Unknown letter: %c", letter);
   }
}