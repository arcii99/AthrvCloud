//FormAI DATASET v1.0 Category: Poker Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

/* Card Struct */
typedef struct card_s {
    const char *face;
    const char *suit;
} Card;

/* Deck Struct */
typedef struct deck_s {
    Card cards[DECK_SIZE];
    int top_card;
} Deck;

/* Hand Struct */
typedef struct hand_s {
    Card cards[HAND_SIZE];
} Hand;

/* Function Prototypes */
void shuffle_deck(Deck *deck);
void swap_cards(Card *card1, Card *card2);
void print_card(const Card *card);
void print_hand(const Hand *hand);
void deal_hand(Deck *deck, Hand *hand);
int evaluate_hand(const Hand *hand);

/* Main Program */
int main(void) {
    Deck deck = {
        .cards = {
            {"2", "Hearts"}, {"2", "Diamonds"}, {"2", "Clubs"}, {"2", "Spades"},
            {"3", "Hearts"}, {"3", "Diamonds"}, {"3", "Clubs"}, {"3", "Spades"},
            {"4", "Hearts"}, {"4", "Diamonds"}, {"4", "Clubs"}, {"4", "Spades"},
            {"5", "Hearts"}, {"5", "Diamonds"}, {"5", "Clubs"}, {"5", "Spades"},
            {"6", "Hearts"}, {"6", "Diamonds"}, {"6", "Clubs"}, {"6", "Spades"},
            {"7", "Hearts"}, {"7", "Diamonds"}, {"7", "Clubs"}, {"7", "Spades"},
            {"8", "Hearts"}, {"8", "Diamonds"}, {"8", "Clubs"}, {"8", "Spades"},
            {"9", "Hearts"}, {"9", "Diamonds"}, {"9", "Clubs"}, {"9", "Spades"},
            {"10", "Hearts"}, {"10", "Diamonds"}, {"10", "Clubs"}, {"10", "Spades"},
            {"Jack", "Hearts"}, {"Jack", "Diamonds"}, {"Jack", "Clubs"}, {"Jack", "Spades"},
            {"Queen", "Hearts"}, {"Queen", "Diamonds"}, {"Queen", "Clubs"}, {"Queen", "Spades"},
            {"King", "Hearts"}, {"King", "Diamonds"}, {"King", "Clubs"}, {"King", "Spades"},
            {"Ace", "Hearts"}, {"Ace", "Diamonds"}, {"Ace", "Clubs"}, {"Ace", "Spades"}
        },
        .top_card = 0
    };

    printf("Initial Deck:\n");
    for(int i = 0; i < DECK_SIZE; i++) {
        print_card(&deck.cards[i]);
    }

    srand(time(NULL)); // Seed random number generator

    shuffle_deck(&deck); // Shuffle the deck

    printf("\nShuffled Deck:\n");
    for(int i = 0; i < DECK_SIZE; i++) {
        print_card(&deck.cards[i]);
    }

    Hand player_hand = {0};

    deal_hand(&deck, &player_hand); // Deal a hand to the player

    printf("\nPlayer's Hand:\n");
    print_hand(&player_hand);

    int hand_value = evaluate_hand(&player_hand); // Evaluate the player's hand

    printf("Hand Value: %d\n", hand_value);

    return 0;
}

/* Shuffle the deck */
void shuffle_deck(Deck *deck) {
    int index1, index2;
    for(int i = 0; i < 100; i++) {
        index1 = rand() % DECK_SIZE;
        index2 = rand() % DECK_SIZE;
        swap_cards(&deck->cards[index1], &deck->cards[index2]);
    }
}

/* Swap two cards */
void swap_cards(Card *card1, Card *card2) {
    Card temp_card = *card1;
    *card1 = *card2;
    *card2 = temp_card;
}

/* Print the value and suit of a card */
void print_card(const Card *card) {
    printf("%s of %s\n", card->face, card->suit);
}

/* Print a hand of cards */
void print_hand(const Hand *hand) {
    for(int i = 0; i < HAND_SIZE; i++) {
        print_card(&hand->cards[i]);
    }
}

/* Deal a hand of cards from a deck */
void deal_hand(Deck *deck, Hand *hand) {
    for(int i = 0; i < HAND_SIZE; i++) {
        hand->cards[i] = deck->cards[deck->top_card];
        deck->top_card++;
    }
}

/* Evaluate the value of a hand of cards */
int evaluate_hand(const Hand *hand) {
    int hand_value = 0;

    // Add up the face values of the cards
    for(int i = 0; i < HAND_SIZE; i++) {
        if(hand->cards[i].face[0] == '2') {
            hand_value += 2;
        }
        else if(hand->cards[i].face[0] == '3') {
            hand_value += 3;
        }
        else if(hand->cards[i].face[0] == '4') {
            hand_value += 4;
        }
        else if(hand->cards[i].face[0] == '5') {
            hand_value += 5;
        }
        else if(hand->cards[i].face[0] == '6') {
            hand_value += 6;
        }
        else if(hand->cards[i].face[0] == '7') {
            hand_value += 7;
        }
        else if(hand->cards[i].face[0] == '8') {
            hand_value += 8;
        }
        else if(hand->cards[i].face[0] == '9') {
            hand_value += 9;
        }
        else if(hand->cards[i].face[0] == '1' || hand->cards[i].face[0] == 'J' || hand->cards[i].face[0] == 'Q' || hand->cards[i].face[0] == 'K') {
            hand_value += 10;
        }
        else if(hand->cards[i].face[0] == 'A') {
            hand_value += 11;
        }
    }

    // Subtract 10 for each Ace until the hand is less than or equal to 21
    int num_aces = 0;
    for(int i = 0; i < HAND_SIZE; i++) {
        if(hand->cards[i].face[0] == 'A') {
            num_aces++;
        }
    }
    while(num_aces > 0 && hand_value > 21) {
        hand_value -= 10;
        num_aces--;
    }

    return hand_value;
}