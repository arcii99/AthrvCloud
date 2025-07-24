//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void startGame();
void playGame();
void gameOver();
int choosePath();
void fight();
void runAway();
void win();
void lose();

int health = 100;
int bossHealth = 150;
int gold = 0;

int main() {
    startGame();
    playGame();
    return 0;
}

// Function to start the game
void startGame() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave warrior who is on a mission to defeat a powerful boss and save your kingdom.\n");
    printf("Your objective is to defeat the boss and win the game.\n");
    printf("Are you ready to start your adventure? (y/n): ");

    char choice[10];
    scanf("%s", choice);

    if (strcmp(choice, "y") == 0) {
        printf("\nGreat! Let's get started.\n\n");
    } else {
        printf("\nMaybe next time. Goodbye!\n");
        exit(0);
    }
}

// Function to play the game
void playGame() {
    printf("You are now on a path that leads to the boss's castle.\n");
    printf("You come across a fork in the road. Which path do you choose?\n");
    printf("1. Left path\n");
    printf("2. Right path\n");

    int path = choosePath();

    switch (path) {
        case 1:
            printf("\nYou chose the left path.\n");
            printf("You see a troll in front of you.\n");
            fight();
            break;
        case 2:
            printf("\nYou chose the right path.\n");
            printf("You come across a river.\n");
            runAway();
            break;
    }
}

// Function to handle game over
void gameOver() {
    printf("\nGame over!\n");
    printf("You have %d health points and %d gold.\n", health, gold);
    exit(0);
}

// Function to choose a path
int choosePath() {
    int choice;
    printf("\nChoose a path (1 or 2): ");
    scanf("%d", &choice);
    return choice;
}

// Function to fight the troll
void fight() {
    printf("\nYou must fight the troll!\n");
    int trollHealth = 50;

    while (health > 0 && trollHealth > 0) {
        printf("Your health: %d\n", health);
        printf("Troll's health: %d\n", trollHealth);
        printf("1. Attack\n");
        printf("2. Run\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                trollHealth -= 20;
                health -= 10;
                printf("You struck the troll for 20 HP.\n");
                printf("The troll struck you for 10 HP.\n");
                break;
            case 2:
                printf("You ran away from the troll.\n");
                printf("You lost 5 health points while running.\n");
                health -= 5;
                playGame();
                break;
        }
    }

    if (health > 0) {
        win();
    } else {
        lose();
    }
}

// Function to run away from the river
void runAway() {
    printf("\nYou must run away from the river!\n");
    printf("You successfully ran away and avoided danger.\n");
    gold += 20;
    printf("You found 20 gold coins on the ground.\n");
    printf("Your total gold is now %d.\n", gold);
    playGame();
}

// Function to handle winning the game
void win() {
    printf("\nCongratulations! You defeated the troll and gained access to the boss's castle.\n");
    printf("You now have the opportunity to save your kingdom and become a hero.\n");
    printf("Enter the castle and defeat the boss once and for all!\n");
    printf("Are you ready? (y/n): ");

    char choice[10];
    scanf("%s", choice);

    if (strcmp(choice, "y") == 0) {
        printf("\nYou entered the castle and are now face to face with the boss.\n");
        printf("Defeat the boss and save your kingdom!\n");
        fightBoss();
    } else {
        printf("\nMaybe next time. Goodbye!\n");
        exit(0);
    }
}

// Function to handle losing the game
void lose() {
    printf("\nYou lost the battle.\n");
    gameOver();
}

// Function to fight the boss
void fightBoss() {
    printf("\nYou must fight the boss!\n");

    while (health > 0 && bossHealth > 0) {
        printf("Your health: %d\n", health);
        printf("Boss's health: %d\n", bossHealth);
        printf("1. Attack\n");
        printf("2. Run\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                bossHealth -= 30;
                health -= 15;
                printf("You struck the boss for 30 HP.\n");
                printf("The boss struck you for 15 HP.\n");
                break;
            case 2:
                printf("You ran away from the boss.\n");
                printf("You lost 10 health points while running.\n");
                health -= 10;
                printf("You cannot escape the boss.\n");
                break;
        }
    }

    if (health > 0) {
        printf("\nCongratulations! You defeated the boss and saved your kingdom!\n");
        printf("You collected 100 gold coins from the boss's treasure.\n");
        gold += 100;
        printf("Your total gold is now %d.\n", gold);
    } else {
        lose();
    }

    gameOver();
}