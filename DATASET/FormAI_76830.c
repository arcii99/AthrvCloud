//FormAI DATASET v1.0 Category: Text processing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char text[200];
  char processed_text[200] = "";
  
  printf("Enter some text:\n");
  fgets(text, 200, stdin);

  for (int i = 0; i < strlen(text); i++) {
    if (text[i] != ' ') {
      char c = text[i];
      if (c >= 'a' && c <= 'z') {
        c = c - 32;
      }
      processed_text[strlen(processed_text)] = c;
      if (i % 2 == 0) {
        processed_text[strlen(processed_text)] = '-';
      }
    }
  }

  printf("Processed text: %s\n", processed_text);

  return 0;
}