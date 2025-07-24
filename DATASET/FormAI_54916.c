//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
  char input[50];
  
  printf("Enter a string to sanitize: ");
  fgets(input, sizeof(input), stdin);
  
  for (int i = 0; i < strlen(input); i++) {
    switch(input[i]) {
      case '>':
        printf("&gt;");
        break;
      case '<':
        printf("&lt;");
        break;
      case '&':
        printf("&amp;");
        break;
      case '\'':
        printf("&apos;");
        break;
      case '\"':
        printf("&quot;");
        break;
      default:
        printf("%c", input[i]);
        break;
    }
  }
  
  return 0;
}