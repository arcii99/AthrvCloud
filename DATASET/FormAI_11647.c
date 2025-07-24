//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to summarize text
void summarize_text(char *text, int num_sentences)
{
  // Declare an array to store sentences
  char *sentences[100];
  int sentence_count = 0;

  // Tokenize text into sentences
  char *sentence = strtok(text, ".");
  while(sentence != NULL) {
    sentences[sentence_count++] = sentence;
    sentence = strtok(NULL, ".");
  }

  // If the number of sentences is greater than the number of allowed sentences,
  // adjust the number of sentences accordingly
  if(num_sentences > sentence_count) {
    num_sentences = sentence_count;
  }

  // Sort sentences based on length
  for(int i = 0; i < sentence_count - 1; i++) {
    for(int j = i + 1; j < sentence_count; j++) {
      if(strlen(sentences[i]) < strlen(sentences[j])) {
        char *temp = sentences[i];
        sentences[i] = sentences[j];
        sentences[j] = temp;
      }
    }
  }

  // Print summarized text
  printf("Summary:\n");
  for(int i = 0; i < num_sentences; i++) {
    // Capitalize first letter of sentence
    char *sentence = sentences[i];
    sentence[0] = toupper(sentence[0]);
    printf("%s.", sentence);
  }
  printf("\n");
}

int main()
{
  char *text = "In the year 2077, the world has become a dark and dangerous place. Corporations rule everything and cybernetic enhancements are the norm. The city of Night City lies at the heart of this dark future. It is a place where life is cheap and only the strong survive.";

  int num_sentences = 2;

  summarize_text(text, num_sentences);

  return 0;
}