//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {
  char text[100];
  char morse[27][5] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
    "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/"
  };
  
  printf("My Dearest Juliet, please input your message:\n");
  scanf("%[^\n]%*c", text);
  
  printf("Here is your message in Morse code:\n");
  
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      printf("%s ", morse[text[i] - 'a']);
    }
    else if (text[i] >= 'A' && text[i] <= 'Z') {
      printf("%s ", morse[text[i] - 'A']);
    }
    else if (text[i] == ' ') {
      printf("/ ");
    }
    else {
      printf("%c ", text[i]);
    }
  }
  
  printf("\nYours always,\nRomeo");
  
  return 0;
}