//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int bingo_card[25], number, count = 0, win = 0;
  char check[25], name[50];

  printf("Welcome to the Bingo Simulator!\n\n");
  printf("Enter your first name: ");
  fgets(name, sizeof(name), stdin);
  printf("\nHello %s! Let's start playing.\n", name);
  printf("Here's your bingo card:\n");

  for (int i = 0; i < 25; i++)
  {
    // Generating random numbers from 1 to 75 for Bingo card
    number = rand() % 75 + 1;
    
    // Checking for unique numbers only
    for (int j = 0; j < i; j++)
    {
      if (bingo_card[j] == number)
        number = rand() % 75 + 1;
    }
      
    bingo_card[i] = number;
  }

  // Initializing the check list with 'X'
  for(int i = 0; i < 25; i++)
  {
    check[i] = 'X';
  }

  // Displaying the Bingo card
  printf("  B  I  N  G  O\n");
  for (int i = 0; i < 25; i++)
  {
    if (i%5 == 0)
      printf("\n");
    printf("%3d ", bingo_card[i]);
  }

  printf("\n\nLet's start the game!\n\n");

  // Game loop
  while(win == 0)
  {
    printf("Enter the next number (1-75): ");
    scanf("%d", &number);

    // Checking for unique numbers and updating the card
    for (int i = 0; i < 25; i++)
    {
      if (bingo_card[i] == number && check[i] == 'X')
      {
        check[i]=' ';
        count++;
      }
    }

    // Displaying the updated card
    printf("  B  I  N  G  O\n");
    for (int i = 0; i < 25; i++)
    {
      if (i%5 == 0)
        printf("\n");
      printf("%2c%2d ", check[i], bingo_card[i]);
    }

    // Checking for Bingo
    if (count >= 5)
    {
      for(int i=0;i<25;i+=5)
      {
        if(check[i]==' ' && check[i+1]==' ' && check[i+2]==' ' && check[i+3]==' ' && check[i+4]==' ')
        {
          printf("Congratulations! You have completed a Bingo!\n");
          win = 1;
        }
      }

      for(int i=0;i<5;i++)
      {
        if(check[i]==' ' && check[i+5]==' ' && check[i+10]==' ' && check[i+15]==' ' && check[i+20]==' ')
        {
          printf("Congratulations! You have completed a Bingo!\n");
          win = 1;
        }
      }

      if(check[0]==' ' && check[6]==' ' && check[12]==' ' && check[18]==' ' && check[24]==' ')
      {
        printf("Congratulations! You have completed a Bingo!\n");
        win = 1;
      }

      if(check[4]==' ' && check[8]==' ' && check[12]==' ' && check[16]==' ' && check[20]==' ')
      {
        printf("Congratulations! You have completed a Bingo!\n");
        win = 1;
      }
    }

    printf("\n");
  }

  return 0;
}