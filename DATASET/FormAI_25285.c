//FormAI DATASET v1.0 Category: Poker Game ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define HAND 5
#define DECK_SIZE 52

const char *suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *ranks[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

typedef struct {
    int rank;
    int suit;
} Card;

typedef struct {
    Card cards[HAND];
    int rank_count[13];
    int suit_count[4];
    int is_flush;
    int is_straight;
} Hand;

typedef struct {
    Card cards[DECK_SIZE];
    int top_card;
} Deck;

char *get_card_str(Card card) {
    char *str = (char *) malloc(sizeof(char) * 16);
    sprintf(str, "%s of %s", ranks[card.rank], suits[card.suit]);
    return str;
}

void shuffle_deck(Deck *deck) {
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        int j = rand() % DECK_SIZE;
        int k = rand() % DECK_SIZE;
        Card temp = deck->cards[j];
        deck->cards[j] = deck->cards[k];
        deck->cards[k] = temp;
    }
    deck->top_card = 0;
}

Card deal_card(Deck *deck) {
    Card card = deck->cards[deck->top_card];
    deck->top_card++;
    return card;
}

void print_hand(Hand hand) {
    printf("Your Hand:\n");
    for (int i = 0; i < HAND; i++) {
        printf("  %d. %s\n", i + 1, get_card_str(hand.cards[i]));
    }
}

void check_flush(Hand *hand) {
    for (int i = 0; i < 4; i++) {
        if (hand->suit_count[i] == HAND) {
            hand->is_flush = 1;
            break;
        }
    }
}

void check_straight(Hand *hand) {
    int count = 0;
    for (int i = 0; i < 13; i++) {
        if (hand->rank_count[i] == 1) {
            count++;
            if (count == 5) {
                hand->is_straight = 1;
                break;
            }
        } else {
            count = 0;
        }
    }
}

void check_hand(Hand *hand) {
    memset(hand->rank_count, 0, sizeof(hand->rank_count));
    memset(hand->suit_count, 0, sizeof(hand->suit_count));
    for (int i = 0; i < HAND; i++) {
        hand->rank_count[hand->cards[i].rank]++;
        hand->suit_count[hand->cards[i].suit]++;
    }
    check_flush(hand);
    check_straight(hand);
}

void print_result(Hand hand) {
    if (hand.is_flush && hand.is_straight && hand.cards[0].rank == 0) {
        printf("Royal Flush!\n");
    } else if (hand.is_flush && hand.is_straight) {
        printf("Straight Flush!\n");
    } else if (hand.rank_count[0] == 4) {
        printf("Four of a Kind!\n");
    } else if (hand.rank_count[0] == 3 && hand.rank_count[1] == 2) {
        printf("Full House!\n");
    } else if (hand.is_flush) {
        printf("Flush!\n");
    } else if (hand.is_straight) {
        printf("Straight!\n");
    } else if (hand.rank_count[0] == 3) {
        printf("Three of a Kind!\n");
    } else if (hand.rank_count[0] == 2 && hand.rank_count[1] == 2) {
        printf("Two Pair!\n");
    } else if (hand.rank_count[0] == 2) {
        printf("Pair!\n");
    } else {
        printf("High Card!\n");
    }
}

void play_game() {
    Deck deck;
    Hand hand;
    memset(hand.cards, 0, sizeof(hand.cards));
    printf("Dealing cards...\n");
    for (int i = 0; i < HAND; i++) {
        hand.cards[i] = deal_card(&deck);
    }
    print_hand(hand);
    check_hand(&hand);
    print_result(hand);
}

int main() {
    printf("Welcome to C Poker!\n");
    printf("Shuffling deck...\n");
    Deck deck;
    for (int i = 0; i < DECK_SIZE; i++) {
        deck.cards[i].rank = i % 13;
        deck.cards[i].suit = i / 13;
    }
    shuffle_deck(&deck);
    while (1) {
        printf("Press ENTER to play a hand or Q to quit.\n");
        char input[2];
        fgets(input, 2, stdin);
        if (input[0] == 'Q' || input[0] == 'q') {
            break;
        }
        play_game();
    }
    return 0;
}