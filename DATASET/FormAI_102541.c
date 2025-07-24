//FormAI DATASET v1.0 Category: Text Summarizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_SIZE 100 // maximum summary size

char* summarize(char* text)
{
  // Initialize necessary variables
  char* summary = (char*) malloc(sizeof(char) * MAX_SUMMARY_SIZE);
  char* sentence;

  int len = strlen(text);
  int count = 0; // count of letters in summary
  int pos = 0; // position in text

  // Loop through text to find sentences
  while (pos < len && count < MAX_SUMMARY_SIZE - 1) {
    // Find next sentence
    sentence = strchr(text + pos, '.');
    if (sentence == NULL) {
      // No more sentences
      break;
    }
    sentence++;

    // Check if sentence should be included in summary
    int sentence_len = sentence - (text + pos);
    if (count + sentence_len <= MAX_SUMMARY_SIZE - 1) {
      // Add sentence to summary
      strncat(summary, text + pos, sentence_len);
      count += sentence_len;
    } else {
      // Summary is at max size, end while loop
      break;
    }

    pos += sentence_len;
  }

  // Add continuation to end of summary, if necessary
  if (pos < len - 1) {
    strcat(summary, "...");
  }

  return summary;
}

int main()
{
  // Test the summarizer with some example text
  char* text = "This is an example sentence. This is another sentence. "
               "This is a third sentence that is longer than the other two. "
               "This is a fourth sentence that is also quite long. "
               "This is a fifth sentence that is not very long.";
  char* summary = summarize(text);

  printf("Original text: \n%s\n\n", text);
  printf("Summary: \n%s\n", summary);

  // Free dynamically allocated memory
  free(summary);

  return 0;
}