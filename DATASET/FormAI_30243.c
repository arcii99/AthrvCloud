//FormAI DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include<stdio.h>
#include<string.h>

#define MAX_MESSAGE_LEN 100
#define SPAM_SCORE_LIMIT 10

int spam_score(char* message);

int main()
{
  char message[MAX_MESSAGE_LEN];
  printf("Enter a message: ");
  fgets(message, MAX_MESSAGE_LEN, stdin);
  message[strcspn(message, "\n")] = '\0'; // Removing newline character from input

  int score = spam_score(message);
  if(score >= SPAM_SCORE_LIMIT)
  {
    printf("SPAM DETECTED!\nScore: %d\n", score);
  }
  else
  {
    printf("Message passed spam filter with a score of %d.\n", score);
  }

  return 0;
}

int spam_score(char* message)
{
  int score = 0;
  char* words_to_check[] = {"discount", "buy now", "limited time offer", "act fast", "cash prize"};
  int num_words = sizeof(words_to_check) / sizeof(words_to_check[0]);

  for(int i = 0; i < num_words; i++)
  {
    if(strstr(message, words_to_check[i]) != NULL) // Word found in message
    {
      score += 2; // Increase score for each match with a spam word
    }
  }

  // Check for excessive use of capital letters
  int num_capitals = 0;
  int message_len = strlen(message);
  for(int i = 0; i < message_len; i++)
  {
    if(message[i] >= 'A' && message[i] <= 'Z') // Character is a capital letter
    {
      num_capitals++;
    }
  }

  if(num_capitals > (message_len / 4)) // If more than 25% of characters are capitals
  {
    score += 3;
  }

  return score;
}