//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the C Text Summarizer game!\n");
    printf("In this game, you will work with other players to summarize a text.\n");
    printf("Are you ready to start playing? (y/n)\n");
    char answer;
    scanf("%c", &answer);

    if (answer == 'n') {
        printf("That's too bad. Maybe next time!\n");
    } else {
        printf("Great! Let's get started.\n");
        printf("First, we need to enter the text to summarize:\n");
        char text[1000];
        scanf(" %[^\n]s", text);

        printf("Now, we need to decide how many players will be playing:\n");
        int num_players;
        scanf("%d", &num_players);

        printf("\n");

        int i;
        for (i = 1; i <= num_players; i++) {
            printf("Player %d: Please enter a summary of the text (max 100 characters):\n", i);
            char summary[100];
            scanf(" %[^\n]s", summary);
            printf("Thank you, Player %d!\n\n", i);
        }

        printf("Now that all the players have submitted their summaries, let's combine them into one final summary:\n");
        char final_summary[500];

        for (i = 1; i <= num_players; i++) {
            printf("Player %d's summary: ", i);
            char summary[100];
            scanf(" %[^\n]s", summary);
            strcat(final_summary, summary);
            strcat(final_summary, " ");
        }

        printf("\n\nThe final summary is: %s", final_summary);
        printf("\nThanks for playing!\n");
    }

    return 0;
}