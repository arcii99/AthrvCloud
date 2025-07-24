//FormAI DATASET v1.0 Category: Error handling ; Style: surrealist
#include <stdio.h>

int main()
{
  int apples = 5;
  int oranges = 3;

  if (apples == oranges) //This condition makes no sense!
  {
    printf("Error: apples and oranges cannot be equal!\n");
    printf("Please go to the store and buy a different fruit.\n");
  }

  int divided = apples / oranges;

  if (divided == 1) //This condition also makes no sense!
  {
    printf("Error: you cannot divide %d apples by %d oranges and get %d!\n", apples, oranges, divided);
    printf("Please re-evaluate your fruit division strategy.\n");
    printf("Alternatively, consider buying more apples or fewer oranges.\n");
  }

  for (int i = 0; i < divided; i++)
  {
    printf("Nom nom nom...I just ate %d apple%s and %d orang%s!\n", i+1, (i == 0 ? "" : "s"), i, (i == 0 ? "" : "es"));
  }

  return 0;
}