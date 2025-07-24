//FormAI DATASET v1.0 Category: Poker Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_HAND 5
#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 52

enum Suit { HEARTS, SPADES, DIAMONDS, CLUBS };
enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

struct Card {
    enum Suit suit;
    enum Rank rank;
};

struct Deck {
    struct Card cards[NUM_CARDS];
    int top;
};

struct Hand {
    struct Card cards[MAX_HAND];
    int size;
};

void init_deck(struct Deck* deck);
void shuffle_deck(struct Deck* deck);
void add_card_to_hand(struct Hand* hand, struct Card* card);
void draw_cards(struct Deck* deck, struct Hand* hand, int num_cards);
void print_cards(struct Card* cards, int num_cards);
void print_hand(struct Hand* hand);
bool pair(struct Hand* hand);
bool two_pairs(struct Hand* hand);
bool three_of_a_kind(struct Hand* hand);
bool straight(struct Hand* hand);
bool flush(struct Hand* hand);
bool full_house(struct Hand* hand);
bool four_of_a_kind(struct Hand* hand);
bool straight_flush(struct Hand* hand);
bool royal_flush(struct Hand* hand);
int compare_cards(const void* card1, const void* card2);
int compare_hands(const void* hand1, const void* hand2);

int main() {
    srand((unsigned)time(NULL));
    struct Deck deck;
    struct Hand hand1, hand2;

    init_deck(&deck);
    shuffle_deck(&deck);

    draw_cards(&deck, &hand1, MAX_HAND);
    draw_cards(&deck, &hand2, MAX_HAND);

    printf("**** Hand 1 ****\n");
    print_hand(&hand1);
    if (royal_flush(&hand1)) {
        printf("Royal Flush!\n");
    } else if (straight_flush(&hand1)) {
        printf("Straight Flush!\n");
    } else if (four_of_a_kind(&hand1)) {
        printf("Four of a Kind!\n");
    } else if (full_house(&hand1)) {
        printf("Full House!\n");
    } else if (flush(&hand1)) {
        printf("Flush!\n");
    } else if (straight(&hand1)) {
        printf("Straight!\n");
    } else if (three_of_a_kind(&hand1)) {
        printf("Three of a Kind!\n");
    } else if (two_pairs(&hand1)) {
        printf("Two Pairs!\n");
    } else if (pair(&hand1)) {
        printf("Pair!\n");
    } else {
        printf("High Card!\n");
    }

    printf("\n**** Hand 2 ****\n");
    print_hand(&hand2);
    if (royal_flush(&hand2)) {
        printf("Royal Flush!\n");
    } else if (straight_flush(&hand2)) {
        printf("Straight Flush!\n");
    } else if (four_of_a_kind(&hand2)) {
        printf("Four of a Kind!\n");
    } else if (full_house(&hand2)) {
        printf("Full House!\n");
    } else if (flush(&hand2)) {
        printf("Flush!\n");
    } else if (straight(&hand2)) {
        printf("Straight!\n");
    } else if (three_of_a_kind(&hand2)) {
        printf("Three of a Kind!\n");
    } else if (two_pairs(&hand2)) {
        printf("Two Pairs!\n");
    } else if (pair(&hand2)) {
        printf("Pair!\n");
    } else {
        printf("High Card!\n");
    }

    return 0;
}

void init_deck(struct Deck* deck) {
    int i, j;
    deck->top = 0;
    for (i = 0; i < NUM_SUITS; i++) {
        for (j = 0; j < NUM_RANKS; j++) {
            deck->cards[deck->top].suit = i;
            deck->cards[deck->top].rank = j;
            deck->top++;
        }
    }
}

void shuffle_deck(struct Deck* deck) {
    int i, j;
    struct Card temp;
    for (i = deck->top - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void add_card_to_hand(struct Hand* hand, struct Card* card) {
    hand->cards[hand->size++] = *card;
}

void draw_cards(struct Deck* deck, struct Hand* hand, int num_cards) {
    int i;
    for (i = 0; i < num_cards; i++) {
        add_card_to_hand(hand, &deck->cards[deck->top - 1]);
        deck->top--;
    }
    qsort(hand->cards, hand->size, sizeof(struct Card), compare_cards);
}

void print_cards(struct Card* cards, int num_cards) {
    int i, j;
    char* suits[] = { "Hearts", "Spades", "Diamonds", "Clubs" };
    char* ranks[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    for (i = 0; i < num_cards; i++) {
        printf("%s of %s\n", ranks[cards[i].rank], suits[cards[i].suit]);
    }
}

void print_hand(struct Hand* hand) {
    print_cards(hand->cards, hand->size);
}

bool pair(struct Hand* hand) {
    int i;
    for (i = 0; i < hand->size - 1; i++) {
        if (hand->cards[i].rank == hand->cards[i + 1].rank) {
            return true;
        }
    }
    return false;
}

bool two_pairs(struct Hand* hand) {
    int i, count = 0;
    for (i = 0; i < hand->size - 1; i++) {
        if (hand->cards[i].rank == hand->cards[i + 1].rank) {
            count++;
            i++;
        }
    }
    if (count == 2) {
        return true;
    }
    return false;
}

bool three_of_a_kind(struct Hand* hand) {
    int i;
    for (i = 0; i < hand->size - 2; i++) {
        if (hand->cards[i].rank == hand->cards[i + 1].rank && hand->cards[i + 1].rank == hand->cards[i + 2].rank) {
            return true;
        }
    }
    return false;
}

bool straight(struct Hand* hand) {
    int i;
    for (i = 0; i < hand->size - 1; i++) {
        if (hand->cards[i].rank != hand->cards[i + 1].rank - 1) {
            return false;
        }
    }
    return true;
}

bool flush(struct Hand* hand) {
    int i;
    for (i = 0; i < hand->size - 1; i++) {
        if (hand->cards[i].suit != hand->cards[i + 1].suit) {
            return false;
        }
    }
    return true;
}

bool full_house(struct Hand* hand) {
    int i;
    bool three_of_a_kind_exists = false;
    bool pair_exists = false;
    for (i = 0; i < hand->size - 2; i++) {
        if (hand->cards[i].rank == hand->cards[i + 1].rank && hand->cards[i + 1].rank == hand->cards[i + 2].rank) {
            three_of_a_kind_exists = true;
            i += 2;
        }
    }
    for (i = 0; i < hand->size - 1; i++) {
        if (hand->cards[i].rank == hand->cards[i + 1].rank) {
            pair_exists = true;
            i++;
        }
    }
    if (three_of_a_kind_exists && pair_exists) {
        return true;
    }
    return false;
}

bool four_of_a_kind(struct Hand* hand) {
    int i;
    for (i = 0; i < hand->size - 3; i++) {
        if (hand->cards[i].rank == hand->cards[i + 1].rank && hand->cards[i + 1].rank == hand->cards[i + 2].rank && hand->cards[i + 2].rank == hand->cards[i + 3].rank) {
            return true;
        }
    }
    return false;
}

bool straight_flush(struct Hand* hand) {
    return straight(hand) && flush(hand);
}

bool royal_flush(struct Hand* hand) {
    return straight_flush(hand) && hand->cards[0].rank == ACE && hand->cards[1].rank == TEN;
}

int compare_cards(const void* card1, const void* card2) {
    return ((struct Card*)card1)->rank - ((struct Card*)card2)->rank;
}

int compare_hands(const void* hand1, const void* hand2) {
    struct Hand* h1 = (struct Hand*)hand1;
    struct Hand* h2 = (struct Hand*)hand2;
    if (royal_flush(h1)) {
        return 1;
    } else if (straight_flush(h1)) {
        if (royal_flush(h2)) {
            return -1;
        } else if (straight_flush(h2)) {
            return h1->cards[4].rank - h2->cards[4].rank;
        }
        return 1;
    } else if (four_of_a_kind(h1)) {
        if (royal_flush(h2) || straight_flush(h2)) {
            return -1;
        } else if (four_of_a_kind(h2)) {
            if (h1->cards[0].rank == h1->cards[1].rank && h1->cards[1].rank == h1->cards[2].rank) {
                if (h2->cards[0].rank == h2->cards[1].rank && h2->cards[1].rank == h2->cards[2].rank) {
                    return h1->cards[0].rank - h2->cards[0].rank;
                }
                return 1;
            } else {
                if (h2->cards[0].rank == h2->cards[1].rank && h2->cards[1].rank == h2->cards[2].rank) {
                    return -1;
                }
                return h1->cards[4].rank - h2->cards[4].rank;
            }
        }
        return 1;
    } else if (full_house(h1)) {
        if (royal_flush(h2) || straight_flush(h2) || four_of_a_kind(h2)) {
            return -1;
        } else if (full_house(h2)) {
            if (h1->cards[0].rank == h1->cards[1].rank && h1->cards[1].rank == h1->cards[2].rank) {
                if (h2->cards[0].rank == h2->cards[1].rank && h2->cards[1].rank == h2->cards[2].rank) {
                    return h1->cards[0].rank - h2->cards[0].rank;
                }
                return 1;
            } else {
                if (h2->cards[0].rank == h2->cards[1].rank && h2->cards[1].rank == h2->cards[2].rank) {
                    return -1;
                }
                return h1->cards[4].rank - h2->cards[4].rank;
            }
        }
        return 1;
    } else if (flush(h1)) {
        if (royal_flush(h2) || straight_flush(h2) || four_of_a_kind(h2) || full_house(h2)) {
            return -1;
        } else if (flush(h2)) {
            return h1->cards[4].rank - h2->cards[4].rank;
        }
        return 1;
    } else if (straight(h1)) {
        if (royal_flush(h2) || straight_flush(h2) || four_of_a_kind(h2) || full_house(h2) || flush(h2)) {
            return -1;
        } else if (straight(h2)) {
            return h1->cards[4].rank - h2->cards[4].rank;
        }
        return 1;
    } else if (three_of_a_kind(h1)) {
        if (royal_flush(h2) || straight_flush(h2) || four_of_a_kind(h2) || full_house(h2) || flush(h2) || straight(h2)) {
            return -1;
        } else if (three_of_a_kind(h2)) {
            if (h1->cards[2].rank == h2->cards[2].rank) {
                return h1->cards[4].rank - h2->cards[4].rank;
            }
            return h1->cards[2].rank - h2->cards[2].rank;
        }
        return 1;
    } else if (two_pairs(h1)) {
        if (royal_flush(h2) || straight_flush(h2) || four_of_a_kind(h2) || full_house(h2) || flush(h2) || straight(h2) || three_of_a_kind(h2)) {
            return -1;
        } else if (two_pairs(h2)) {
            if (h1->cards[3].rank == h2->cards[3].rank) {
                if (h1->cards[1].rank == h2->cards[1].rank) {
                    return h1->cards[4].rank - h2->cards[4].rank;
                }
                return h1->cards[1].rank - h2->cards[1].rank;
            }
            return h1->cards[3].rank - h2->cards[3].rank;
        }
        return 1;
    } else if (pair(h1)) {
        if (royal_flush(h2) || straight_flush(h2) || four_of_a_kind(h2) || full_house(h2) || flush(h2) || straight(h2) || three_of_a_kind(h2) || two_pairs(h2)) {
            return -1;
        } else if (pair(h2)) {
            if (h1->cards[1].rank == h2->cards[1].rank) {
                if (h1->cards[3].rank == h2->cards[3].rank) {
                    if (h1->cards[4].rank == h2->cards[4].rank) {
                        return h1->cards[2].rank - h2->cards[2].rank;
                    }
                    return h1->cards[4].rank - h2->cards[4].rank;
                }
                return h1->cards[3].rank - h2->cards[3].rank;
            }
            return h1->cards[1].rank - h2->cards[1].rank;
        }
        return 1;
    } else {
        if (royal_flush(h2) || straight_flush(h2) || four_of_a_kind(h2) || full_house(h2) || flush(h2) || straight(h2) || three_of_a_kind(h2) || two_pairs(h2) || pair(h2)) {
            return -1;
        } else {
            return h1->cards[4].rank - h2->cards[4].rank;
        }
    }
}