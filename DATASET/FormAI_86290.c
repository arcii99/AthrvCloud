//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: creative
#include <stdio.h> // Standard Input-Output Library
#include <ctype.h> // Character Type Library
#include <string.h> // C String Library

char *convertToMorseCode(char c) // function to convert a character to morse code
{
   static char *morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "}; // array of morse codes
   char *code; // pointer to hold the morse code
   
   if(isalpha(c)) // if the character is an alphabet
   {
      code = morseCodes[toupper(c) - 'A']; // get the morse code based on the uppercase letter
   }
   else if(isdigit(c)) // if the character is a digit
   {
      code = morseCodes[c - '0' + 25]; // get the morse code based on the number
   }
   else // if the character is not an alphabet or a digit
   {
      code = morseCodes[26]; // get the morse code for space
   }
   
   return code; // return the morse code
}

int main()
{
   char input[100]; // array to hold the input text
   printf("Enter the text to convert to morse code: "); // prompt the user for input
   fgets(input, 100, stdin); // read the input from the user
   
   int length = strlen(input); // get the length of the input string
   char *morseCode[length]; // array to hold the morse code for the input string
   
   for(int i = 0; i < length; i++) // loop through the input string
   {
      morseCode[i] = convertToMorseCode(input[i]); // convert each character to morse code and store it in the array
   }
   
   printf("\nMorse Code: "); // print the label for the morse code
   
   for(int i = 0; i < length; i++) // loop through the morse code array
   {
      printf("%s ", morseCode[i]); // print each morse code separated by a space
   }
   
   return 0; // exit the program
}