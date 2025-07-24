//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: recursive
#include <stdio.h>
#include <string.h>

/* Function declaration */
int play_game(int level);

int main() {
    printf("Welcome to Adventure Game!\n");
    printf("==========================\n\n");

    /* Start the game from level 1 */
    play_game(1);

    return 0;
}

/* Recursive function to play the game */
int play_game(int level) {
    char answer[50];

    /* Level descriptions */
    if(level == 1) {
        printf("You find yourself in a dark cave. There are two paths in front of you: ");
        printf("one leads to the left and the other leads to the right.\n\n");
        printf("Which path would you like to take? (left/right): ");
    } else if(level == 2) {
        printf("You come across a river. The water is too deep to cross on foot, but ");
        printf("you notice a raft floating nearby.\n\n");
        printf("Do you want to take the raft? (yes/no): ");
    } else if(level == 3) {
        printf("You reach a clearing where you see a castle in the distance.\n\n");
        printf("Do you want to approach the castle? (yes/no): ");
    } else if(level == 4) {
        printf("You enter the castle and are faced with two doors: ");
        printf("one on the left and one on the right.\n\n");
        printf("Which door do you choose? (left/right): ");
    } else if(level == 5) {
        printf("You climb a staircase and find the treasure chamber!\n\n");
        printf("Congratulations! You've won the game!\n");
        return 0;
    }

    /* Get user input */
    fgets(answer, 50, stdin);

    /* Remove newline character */
    answer[strcspn(answer, "\n")] = 0;

    /* Game logic for each level */
    if(level == 1) {
        if(strcmp(answer, "left") == 0) {
            printf("You reach a dead end and are trapped. Game over!\n");
            return 0;
        } else if(strcmp(answer, "right") == 0) {
            level = 2;
        } else {
            printf("Invalid input. Please enter 'left' or 'right'.\n\n");
            /* Play the same level again until valid input is entered */
            play_game(1);
        }
    } else if(level == 2) {
        if(strcmp(answer, "yes") == 0) {
            level = 3;
        } else if(strcmp(answer, "no") == 0) {
            printf("You try to find another way, but get lost and can't find your way back. Game over!\n");
            return 0;
        } else {
            printf("Invalid input. Please enter 'yes' or 'no'.\n\n");
            play_game(2);
        }
    } else if(level == 3) {
        if(strcmp(answer, "yes") == 0) {
            level = 4;
        } else if(strcmp(answer, "no") == 0) {
            printf("You turn back and get lost in the forest. Game over!\n");
            return 0;
        } else {
            printf("Invalid input. Please enter 'yes' or 'no'.\n\n");
            play_game(3);
        }
    } else if(level == 4) {
        if(strcmp(answer, "left") == 0) {
            printf("You fall into a pit and can't get out. Game over!\n");
            return 0;
        } else if(strcmp(answer, "right") == 0) {
            level = 5;
        } else {
            printf("Invalid input. Please enter 'left' or 'right'.\n\n");
            play_game(4);
        }
    }

    /* Play the next level */
    play_game(level + 1);
}