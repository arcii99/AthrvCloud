//FormAI DATASET v1.0 Category: Poker Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* card_suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
char* card_ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
int card_values[13] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

int main() {
    srand(time(NULL));
    printf("Welcome to the most exciting game of Poker on the planet!\n");

    int player_score = 0;
    int computer_score = 0;
    int num_rounds = 0;

    while (1) {
        printf("\nRound %d. FIGHT!\n", num_rounds+1);
        num_rounds++;

        // Deal player and computer cards
        int player_card1_index = rand() % 13;
        int player_card1_value = card_values[player_card1_index];
        char* player_card1_suit = card_suits[rand() % 4];
        char* player_card1_rank = card_ranks[player_card1_index];

        int player_card2_index = rand() % 13;
        int player_card2_value = card_values[player_card2_index];
        char* player_card2_suit = card_suits[rand() % 4];
        char* player_card2_rank = card_ranks[player_card2_index];

        int computer_card_index = rand() % 13;
        int computer_card_value = card_values[computer_card_index];
        char* computer_card_suit = card_suits[rand() % 4];
        char* computer_card_rank = card_ranks[computer_card_index];

        // Print player and computer cards
        printf("Your cards: %s of %s and %s of %s\n", player_card1_rank, player_card1_suit, player_card2_rank, player_card2_suit);
        printf("Computer's card: %s of %s\n", computer_card_rank, computer_card_suit);

        // Check for Poker!
        if ((player_card1_value == 10 && player_card2_value == 11) || (player_card1_value == 11 && player_card2_value == 10)) {
            printf("POKER FACE! You win this round!\n");
            player_score++;
        } else if (computer_card_value == 10) {
            printf("Uh oh, the computer has a 10. You lost this round.. Womp womp.\n");
            computer_score++;
        } else {
            // Sum player and computer card values
            int player_total = player_card1_value + player_card2_value;
            int computer_total = computer_card_value;

            printf("Your total: %d\n", player_total);
            printf("Computer's total: %d\n", computer_total);

            // Compare player and computer totals
            if (player_total > 21) {
                printf("BUSTED! You lose this round :( Better luck next time.\n");
                computer_score++;
            } else if (computer_total > 21) {
                printf("The computer BUSTED! You win this round! :D\n");
                player_score++;
            } else if (player_total == computer_total) {
                printf("TIE! No points awarded.\n");
            } else if (player_total > computer_total) {
                printf("You win this round! :)\n");
                player_score++;
            } else if (computer_total > player_total) {
                printf("Too bad, the computer wins this round.. :(\n");
                computer_score++;
            }
        }

        printf("Current score: You %d - %d Computer\n", player_score, computer_score);

        // Check if player or computer has won the game
        if ((player_score >= 5) || (computer_score >= 5)) {
            printf("\nGAME OVER! ");
            if (player_score > computer_score) {
                printf("Congratulations! You win with a score of %d-%d!\n", player_score, computer_score);
            } else {
                printf("The computer wins with a score of %d-%d. Better luck next time!\n", computer_score, player_score);
            }
            break;
        }
    }

    return 0;
}