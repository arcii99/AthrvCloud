//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  char questions[5][100] = {"Will I ever find true love?", "Will I become rich?", "Will I be successful in my career?", "Will I travel the world?", "Will I live a long and happy life?"};
  char answers[5][3][100] = {
      {"The stars say yes, my child.", "I'm sensing a positive outcome, my child.", "It is destined to be, my child."},
      {"Alas, this may not come true.", "The stars do not look favorably upon this, my child.", "There may be other paths to wealth, my child."},
      {"I sense great success in your future, my child.", "The stars align for your career, my child.", "You have great potential for success, my child."},
      {"Wanderlust sings in your heart, my child.", "Travel is in your future, my child.", "Destiny calls for you to be a global explorer, my child."},
      {"Happiness awaits you, my child.", "Your life will be full of joy, my child.", "The stars will shine on you, my child."}
  };

  srand(time(NULL));

  printf("Welcome to the medieval Fortune Teller!\n\n");
  printf("Ask me a question, my child: ");

  char question[100];
  fgets(question, 100, stdin);

  int index = rand() % 5;
  int answerIndex = rand() % 3;

  printf("\nAh, I see... %s\n", questions[index]);
  printf("Let me consult with the stars...\n");
  printf("The answer is: %s\n", answers[index][answerIndex]);

  return 0;
}