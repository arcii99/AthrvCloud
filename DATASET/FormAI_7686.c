//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: artistic
#include <stdio.h>
#include <string.h>

// Function to convert text to Morse code
void textToMorse(char string[]) {
  // Length of input string
  int length = strlen(string);
  
  // Morse code table for each character
  char *morseTable[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                        "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                        "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....",
                        "--...", "---..", "----.", "/", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--",
                        "-..-.", "-.--.", "-.--.-", ".-...", "...-..-", ".-.-.", "-....-", ".--.-."};
  
  // Loop through each character in the input string
  for (int i = 0; i < length; i++) {
    // Convert uppercase characters to lowercase
    char ch = tolower(string[i]);
    int index;
    
    // Get index of current character in Morse code table
    if (ch >= 'a' && ch <= 'z') {
      index = ch - 'a';
    }
    else if (ch == ' ') {
      printf("/ ");
      continue;
    }
    else if (ch >= '0' && ch <= '9') {
      index = ch - '0' + 26;
    }
    else {
      printf("Invalid input!");
      return;
    }
    
    // Print Morse code for current character
    printf("%s ", morseTable[index]);
  }
}

int main() {
  char input[100];
  
  printf("Enter text to convert to Morse code: ");
  fgets(input, 100, stdin);
  
  // Remove newline character from input string
  input[strcspn(input, "\n")] = 0;
  
  printf("Morse code: ");
  textToMorse(input);
  printf("\n");
  
  return 0;
}