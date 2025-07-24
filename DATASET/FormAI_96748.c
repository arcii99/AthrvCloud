//FormAI DATASET v1.0 Category: Poker Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the deck
void init_deck(int deck[]) {
    int i, j, k = 0;

    for (i = 1; i <= 4; i++) {
        for (j = 1; j <= 13; j++) {
            deck[k++] = j;
        }
    }
}

// Function to shuffle the deck
void shuffle_deck(int deck[]) {
    int i, j, temp;

    srand(time(NULL)); // Seeds the random number generator

    for (i = 0; i < 52; i++) {
        j = rand() % 52; // Picks a random card from the deck
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print a card
void print_card(int card) {
    if (card >= 2 && card <= 10) {
        printf("%d", card);
    } else if (card == 1) {
        printf("A");
    } else if (card == 11) {
        printf("J");
    } else if (card == 12) {
        printf("Q");
    } else if (card == 13) {
        printf("K");
    }
}

// Function to print the player's hand
void print_hand(int hand[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        print_card(hand[i]);
        printf(" ");
    }
}

// Function to evaluate a hand
int evaluate_hand(int hand[], int size) {
    int i, j, rank, suit, straight, flush;
    int freq[14] = {0};
    int suits[4] = {0};

    // Count the frequency of each rank and suit
    for (i = 0; i < size; i++) {
        freq[hand[i]]++;
        switch ((hand[i] - 1) / 13) {
            case 0:
                suits[0]++;
                break;
            case 1:
                suits[1]++;
                break;
            case 2:
                suits[2]++;
                break;
            case 3:
                suits[3]++;
                break;
        }
    }

    // Check for a flush
    flush = 0;
    for (i = 0; i < 4; i++) {
        if (suits[i] >= 5) {
            flush = 1;
            break;
        }
    }

    // Check for a straight
    straight = 0;
    for (i = 1; i <= 10; i++) {
        if (freq[i] && freq[i+1] && freq[i+2] && freq[i+3] && freq[i+4]) {
            straight = 1;
            break;
        }
    }
    if (freq[1] && freq[10] && freq[11] && freq[12] && freq[13]) {
        straight = 1;
    }

    // Check for the hand rank
    if (straight && flush) {
        rank = 8;
    } else if (freq[1] && freq[10] && freq[11] && freq[12] && freq[13]) {
        rank = 7;
    } else if (freq[2] == 4 || freq[3] == 4 || freq[4] == 4 || freq[5] == 4 || freq[6] == 4 || freq[7] == 4 || freq[8] == 4 || freq[9] == 4 || freq[10] == 4 || freq[11] == 4 || freq[12] == 4 || freq[13] == 4) {
        rank = 6;
    } else if ((freq[1] == 3 && (freq[2] == 2 || freq[3] == 2 || freq[4] == 2 || freq[5] == 2 || freq[6] == 2 || freq[7] == 2 || freq[8] == 2 || freq[9] == 2 || freq[10] == 2 || freq[11] == 2 || freq[12] == 2 || freq[13] == 2)) || ((freq[2] == 3 || freq[3] == 3 || freq[4] == 3 || freq[5] == 3 || freq[6] == 3 || freq[7] == 3 || freq[8] == 3 || freq[9] == 3 || freq[10] == 3 || freq[11] == 3 || freq[12] == 3 || freq[13] == 3) && (freq[1] == 2 || freq[10] == 2 || freq[11] == 2 || freq[12] == 2 || freq[13] == 2))) {
        rank = 5;
    } else if (flush) {
        rank = 4;
    } else if (straight) {
        rank = 3;
    } else if (freq[1] && freq[10] && freq[11] && freq[12] && freq[13]) {
        rank = 2;
    } else if (freq[1] == 3 || freq[2] == 3 || freq[3] == 3 || freq[4] == 3 || freq[5] == 3 || freq[6] == 3 || freq[7] == 3 || freq[8] == 3 || freq[9] == 3 || freq[10] == 3 || freq[11] == 3 || freq[12] == 3 || freq[13] == 3) {
        rank = 1;
    } else {
        rank = 0;
    }

    return rank;
}

int main() {
    int deck[52];
    int player_hand[5];
    int computer_hand[5];
    int i, player_rank, computer_rank;

    init_deck(deck);
    shuffle_deck(deck);

    // Deal the cards
    for (i = 0; i < 5; i++) {
        player_hand[i] = deck[i*2];
        computer_hand[i] = deck[i*2+1];
    }

    // Evaluate the hands
    player_rank = evaluate_hand(player_hand, 5);
    computer_rank = evaluate_hand(computer_hand, 5);

    // Print the hands
    printf("Your hand: ");
    print_hand(player_hand, 5);
    printf("\n");
    printf("Computer's hand: ");
    print_hand(computer_hand, 5);
    printf("\n");

    // Print the ranks
    switch (player_rank) {
        case 0:
            printf("You have a high card.\n");
            break;
        case 1:
            printf("You have a pair.\n");
            break;
        case 2:
            printf("You have two pairs.\n");
            break;
        case 3:
            printf("You have a straight.\n");
            break;
        case 4:
            printf("You have a flush.\n");
            break;
        case 5:
            printf("You have a full house.\n");
            break;
        case 6:
            printf("You have four of a kind.\n");
            break;
        case 7:
            printf("You have a straight flush.\n");
            break;
        case 8:
            printf("You have a royal flush.\n");
            break;
    }
    switch (computer_rank) {
        case 0:
            printf("The computer has a high card.\n");
            break;
        case 1:
            printf("The computer has a pair.\n");
            break;
        case 2:
            printf("The computer has two pairs.\n");
            break;
        case 3:
            printf("The computer has a straight.\n");
            break;
        case 4:
            printf("The computer has a flush.\n");
            break;
        case 5:
            printf("The computer has a full house.\n");
            break;
        case 6:
            printf("The computer has four of a kind.\n");
            break;
        case 7:
            printf("The computer has a straight flush.\n");
            break;
        case 8:
            printf("The computer has a royal flush.\n");
            break;
    }

    // Determine the winner
    if (player_rank > computer_rank) {
        printf("You win!\n");
    } else if (player_rank < computer_rank) {
        printf("The computer wins.\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}