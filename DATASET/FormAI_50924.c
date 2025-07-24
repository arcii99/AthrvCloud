//FormAI DATASET v1.0 Category: Poker Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CARD_SUITS 4
#define CARD_RANKS 13
#define MAX_CARDS 52
#define PLAYER_HAND_SIZE 5
#define MAX_PLAYERS 8

typedef enum {
    SUIT_CLUBS,
    SUIT_DIAMONDS,
    SUIT_HEARTS,
    SUIT_SPADES
} Suit;

typedef enum {
    RANK_TWO,
    RANK_THREE,
    RANK_FOUR,
    RANK_FIVE,
    RANK_SIX,
    RANK_SEVEN,
    RANK_EIGHT,
    RANK_NINE,
    RANK_TEN,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE
} Rank;

typedef struct {
    Suit suit;
    Rank rank;
} Card;

typedef struct {
    Card cards[PLAYER_HAND_SIZE];
} Hand;

typedef struct {
    char name[100];
    int money;
    Hand hand;
} Player;

void print_card(Card card) {
    switch (card.rank) {
        case RANK_TWO:
            printf("2");
            break;
        case RANK_THREE:
            printf("3");
            break;
        case RANK_FOUR:
            printf("4");
            break;
        case RANK_FIVE:
            printf("5");
            break;
        case RANK_SIX:
            printf("6");
            break;
        case RANK_SEVEN:
            printf("7");
            break;
        case RANK_EIGHT:
            printf("8");
            break;
        case RANK_NINE:
            printf("9");
            break;
        case RANK_TEN:
            printf("10");
            break;
        case RANK_JACK:
            printf("J");
            break;
        case RANK_QUEEN:
            printf("Q");
            break;
        case RANK_KING:
            printf("K");
            break;
        case RANK_ACE:
            printf("A");
            break;
    }

    switch (card.suit) {
        case SUIT_CLUBS:
            printf("C");
            break;
        case SUIT_DIAMONDS:
            printf("D");
            break;
        case SUIT_HEARTS:
            printf("H");
            break;
        case SUIT_SPADES:
            printf("S");
            break;
    }
}

void print_hand(Hand hand) {
    for (int i = 0; i < PLAYER_HAND_SIZE; i++) {
        print_card(hand.cards[i]);
        printf(" ");
    }
}

void shuffle_deck(Card deck[]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards(Card deck[], Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < PLAYER_HAND_SIZE; j++) {
            players[i].hand.cards[j] = deck[i+num_players*j];
        }
    }
}

void print_player_hands(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("%s: ", players[i].name);
        print_hand(players[i].hand);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    Card deck[MAX_CARDS];

    int n = 0;
    for (int s = 0; s < CARD_SUITS; s++) {
        for (int r = 0; r < CARD_RANKS; r++) {
            deck[n].suit = s;
            deck[n].rank = r;
            n++;
        }
    }

    shuffle_deck(deck);

    char name[100];
    int money;

    printf("Enter number of players (1-8): ");
    int num_players;
    scanf("%d", &num_players);

    Player players[num_players];

    for (int i = 0; i < num_players; i++) {
        printf("Enter name for Player %d: ", i+1);
        scanf("%s", name);
        strcpy(players[i].name, name);

        printf("Enter starting money for Player %d: ", i+1);
        scanf("%d", &money);
        players[i].money = money;

        printf("\n");
    }

    deal_cards(deck, players, num_players);

    print_player_hands(players, num_players);

    return 0;
}