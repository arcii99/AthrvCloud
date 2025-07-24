//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  char *subjects[] = {"The government", "The Illuminati", "Aliens", "The New World Order"};
  char *verbs[] = {"is manipulating", "is controlling", "is monitoring", "is brainwashing"};
  char *objects[] = {"the weather", "our minds", "cryptocurrency prices", "social media"};
  char *complications[] = {"to distract us from their true intentions", "to create chaos and confusion", "to gain unlimited power", "to enslave the human race"};

  printf("Welcome to the Random Conspiracy Theory Generator!\n");

  while(1)
  {
    printf("\nDid you know that... \n");
    printf("%s %s %s %s\n", subjects[rand() % 4], verbs[rand() % 4], objects[rand() % 4], complications[rand() % 4]);
    printf("\nDon't believe me? Just think about it for a moment...\n");

    char again;
    printf("\nDo you want to hear another theory? (y/n) ");
    scanf(" %c", &again);
    if (again == 'n' || again == 'N')
    {
      printf("Thank you for using the Random Conspiracy Theory Generator. Stay vigilant!\n");
      break;
    }
  }

  return 0;
}