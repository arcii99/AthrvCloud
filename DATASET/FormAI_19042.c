//FormAI DATASET v1.0 Category: Text Summarizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a max length for the summarized text
#define MAX_LENGTH 100

// Function to summarize the text
void summarize(char *article) {
  // Convert article to lowercase
  for (int i = 0; i < strlen(article); i++) {
    article[i] = tolower(article[i]);
  }

  // Split the article into words
  char *word = strtok(article, " ");
  int num_words = 0;

  // Count the number of words
  while (word != NULL) {
    num_words++;
    word = strtok(NULL, " ");
  }

  // Calculate the average word length
  int total_length = strlen(article) - num_words + 1;
  float avg_length = (float)total_length / num_words;

  // Determine the number of sentences needed to reach the max length
  int num_sentences = (int)(MAX_LENGTH / (avg_length * 0.8));

  // Split the article into sentences
  char *sentence = strtok(article, ".");
  int num_sent = 0;

  // Print the summarized text
  printf("Summary:\n");
  while (sentence != NULL) {
    // Only print the first num_sentences sentences
    if (num_sent < num_sentences) {
      printf("%s.\n", sentence);
    }

    // Move to the next sentence
    sentence = strtok(NULL, ".");
    num_sent++;
  }
}

int main() {
  // Define a long article for testing
  char article[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam nec lobortis sem, nec vulputate ipsum. "
                   "Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Fusce "
                   "ullamcorper nunc libero, eget blandit arcu hendrerit vel. Morbi tincidunt molestie tellus, sed "
                   "finibus libero efficitur sit amet. Maecenas imperdiet tincidunt dolor, sit amet bibendum augue "
                   "venenatis eu. Nam non tristique sapien. Morbi in diam felis. Donec aliquam turpis vel laoreet "
                   "venenatis.";

  // Call the summarize function
  summarize(article);

  return 0;
}