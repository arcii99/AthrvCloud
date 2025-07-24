//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constants and global variables
#define MAX_INPUT 50
char input[MAX_INPUT];
int health = 100;

// Declare functions
void start_game();
void investigate_clue();
void go_to_location();
void fight_villain();
void check_health();
void game_over();

int main() {
   start_game();
   return 0;
}

void start_game() {
   printf("\n----------------------------------------");
   printf("\n|   WELCOME TO THE SHERLOCK HOLMES     |");
   printf("\n|          TEXT-BASED GAME             |");
   printf("\n----------------------------------------\n");
   printf("\nYou are Sherlock Holmes, the famous detective. Your mission is to solve a mystery and capture the villain.\n");
   printf("\nYou currently have 100 health and can use commands such as:\ninvestigate, go to, fight and check health\n");
   printf("\nWhat would you like to do?\n");

   fgets(input, MAX_INPUT, stdin);
   printf("\n");

   if (strcmp(input, "investigate\n") == 0) {
      investigate_clue();
   } else if (strcmp(input, "go to\n") == 0) {
      go_to_location();
   } else if (strcmp(input, "fight\n") == 0) {
      fight_villain();
   } else if (strcmp(input, "check health\n") == 0) {
      check_health();
   } else {
      printf("Invalid input. Try again.\n");
      start_game();
   }
}

void investigate_clue() {
   printf("\nYou have found a clue. It is a note from the villain.\n");
   printf("\nIt reads: Meet me at the old mansion at midnight. Come alone.\n");
   printf("\nWhat would you like to do?\n");

   fgets(input, MAX_INPUT, stdin);
   printf("\n");

   if (strcmp(input, "investigate\n") == 0) {
      printf("\nYou find nothing else of interest.\n");
      start_game();
   } else if (strcmp(input, "go to\n") == 0) {
      go_to_location();
   } else if (strcmp(input, "fight\n") == 0) {
      printf("\nThere is no one to fight here.\n");
      investigate_clue();
   } else if (strcmp(input, "check health\n") == 0) {
      check_health();
      investigate_clue();
   } else {
      printf("Invalid input. Try again.\n");
      investigate_clue();
   }
}

void go_to_location() {
   printf("\nYou have arrived at the old mansion. It is very dark and quiet.\n");
   printf("\nWhat would you like to do?\n");

   fgets(input, MAX_INPUT, stdin);
   printf("\n");

   if (strcmp(input, "investigate\n") == 0) {
      printf("\nYou find footprints leading to the door.\n");
      go_to_location();
   } else if (strcmp(input, "go to\n") == 0) {
      printf("\nThere is nowhere else to go.\n");
      go_to_location();
   } else if (strcmp(input, "fight\n") == 0) {
      fight_villain();
   } else if (strcmp(input, "check health\n") == 0) {
      check_health();
      go_to_location();
   } else {
      printf("Invalid input. Try again.\n");
      go_to_location();
   }
}

void fight_villain() {
   printf("\nYou have encountered the villain. He is armed and dangerous.\n");
   
   while (health > 0) {
      printf("\nEnter 'fight' to attack or 'run away' to try and escape.\n");
      fgets(input, MAX_INPUT, stdin);
      printf("\n");

      if (strcmp(input, "fight\n") == 0) {
         printf("You attacked the villain and dealt 10 damage.\n");
         health -= 10;
         printf("Your health is now %d.\n", health);
         if (health <= 0) {
            game_over();
         }
      } else if (strcmp(input, "run away\n") == 0) {
         printf("You tried to escape, but the villain caught you and dealt 20 damage.\n");
         health -= 20;
         printf("Your health is now %d.\n", health);
         if (health <= 0) {
            game_over();
         }
      } else {
         printf("Invalid input. Try again.\n");
      }
   }
   
   printf("\nCongratulations! You have caught the villain and solved the mystery.\n");
   printf("\nThanks for playing!\n");

}

void check_health() {
   printf("\nYour health is currently %d.\n", health);
}

void game_over() {
   printf("\nGame over. You have lost all your health.\n");
   printf("\nThanks for playing!\n");
   exit(0);
}