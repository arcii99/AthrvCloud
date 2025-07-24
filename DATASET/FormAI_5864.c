//FormAI DATASET v1.0 Category: Poker Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* define card ranks, suits, and values */
const char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const int values[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

/* function prototypes */
void shuffle(int deck[52]);
void deal(int deck[52], int *player_hand, int *dealer_hand);
void print_hand(char *player, int hand[], int num_cards);
int get_hand_value(int hand[], int num_cards);
void hit(int deck[], int *hand, int *num_cards);
void play_game(int deck[52]);

/* main function */
int main()
{
    /* seed random number generator */
    srand(time(NULL));

    /* create deck of cards */
    int deck[52];
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }

    /* play game */
    play_game(deck);

    return 0;
}

/* shuffle deck of cards */
void shuffle(int deck[52]) {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

/* deal cards */
void deal(int deck[52], int *player_hand, int *dealer_hand) {
    shuffle(deck);

    /* give player first card */
    player_hand[0] = deck[0];

    /* give dealer first card */
    dealer_hand[0] = deck[1];

    /* give player second card */
    player_hand[1] = deck[2];

    /* give dealer second card */
    dealer_hand[1] = deck[3];
}

/* print player or dealer hand */
void print_hand(char *player, int hand[], int num_cards) {
    printf("%s's hand: ", player);
    for (int i = 0; i < num_cards; i++) {
        int rank = hand[i] % 13;
        int suit = hand[i] / 13;
        printf("%s of %s, ", ranks[rank], suits[suit]);
    }
    printf("\n");
}

/* calculate value of hand */
int get_hand_value(int hand[], int num_cards) {
    int value = 0;
    int num_aces = 0;

    for (int i = 0; i < num_cards; i++) {
        int rank = hand[i] % 13;
        value += values[rank];

        if (rank == 0) {
            num_aces++;
        }
    }

    /* adjust for aces */
    while (value > 21 && num_aces > 0) {
        value -= 10;
        num_aces--;
    }

    return value;
}

/* player takes a hit */
void hit(int deck[], int *hand, int *num_cards) {
    hand[*num_cards] = deck[*num_cards + 4];
    (*num_cards)++;
}

/* play the game */
void play_game(int deck[52]) {
    int player_hand[10] = {0};
    int dealer_hand[10] = {0};
    int player_num_cards = 2;
    int dealer_num_cards = 2;
    int player_value, dealer_value;

    /* deal cards */
    deal(deck, player_hand, dealer_hand);

    /* print initial hands */
    printf("Dealer shows: %s of %s\n", ranks[dealer_hand[0] % 13], suits[dealer_hand[0] / 13]);
    print_hand("Player", player_hand, player_num_cards);

    /* player's turn */
    while (1) {
        printf("Do you want to hit or stay? (h/s) ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'h') {
            hit(deck, player_hand, &player_num_cards);
            print_hand("Player", player_hand, player_num_cards);

            player_value = get_hand_value(player_hand, player_num_cards);

            if (player_value > 21) {
                printf("Player busts! Dealer wins!\n");
                return;
            }
        } else if (choice == 's') {
            player_value = get_hand_value(player_hand, player_num_cards);
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    /* dealer's turn */
    printf("Dealer's turn: \n");
    print_hand("Dealer", dealer_hand, dealer_num_cards);

    dealer_value = get_hand_value(dealer_hand, dealer_num_cards);

    while (dealer_value < 17) {
        printf("Dealer hits\n");
        hit(deck, dealer_hand, &dealer_num_cards);
        dealer_value = get_hand_value(dealer_hand, dealer_num_cards);
        print_hand("Dealer", dealer_hand, dealer_num_cards);
    }

    /* determine winner */
    printf("Player's hand value: %d\nDealer's hand value: %d\n", player_value, dealer_value);

    if (player_value > dealer_value || dealer_value > 21) {
        printf("Player wins!\n");
    } else if (dealer_value > player_value) {
        printf("Dealer wins!\n");
    } else {
        printf("Tie!\n");
    }
}