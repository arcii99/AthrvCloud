//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surprised
#include <stdio.h>
#include <ctype.h>

int main() {
  char input[100];
  int i = 0;
  printf("Hey there! Please enter some text: ");
  fgets(input, 100, stdin);

  printf("Woah, let me sanitize that for you! Here's the cleaned up version:\n");

  while (input[i]) {
    if (!isalpha(input[i]) && !isspace(input[i])) {
      input[i] = ' ';
    }
    putchar(tolower(input[i]));
    i++;
  }
  
  printf("Hope that helps! Have a nice day :)");
  return 0;
}