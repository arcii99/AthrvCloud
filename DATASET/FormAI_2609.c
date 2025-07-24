//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *subject[] = {"The government", "The aliens", "The Illuminati", "The lizard people", "The robots"};
char *action[] = {"are controlling", "are observing", "are manipulating", "are brainwashing", "are experimenting on"};
char *object[] = {"our dreams", "our thoughts", "our DNA", "the weather", "the stock market"};

int main()
{
  int i, r;

  srand(time(NULL));

  for (i = 0; i < 10; i++)
  {
    printf("Did you know that %s %s %s?\n", subject[rand()%5], action[rand()%5], object[rand()%5]);
  }

  return 0;
}