//FormAI DATASET v1.0 Category: Poker Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_RANKS 13

typedef enum { CLUBS, DIAMONDS, HEARTS, SPADES } suit;

typedef struct {
    suit s;
    int r;
} card;

void init_deck(card *deck)
{
    int i, j, k = 0;

    for (i = 0; i < NUM_RANKS; i++) {
        for (j = 0; j < NUM_SUITS; j++) {
            deck[k].s = j;
            deck[k].r = i;
            k++;
        }
    }
}

void shuffle_deck(card *deck)
{
    int i, j;
    card temp;

    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(card c)
{
    char rank, suit;

    switch (c.r) {
        case 0: rank = '2'; break;
        case 1: rank = '3'; break;
        case 2: rank = '4'; break;
        case 3: rank = '5'; break;
        case 4: rank = '6'; break;
        case 5: rank = '7'; break;
        case 6: rank = '8'; break;
        case 7: rank = '9'; break;
        case 8: rank = 'T'; break;
        case 9: rank = 'J'; break;
        case 10: rank = 'Q'; break;
        case 11: rank = 'K'; break;
        case 12: rank = 'A'; break;
    }

    switch (c.s) {
        case CLUBS: suit = 'C'; break;
        case DIAMONDS: suit = 'D'; break;
        case HEARTS: suit = 'H'; break;
        case SPADES: suit = 'S'; break;
    }

    printf("%c%c ", rank, suit);
}

void print_hand(card *hand, int num_cards)
{
    int i;

    for (i = 0; i < num_cards; i++) {
        print_card(hand[i]);
    }
}

int count_points(card *hand, int num_cards)
{
    int i, points = 0, aces = 0;

    for (i = 0; i < num_cards; i++) {
        if (hand[i].r == 8 || hand[i].r == 9 || hand[i].r == 10 ||
            hand[i].r == 11 || hand[i].r == 12) {
            points += 10;
        } else if (hand[i].r == 0) {
            points += 2;
            aces++;
        } else {
            points += hand[i].r + 2;
        }
    }

    while (points > 21 && aces > 0) {
        aces--;
        points -= 10;
    }

    return points;
}

int main()
{
    card deck[NUM_CARDS];
    card player_hand[10];
    card dealer_hand[10];
    int i, player_points, dealer_points, player_num_cards, dealer_num_cards;

    srand(time(NULL));

    init_deck(deck);
    shuffle_deck(deck);

    player_num_cards = 2;
    dealer_num_cards = 2;

    player_hand[0] = deck[0];
    dealer_hand[0] = deck[1];
    player_hand[1] = deck[2];
    dealer_hand[1] = deck[3];

    printf("Your hand: ");
    print_hand(player_hand, player_num_cards);
    printf("\nDealer's hand: ");
    print_card(dealer_hand[0]);
    printf("X\n\n");

    player_points = count_points(player_hand, player_num_cards);

    if (player_points == 21) {
        printf("Blackjack! You win.\n");
        return 0;
    }

    while (1) {
        char hit;

        printf("Your score is %d. Do you want to hit? (y/n): ", player_points);
        scanf(" %c", &hit);

        if (hit == 'y') {
            player_hand[player_num_cards++] = deck[player_num_cards + dealer_num_cards - 1];
            printf("Your hand: ");
            print_hand(player_hand, player_num_cards);
            printf("\n");

            player_points = count_points(player_hand, player_num_cards);

            if (player_points > 21) {
                printf("Busted! Dealer wins.\n");
                return 0;
            } else if (player_points == 21) {
                printf("Blackjack! You win.\n");
                return 0;
            }
        } else {
            break;
        }
    }

    dealer_points = count_points(dealer_hand, dealer_num_cards);

    while (dealer_points < 17) {
        printf("Dealer hits.\n");
        dealer_hand[dealer_num_cards++] = deck[player_num_cards + dealer_num_cards - 1];

        dealer_points = count_points(dealer_hand, dealer_num_cards);
    }

    printf("\nYour hand: ");
    print_hand(player_hand, player_num_cards);
    printf("\nDealer's hand: ");
    print_hand(dealer_hand, dealer_num_cards);
    printf("\n");

    if (dealer_points > 21) {
        printf("Dealer busted! You win.\n");
    } else if (dealer_points >= player_points) {
        printf("Dealer wins.\n");
    } else {
        printf("You win!\n");
    }

    return 0;
}