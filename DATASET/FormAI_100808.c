//FormAI DATASET v1.0 Category: Poker Game ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to shuffle the deck
void shuffle(int *deck, int num_cards) {
    int i, j, tmp;
    for (i = 0; i < num_cards; i++) {
        j = rand() % num_cards;
        tmp = deck[i];
        deck[i] = deck[j];
        deck[j] = tmp;
    }
}

// function to print the card
void print_card(int card) {
    int value = card % 13;
    int suit = card / 13;

    printf("%c", value + '2');
    switch (suit) {
        case 0: printf("C ");
                break;
        case 1: printf("D ");
                break;
        case 2: printf("H ");
                break;
        case 3: printf("S ");
                break;
    }
}

// function to determine the winner hand
void determine_winner(int *player1_cards, int *player2_cards) {
    int i, j;
    int p1[5], p2[5];
    int p1_rank = 0, p2_rank = 0;

    // split the cards into ranks and suits
    for (i = 0; i < 5; i++) {
        p1[i] = player1_cards[i] % 13;
        p2[i] = player2_cards[i] % 13;
    }

    // sort the hands
    for (i = 0; i < 5; i++) {
        for (j = i+1; j < 5; j++) {
            if (p1[i] > p1[j]) {
                int temp = p1[i];
                p1[i] = p1[j];
                p1[j] = temp;
            }
            if (p2[i] > p2[j]) {
                int temp = p2[i];
                p2[i] = p2[j];
                p2[j] = temp;
            }
        }
    }

    // determine the rank of the hand
    for (i = 0; i < 4; i++) {
        if (p1[i] == p1[i+1]-1) {
            p1_rank++;
        }
        if (p2[i] == p2[i+1]-1) {
            p2_rank++;
        }
    }

    // determine the winner
    if (p1_rank > p2_rank) {
        printf("Player 1 wins!\n");
    } else if (p1_rank < p2_rank) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    int deck[52];
    int i, j, k = 0;
    int player1_cards[5], player2_cards[5];

    // initialize the deck
    for (i = 0; i < 52; i++) {
        deck[i] = i;
    }

    // shuffle the deck
    srand(time(NULL));
    shuffle(deck, 52);

    // deal the cards
    for (i = 0; i < 5; i++) {
        player1_cards[i] = deck[k++];
        player2_cards[i] = deck[k++];
    }

    // print the hands
    printf("Player 1's hand: ");
    for (i = 0; i < 5; i++) {
        print_card(player1_cards[i]);
    }
    printf("\n");
    printf("Player 2's hand: ");
    for (i = 0; i < 5; i++) {
        print_card(player2_cards[i]);
    }
    printf("\n");

    // determine the winner
    determine_winner(player1_cards, player2_cards);

    return 0;
}