//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Function to generate random integers */
int generate_rand(int limit) {
  srand(time(NULL));
  return rand() % limit;
}

/* Struct that represents a spaceship */
typedef struct {
  char name[20];
  int hull_health; // max: 100
  int shield_health; // max: 50
  int photon_torpedoes; // max: 10
} Spaceship;

/* Function to display spaceship information */
void display_spaceship(Spaceship *ship) {
  printf("Spaceship Name: %s\n", ship->name);
  printf("Hull Health: %d/100\n", ship->hull_health);
  printf("Shield Health: %d/50\n", ship->shield_health);
  printf("Photon Torpedoes: %d/10\n", ship->photon_torpedoes);
}

/* Function to simulate an encounter with an enemy */
void simulate_encounter(Spaceship *player_ship) {
  Spaceship enemy_ship = {"Borg Cube", 100, 50, 10};
  printf("An enemy ship has appeared: %s\n", enemy_ship.name);
  printf("Prepare for battle!\n\n");

  while (player_ship->hull_health > 0 && enemy_ship.hull_health > 0) {
    // Player attacks the enemy
    int damage = generate_rand(10);
    enemy_ship.shield_health -= damage;
    printf("%s attacks the %s for %d damage!\n", player_ship->name, enemy_ship.name, damage);

    // Check if enemy's shields are down
    if (enemy_ship.shield_health <= 0) {
      printf("%s's shields are down!\n", enemy_ship.name);
      damage = generate_rand(20);
      enemy_ship.hull_health -= damage;
      printf("%s hits %s for %d damage!\n", enemy_ship.name, player_ship->name, damage);

      // Check if player's ship is destroyed
      if (player_ship->hull_health <= 0) {
        printf("%s's ship is destroyed!\n", player_ship->name);
        break;
      }
    } else {
      printf("%s's shield holds!\n", enemy_ship.name);
    }

    // Enemy attacks the player
    damage = generate_rand(15);
    player_ship->shield_health -= damage;
    printf("%s attacks %s for %d damage!\n", enemy_ship.name, player_ship->name, damage);

    // Check if player's shields are down
    if (player_ship->shield_health <= 0) {
      printf("%s's shields are down!\n", player_ship->name);
      damage = generate_rand(25);
      player_ship->hull_health -= damage;
      printf("%s hits %s for %d damage!\n", player_ship->name, player_ship->name, damage);

      // Check if enemy's ship is destroyed
      if (enemy_ship.hull_health <= 0) {
        printf("%s's ship is destroyed!\n", enemy_ship.name);
        break;
      }
    } else {
      printf("%s's shield holds!\n", player_ship->name);
    }

    printf("\n");
  }

  // Display result of the encounter
  if (player_ship->hull_health > enemy_ship.hull_health) {
    printf("%s has defeated the %s!\n", player_ship->name, enemy_ship.name);
  } else if (player_ship->hull_health < enemy_ship.hull_health) {
    printf("%s has been defeated by the %s!\n", player_ship->name, enemy_ship.name);
  } else {
    printf("The encounter has ended in a draw!\n");
  }
}

/* Main program */
int main() {
  Spaceship player_ship = {"USS Enterprise", 100, 50, 10};
  char play_again;

  printf("Welcome to Procedural Space Adventure!\n\n");
  printf("You are the captain of the USS Enterprise, on a mission to explore strange new worlds, to seek out new life and new civilizations, to boldly go where no one has gone before!\n\n");

  do {
    display_spaceship(&player_ship);
    printf("\n");

    simulate_encounter(&player_ship);

    printf("\nDo you want to play again? (Y/N) ");
    scanf(" %c", &play_again);
    printf("\n");
  } while (play_again == 'Y' || play_again == 'y');

  printf("Thanks for playing Procedural Space Adventure!\n");
  return 0;
}