//FormAI DATASET v1.0 Category: Poker Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for card values and suits
const char *card_values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const char *card_suits[] = {"Spades", "Hearts", "Clubs", "Diamonds"};

// Define a struct to represent a single card
typedef struct Card {
    int value;
    int suit;
    struct Card *next;
} Card;

// Define a struct to represent a deck of cards
typedef struct Deck {
    Card *head;
    int size;
} Deck;

// Define a function to create and initialize a new deck of cards
Deck *create_deck() {
    Deck *deck = (Deck *)malloc(sizeof(Deck));
    deck->head = NULL;
    deck->size = 0;
    for (int s = 0; s < 4; s++) {
        for (int v = 0; v < 13; v++) {
            Card *card = (Card *)malloc(sizeof(Card));
            card->value = v;
            card->suit = s;
            card->next = deck->head;
            deck->head = card;
            deck->size++;
        }
    }
    return deck;
}

// Define a function to shuffle a deck of cards
void shuffle_deck(Deck *deck) {
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        Card *a = deck->head;
        Card *b = deck->head;
        int count = rand() % deck->size;
        while (count--) {
            b = b->next;
        }
        while (a != NULL && b != NULL) {
            Card tmp = *a;
            *a = *b;
            *b = tmp;
            a = a->next;
            b = b->next;
        }
    }
}

// Define a function to print a card
void print_card(Card *card) {
    printf("%s of %s\n", card_values[card->value], card_suits[card->suit]);
}

// Define a function to print a deck of cards
void print_deck(Deck *deck) {
    printf("Deck:\n");
    Card *card = deck->head;
    while (card != NULL) {
        print_card(card);
        card = card->next;
    }
}

// Define a function to deal a card from the top of a deck
Card *deal_card(Deck *deck) {
    if (deck->size == 0) {
        return NULL;
    }
    Card *card = deck->head;
    deck->head = card->next;
    deck->size--;
    return card;
}

int main() {
    printf("Welcome to the Sherlock Holmes Poker Game!\n");
    printf("In this game, you will be playing against the famous detective himself.\n");
    printf("Let's get started!\n");

    // Create a new deck, shuffle it, and print it
    Deck *deck = create_deck();
    shuffle_deck(deck);
    printf("\n");
    print_deck(deck);

    // Deal two cards to the player and print them
    printf("\nDealing cards...\n");
    Card *player_card1 = deal_card(deck);
    Card *player_card2 = deal_card(deck);
    printf("\nYour cards:\n");
    print_card(player_card1);
    print_card(player_card2);

    // Deal two cards to Sherlock Holmes and print them
    printf("\nDealing cards to Sherlock Holmes...\n");
    Card *sherlock_card1 = deal_card(deck);
    Card *sherlock_card2 = deal_card(deck);
    printf("\nSherlock Holmes's cards:\n");
    print_card(sherlock_card1);
    print_card(sherlock_card2);

    // Discard the player's cards and deal two new ones
    printf("\nDiscarding your cards...\n");
    free(player_card1);
    free(player_card2);
    player_card1 = deal_card(deck);
    player_card2 = deal_card(deck);
    printf("\nYour new cards:\n");
    print_card(player_card1);
    print_card(player_card2);

    // Discard Sherlock Holmes's cards and deal two new ones
    printf("\nDiscarding Sherlock Holmes's cards...\n");
    free(sherlock_card1);
    free(sherlock_card2);
    sherlock_card1 = deal_card(deck);
    sherlock_card2 = deal_card(deck);
    printf("\nSherlock Holmes's new cards:\n");
    print_card(sherlock_card1);
    print_card(sherlock_card2);

    // Free memory and end the program
    free(player_card1);
    free(player_card2);
    free(sherlock_card1);
    free(sherlock_card2);
    Card *card = deck->head;
    while (card != NULL) {
        Card *next = card->next;
        free(card);
        card = next;
    }
    free(deck);
    return 0;
}