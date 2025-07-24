//FormAI DATASET v1.0 Category: Text processing ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
  char text[100];
  printf("Welcome to the Curious Text Processor!\n");
  printf("Enter your text: ");
  fgets(text, 100, stdin);

  int length = strlen(text);

  printf("Your text has %d characters.\n", length);
  printf("Your text spelled backwards is: ");

  for(int i = length - 1; i >= 0; i--) {
    printf("%c", text[i]);
  }

  printf("\n");

  int vowels = 0;
  int consonants = 0;

  for(int i = 0; i < length; i++) {
    if(text[i] >= 'A' && text[i] <= 'Z')
      text[i] += 'a' - 'A';

    if(text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u')
      vowels++;
    else if(text[i] >= 'a' && text[i] <= 'z')
      consonants++;
  }

  printf("Your text has %d vowels and %d consonants.\n", vowels, consonants);

  if(strncmp(text, "hello", 5) == 0)
    printf("Your text starts with 'hello'. How delightful!\n");
  else
    printf("Your text does not start with 'hello'. How curious!\n");

  return 0;
}