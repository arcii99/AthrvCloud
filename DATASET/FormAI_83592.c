//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  printf("\n\n\n");
  printf("-------------------- Welcome to the Automated Fortune Teller ----------------------\n\n");
  printf("You seek guidance and I shall provide it. \n\n");

  char question[100];
  printf("Ask your question: \n\n");
  fgets(question, 100, stdin);

  srand(time(NULL));
  int random_num = rand() % 10;

  if (random_num == 0)
  {
    printf("\nOutlook not so good. \n");
  }
  else if (random_num == 1)
  {
    printf("\nBetter not tell you now. \n");
  }
  else if (random_num == 2)
  {
    printf("\nDon’t count on it. \n");
  }
  else if (random_num == 3)
  {
    printf("\nCannot predict now. \n");
  }
  else if (random_num == 4)
  {
    printf("\nSigns point to yes. \n");
  }
  else if (random_num == 5)
  {
    printf("\nOutlook good. \n");
  }
  else if (random_num == 6)
  {
    printf("\nReply hazy, try again. \n");
  }
  else if (random_num == 7)
  {
    printf("\nMy sources say no. \n");
  }
  else if (random_num == 8)
  {
    printf("\nVery doubtful. \n");
  }
  else if (random_num == 9)
  {
    printf("\nAbsolutely. \n");
  }

  printf("\n\n--------------------------------------------------------------------------------");
  return 0;
}