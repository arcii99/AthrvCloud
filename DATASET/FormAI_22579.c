//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char questions[16][80] = { /* Array of possible questions */
    "What is my future?",
    "Will I become wealthy?",
    "Am I going to find love?",
    "Will I be successful?",
    "What can I expect from my career?",
    "Should I take that new job?",
    "Should I invest in the stock market?",
    "Will I win the lottery?",
    "Should I move to a new city?",
    "Will my health improve?",
    "Is it a good time to start a family?",
    "Will my dreams come true?",
    "Should I pursue further education?",
    "Should I travel this year?",
    "What can I do to improve my life?",
    "Is there anything I should be cautious of?"
  };

  char answers[8][80] = { /* Array of possible answers */
    "It is certain.",
    "It is decidedly so.",
    "Without a doubt.",
    "Yes, definitely.",
    "You may rely on it.",
    "As I see it, yes.",
    "Most likely.",
    "Outlook good."
  };

  char warnings[4][80] = { /* Array of warning messages */
    "Reply hazy, try again.",
    "Better not tell you now.",
    "Cannot predict now.",
    "Concentrate and ask again."
  };

  char negative[4][80] = { /* Array of negative responses */
    "Don't count on it.",
    "Outlook not so good.",
    "My sources say no.",
    "Very doubtful."
  };

  int random_number;
  char question[80];

  srand(time(NULL)); /* Seed the random number generator */

  printf("Welcome to the Automated Fortune Teller!\n\n");
  printf("Type your yes or no question and press enter:\n");
  fgets(question, 80, stdin);

  printf("\nThe answer to your question \"%s\" is...\n", question);

  random_number = rand() % 20; /* Generate random number between 0-19 */

  if (random_number < 8) { /* If random number is between 0-7, give positive response */
    printf("%s\n", answers[random_number % 8]);
  }
  else if (random_number < 12) { /* If random number is between 8-11, give warning */
    printf("%s\n", warnings[random_number % 4]);
  }
  else { /* If random number is between 12-19, give negative response */
    printf("%s\n", negative[random_number % 4]);
  }

  return 0;
}