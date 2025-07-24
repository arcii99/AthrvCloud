//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_welcome_message();
void enter_home();
void search_for_items();
void encounter_ghosts();
int roll_dice();

int main(void) {
  print_welcome_message();
  enter_home();
  search_for_items();
  encounter_ghosts();
  return 0;
}

void print_welcome_message() {
  printf("Welcome to the Haunted House Simulator!\n");
  printf("You find yourself standing in front of an old, rundown house.\n");
  printf("As you approach the door, you hear the creaking of the old wood.\n");
  printf("The wind is howling and the air feels thick with an unknown presence.\n");
  printf("Do you dare to enter the house?\n");
}

void enter_home() {
  printf("As you step inside the house, the door slams shut behind you.\n");
  printf("You are surrounded by darkness and the silence is deafening.\n");
  printf("You suddenly see a small, flickering light in the distance.\n");
  printf("You follow the light, hoping to find some way out or at least some answers.\n");
}

void search_for_items() {
  printf("As you move closer to the light, you start to see objects scattered around the room.\n");
  printf("You see a dusty table, a broken vase, and a large book on the floor.\n");
  printf("You realize that you must search the room for helpful items.\n");

  int found_items = 0;
  while (found_items < 3) {
    printf("Quickly, search the room for something useful!\n");

    // Roll the dice to determine if something is found
    int dice_roll = roll_dice();
    if (dice_roll > 3) {
      printf("You found an old key!\n");
      found_items++;
    } else {
      printf("You found nothing useful.\n");
    }
  }

  printf("You have found all the items you can. It's time to move on.\n");
}

void encounter_ghosts() {
  printf("As you continue through the house, the air grows colder and a chill runs down your spine.\n");
  printf("You hear a faint whispering from the shadows.\n");

  int ghosts_encountered = 0;
  while (ghosts_encountered < 3) {
    printf("Suddenly, you are face to face with a ghost!\n");

    // Roll the dice to determine if the ghost is friendly
    int dice_roll = roll_dice();
    if (dice_roll > 3) {
      printf("The ghost is friendly and hands you a clue!\n");
    } else {
      printf("The ghost attacks you! You defend yourself and escape, but not before losing some health.\n");
    }

    ghosts_encountered++;
  }

  printf("You have made it through the house, but you are scarred and shaken from your experience.\n");
}

int roll_dice() {
  srand(time(NULL));
  return rand() % 6 + 1;
}