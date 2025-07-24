//FormAI DATASET v1.0 Category: Poker Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define CARD_RANK 13
#define CARD_SUIT 4

char* rank[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
char* suit[4] = {"hearts", "diamonds", "clubs", "spades"};

void shuffle_deck(int deck[]) {
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < DECK_SIZE; i++) {
        j = rand() % DECK_SIZE;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(int card) {
    printf("%s of %s\n", rank[card % CARD_RANK], suit[card / CARD_RANK]);
}

int main() {
    int deck[DECK_SIZE];
    int i, player_card, dealer_card;
    char choice;
    shuffle_deck(deck);
    printf("Welcome to C Poker Game!\n");
    for (i = 0; i < 2; i++) {
        player_card = deck[i];
        dealer_card = deck[i+2];
        printf("Your card: ");
        print_card(player_card);
        printf("Dealer's card: ");
        print_card(dealer_card);
    }
    printf("Do you want to hit or stand? (h/s): ");
    while (1) {
        scanf("%c", &choice);
        if (choice == 'h') {
            player_card = deck[i++];
            printf("Your card: ");
            print_card(player_card);
            if (i > 3) {
                printf("You have reached max limit of cards!\n");
                break;
            }
            printf("Do you want to hit or stand? (h/s): ");
        }
        else if (choice == 's') {
            printf("You chose to stand.\n");
            break;
        }
        else {
            printf("Invalid input!\n");
            printf("Do you want to hit or stand? (h/s): ");
        }
    }
    return 0;
}