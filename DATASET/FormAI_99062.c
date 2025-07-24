//FormAI DATASET v1.0 Category: String manipulation ; Style: scientific
#include <stdio.h>
#include <string.h>

int main()
{
  char sentence[100];
  char vowels[] = "aeiouAEIOU";
  int vowel_count = 0;
  int max_word_length = 0;
  char max_word[20];

  printf("Enter a sentence: ");
  fgets(sentence, 100, stdin); // read in sentence

  char* word = strtok(sentence, " ."); // tokenize sentence by space and period

  while (word != NULL) { // loop through each word
    int word_length = strlen(word);
    if (word_length > max_word_length) { // check if new max length
      max_word_length = word_length;
      strcpy(max_word, word);
    }

    for (int i = 0; i < word_length; i++) { // loop through each character of the word
      char* is_vowel = strchr(vowels, word[i]); // check if character is a vowel
      if (is_vowel != NULL) {
        vowel_count++;
      }
    }

    word = strtok(NULL, " ."); // get next word
  }

  printf("Number of vowels: %d\n", vowel_count);
  printf("Longest word: %s\n", max_word);

  return 0;
}