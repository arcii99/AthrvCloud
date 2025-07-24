//FormAI DATASET v1.0 Category: Poker Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct Card {
    char face[2];
    char suit[10];
    int value;
} Card;

int get_card_value(char face[2]) {
    if (face[0] == 'J') {
        return 11;
    } else if (face[0] == 'Q') {
        return 12;
    } else if (face[0] == 'K') {
        return 13;
    } else if (face[0] == 'A') {
        return 14;
    } else {
        return atoi(face);
    }
}

void swap_cards(Card *card1, Card *card2) {
    Card temp = *card1;
    *card1 = *card2;
    *card2 = temp;
}

void shuffle_deck(Card deck[DECK_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int rand_index = rand() % DECK_SIZE;
        swap_cards(&deck[i], &deck[rand_index]);
    }
}

Card* deal_cards(Card deck[DECK_SIZE], int num_cards) {
    Card *hand = malloc(num_cards * sizeof(Card));
    for (int i = 0; i < num_cards; i++) {
        hand[i] = deck[i];
    }
    return hand;
}

void print_cards(Card *cards, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        printf("%s of %s\n", cards[i].face, cards[i].suit);
    }
}

void print_hand_ranking(int rank) {
    switch(rank) {
        case 1:
            printf("High Card\n");
            break;
        case 2:
            printf("Pair\n");
            break;
        case 3:
            printf("Two Pair\n");
            break;
        case 4:
            printf("Three of a Kind\n");
            break;
        case 5:
            printf("Straight\n");
            break;
        case 6:
            printf("Flush\n");
            break;
        case 7:
            printf("Full House\n");
            break;
        case 8:
            printf("Four of a Kind\n");
            break;
        case 9:
            printf("Straight Flush\n");
            break;
        case 10:
            printf("Royal Flush\n");
            break;
        default:
            printf("Error: Invalid Rank\n");
            break;
    }
}

int get_hand_ranking(Card *hand, int num_cards) {
    int rank = 0;
    int pair_count = 0;
    int three_count = 0;
    int four_count = 0;
    int flush_count = 0;
    int straight_count = 0;
    int ace_count = 0;

    int values[num_cards];
    for (int i = 0; i < num_cards; i++) {
        values[i] = get_card_value(hand[i].face);
        if (hand[i].face[0] == 'A') {
            ace_count++;
        }
    }
    int flush_values[num_cards];
    for (int i = 0; i < num_cards; i++) {
        flush_values[i] = hand[i].suit[0];
    }

    for (int i = 0; i < num_cards - 1; i++) {
        for (int j = i + 1; j < num_cards; j++) {
            if (values[i] > values[j]) {
                swap_cards(&hand[i], &hand[j]);
                swap_cards(&values[i], &values[j]);
            }
        }
    }

    if (values[0] == values[1] - 1
        && values[1] == values[2] - 1
        && values[2] == values[3] - 1
        && values[3] == values[4] - 1) {
        straight_count++;
    } else if (ace_count == 1
               && values[0] == 2
               && values[1] == 3
               && values[2] == 4
               && values[3] == 5
               && values[4] == 14) {
        straight_count++;
    }

    for (int i = 0; i < num_cards - 1; i++) {
        if (flush_values[i] == flush_values[i+1]) {
            flush_count++;
        }
    }

    for (int i = 0; i < num_cards - 3; i++) {
        if (values[i] == values[i+1]
            && values[i+1] == values[i+2]
            && values[i+2] == values[i+3]) {
            four_count++;
        }
    }

    for (int i = 0; i < num_cards - 2; i++) {
        if (values[i] == values[i+1]
            && values[i+1] == values[i+2]) {
            three_count++;
        }
    }

    for (int i = 0; i < num_cards - 1; i++) {
        if (values[i] == values[i+1]) {
            pair_count++;
        }
        if (values[i] == values[i+1] && i+3 < num_cards && values[i+2] == values[i+3]) {
            three_count++;
        }
        if (values[i] == values[i+1] && i+4 < num_cards && values[i+2] == values[i+3] && values[i+3] == values[i+4]) {
            four_count++;
        }
    }

    if (flush_count == 4 && straight_count == 1
        && values[0] == 10 && values[1] == 11
        && values[2] == 12 && values[3] == 13
        && values[4] == 14) {
        return 10;  // Royal Flush
    } else if (flush_count == 4 && straight_count == 1) {
        return 9;   // Straight Flush
    } else if (four_count == 1) {
        return 8;   // Four of a Kind
    } else if (three_count == 1 && pair_count == 1) {
        return 7;   // Full House
    } else if (flush_count == 4) {
        return 6;   // Flush
    } else if (straight_count == 1) {
        return 5;   // Straight
    } else if (three_count == 1) {
        return 4;   // Three of a Kind
    } else if (pair_count == 2) {
        return 3;   // Two Pair
    } else if (pair_count == 1) {
        return 2;   // Pair
    } else {
        return 1;   // High Card
    }
}

int main() {
    Card deck[DECK_SIZE] = {
        {"A", "Hearts", 14}, {"2", "Hearts", 2},
        {"3", "Hearts", 3}, {"4", "Hearts", 4},
        {"5", "Hearts", 5}, {"6", "Hearts", 6},
        {"7", "Hearts", 7}, {"8", "Hearts", 8},
        {"9", "Hearts", 9}, {"10", "Hearts", 10},
        {"J", "Hearts", 11}, {"Q", "Hearts", 12},
        {"K", "Hearts", 13}, {"A", "Diamonds", 14},
        {"2", "Diamonds", 2}, {"3", "Diamonds", 3},
        {"4", "Diamonds", 4}, {"5", "Diamonds", 5},
        {"6", "Diamonds", 6}, {"7", "Diamonds", 7},
        {"8", "Diamonds", 8}, {"9", "Diamonds", 9},
        {"10", "Diamonds", 10}, {"J", "Diamonds", 11},
        {"Q", "Diamonds", 12}, {"K", "Diamonds", 13},
        {"A", "Clubs", 14}, {"2", "Clubs", 2},
        {"3", "Clubs", 3}, {"4", "Clubs", 4},
        {"5", "Clubs", 5}, {"6", "Clubs", 6},
        {"7", "Clubs", 7}, {"8", "Clubs", 8},
        {"9", "Clubs", 9}, {"10", "Clubs", 10},
        {"J", "Clubs", 11}, {"Q", "Clubs", 12},
        {"K", "Clubs", 13}, {"A", "Spades", 14},
        {"2", "Spades", 2}, {"3", "Spades", 3},
        {"4", "Spades", 4}, {"5", "Spades", 5},
        {"6", "Spades", 6}, {"7", "Spades", 7},
        {"8", "Spades", 8}, {"9", "Spades", 9},
        {"10", "Spades", 10}, {"J", "Spades", 11},
        {"Q", "Spades", 12}, {"K", "Spades", 13}
    };

    shuffle_deck(deck);

    // Deal cards to player and computer
    Card *player_hand = deal_cards(deck, HAND_SIZE);
    Card *computer_hand = deal_cards(deck + HAND_SIZE, HAND_SIZE);

    printf("Your cards:\n");
    print_cards(player_hand, HAND_SIZE);
    printf("\n");

    // Get rank of player's hand
    int player_rank = get_hand_ranking(player_hand, HAND_SIZE);
    printf("Your hand is a ");
    print_hand_ranking(player_rank);

    // Get rank of computer's hand
    int computer_rank = get_hand_ranking(computer_hand, HAND_SIZE);

    printf("\nComputer's cards:\n");
    print_cards(computer_hand, HAND_SIZE);
    printf("\n");

    printf("Computer's hand is a ");
    print_hand_ranking(computer_rank);

    // Determine winner
    if (player_rank > computer_rank) {
        printf("\nCongratulations! You win!\n");
    } else if (player_rank < computer_rank) {
        printf("\nSorry, you lose. Better luck next time.\n");
    } else {
        printf("\nIt's a tie!\n");
    }

    return 0;
}