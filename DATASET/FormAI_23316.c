//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_SIZE 50
#define NUM_PLAYERS 2

// function to sanitize input
void sanitize_input(char input[]) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (!isalpha(input[i])) {
            input[i] = '*'; // replace non-alphabetic characters with *
        } else {
            input[i] = tolower(input[i]); // convert alphabetic characters to lowercase
        }
    }
}

int main() {
    char input[MAX_INPUT_SIZE]; // input buffer
    int turn_counter = 0; // counter for turns taken
    int winner = -1; // variable to store the index of the winner
    
    // array to store player names
    char player_names[NUM_PLAYERS][MAX_INPUT_SIZE] = {"Player 1", "Player 2"};
    
    printf("Welcome to the Input Sanitizer game!\n");
    printf("Enter your name, player 1: ");
    fgets(player_names[0], MAX_INPUT_SIZE, stdin);
    sanitize_input(player_names[0]); // sanitize player name
    
    printf("Enter your name, player 2: ");
    fgets(player_names[1], MAX_INPUT_SIZE, stdin);
    sanitize_input(player_names[1]); // sanitize player name
    
    // game loop
    while (winner == -1) {
        printf("\n%s's turn, enter your input: ", player_names[turn_counter % 2]);
        fgets(input, MAX_INPUT_SIZE, stdin);
        sanitize_input(input); // sanitize input
        
        printf("Sanitized input: %s\n", input);
        turn_counter++; // increment turn counter
        
        // check for winner
        if (strncmp(input, "exit", 4) == 0) {
            winner = turn_counter % 2; // set winner to current player
        }
    }
    
    printf("\n%s wins!", player_names[winner]);
    
    return 0;
}