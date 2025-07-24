//FormAI DATASET v1.0 Category: Table Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a random number between 1 and 10 for card value
int get_card_value() {
    return rand() % 10 + 1;
}

// Function to calculate the total value of the player's hand
int get_hand_value(int* hand, int num_cards) {
    int value = 0;
    int aces = 0; // variable to keep track of the number of aces in the hand
    for(int i = 0; i < num_cards; i++) {
        value += hand[i];
        if(hand[i] == 1) { // if the card is an ace, increment the aces variable
            aces++;
        }
    }
    // Handle aces - if the hand total is less than or equal to 11, treat an ace as 11. Otherwise, treat it as 1.
    while(aces > 0 && value <= 11) {
        value += 10;
        aces--;
    }
    return value;
}

int main() {
    srand(time(NULL)); // seed the random number generator
    
    int player_hand[10]; // array to hold the player's cards
    int dealer_hand[10]; // array to hold the dealer's cards
    
    // Deal two cards to the player and one card to the dealer
    player_hand[0] = get_card_value();
    player_hand[1] = get_card_value();
    dealer_hand[0] = get_card_value();
    
    int num_player_cards = 2;
    int num_dealer_cards = 1;
    
    // Game loop - allows player to take as many hits as desired until they stay or bust
    int stay = 0; // variable to indicate if the player has chosen to stay
    int player_bust = 0;
    while(!stay && !player_bust) {
        printf("Your hand: ");
        for(int i = 0; i < num_player_cards; i++) {
            printf("%d ", player_hand[i]);
        }
        printf("\n");
        
        printf("Dealer showing: %d\n", dealer_hand[0]);
        
        printf("Do you want to 'hit' or 'stay'? ");
        char input[10];
        fgets(input, 10, stdin);
        if(input[0] == 'h') { // if player chooses to hit, deal a new card
            player_hand[num_player_cards] = get_card_value();
            num_player_cards++;
            int player_total = get_hand_value(player_hand, num_player_cards);
            if(player_total > 21) { // handle bust condition
                printf("Total value of your hand: %d\n", player_total);
                printf("Bust! You lost.\n");
                player_bust = 1;
            }
        }
        else { // if player chooses to stay, exit the loop
            stay = 1;
        }
    }
    
    // Handle dealer's turn - dealer hits until their total is 17 or higher
    int dealer_total = get_hand_value(dealer_hand, num_dealer_cards);
    while(dealer_total < 17) {
        dealer_hand[num_dealer_cards] = get_card_value();
        num_dealer_cards++;
        dealer_total = get_hand_value(dealer_hand, num_dealer_cards);
    }
    
    // Determine winner
    if(!player_bust && dealer_total > 21) { // player wins if dealer busts
        printf("Your hand: ");
        for(int i = 0; i < num_player_cards; i++) {
            printf("%d ", player_hand[i]);
        }
        printf("\n");
        printf("Dealer hand: ");
        for(int i = 0; i < num_dealer_cards; i++) {
            printf("%d ", dealer_hand[i]);
        }
        printf("\n");
        printf("Dealer bust! You win!\n");
        return 0;
    }
    else {
        int player_total = get_hand_value(player_hand, num_player_cards);
        if(player_total > dealer_total) { // player wins if their total is greater than the dealer's total
            printf("Your hand: ");
            for(int i = 0; i < num_player_cards; i++) {
                printf("%d ", player_hand[i]);
            }
            printf("\n");
            printf("Dealer hand: ");
            for(int i = 0; i < num_dealer_cards; i++) {
                printf("%d ", dealer_hand[i]);
            }
            printf("\n");
            printf("You win! (%d vs %d)\n", player_total, dealer_total);
            return 0;
        }
        else if(player_total < dealer_total) { // dealer wins if their total is greater than the player's total
            printf("Your hand: ");
            for(int i = 0; i < num_player_cards; i++) {
                printf("%d ", player_hand[i]);
            }
            printf("\n");
            printf("Dealer hand: ");
            for(int i = 0; i < num_dealer_cards; i++) {
                printf("%d ", dealer_hand[i]);
            }
            printf("\n");
            printf("Dealer wins! (%d vs %d)\n", dealer_total, player_total);
            return 0;
        }
        else { // tie game if the totals are equal
            printf("Your hand: ");
            for(int i = 0; i < num_player_cards; i++) {
                printf("%d ", player_hand[i]);
            }
            printf("\n");
            printf("Dealer hand: ");
            for(int i = 0; i < num_dealer_cards; i++) {
                printf("%d ", dealer_hand[i]);
            }
            printf("\n");
            printf("Tie game! (%d vs %d)\n", player_total, dealer_total);
            return 0;
        }
    }
}