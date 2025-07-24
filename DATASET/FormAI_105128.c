//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
  char greeting[] = "Hello, World!";
  char name[20];
  char peaceful_phrase[] = "Life is beautiful.";

  // prompt user to enter their name
  printf("What is your name? ");
  scanf("%s", name);

  // concatenate name to greeting
  strcat(greeting, " My name is ");
  strcat(greeting, name);
  printf("%s\n", greeting);

  // check if peaceful_phrase is inside greeting
  char* is_peaceful = strstr(greeting, peaceful_phrase);
  if (is_peaceful != NULL) {
    printf("%s\n", "\"Life is beautiful.\" is in the greeting.");
  } else {
    printf("%s\n", "\"Life is beautiful.\" is not in the greeting.");
  }

  // count the number of vowels in peaceful_phrase
  int vowel_count = 0;
  for (int i = 0; i < strlen(peaceful_phrase); i++) {
    char c = peaceful_phrase[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      vowel_count++;
    }
  }
  printf("There are %d vowels in \"%s\".\n", vowel_count, peaceful_phrase);

  // reverse peaceful_phrase
  char reversed_peaceful[strlen(peaceful_phrase)];
  for (int i = strlen(peaceful_phrase) - 1; i >= 0; i--) {
    reversed_peaceful[strlen(peaceful_phrase) - i - 1] = peaceful_phrase[i];
  }
  printf("\"%s\" reversed is \"%s\".\n", peaceful_phrase, reversed_peaceful);

  return 0;
}