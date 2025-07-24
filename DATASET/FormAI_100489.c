//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  char* topics[10] = {"Chemtrails", "Moon Landing", "Flat Earth", "Illuminati", "9/11", "Bigfoot", "JFK Assassination", "Aliens", "New World Order", "Global Warming"};
  char* verbs[4] = {"causes", "is behind", "is controlled by", "has evidence of"};
  char* actors[5] = {"the government", "the Vatican", "the Illuminati", "the reptilians", "the Freemasons"};
  char* proofs[7] = {"documents leaked by Edward Snowden", "testimonies from former Area 51 employees", "the shape of clouds in the sky", "anomalies in the behavior of sea creatures", "messages hidden in popular songs", "patterns in the stock market", "the numbers on a dollar bill"};

  srand(time(NULL));
  
  printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

  while (1) {
    printf("Press ENTER to generate a new theory. Type QUIT to exit.\n");

    char input[5];
    fgets(input, 5, stdin);
    if (input[0] == 'q' || input[0] == 'Q') {
      break;
    }

    printf("\n");
    printf("%s %s %s because %s. According to %s, of course.\n", topics[rand() % 10], verbs[rand() % 4], actors[rand() % 5], proofs[rand() % 7], actors[rand() % 5]);
    printf("\n");
  }

  printf("Thanks for using the Random Conspiracy Theory Generator. Stay suspicious!\n");

  return 0;
}