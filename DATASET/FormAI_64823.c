//FormAI DATASET v1.0 Category: Poker Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum suits {hearts, diamonds, clubs, spades};
enum faces {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

struct card {
    enum suits suit;
    enum faces face;
};

struct hand {
    int num_cards;
    struct card *cards[5];
};

void print_card(struct card c) {
    char *suit_str;
    char *face_str;
    switch (c.suit) {
        case hearts:
            suit_str = "Hearts";
            break;
        case diamonds:
            suit_str = "Diamonds";
            break;
        case clubs:
            suit_str = "Clubs";
            break;
        case spades:
            suit_str = "Spades";
            break;
    }
    switch (c.face) {
        case two:
            face_str = "Two";
            break;
        case three:
            face_str = "Three";
            break;
        case four:
            face_str = "Four";
            break;
        case five:
            face_str = "Five";
            break;
        case six:
            face_str = "Six";
            break;
        case seven:
            face_str = "Seven";
            break;
        case eight:
            face_str = "Eight";
            break;
        case nine:
            face_str = "Nine";
            break;
        case ten:
            face_str = "Ten";
            break;
        case jack:
            face_str = "Jack";
            break;
        case queen:
            face_str = "Queen";
            break;
        case king:
            face_str = "King";
            break;
        case ace:
            face_str = "Ace";
            break;
    }
    printf("%s of %s\n", face_str, suit_str);
}

void print_hand(struct hand h) {
    for (int i = 0; i < h.num_cards; i++) {
        print_card(*h.cards[i]);
    }
}

struct deck {
    int num_cards;
    struct card cards[52];
};

void shuffle_deck(struct deck *d) {
    srand(time(NULL));
    for (int i = 0; i < d->num_cards; i++) {
        int j = rand() % d->num_cards;
        struct card temp = d->cards[i];
        d->cards[i] = d->cards[j];
        d->cards[j] = temp;
    }
}

struct deck create_deck() {
    struct deck d;
    d.num_cards = 52;
    int count = 0;
    for (int s = 0; s < 4; s++) {
        for (int f = 0; f < 13; f++) {
            d.cards[count].suit = s;
            d.cards[count].face = f;
            count++;
        }
    }
    return d;
}

void deal(struct deck *d, struct hand *h) {
    for (int i = 0; i < h->num_cards; i++) {
        h->cards[i] = &(d->cards[i]);
    }
    d->num_cards -= h->num_cards;
    for (int i = 0; i < h->num_cards; i++) {
        for (int j = i+1; j < h->num_cards; j++) {
            if (h->cards[i]->face > h->cards[j]->face) {
                struct card *temp = h->cards[i];
                h->cards[i] = h->cards[j];
                h->cards[j] = temp;
            }
        }
    }
}

int main() {
    struct deck d = create_deck();
    printf("Before shuffling:\n");
    print_card(d.cards[0]);
    printf("\n");
    shuffle_deck(&d);
    printf("After shuffling:\n");
    print_card(d.cards[0]);
    printf("\n");
    struct hand h1 = {.num_cards = 5};
    deal(&d, &h1);
    printf("Player 1's hand:\n");
    print_hand(h1);
    printf("\n");
    struct hand h2 = {.num_cards = 5};
    deal(&d, &h2);
    printf("Player 2's hand:\n");
    print_hand(h2);
    printf("\n");
    return 0;
}