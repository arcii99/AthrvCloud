//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <string.h>

int main() {
  char text[100], morse[100]; // define strings for input text and morse code output
  int i, j, len; // define variables for loop iteration and string lengths
  
  // define the Morse code array
  const char* morse_code[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", 
                                "....", "..", ".---", "-.-", ".-..", "--", "-.", 
                                "---", ".--.", "--.-", ".-.", "...", "-", "..-", 
                                "...-", ".--", "-..-", "-.--", "--.."};
  
  printf("Enter text to convert to Morse code (uppercase letters only):\n");
  scanf("%[^\n]", text); // read text input from user until newline character
  
  len = strlen(text); // get the length of the text string
  
  // convert each character to Morse code and store in morse string
  for (i = 0; i < len; i++) {
    if (text[i] >= 'A' && text[i] <= 'Z') { // check that the character is uppercase
      j = text[i] - 'A'; // map the character to the corresponding index in the Morse code array
      strcat(morse, morse_code[j]); // concatenate the Morse code for that character to the morse string
      strcat(morse, " "); // add a space between each Morse code character
    }
  }
  
  printf("Morse code: %s\n", morse); // print the Morse code string
  
  return 0;
}