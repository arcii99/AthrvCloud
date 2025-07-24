//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen();
void gameOver();
void win();

int main() {
    int health = 100;
    int damage;
    int random;
    srand(time(NULL)); // initialize random seed
    
    printf("Welcome to the Jungle Adventure Game!\n\n");
    printf("You are on a mission to find the treasure hidden deep in the jungle.\n");
    printf("You have a health bar which starts at 100.\n");
    printf("Your goal is to navigate through the jungle and find the treasure.\n");
    printf("Be careful! There are dangerous animals lurking around every corner.\n");
    printf("You may encounter crocodiles, tigers, and even giant snakes on your journey.\n");
    printf("You have a 50/50 chance of defeating any enemy you encounter.\n");
    printf("You will lose health if you lose a battle, so be careful!\n\n");

    while(health > 0) {
        printf("\nYou see something moving in the distance.\n");
        printf("Press ENTER to investigate...");
        getchar();
        clearScreen();

        random = rand() % 2; // generates random number between 0 and 1
        if(random == 0) {
            printf("You encounter a crocodile!\n");
            printf("Prepare for battle!\n\n");

            damage = rand() % 25 + 1; // generates random number between 1 and 25
            printf("You attack the crocodile and deal %d damage!\n", damage);

            if(damage >= 15) {
                printf("You defeated the crocodile!\n");
            }
            else {
                printf("The crocodile bit you and did %d damage!\n", damage);
                health -= damage;
            }
        }
        else {
            printf("You find a hidden path that leads to the treasure!\n");
            printf("Congratulations, you won the game!\n");
            win();
            return 0;
        }

        if(health <= 0) {
            clearScreen();
            printf("Your health has dropped to 0. Game Over.\n");
            gameOver();
            return 0;
        }

        printf("\nYour current health is %d.\n", health);
        printf("Press ENTER to continue...");
        getchar();
        clearScreen();
    }

    return 0;
}

void clearScreen() {
    system("cls||clear");
}

void gameOver() {
    printf("         _______..______\n");
    printf("        /       ||   _  \\\n");
    printf("       |   (----`|  |_)  |\n");
    printf("        \\   \\    |      /\n");
    printf(".----)   |   |   |  |\\  \\-------.\n");
    printf("|_______/    |___| _| `.________|\n");
}

void win() {
    printf(" __     __          __          ___________ _        __\n");
    printf(" \\ \\   / /          \\ \\        / /_   _|_ _| |      / /\n");
    printf("  \\ \\_/ /__  _   _   \\ \\  /\\  / /  | |  | | |     / / \n");
    printf("   \\   / _ \\| | | |   \\ \\/  \\/ /   | |  | | |    / /  \n");
    printf("    | | (_) | |_| |    \\  /\\  /   _| |_ |_|_|   /_/   \n");
    printf("    |_|\\___/ \\__,_|     \\/  \\/   |_____| (_)  (_)    \n");
}