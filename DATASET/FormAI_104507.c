//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  int i,j,k,lines,numbers[75],rows[5][5];
  char letter;
  
  //Initialize random number generator
  srand(time(NULL));
  
  //Generate unique random numbers from 1 to 75
  for(i=0;i<75;i++)
  {
    numbers[i] = i+1;
  }
  for(i=0;i<75;i++)
  {
    j = rand()%75;
    k = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = k;
  }
  
  //Initialize rows with zeros
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
      rows[i][j] = 0;
    }
  }
  
  //Print futuristic bingo card
  printf("-----------------------------------------\n");
  printf("| B    I    N    G    O |\n");
  printf("-----------------------------------------\n");
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
      if(j == 2 && i == 2)
      {
        printf("|XX   ");
      }
      else
      {
        printf("| %d   ",rows[i][j]);
      }
    }
    printf("|\n");
    printf("-----------------------------------------\n");
  }
  
  //Ask user to enter their desired letter for bingo
  printf("Enter your desired letter for BINGO (B, I, N, G, or O): ");
  scanf("%c",&letter);
  
  //Assign corresponding column number based on user's input letter
  if(letter == 'B')
  {
    lines = 0;
  }
  else if(letter == 'I')
  {
    lines = 1;
  }
  else if(letter == 'N')
  {
    lines = 2;
  }
  else if(letter == 'G')
  {
    lines = 3;
  }
  else if(letter == 'O')
  {
    lines = 4;
  }
  else
  {
    printf("Invalid letter!\n");
    exit(0);
  }
  
  //Start generating random numbers for the chosen column until bingo is reached
  while(1)
  {
    j = rand()%15;
    k = numbers[lines*15+j]; //get random number from the chosen column
    
    //Mark the number if it exists and check for a line or bingo
    for(i=0;i<5;i++)
    {
      if(rows[i][lines] == k)
      {
        rows[i][lines] = -1;
        //check for a line or bingo
        if(i == 0 && rows[1][lines] == -1 && rows[2][lines] == -1 && rows[3][lines] == -1 && rows[4][lines] == -1)
        {
          printf("LINE!\n");
        }
        else if(i == 1 && rows[0][lines] == -1 && rows[2][lines] == -1 && rows[3][lines] == -1 && rows[4][lines] == -1)
        {
          printf("LINE!\n");
        }
        else if(i == 2 && rows[0][lines] == -1 && rows[1][lines] == -1 && rows[3][lines] == -1 && rows[4][lines] == -1)
        {
          printf("LINE!\n");
        }
        else if(i == 3 && rows[0][lines] == -1 && rows[1][lines] == -1 && rows[2][lines] == -1 && rows[4][lines] == -1)
        {
          printf("LINE!\n");
        }
        else if(i == 4 && rows[0][lines] == -1 && rows[1][lines] == -1 && rows[2][lines] == -1 && rows[3][lines] == -1)
        {
          printf("LINE!\n");
        }
        else if(rows[0][lines] == -1 && rows[1][lines] == -1 && rows[2][lines] == -1 && rows[3][lines] == -1 && rows[4][lines] == -1)
        {
          printf("BINGO!\n");
          exit(0);
        }
        break;
      }
    }
    //If the number is not marked yet
    if(i == 5)
    {
      rows[j][lines] = k;
    }
  }
  
  return 0;
}