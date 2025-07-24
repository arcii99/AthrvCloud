//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  //initialize variables
  int player_health = 100;
  int monster_health = 100;
  int player_attack, monster_attack;

  //seed the random number generator
  srand(time(NULL));

  //game introduction and instructions
  printf("Welcome to the Statistical Adventure Game!\n");
  printf("You will face a monster and take turns attacking each other.\n");
  printf("The game ends when either you or the monster's health reaches 0.\n");
  printf("Good luck!\n\n");

  //game loop
  while (player_health > 0 && monster_health > 0)
  {
    //player attack
    player_attack = rand() % 20 + 10; //random number between 10 and 30
    monster_health -= player_attack;
    printf("You attack the monster for %d damage.\n", player_attack);

    //check if monster is still alive
    if (monster_health <= 0)
    {
      printf("Congratulations! You defeated the monster!\n");
      break;
    }

    //monster attack
    monster_attack = rand() % 20 + 10; //random number between 10 and 30
    player_health -= monster_attack;
    printf("The monster attacks you for %d damage.\n", monster_attack);

    //check if player is still alive
    if (player_health <= 0)
    {
      printf("Game Over! The monster has defeated you.\n");
      break;
    }

    //display current health
    printf("Your health: %d\n", player_health);
    printf("Monster health: %d\n\n", monster_health);
  }

  return 0;
}