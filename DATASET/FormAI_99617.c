//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 1000 // maximum length of user input
#define MAX_SUMMARY 200 // maximum length of summary

int main() {
    char input[MAX_INPUT]; // user input
    char summary[MAX_SUMMARY]; // summarized output
    int players = 2; // number of players
    int current_player = 1; // current player
    int round = 1; // current round
    int winner = 0; // current winner (default: no winner)
    int scores[players]; // scores of each player
    memset(scores, 0, players * sizeof(int)); // set all scores to 0

    printf("Welcome to the Text Summarizer game!\n");
    printf("There are %d players.\n", players);

    while (1) {
        printf("Round %d. Player %d, enter your text: ", round, current_player);
        fgets(input, MAX_INPUT, stdin); // get user input
        input[strcspn(input, "\n")] = 0; // remove trailing newline character

        // summarize the input
        char *word = strtok(input, " ");
        while (word) {
            word[0] = toupper(word[0]); // capitalize first letter
            strcat(summary, word);
            strcat(summary, " ");
            word = strtok(NULL, " ");
        }

        // display the summary
        printf("Summary: %s\n", summary);

        // update scores
        scores[current_player - 1] += strlen(summary);
        printf("Player %d earns %d points for this round.\n", current_player, strlen(summary));

        // check for winner
        for (int i = 0; i < players; i++) {
            if (scores[i] >= 100) {
                winner = i + 1;
                break;
            }
        }

        // display scores
        printf("Current scores: ");
        for (int i = 0; i < players; i++) {
            printf("Player %d: %d points  ", i + 1, scores[i]);
        }
        printf("\n");

        if (winner) {
            printf("Congratulations! Player %d wins!\n", winner);
            break; // end the game
        }

        // prepare for the next round
        memset(input, 0, sizeof(input)); // clear user input
        memset(summary, 0, sizeof(summary)); // clear summary
        current_player = (current_player % players) + 1; // move to the next player
        round++; // increment round
    }

    return 0;
}