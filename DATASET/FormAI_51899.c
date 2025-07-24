//FormAI DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
  char text[100];
  char peaceful_text[100];
  int i, j;
  
  printf("Enter some text: ");
  fgets(text, sizeof(text), stdin);
  
  for (i = 0, j = 0; i < strlen(text); i++) {
    if (text[i] == 'w' && text[i+1] == 'a' && text[i+2] == 'r') {
      peaceful_text[j] = 'p';
      peaceful_text[j+1] = 'e';
      peaceful_text[j+2] = 'a';
      peaceful_text[j+3] = 'c';
      peaceful_text[j+4] = 'e';
      peaceful_text[j+5] = 'f';
      peaceful_text[j+6] = 'u';
      peaceful_text[j+7] = 'l';
      peaceful_text[j+8] = 'l';
      j += 9;
      i += 2;
    } else {
      peaceful_text[j] = text[i];
      j++;
    }
  }
  peaceful_text[j] = '\0';
  
  printf("Transformed text: %s", peaceful_text);

  return 0;
}