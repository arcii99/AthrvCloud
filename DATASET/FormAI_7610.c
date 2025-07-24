//FormAI DATASET v1.0 Category: Text processing ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  char output[100] = "";
  int vowels = 0;
  int consonants = 0;

  printf("Let's process some text! Enter a sentence: ");
  fgets(input, 100, stdin);

  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' ||
        input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
      vowels++;
    } else if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) {
      consonants++;
      strncat(output, &input[i], 1);
    }
  }

  printf("\nHere's the original text: \n%s", input);
  printf("\nHere's the text with only consonants: \n%s", output);
  printf("\nVowels: %d \nConsonants: %d\n", vowels, consonants);

  return 0;
}