//FormAI DATASET v1.0 Category: Poker Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the card and deck types
typedef struct {
    char* suit;
    char* face;
    int value;
} Card;

typedef struct {
    Card cards[52];
    int num_cards;
} Deck;

// Shuffle the deck
void shuffle_deck(Deck* deck) {
    srand(time(NULL));
    
    for (int i = 0; i < deck->num_cards; i++) {
        int j = rand() % (deck->num_cards - i) + i;
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// Deal cards to players
void deal_cards(Deck* deck, Card* player1_hand, Card* player2_hand) {
    for (int i = 0; i < 5; i++) {
        player1_hand[i] = deck->cards[i];
        player2_hand[i] = deck->cards[i+5];
    }
    deck->num_cards -= 10; // Remove dealt cards from deck
}

// Print the player's hand
void print_hand(Card* hand) {
    for (int i = 0; i < 5; i++) {
        printf("%s of %s\n", hand[i].face, hand[i].suit);
    }
}

// Determine the winner based on hand values
int determine_winner(Card* player1_hand, Card* player2_hand) {
    int player1_value = 0;
    int player2_value = 0;
    
    // Calculate the hand values
    for (int i = 0; i < 5; i++) {
        player1_value += player1_hand[i].value;
        player2_value += player2_hand[i].value;
    }
    
    // Determine the winner
    if (player1_value > player2_value) {
        return 1;
    } else if (player2_value > player1_value) {
        return 2;
    } else {
        return 0; // Tie
    }
}

int main() {
    // Initialize the deck
    Deck deck;
    char* suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char* faces[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    int values[13] = {14, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    deck.num_cards = 52;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            Card card;
            card.suit = suits[i];
            card.face = faces[j];
            card.value = values[j];
            deck.cards[i*13+j] = card;
        }
    }
    
    // Shuffle the deck
    shuffle_deck(&deck);
    
    // Deal cards to players
    Card player1_hand[5];
    Card player2_hand[5];
    deal_cards(&deck, player1_hand, player2_hand);
    
    // Print the players' hands
    printf("Player 1's hand:\n");
    print_hand(player1_hand);
    printf("\n");
    
    printf("Player 2's hand:\n");
    print_hand(player2_hand);
    printf("\n");
    
    // Determine the winner
    int result = determine_winner(player1_hand, player2_hand);
    if (result == 1) {
        printf("Player 1 wins!\n");
    } else if (result == 2) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}