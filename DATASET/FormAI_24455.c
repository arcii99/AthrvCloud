//FormAI DATASET v1.0 Category: Poker Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct {
    char *name;
    int *hand;
} Player;

void shuffle_deck(int *deck) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        int tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
    }
}

void deal_cards(int *deck, Player *p1, Player *p2) {
    p1->hand = malloc(sizeof(int) * HAND_SIZE);
    p2->hand = malloc(sizeof(int) * HAND_SIZE);
    for (int i = 0; i < HAND_SIZE; i++) {
        p1->hand[i] = deck[i*2];
        p2->hand[i] = deck[i*2+1];
    }
}

void print_card(int card) {
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    printf("%s of %s", ranks[card % 13], suits[card / 13]);
}

void print_hand(int *hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        print_card(hand[i]);
        printf("\n");
    }
}

void play_game(Player *p1, Player *p2) {
    printf("%s's hand:\n", p1->name);
    print_hand(p1->hand);
    printf("\n%s's hand:\n", p2->name);
    print_hand(p2->hand);
    // TODO: Implement game logic!
}

int main() {
    int deck[DECK_SIZE];
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i] = i;
    }
    shuffle_deck(deck);

    Player p1 = {"Player 1", NULL};
    Player p2 = {"Player 2", NULL};
    deal_cards(deck, &p1, &p2);

    play_game(&p1, &p2);

    free(p1.hand);
    free(p2.hand);
    return 0;
}