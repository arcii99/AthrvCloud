//FormAI DATASET v1.0 Category: Poker Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

void read_cards(int hand[NUM_CARDS][2]);
void analyze_hand(int hand[NUM_CARDS][2], int *p_rank, int *p_flush, int *p_straight);
void print_result(int rank, int flush, int straight);

int main(void) {
    int hand[NUM_CARDS][2] = {0};
    int rank, flush, straight;

    read_cards(hand);
    analyze_hand(hand, &rank, &flush, &straight);
    print_result(rank, flush, straight);

    return 0;
}

void read_cards(int hand[NUM_CARDS][2]) {
    int cards_read = 0;
    char rank_ch, suit_ch;
    int rank, suit;
    int card_exists[NUM_RANKS][NUM_SUITS] = {0};

    while (cards_read < NUM_CARDS) {
        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch) {
            case '0':           exit(EXIT_SUCCESS);
            case '2':           rank = 0; break;
            case '3':           rank = 1; break;
            case '4':           rank = 2; break;
            case '5':           rank = 3; break;
            case '6':           rank = 4; break;
            case '7':           rank = 5; break;
            case '8':           rank = 6; break;
            case '9':           rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default:            rank = -1; break;
        }

        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default:            suit = -1; break;
        }

        while (getchar() != '\n');

        if (rank == -1 || suit == -1 || card_exists[rank][suit]) {
            printf("Error: invalid card or card already entered.\n");
        } else {
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            card_exists[rank][suit] = 1;
            cards_read++;
        }
    }
}

void analyze_hand(int hand[NUM_CARDS][2], int *p_rank, int *p_flush, int *p_straight) {
    int same_suit = 1, same_rank = 1, high_card, rank, suit;
    int rank_seen[NUM_RANKS] = {0};

    for (int i = 0; i < NUM_CARDS - 1; i++) {
        if (hand[i][1] != hand[i+1][1]) {
            same_suit = 0;
        }
        if (hand[i][0] != hand[i+1][0]) {
            same_rank = 0;
        }
        rank_seen[hand[i][0]] = 1;
    }
    rank_seen[hand[NUM_CARDS - 1][0]] = 1;

    if (same_suit) {
        *p_flush = 1;
    }

    if (same_rank) {
        *p_rank = 1;
    } else {
        for (rank = 0; rank < NUM_RANKS; rank++) {
            if (rank_seen[rank]) {
                high_card = rank;
                for (suit = 0; suit < NUM_SUITS; suit++) {
                    if (!rank_seen[rank] || !rank_seen[suit+1]) {
                        break;
                    }
                }
                if (suit == NUM_SUITS) {
                    *p_straight = 1;
                    break;
                }
            }
        }
        if (suit == NUM_SUITS) {
            *p_rank = 2;
        }
    }
}

void print_result(int rank, int flush, int straight) {
    if (rank == 1 && flush && straight) {
        printf("Royal flush\n");
    } else if (rank == 1 && flush && !straight) {
        printf("Straight flush\n");
    } else if (rank == 2 && flush && straight) {
        printf("Straight flush\n");
    } else if (rank == 2 && !flush && straight) {
        printf("Straight\n");
    } else if (rank == 3 && flush && !straight) {
        printf("Flush\n");
    } else if (rank == 4 && !flush && !straight) {
        printf("High card\n");
    } else {
        printf("Error: invalid hand.\n");
    }
}