//FormAI DATASET v1.0 Category: Poker Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DECK_SIZE 52
#define CARD_VALUES "234567891JQKA"
#define CARD_SUITS "cdhs"

typedef enum {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
} card_value_t;

typedef enum {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
} card_suit_t;

typedef struct {
    card_value_t value;
    card_suit_t suit;
} card_t;

typedef struct {
    card_t* deck;
    size_t n_cards;
} deck_t;

void shuffle_deck(deck_t *d);
void print_cards(const deck_t* d);
void print_card(const card_t* c);
void init_deck(deck_t* d);
void clean_deck(deck_t* d);
int draw_card(deck_t* d, card_t* c);
int compare_cards(const void* a, const void* b);
int calc_hand_value(const card_t hand[], size_t size);

int main(void)
{
    srand(time(NULL)); // Seed RNG

    deck_t deck = { .deck = NULL, .n_cards = 0 };
    init_deck(&deck);
    shuffle_deck(&deck);

    card_t hand[5];
    memset(hand, 0, sizeof(hand));
    for (size_t i = 0; i < 5; ++i) {
        draw_card(&deck, &hand[i]);
    }

    printf("Your hand:\n");
    print_cards(hand);
    printf("\n");

    int hand_value = calc_hand_value(hand, 5);
    printf("Your hand is worth %d points.\n", hand_value);

    clean_deck(&deck);

    return 0;
}

void shuffle_deck(deck_t *d)
{
    for (size_t i = 0; i < d->n_cards; ++i) {
        size_t swap_idx = rand() % d->n_cards;
        card_t temp = d->deck[i];
        d->deck[i] = d->deck[swap_idx];
        d->deck[swap_idx] = temp;
    }
}

void print_cards(const deck_t* d)
{
    for (size_t i = 0; i < d->n_cards; ++i) {
        const card_t c = d->deck[i];
        print_card(&c);
        printf(" ");
    }
}

void print_card(const card_t* c)
{
    const char* value_str = NULL;
    const char* suit_str = NULL;

    switch (c->value) {
    case ACE:
        value_str = "A";
        break;
    case JACK:
        value_str = "J";
        break;
    case QUEEN:
        value_str = "Q";
        break;
    case KING:
        value_str = "K";
        break;
    default:
        value_str = &CARD_VALUES[c->value - 2];
        break;
    }

    switch (c->suit) {
    case CLUBS:
        suit_str = "♣";
        break;
    case DIAMONDS:
        suit_str = "♦";
        break;
    case HEARTS:
        suit_str = "♥";
        break;
    case SPADES:
        suit_str = "♠";
        break;
    }

    printf("%s%s", value_str, suit_str);
}

void init_deck(deck_t* d)
{
    d->deck = malloc(DECK_SIZE * sizeof(card_t));
    if (d->deck == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    size_t idx = 0;
    for (int value = ACE; value <= KING; ++value) {
        for (int suit = CLUBS; suit <= SPADES; ++suit) {
            d->deck[idx++] = (card_t) { .value = (card_value_t)value, .suit = (card_suit_t)suit };
        }
    }

    d->n_cards = DECK_SIZE;
}

void clean_deck(deck_t* d)
{
    free(d->deck);
    d->deck = NULL;
    d->n_cards = 0;
}

int draw_card(deck_t* d, card_t* c)
{
    if (d == NULL || c == NULL || d->n_cards == 0) {
        return -1;
    }

    *c = d->deck[--d->n_cards];

    return 0;
}

int compare_cards(const void* a, const void* b)
{
    const card_t* card_a = (const card_t*)a;
    const card_t* card_b = (const card_t*)b;

    return card_a->value - card_b->value;
}

int calc_hand_value(const card_t hand[], size_t size)
{
    qsort((void*)hand, size, sizeof(card_t), compare_cards);

    // Determine if hand has any pairs
    card_value_t pair_value = 0;
    size_t pair_count = 0;
    for (size_t i = 1; i < size; ++i) {
        if (hand[i].value == hand[i - 1].value) {
            pair_value = hand[i].value;
            pair_count++;
        }
    }

    if (pair_count == 1) { // One pair
        return 10 + pair_value; // Pair is worth 10 points plus the value of the pair
    } else if (pair_count == 2) { // Two pairs
        return 20 + hand[3].value; // Two pairs is worth 20 points plus value of highest pair
    }

    // Otherwise, hand has no pairs
    return hand[4].value; // Value of hand is equal to the highest card value
}