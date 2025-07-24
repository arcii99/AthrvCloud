//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int health = 100;
  int gold = 0;
  int inventory[3] = {0};
  int dungeon_level = 0;
  int boss_level = 0;

  printf("Welcome, adventurer! You are about to embark on a dangerous journey through the depths of the dungeon.\n");

  while (health > 0) {
    int room_type = rand() % 3;

    if (room_type == 0) {
      printf("You have entered a treasure room!\n");
      gold += rand() % 50 + 1;
      printf("You found %d gold coins! Your total gold is now %d.\n", gold - inventory[0] - inventory[1] - inventory[2], gold);
      printf("You also found a potion!\n");
      if (inventory[0] == 0) {
        inventory[0] = 1;
        printf("You added the potion to your inventory.\n");
      } else if (inventory[1] == 0) {
        inventory[1] = 1;
        printf("You added the potion to your inventory.\n");
      } else if (inventory[2] == 0) {
        inventory[2] = 1;
        printf("You added the potion to your inventory.\n");
      } else {
        printf("Your inventory is full. You cannot add the potion to your inventory.\n");
      }

    } else if (room_type == 1) {
      printf("You have encountered a monster!\n");
      int monster_health = rand() % 20 + 30;
      printf("Monster's health is %d.\n", monster_health);
      while (monster_health > 0) {
        int player_damage = rand() % 20 + 10;
        int monster_damage = rand() % 15 + 5;
        printf("You dealt %d damage to the monster!\n", player_damage);
        monster_health -= player_damage;
        if (monster_health <= 0) {
          printf("You defeated the monster!\n");
          int monster_gold = rand() % 20 + 10;
          printf("The monster dropped %d gold.\n", monster_gold - inventory[0] - inventory[1] - inventory[2]);
          gold += monster_gold;
          printf("Your total gold is now %d.\n", gold);
          break;
        }
        printf("The monster dealt %d damage to you!\n", monster_damage);
        health -= monster_damage;
        if (health <= 0) {
          printf("You have been slain by the monster...\n");
          break;
        }
        printf("Your health is now %d.\n", health);
      }

    } else {
      printf("You have found a staircase leading down to the next level of the dungeon!\n");
      dungeon_level++;
      if (dungeon_level % 5 == 0) {
        printf("You have encountered the boss of this dungeon!\n");
        int boss_health = rand() % 50 + 100 + boss_level * 10;
        printf("Boss's health is %d.\n", boss_health);
        while (boss_health > 0) {
          int player_damage = rand() % 20 + 10;
          int boss_damage = rand() % 20 + 15 + boss_level * 5;
          printf("You dealt %d damage to the boss!\n", player_damage);
          boss_health -= player_damage;
          if (boss_health <= 0) {
            printf("You defeated the boss!\n");
            int boss_gold = rand() % 50 + 50 + boss_level * 10;
            printf("The boss dropped %d gold.\n", boss_gold - inventory[0] - inventory[1] - inventory[2]);
            gold += boss_gold;
            printf("Your total gold is now %d.\n", gold);
            boss_level++;
            break;
          }
          printf("The boss dealt %d damage to you!\n", boss_damage);
          health -= boss_damage;
          if (health <= 0) {
            printf("You have been slain by the boss...\n");
            break;
          }
          printf("Your health is now %d.\n", health);
        }
      }
    }
  }

  printf("Game over.\n");

  return 0;
}