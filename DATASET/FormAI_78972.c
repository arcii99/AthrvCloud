//FormAI DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char choice[20];
  printf("You wake up to find yourself in a dark, musty dungeon. A voice booms out, 'Welcome to the Maze of Doom!'\n");
  printf("You have 3 lives. Your goal is to reach the end of the maze without dying. Good luck!\n");

  int lives = 3;
  while (lives > 0)
  {
    printf("\nYou come across a fork in the road. Do you go left or right?\n");
    fgets(choice, 20, stdin);
    choice[strcspn(choice, "\n")] = 0; // remove \n from user input

    if (strcmp(choice, "left") == 0)
    {
      printf("You head down the left passage...\n");
      printf("Oh no! You've fallen into a pit trap and lost a life. You have %d lives left.\n", --lives);
    }
    else if (strcmp(choice, "right") == 0)
    {
      printf("You head down the right passage...\n");
      printf("You encounter a troll blocking the path. He challenges you to a game of rock-paper-scissors.\n");
      printf("Do you choose 'rock', 'paper', or 'scissors'?\n");

      fgets(choice, 20, stdin);
      choice[strcspn(choice, "\n")] = 0; // remove \n from user input

      int troll_choice = rand() % 3; // computer chooses random number from 0 to 2, representing rock-paper-scissors
      if (strcmp(choice, "rock") == 0 && troll_choice == 0)
      {
        printf("The troll chose rock! It's a tie.\n");
      }
      else if (strcmp(choice, "rock") == 0 && troll_choice == 1)
      {
        printf("The troll chose paper! You lose a life. You have %d lives left.\n", --lives);
      }
      else if (strcmp(choice, "rock") == 0 && troll_choice == 2)
      {
        printf("The troll chose scissors! You win.\n");
      }
      else if (strcmp(choice, "paper") == 0 && troll_choice == 0)
      {
        printf("The troll chose rock! You win.\n");
      }
      else if (strcmp(choice, "paper") == 0 && troll_choice == 1)
      {
        printf("The troll chose paper! It's a tie.\n");
      }
      else if (strcmp(choice, "paper") == 0 && troll_choice == 2)
      {
        printf("The troll chose scissors! You lose a life. You have %d lives left.\n", --lives);
      }
      else if (strcmp(choice, "scissors") == 0 && troll_choice == 0)
      {
        printf("The troll chose rock! You lose a life. You have %d lives left.\n", --lives);
      }
      else if (strcmp(choice, "scissors") == 0 && troll_choice == 1)
      {
        printf("The troll chose paper! You win.\n");
      }
      else if (strcmp(choice, "scissors") == 0 && troll_choice == 2)
      {
        printf("The troll chose scissors! It's a tie.\n");
      }
    }
    else
    {
      printf("That's not a valid choice. Please try again.\n");
    }
  }

  printf("\nGame over. You ran out of lives. Better luck next time!\n");
  return 0;
}