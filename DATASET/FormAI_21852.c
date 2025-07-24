//FormAI DATASET v1.0 Category: Poker Game ; Style: Romeo and Juliet
/*
 * Romeo and Juliet Poker Game
 * By: Your Friendly Neighborhood Chatbot
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HAND_SIZE 5
#define DECK_SIZE 52

typedef enum{CLUBS, DIAMONDS, HEARTS, SPADES} Suit;
typedef enum{
    TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8,
    NINE = 9, TEN = 10, JACK = 11, QUEEN = 12, KING = 13, ACE = 14
} Rank;

typedef struct{
    Suit suit;
    Rank rank;
} Card;

typedef struct{
    Card cards[HAND_SIZE];
    int worth;
} Hand;

typedef struct{
    Card deck[DECK_SIZE];
    int top;
} Deck;

void shuffle(Deck* deck){
    Card temp;
    int randIndex;

    for(int i = 0; i < DECK_SIZE; i++){
        randIndex = rand() % DECK_SIZE;
        temp = deck->deck[i];
        deck->deck[i] = deck->deck[randIndex];
        deck->deck[randIndex] = temp;
    }
}

void deal(Hand* hand, Deck* deck){
    for(int i = 0; i < HAND_SIZE; i++){
        hand->cards[i] = deck->deck[deck->top++];
    }
}

void printHand(Hand hand){
    char* rankNames[13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
    "Ten", "Jack", "Queen", "King", "Ace"};
    char* suitNames[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    for(int i = 0; i < HAND_SIZE; i++){
        printf("%s of %s\n", rankNames[hand.cards[i].rank - 2], suitNames[hand.cards[i].suit]);
    }
}

int main(){
    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the Romeo and Juliet Poker Game!\n\n");

    // Initialize deck
    Deck deck;
    int cardIndex = 0;
    for(int suit = CLUBS; suit <= SPADES; suit++){
        for(int rank = TWO; rank <= ACE; rank++){
            deck.deck[cardIndex].suit = suit;
            deck.deck[cardIndex].rank = rank;
            cardIndex++;
        }
    }
    deck.top = 0;

    // Shuffle deck
    shuffle(&deck);

    // Deal hands to Romeo and Juliet
    Hand romeoHand, julietHand;
    deal(&romeoHand, &deck);
    deal(&julietHand, &deck);

    printf("Romeo's Hand:\n");
    printHand(romeoHand);
    printf("\nJuliet's Hand:\n");
    printHand(julietHand);

    printf("\nMay the best lover win!\n");

    return 0;
}