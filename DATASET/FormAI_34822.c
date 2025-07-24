//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Display intro message
  printf("## Welcome to the Automated Fortune Teller ##\n");
  printf("Think of a question and I'll give you the answer...\n");

  // Create array of potential answers
  char *answers[] = {
    "Yes.",
    "No.",
    "Maybe.",
    "It is certain.",
    "Outlook not so good.",
    "Definitely.",
    "Cannot predict now.",
    "Ask again later.",
    "Signs point to yes.",
    "Don't count on it."
  };

  // Seed the random number generator
  srand(time(NULL));

  // Loop to allow for multiple questions
  while (1) {
    // Get user's question
    char question[100];
    printf("\nAsk me a question: ");
    fgets(question, 100, stdin);

    // Generate a random answer
    int index = rand() % 10;
    printf("\nAnswer: %s\n", answers[index]);
  }

  return 0;
}