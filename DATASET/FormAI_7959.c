//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: funny
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_NUM_WORDS 1000

void sanitize_word(char *word) {
  int len = strlen(word);
  
  // Remove any trailing punctuation
  while (len > 0 && ispunct(word[len-1])) {
    word[--len] = '\0';
  }
  
  // Convert word to lowercase
  for (int i = 0; i < len; i++) {
    word[i] = tolower(word[i]);
  }
}

void print_word_freq(char *text) {
  char words[MAX_NUM_WORDS][MAX_WORD_LEN] = {0};
  int freq[MAX_NUM_WORDS] = {0};
  int num_words = 0;
  
  char *word_start = text;
  
  while (*word_start != '\0') {
    char *word_end = word_start;
    
    // Find the end of the word
    while (*word_end != '\0' && !isspace(*word_end) && ((word_end - word_start) < MAX_WORD_LEN)) {
      word_end++;
    }
    
    // Copy the word into our words array
    int word_len = word_end - word_start;
    if (word_len > 0) {
      strncpy(words[num_words], word_start, word_len);
      sanitize_word(words[num_words]);

      // Increment the frequency of this word
      freq[num_words]++;
      
      num_words++;
    }
    
    // Move to the next word in the text
    word_start = word_end;
    while (*word_start != '\0' && isspace(*word_start)) {
      word_start++;
    }
  }
  
  // Print out the frequency of each word
  printf("Word\tFrequency\n");
  for (int i = 0; i < num_words; i++) {
    printf("%s\t%d\n", words[i], freq[i]);
  }
}

int main() {
  char text[] = "Did you hear about the mathematician who's afraid of negative numbers? He will stop at nothing to avoid them.";
  print_word_freq(text);
  return 0;
}