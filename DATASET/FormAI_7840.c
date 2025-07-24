//FormAI DATASET v1.0 Category: Poker Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Deck of cards
char *deck[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

// Suit of cards
char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

// Value of cards
int value[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

// Print the cards
void print_cards(int cards[], int num_cards) {
    printf("\nCards: ");
    for (int i = 0; i < num_cards; i++) {
        int card_num = cards[i];
        printf("%s of %s, ", deck[card_num], suit[card_num % 4]);
    }
    printf("\n");
}

// Calculate the total value of the cards
int calculate_total(int cards[], int num_cards) {
    int total = 0;
    for (int i = 0; i < num_cards; i++) {
        int card_num = cards[i];
        total += value[card_num];
    }
    return total;
}

// Shuffle the deck of cards
void shuffle_deck(int deck[]) {
    srand(time(0));
    for (int i = 0; i < 52; i++) {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main() {
    int deck[52];
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }

    shuffle_deck(deck);

    int player_cards[10];
    int num_player_cards = 0;

    int computer_cards[10];
    int num_computer_cards = 0;

    // Deal the cards
    player_cards[num_player_cards] = deck[0];
    num_player_cards++;

    computer_cards[num_computer_cards] = deck[1];
    num_computer_cards++;

    player_cards[num_player_cards] = deck[2];
    num_player_cards++;

    computer_cards[num_computer_cards] = deck[3];
    num_computer_cards++;

    printf("Welcome to Poker!\n");

    // Player's turn
    printf("PLAYER'S TURN:\n\n");
    print_cards(player_cards, num_player_cards);

    int player_total = calculate_total(player_cards, num_player_cards);

    while (player_total < 21) {
        char choice;
        printf("\nDo you want to hit or stand? (h/s)\n");
        scanf(" %c", &choice);

        if (choice == 'h') {
            player_cards[num_player_cards] = deck[num_player_cards + num_computer_cards];
            num_player_cards++;
            printf("\nYour new card is: %s of %s\n", deck[player_cards[num_player_cards - 1]], suit[player_cards[num_player_cards - 1] % 4]);
            print_cards(player_cards, num_player_cards);
            player_total = calculate_total(player_cards, num_player_cards);

        } else if (choice == 's') {
            printf("\nPlayer stands.\n");
            break;
        } else {
            printf("\nInvalid choice.\n");
        }
    }

    if (player_total > 21) {
        printf("\nPlayer busts. Computer wins!\n");
        return 0;
    }

    // Computer's turn
    printf("\n\nCOMPUTER'S TURN:\n\n");
    print_cards(computer_cards, num_computer_cards);

    int computer_total = calculate_total(computer_cards, num_computer_cards);

    while (computer_total < 17) {
        computer_cards[num_computer_cards] = deck[num_player_cards + num_computer_cards];
        num_computer_cards++;
        printf("\nComputer hits.");
        computer_total = calculate_total(computer_cards, num_computer_cards);

        if (computer_total > 21) {
            printf("\nComputer busts. Player wins!\n");
            return 0;
        }
    }

    printf("\nComputer stands.\n");

    // Compare the totals
    if (player_total > computer_total) {
        printf("\nPlayer wins!\n");
    } else if (player_total < computer_total) {
        printf("\nComputer wins!\n");
    } else {
        printf("\nIt's a tie!\n");
    }

    return 0;
}