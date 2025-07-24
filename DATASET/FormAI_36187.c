//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multivariable
#include <stdio.h>

int main() {
   char text[100], morse[100];
   int i, j;

   // defining the arrays to store the Morse Codes
   char *Codes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "};
   char *Letters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " "};

   // getting the user input
   printf("Enter the text you want to convert to Morse Code: ");
   fgets(text, 100, stdin);

   // loop through each letter in the text input
   for(i = 0; text[i] != '\0'; i++) {

      // finding the index of the letter in the Letters array
      for(j = 0; j < 27; j++){
         if(text[i] == *Letters[j]) {
            strcat(morse, *(Codes+j));
            strcat(morse, " ");
         }
      }
   }

   printf("Morse Code: %s\n", morse);

   return 0;
}