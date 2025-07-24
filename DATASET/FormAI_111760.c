//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// define constant variables
#define BOARD_SIZE 5
#define MAX_GUESSES 10
#define LOVE_POINTS_TO_WIN 100

// function to print the game board
void print_board(int board[][BOARD_SIZE], int love_points) {
    printf("\n~~~ LOVE GAME ~~~\n\n");
    printf("Love Points: %d\n", love_points);
    printf("Guesses left: %d\n\n", MAX_GUESSES);
    
    // print the game board
    for(int row=0; row<BOARD_SIZE; row++) {
        for(int col=0; col<BOARD_SIZE; col++) {
            if(board[row][col] == 0) {
                printf("~ ");
            } else {
                printf("%d ", board[row][col]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if the game is finished
bool is_game_finished(int love_points) {
    if(love_points >= LOVE_POINTS_TO_WIN) {
        printf("\nYou Win!");
        return true;
    } else if(MAX_GUESSES <= 0) {
        printf("\nGame Over!");
        return true;
    } else {
        return false;
    }
}

// function for the user's turn
void user_turn(int board[][BOARD_SIZE], int *love_points, int *guess_count) {
    int guess_row, guess_col;
    
    printf("Enter your guess (row column): ");
    scanf("%d %d", &guess_row, &guess_col);
    
    if(board[guess_row][guess_col] == 9) {
        *love_points += 20;
        board[guess_row][guess_col] = 0;
        printf("You found a heart!\n");
    } else if(board[guess_row][guess_col] == 0) {
        printf("You already guessed there!\n");
    } else {
        *guess_count -= 1;
        printf("Missed! Guesses left: %d\n", *guess_count);
    }
}

// function for the computer's turn
void computer_turn(int board[][BOARD_SIZE], int *love_points) {
    int guess_row, guess_col;
    
    // generate random guesses until it hits a number
    do {
        guess_row = rand() % BOARD_SIZE;
        guess_col = rand() % BOARD_SIZE;
    } while(board[guess_row][guess_col] == 0);
    
    if(board[guess_row][guess_col] == 9) {
        *love_points -= 10;
        board[guess_row][guess_col] = 0;
        printf("AI found a heart!\n");
    } else {
        *love_points += 5;
        board[guess_row][guess_col] = 0;
        printf("AI missed!\n");
    }
}

int main() {
    // initialize variables
    int board[BOARD_SIZE][BOARD_SIZE];
    int love_points = 0;
    int guess_count = MAX_GUESSES;
    
    srand(time(NULL)); // seed the random number generator
    
    // initialize board
    for(int row=0; row<BOARD_SIZE; row++) {
        for(int col=0; col<BOARD_SIZE; col++) {
            board[row][col] = rand() % 10;
        }
    }
    
    // print welcome message and instructions
    printf("~~~ Welcome to Love Game! ~~~\n\n");
    printf("Instructions: \n");
    printf(" - You have %d guesses to find the hearts on the board.\n", MAX_GUESSES);
    printf(" - Each heart will give you 20 points, and each miss will take 10 points.\n");
    printf(" - You win if you reach %d love points.\n\n",LOVE_POINTS_TO_WIN);
    
    // loop until the game is finished
    while(!is_game_finished(love_points)) {
        print_board(board, love_points);
        user_turn(board, &love_points, &guess_count);
        if(!is_game_finished(love_points)) {
            computer_turn(board, &love_points);
        }
    }
    
    return 0;
}