//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main()
{
  char message[100];
  char morse[100][50] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", " ", "\n"};  // Store Morse code for alphabets and numbers
  int i, j;

  printf("Enter a message to convert to Morse code:\n");
  fgets(message, 100, stdin);
  message[strcspn(message, "\n")] = 0;  // Remove newline character from input

  printf("Input message: %s\n", message);
  printf("Morse code output: ");

  for(i = 0; i < strlen(message); i++){

    // Convert uppercase letters to corresponding Morse code
    if(message[i] >= 'A' && message[i] <= 'Z'){
      j = message[i] - 'A';
      printf("%s ", morse[j]);
    }
    // Convert digits to corresponding Morse code
    else if(message[i] >= '0' && message[i] <= '9'){
      j = message[i] - '0' + 26;
      printf("%s ", morse[j]);
    }
    // Convert whitespace character to corresponding Morse code
    else if(message[i] == ' '){
      j = 36;
      printf("%s", morse[j]);
    }
    // Convert all other characters to corresponding Morse code
    else{
      j = 37;
      printf("%s", morse[j]);
    }
  }
  printf("\n");

  return 0;
}