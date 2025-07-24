//FormAI DATASET v1.0 Category: Poker Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    
    int player_hand[2]; // player's hand, containing two cards
    int dealer_hand[2]; // dealer's hand, containing two cards
    int community_cards[5]; // community cards, containing five cards
    int player_score = 0; // player's score, based on their best five-card hand
    int dealer_score = 0; // dealer's score, based on their best five-card hand
    int i, j, k; // loop variables
    
    // initialize player's hand
    printf("Getting your first two cards...\n");
    for (i = 0; i < 2; i++) {
        player_hand[i] = rand() % 52; // generate random card number (0-51)
        printf("Card %d: %d\n", i+1, player_hand[i]);
    }
    
    // initialize dealer's hand
    printf("Getting dealer's two cards...\n");
    for (i = 0; i < 2; i++) {
        dealer_hand[i] = rand() % 52; // generate random card number (0-51)
        printf("Card %d: %d\n", i+1, dealer_hand[i]);
    }
    
    // initialize community cards
    printf("Dealing the first three community cards...\n");
    for (i = 0; i < 3; i++) {
        community_cards[i] = rand() % 52; // generate random card number (0-51)
        printf("Community Card %d: %d\n", i+1, community_cards[i]);
    }
    
    // calculate player's score
    printf("Calculating your score...\n");
    for (i = 0; i < 5; i++) {
        if (i < 2) {
            // player's hand
            player_score += player_hand[i];
        } else {
            // combine player's hand with community cards
            player_score += community_cards[i-2];
        }
    }
    printf("Your score: %d\n", player_score);
    
    // calculate dealer's score
    printf("Calculating dealer's score...\n");
    for (i = 0; i < 5; i++) {
        if (i < 2) {
            // dealer's hand
            dealer_score += dealer_hand[i];
        } else {
            // combine dealer's hand with community cards
            dealer_score += community_cards[i-2];
        }
    }
    printf("Dealer's score: %d\n", dealer_score);
    
    // determine winner
    if (player_score > dealer_score) {
        printf("Congratulations, you won!\n");
    } else if (player_score < dealer_score) {
        printf("Sorry, the dealer won.\n");
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}