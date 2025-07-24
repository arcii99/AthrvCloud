//FormAI DATASET v1.0 Category: Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declare function prototypes
void print_header();
int roll_dice();
void play_game(int point);
int check_winner(int point, int sum);

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    // display header
    print_header();
    
    // start game loop
    while (1) {
        int point = roll_dice();
        play_game(point);
    }
    
    return 0;
}

void print_header() {
    printf("Welcome to the Dice Game!\n");
}

int roll_dice() {
    printf("Press enter to roll the dice...\n");
    getchar();  // wait for user to press enter
    
    int die1 = rand() % 6 + 1;  // generate random number between 1-6
    int die2 = rand() % 6 + 1; 
    
    int sum = die1 + die2;
    printf("You rolled %d + %d = %d\n", die1, die2, sum);
    
    return sum;
}

void play_game(int point) {
    int sum = roll_dice();
    int result = check_winner(point, sum);
    
    if (result == 1) {
        printf("You win!\n");
        exit(0);
    }
    else if (result == 0) {
        printf("You lose!\n");
        exit(0);
    }
    else {
        printf("Roll again to try to get your point!\n");
        getchar();
    }
}

int check_winner(int point, int sum) {
    if (sum == point) {
        return 1;  // player wins
    }
    else if (sum == 7) {
        return 0;  // player loses
    }
    else {
        return -1;  // continue game
    }
}