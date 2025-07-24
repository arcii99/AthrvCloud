//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: irregular
#include <stdio.h>
#include <string.h>

int main() {
   char input[100];
   char morse[27][10] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
                          "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."}; //Morse code for letters A to Z

   printf("Please enter a message in uppercase: ");
   fgets(input, 100, stdin); //Get user input
   
   for(int i = 0; i < strlen(input); i++) {
      if(input[i] == ' ') {
         printf(" \n"); //Print a newline character if input is a space
      }
      else if(input[i] >= 'A' && input[i] <= 'Z') {
         int index = input[i] - 'A'; //Get the index of the corresponding letter in the Morse code array
         printf("%s ", morse[index]); //Print the Morse code for the corresponding letter and a space
      }
   }
   
   return 0;
}