//FormAI DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <string.h>

int main() {
  char text[] = "This is a sample text for the text processing example program."; // Input text
  char search_term[] = "text"; // Term to be searched in the input text
  int search_term_length = strlen(search_term); // Length of the search term
  char replacement[] = "string"; // Term to replace the search term
  int replacement_length = strlen(replacement); // Length of the replacement term

  int i = 0; // Counter for the loop
  int j, k; // Counters for nested loops
  int text_length = strlen(text); // Length of the input text
  int occurrences = 0; // Counter for the occurrences of the search term

  while (i < text_length) {
    j = 0;
    while (text[i+j] == search_term[j] && j < search_term_length) {
      j++;
    }
    if (j == search_term_length) { // Search term found
      occurrences++;
      for (k = 0; k < replacement_length; k++) {
        text[i+k] = replacement[k]; // Replace the search term with the replacement term
      }
      i += replacement_length; // Skip the replaced characters
    } else {
      i++;
    }
  }

  printf("Original text: %s\n", text); // Print the original input text
  printf("Number of occurrences of the search term: %d\n", occurrences); // Print the number of occurrences of the search term
  printf("Processed text: %s\n", text); // Print the processed text with the replaced term

  return 0;
}