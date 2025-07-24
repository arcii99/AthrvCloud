//FormAI DATASET v1.0 Category: Poker Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARD_COUNT 52
#define HAND_SIZE 5

// Function to print the player's hand
void print_hand(int hand[], int size) {
    for(int i = 0; i < size; i++) {
        if(hand[i] % 13 == 0)
            printf("King ");
        else if(hand[i] % 13 == 1)
            printf("Ace ");
        else if(hand[i] % 13 == 11)
            printf("Jack ");
        else if(hand[i] % 13 == 12)
            printf("Queen ");
        else
            printf("%d ", hand[i] % 13 + 1);

        if(hand[i] / 13 == 0)
            printf("of Diamonds");
        else if(hand[i] / 13 == 1)
            printf("of Clubs");
        else if(hand[i] / 13 == 2)
            printf("of Hearts");
        else
            printf("of Spades");

        printf("\n");
    }
}

// Function to check if a hand is a flush
int is_flush(int hand[], int size) {
    for(int i = 1; i < size; i++) {
        if(hand[i] / 13 != hand[0] / 13)
            return 0;
    }
    return 1;
}

// Function to check if a hand is a straight
int is_straight(int hand[], int size) {
    int max_val = hand[0] % 13 + 1;
    for(int i = 1; i < size; i++) {
        if(hand[i] % 13 + 1 != max_val + i)
            return 0;
    }
    return 1;
}

// Function to find the rank of a hand
void find_rank(int hand[], int size) {
    int flush = is_flush(hand, size);
    int straight = is_straight(hand, size);

    if(flush && straight)
        printf("Straight flush!\n");
    else if(flush)
        printf("Flush!\n");
    else if(straight)
        printf("Straight!\n");
    else
        printf("Nothing special.\n");
}

int main() {
    int cards[CARD_COUNT];
    int player_hand[HAND_SIZE];

    // Initialize cards array with values 0-51
    for(int i = 0; i < CARD_COUNT; i++)
        cards[i] = i;

    // Shuffle the cards
    srand(time(NULL));
    for(int i = CARD_COUNT - 1; i >= 1; i--) {
        int j = rand() % (i+1);
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }

    // Deal the player's hand
    for(int i = 0; i < HAND_SIZE; i++)
        player_hand[i] = cards[i];

    // Print the player's hand
    printf("Your hand:\n");
    print_hand(player_hand, HAND_SIZE);

    // Find the rank of the hand
    find_rank(player_hand, HAND_SIZE);

    return 0;
}