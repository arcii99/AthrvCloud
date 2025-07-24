//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Mapping table for C Cat Language
char mapping_table[26] = {
  'c', 'a', 't', 'f', 'd', 'e', 'g', 'h', 'i', 'j', 'k', 'l',
  'm', 'n', 'o', 'p', 'q', 'r', 's', 'u', 'v', 'w', 'x', 'y', 'z'
};

// Function to translate C code to C Cat code
void translate_to_c_cat(char* c_code, char* c_cat) {
  int i, j;
  int length = strlen(c_code);

  // Loop through each character in the input string
  for (i = 0, j = 0; i < length; i++, j++) {
    // Get the index of the character in the mapping table
    int idx = c_code[i] - 'a';

    // If the character is not in the mapping table (e.g. a space),
    // simply copy it over to the output string
    if (idx < 0 || idx > 25) {
      c_cat[j] = c_code[i];
    }
    else {
      // Translate the character to C Cat language
      c_cat[j] = mapping_table[idx];

      // We need to add a "meow" after the letter 'c'
      if (c_cat[j] == 'c') {
        c_cat[++j] = 'm';
        c_cat[++j] = 'e';
        c_cat[++j] = 'o';
        c_cat[++j] = 'w';
      }
    }
  }

  // Terminate the output string with a null character
  c_cat[j] = '\0';
}

int main() {
  char c_code[MAX_LENGTH], c_cat[MAX_LENGTH * 2];

  printf("Enter C code to translate to C Cat language:\n");
  fgets(c_code, MAX_LENGTH, stdin);

  // Remove the newline character from the input string
  strtok(c_code, "\n");

  // Translate the input string to C Cat language
  translate_to_c_cat(c_code, c_cat);

  printf("Translated C Cat code:\n%s\n", c_cat);

  return 0;
}