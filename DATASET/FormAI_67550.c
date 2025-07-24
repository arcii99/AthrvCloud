//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5
#define MAX_NAME_LENGTH 20

typedef struct player_t {
    char name[MAX_NAME_LENGTH];
    int score;
} player;

void sanitize_input(char *input) {
    for (int i = 0; i < strlen(input); i++) {
        // Replace non-alphabet characters with spaces
        if (!isalpha(input[i])) {
            input[i] = ' ';
        }
        // Convert uppercase letters to lowercase
        if (isupper(input[i])) {
            input[i] = tolower(input[i]);
        }
    }
}

int main() {
    player players[MAX_PLAYERS];
    int num_players = 0;

    printf("Welcome to Multiplayer Input Sanitizer!\n");
    printf("Enter player names to get started, up to %d players\n", MAX_PLAYERS);

    // Get player names
    char input[MAX_NAME_LENGTH];
    while (num_players < MAX_PLAYERS) {
        printf("Enter player %d's name (or type 'done' to start): ", num_players + 1);
        fgets(input, sizeof(input), stdin);
        sanitize_input(input);
        if (strcmp(input, "done\n") == 0) {
            break;
        }
        // Copy sanitized name into player struct
        strncpy(players[num_players].name, input, MAX_NAME_LENGTH);
        players[num_players].score = 0;
        num_players++;
    }

    printf("Welcome %d players!\n", num_players);

    // Main game loop
    int round = 1;
    while (1) {
        printf("Round %d:\n", round);
        for (int i = 0; i < num_players; i++) {
            printf("%s's Turn:\n", players[i].name);
            printf("Enter your input: ");
            fgets(input, sizeof(input), stdin);
            sanitize_input(input);
            // Score the input and update player's score
            players[i].score += strlen(input);
            printf("Your score for this round is: %d\n", strlen(input));
            printf("Your total score is now: %d\n", players[i].score);
        }
        round++;
        // Check if players want to continue
        char choice;
        printf("Continue? (y/n): ");
        fgets(input, sizeof(input), stdin);
        if (tolower(input[0]) == 'n') {
            break; // Exit game loop
        }
    }

    printf("Final Scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}