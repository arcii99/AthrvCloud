//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: scientific
#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 1000 /* Maximum length of input */

/* Function to convert C Cat Language to English */
void cCatToEnglish(char *s) {
  /* C Cat Language keywords and their English equivalents */
  char *cCatKeywords[10] = {"HZZZB", "MEOOW", "PURREEOOW", "HISSSS", "ROWRR", "MROWWW",
                            "MEOOWPURREEOOW", "HZZZBPURREEOOW", "MEOW", "ROWRRHISSSS"};
  char *englishLetters[10] = {"A", "E", "I", "O", "U", "S", "W", "Y", "B", "C"};

  /* Tokenize the input string based on spaces */
  char *token = strtok(s, " ");

  /* Loop through each token */
  while (token != NULL) {
    /* Check if the token matches a C Cat keyword */
    for (int i = 0; i < 10; i++) {
      if (strcmp(token, cCatKeywords[i]) == 0) {
        printf("%s ", englishLetters[i]); /* Print the English equivalent if matched */
        break; /* Break out of loop once matched */
      }
    }
    token = strtok(NULL, " "); /* Move to next token */
  }
}

int main() {
  char input[MAX_LENGTH]; /* Input string */

  printf("Enter C Cat Language string: ");
  fgets(input, MAX_LENGTH, stdin); /* Get input from user */
  input[strcspn(input, "\n")] = '\0'; /* Remove trailing newline character */

  printf("C Cat Language string: %s\n", input); /* Print original string */
  printf("English equivalent: ");
  cCatToEnglish(input); /* Convert to English and print */

  return 0;
}