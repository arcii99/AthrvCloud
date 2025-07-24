//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to simulate a random encounter in space
int randomEncounter(){
  int encounter = rand()%4 + 1; //Random number between 1 and 4
  
  switch(encounter){
    case 1:
      printf("You've stumbled upon an abandoned spaceship. Do you want to investigate it? (Y/N)\n");
      break;
    case 2:
      printf("You're being hailed by an unknown ship. Do you want to respond? (Y/N)\n");
      break;
    case 3:
      printf("You detect a distress signal. Do you want to investigate it? (Y/N)\n");
      break;
    case 4:
      printf("You encounter a group of space pirates. Do you want to fight or flee? (F/F)\n");
      break;
  }
  return encounter;
}

//Function to simulate a battle with space pirates
int battle(){

  int playerHealth = 100;
  int enemyHealth = 75;
  int playerAttack = rand()%11 + 10; //Random number between 10 and 20
  int enemyAttack = rand()%6 + 5; //Random number between 5 and 10
  
  printf("Let the battle begin!\n");
  
  //Battle loop
  while(1){
    //Player attacks
    printf("You attack the space pirates and deal %d damage.\n", playerAttack);
    enemyHealth -= playerAttack;
    
    //Check if enemy is defeated
    if(enemyHealth <= 0){
      printf("You have defeated the space pirates!\n");
      return 1;
    }
    
    //Enemy attacks
    printf("The space pirates attack you and deal %d damage.\n", enemyAttack);
    playerHealth -= enemyAttack;
    
    //Check if player is defeated
    if(playerHealth <= 0){
      printf("You have been defeated by the space pirates!\n");
      return 0;
    }
    
    //Print player and enemy health
    printf("Your health: %d\n", playerHealth);
    printf("Space pirates health: %d\n", enemyHealth);
    
    //Wait for user input to continue the battle
    printf("Press enter to continue.\n");
    getchar();
    getchar();
    printf("\n");
  }
  
}

int main(){
  
  srand(time(0)); //Seed the random number generator with current time
  
  printf("Welcome to the Procedural Space Adventure game!\n\n");
  printf("You are the captain of a spaceship traveling through space.\n");
  printf("Your mission is to explore the galaxy and discover new worlds and civilizations.\n");
  printf("But be careful, space is a dangerous place with many unforeseen dangers.\n\n");
  
  //Game loop
  while(1){
    int choice;
    printf("What do you want to do?\n");
    printf("1. Explore\n");
    printf("2. Check status\n");
    printf("3. Quit\n");
    scanf("%d", &choice);
    
    switch(choice){
      case 1:
        printf("You are exploring space...\n");
        int encounter = randomEncounter();
        if(encounter == 4){
          //Fight with space pirates
          int result = battle();
          if(result == 1){
            printf("You have gained 100 space coins!\n");
          }
        }else{
          //Non-combat encounter
          printf("You have gained 50 space coins!\n");
        }
        break;
      case 2:
        printf("Your ship has %d health points.\n", rand()%51 + 50); //Random number between 50 and 100
        printf("You have %d space coins.\n", rand()%301 + 200); //Random number between 200 and 500
        break;
      case 3:
        printf("Thanks for playing the Procedural Space Adventure game!\n");
        exit(0);
      default:
        printf("Invalid choice.\n");
        break;
    }
    
    //Wait for user input to continue
    printf("Press enter to continue.\n");
    getchar();
    getchar();
    printf("\n");
  }
  
  return 0;
}