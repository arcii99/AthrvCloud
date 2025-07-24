//FormAI DATASET v1.0 Category: Poker Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a random card
int get_card() {
    return (rand() % 13) + 1;
}

// Function to print the current hand
void print_hand(int *hand, int size) {
    for (int i = 0; i < size; i++) {
        if (hand[i] == 1) {
            printf("Ace ");
        } else if (hand[i] == 11) {
            printf("Jack ");
        } else if (hand[i] == 12) {
            printf("Queen ");
        } else if (hand[i] == 13) {
            printf("King ");
        } else {
            printf("%d ", hand[i]);
        }
    }
}

// Function to calculate the total value of the hand
int get_hand_value(int *hand, int size) {
    int value = 0;
    int ace_count = 0;
    for (int i = 0; i < size; i++) {
        if (hand[i] == 1) {
            ace_count++;
            value += 11;
        } else if (hand[i] > 10) {
            value += 10;
        } else {
            value += hand[i];
        }
    }
    while (ace_count > 0 && value > 21) {
        value -= 10;
        ace_count--;
    }
    return value;
}

int main() {
    srand(time(NULL));
    int deck[52];
    for (int i = 0; i < 52; i++) {
        deck[i] = i % 13 + 1;
    }
    printf("Welcome to Poker game!\n");
    while (1) {
        printf("\nPress Enter to start a new round or type 'exit' to quit.\n");
        char input[10];
        fgets(input, 10, stdin);
        if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't') {
            break;
        }
        int player_hand[5];
        int dealer_hand[5];
        int player_size = 2;
        int dealer_size = 2;
        player_hand[0] = get_card();
        player_hand[1] = get_card();
        dealer_hand[0] = get_card();
        dealer_hand[1] = get_card();
        printf("\nDealer's hand: ");
        printf("X ");
        print_hand(&dealer_hand[1], 1);
        printf("\nYour hand: ");
        print_hand(player_hand, player_size);
        printf("\n");
        while (1) {
            int player_value = get_hand_value(player_hand, player_size);
            if (player_value > 21) {
                printf("Bust! Your hand value is: %d\n", player_value);
                break;
            } else if (player_value == 21) {
                printf("Blackjack!\n");
                break;
            }
            printf("Type 'hit' to draw another card or 'stand' to stay.\n");
            char input[10];
            fgets(input, 10, stdin);
            if (input[0] == 'h' && input[1] == 'i' && input[2] == 't') {
                player_hand[player_size] = get_card();
                player_size++;
                printf("\nDealer's hand: ");
                printf("X ");
                print_hand(&dealer_hand[1], 1);
                printf("\nYour hand: ");
                print_hand(player_hand, player_size);
                printf("\n");
            } else if (input[0] == 's' && input[1] == 't' && input[2] == 'a' && input[3] == 'n' && input[4] == 'd') {
                printf("\nDealer's hand: ");
                print_hand(dealer_hand, dealer_size);
                printf("\n");
                while (get_hand_value(dealer_hand, dealer_size) < 17) {
                    dealer_hand[dealer_size] = get_card();
                    dealer_size++;
                    printf("Dealer draws another card.\n");
                }
                int dealer_value = get_hand_value(dealer_hand, dealer_size);
                if (dealer_value > 21) {
                    printf("Dealer busts! Your hand value is: %d\n", player_value);
                } else if (dealer_value > player_value) {
                    printf("Dealer wins! Your hand value is: %d, dealer's hand value is: %d\n", player_value, dealer_value);
                } else if (dealer_value == player_value) {
                    printf("Push!\n");
                } else {
                    printf("You win! Your hand value is: %d, dealer's hand value is: %d\n", player_value, dealer_value);
                }
                break;
            }
        }
    }
    printf("Thank you for playing Poker game!\n");
    return 0;
}