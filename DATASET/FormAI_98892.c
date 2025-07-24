//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_instructions();
void enter_room();
void examine_item();
void unlock_door();
void win_game();
void lose_game();

int main () {
    show_instructions();
    enter_room();
    return 0;
}

void show_instructions () {

    printf("Welcome to the Cryptic Adventure Game!\n");
    printf("You find yourself trapped in a room with no windows and only one door. \n");
    printf("To escape, you will need to unlock the door with a special key. \n");
    printf("Hint: the key is hidden somewhere in this room.\n");
    printf("Type 'help' if you need assistance.\n\n");
}

void enter_room () {

    char input[20];

    printf("You find yourself in the center of a small room. The walls are made of stone.\n");
    printf("There is a wooden table in the center of the room with a small dust-covered box on top.\n");
    printf("There is also a painting on the wall with symbols etched into the frame.\n");

    while (1) {

        printf("What do you want to do?\n");
        fgets(input, 20, stdin);

        if (strncmp(input, "examine", 7) == 0) {
            examine_item(input);
        }
        else if (strncmp(input, "unlock", 6) == 0) {
            unlock_door();
        }
        else if (strncmp(input, "help", 4) == 0) {
            printf("Try examining the painting or the box.\n");
        }
        else {
            printf("I do not understand what you mean.\n");
        }
    }
}

void examine_item (char *item) {

    if (strncmp(item, "examine box", 11) == 0) {
        printf("You find a small key inside the box!\n");
    }
    else if (strncmp(item, "examine painting", 15) == 0) {
        printf("The symbols on the frame form a word: 'NEXUS'.\n");
    }
    else {
        printf("Examine what?\n");
    }
}

void unlock_door() {

   int key_found = 0;

   printf("What key do you want to use?\n");
   char input[20];
   fgets(input, 20, stdin);

   if (strncmp(input, "small key", 9) == 0) {
       printf("You unlock the door and escape!\n");
       win_game();
   }
   else if (strncmp(input, "key", 3) == 0) {
       printf("What key are you talking about? You have not found it yet.\n");
   }
   else {
       printf("The key is not the right one.\n");
   }
}

void win_game () {
    printf("Congratulations, you have won the Cryptic Adventure Game!\n");
    printf("Thanks for playing!\n");
    exit(0);
}

void lose_game () {
    printf("Sorry, you have lost the Cryptic Adventure Game.\n");
    printf("Better luck next time!\n");
    exit(0);
}