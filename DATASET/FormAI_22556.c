//FormAI DATASET v1.0 Category: Poker Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define NUM_CARDS 2

int random_card();
int get_card_value(int card);
int determine_hand_value(int hand[], int num_cards);

int main() {
    int deck[DECK_SIZE]; // Array to represent the deck of cards
    int player_hand[NUM_CARDS]; // Array to hold the cards in the player's hand
    int dealer_hand[NUM_CARDS]; // Array to hold the cards in the dealer's hand
    int player_total, dealer_total;
    int player_score = 0, dealer_score = 0;
    int num_games = 1;
    char input;

    srand(time(NULL)); // Seed the random number generator

    while (1) { // Loop to play multiple games
        printf("Game %d:\n", num_games);
        num_games++;

        // Initialize the deck of cards
        for (int i = 0; i < DECK_SIZE; i++) {
            deck[i] = i;
        }

        // Shuffle the deck
        for (int i = 0; i < DECK_SIZE; i++) {
            int j = rand() % DECK_SIZE;
            int temp = deck[i];
            deck[i] = deck[j];
            deck[j] = temp;
        }

        // Deal the cards
        player_hand[0] = deck[0];
        dealer_hand[0] = deck[1];
        player_hand[1] = deck[2];
        dealer_hand[1] = deck[3];

        // Print the dealer's face up card
        printf("Dealer's face up card: %d\n", get_card_value(dealer_hand[0]));

        // Ask the player for their move
        printf("Your hand: %d, %d\n", get_card_value(player_hand[0]), get_card_value(player_hand[1]));
        printf("What do you want to do? (h)it or (s)tand? ");

        // Get the player's move
        input = getchar();
        while (input != 'h' && input != 's') {
            input = getchar();
        }
        while (getchar() != '\n'); // Clear any extra input

        // Player hits
        if (input == 'h') {
            player_hand[2] = deck[4];

            // Determine the value of the player's hand
            player_total = determine_hand_value(player_hand, 3);

            // Print the player's hand and total
            printf("Your hand: %d, %d, %d\n", get_card_value(player_hand[0]), get_card_value(player_hand[1]), get_card_value(player_hand[2]));
            printf("Your total: %d\n", player_total);

            // Determine the value of the dealer's hand
            dealer_total = determine_hand_value(dealer_hand, 2);

            // Dealer hits until they have a total of at least 17
            while (dealer_total < 17) {
                dealer_hand[2] = deck[5];
                dealer_total = determine_hand_value(dealer_hand, 3);
            }

            // Print the dealer's hand and total
            printf("Dealer's hand: %d, %d, %d\n", get_card_value(dealer_hand[0]), get_card_value(dealer_hand[1]), get_card_value(dealer_hand[2]));
            printf("Dealer's total: %d\n", dealer_total);

            // Determine the winner
            if ((player_total > dealer_total && player_total <= 21) || (dealer_total > 21 && player_total <= 21)) {
                printf("You win!\n");
                player_score++;
            }
            else if ((dealer_total > player_total && dealer_total <= 21) || (player_total > 21 && dealer_total <= 21)) {
                printf("Dealer wins!\n");
                dealer_score++;
            }
            else {
                printf("Draw!\n");
            }
        }
        // Player stands
        else if (input == 's') {
            // Determine the value of the player's hand
            player_total = determine_hand_value(player_hand, 2);

            // Determine the value of the dealer's hand
            dealer_total = determine_hand_value(dealer_hand, 2);

            // Dealer hits until they have a total of at least 17
            while (dealer_total < 17) {
                dealer_hand[2] = deck[4];
                dealer_total = determine_hand_value(dealer_hand, 3);
            }

            // Print the dealer's hand and total
            printf("Dealer's hand: %d, %d, %d\n", get_card_value(dealer_hand[0]), get_card_value(dealer_hand[1]), get_card_value(dealer_hand[2]));
            printf("Dealer's total: %d\n", dealer_total);

            // Determine the winner
            if ((player_total > dealer_total && player_total <= 21) || (dealer_total > 21 && player_total <= 21)) {
                printf("You win!\n");
                player_score++;
            }
            else if ((dealer_total > player_total && dealer_total <= 21) || (player_total > 21 && dealer_total <= 21)) {
                printf("Dealer wins!\n");
                dealer_score++;
            }
            else {
                printf("Draw!\n");
            }
        }

        // Print the current score
        printf("Score: You %d, Dealer %d\n", player_score, dealer_score);

        // Ask the player if they want to play again
        printf("Play again? (y/n) ");
        input = getchar();
        while (input != 'y' && input != 'n') {
            input = getchar();
        }
        while (getchar() != '\n'); // Clear any extra input

        if (input == 'n') {
            break;
        }

        printf("\n");
    }

    return 0;
}

// Function to get a random card from the deck
int random_card() {
    static int card_index = 0;
    return card_index++;
}

// Function to get the value of a card
int get_card_value(int card) {
    int value = (card % 13) + 1;
    if (value > 10) {
        value = 10;
    }
    return value;
}

// Function to determine the total value of a hand
int determine_hand_value(int hand[], int num_cards) {
    int total = 0;
    int num_aces = 0;

    for (int i = 0; i < num_cards; i++) {
        int card_value = get_card_value(hand[i]);
        if (card_value == 1) {
            num_aces++;
        }
        total += card_value;
    }

    // If there are aces in the hand, adjust the total for the highest possible value
    while (num_aces > 0 && total + 10 <= 21) {
        total += 10;
        num_aces--;
    }

    return total;
}