//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
  //Define the input string and its length
  char string[100];
  int len = 0;

  //Ask the user for input
  printf("Please input the text you wish to convert to Morse code: ");
  scanf("%[^\n]", string);
  getchar();

  //Calculate the input string length
  len = strlen(string);

  //Define the Morse code array
  char *morse_code[] = {
      ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
      "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
      "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
      "....-", ".....", "-....", "--...", "---..", "----.", "-----", "/", "\0"
  };

  //Loop through each character in the input string
  for(int i = 0; i < len; i++) {
    //Convert lowercase characters to uppercase
    char current_char = string[i];
    if(current_char >= 'a' && current_char <= 'z') {
      current_char -= 32;
    }

    //Skip whitespace
    if(current_char == ' ') {
      printf(" ");
      continue;
    }

    //Convert the character to Morse code
    int index = current_char - 'A';
    if(index < 0 || index > 25) {
      printf("?");
    } else {
      printf("%s ", morse_code[index]);
    }
  }

  return 0;
}