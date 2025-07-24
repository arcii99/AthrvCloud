//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

void translate(char *input) {
  // Define the alien language rules
  char vowel[] = {'a', 'e', 'i', 'o', 'u'};
  char consonant[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n',
                      'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};

  // Translate the text by swapping letters based on the alien language rules
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      printf(" ");
    } else if (strchr(vowel, input[i]) != NULL) {
      printf("%c", consonant[input[i] - 'a']);
    } else {
      printf("%c", vowel[input[i] - 'a']);
    }
  }
  printf("\n");
}

int main() {
  char input[100];
  
  // Read the text to be translated
  printf("Enter the text to be translated: ");
  fgets(input, sizeof(input), stdin);

  // Remove the newline character from the input
  input[strcspn(input, "\n")] = 0;

  // Translate the text and print the result
  printf("The translated text is: ");
  translate(input);

  return 0;
}