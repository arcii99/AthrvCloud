//FormAI DATASET v1.0 Category: Poker Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
int values[] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

struct card {
    int rank;
    int suit;
};

void shuffle_deck(struct card *deck);
void swap_cards(struct card *deck, int index1, int index2);
void print_card(struct card card);
void print_hand(struct card hand[], int size);
int calculate_hand(struct card hand[], int size);
int get_choice();

int main() {
    struct card deck[DECK_SIZE];
    struct card hand[HAND_SIZE];
    int money = 100, bet = 0, choice = 0;
    srand(time(NULL));
    
    // Fill deck with cards
    for (int i = 0; i < DECK_SIZE; i++) {
        deck[i].rank = i % 13;
        deck[i].suit = i / 13;
    }
    
    while (money > 0) {
        printf("You have $%d. Enter bet amount: ", money);
        scanf("%d", &bet);
        
        // Shuffle deck and deal cards
        shuffle_deck(deck);
        for (int i = 0; i < HAND_SIZE; i++) {
            hand[i] = deck[i];
        }
        
        // Print initial hand and calculate value
        printf("\nHand: ");
        print_hand(hand, HAND_SIZE);
        int hand_value = calculate_hand(hand, HAND_SIZE);
        printf("Hand value: %d\n", hand_value);
        
        // Give player option to hit or stand
        do {
            choice = get_choice();
            if (choice == 1) {
                // Take additional card and recalculate value
                hand[HAND_SIZE - 1] = deck[HAND_SIZE];
                printf("Card dealt: ");
                print_card(hand[HAND_SIZE - 1]);
                hand_value = calculate_hand(hand, HAND_SIZE);
                printf("Hand value: %d\n", hand_value);
                
                // Check if hand is bust
                if (hand_value > 21) {
                    printf("Bust! You lose.\n");
                    money -= bet;
                    break;
                }
            }
        } while (choice == 1);
        
        // Player stands, calculate dealer's hand
        if (choice == 2) {
            struct card dealer_hand[HAND_SIZE];
            shuffle_deck(deck);
            for (int i = 0; i < HAND_SIZE; i++) {
                dealer_hand[i] = deck[i];
            }
            printf("\nDealer's Hand: ");
            print_hand(dealer_hand, HAND_SIZE);
            int dealer_value = calculate_hand(dealer_hand, HAND_SIZE);
            printf("Dealer's Hand Value: %d\n", dealer_value);
            
            // Dealer will keep hitting until hand value reaches 17 or more
            while (dealer_value < 17) {
                dealer_hand[HAND_SIZE - 1] = deck[HAND_SIZE];
                printf("Card dealt to dealer: ");
                print_card(dealer_hand[HAND_SIZE - 1]);
                dealer_value = calculate_hand(dealer_hand, HAND_SIZE);
                printf("Dealer's Hand Value: %d\n", dealer_value);
            }
            
            // Determine winner
            if (dealer_value > 21) {
                printf("Dealer busts! You win.\n");
                money += bet;
            } else if (dealer_value >= hand_value || hand_value > 21) {
                printf("Dealer wins.\n");
                money -= bet;
            } else {
                printf("You win!\n");
                money += bet;
            }
        }
        
        // Check if player is out of money
        if (money == 0) {
            printf("You are out of money. Game Over.\n");
            break;
        }
        
        // Give player option to play again or quit
        do {
            printf("Enter 1 to play another hand or 2 to quit: ");
            scanf("%d", &choice);
        } while (choice != 1 && choice != 2);
        
        if (choice == 2) {
            printf("Thanks for playing! Goodbye.\n");
            break;
        }
    }
    
    return 0;
}

void shuffle_deck(struct card *deck) {
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap_cards(deck, i, j);
    }
}

void swap_cards(struct card *deck, int index1, int index2) {
    struct card temp = deck[index1];
    deck[index1] = deck[index2];
    deck[index2] = temp;
}

void print_card(struct card card) {
    printf("%s of %s\n", ranks[card.rank], suits[card.suit]);
}

void print_hand(struct card hand[], int size) {
    for (int i = 0; i < size; i++) {
        print_card(hand[i]);
    }
}

int calculate_hand(struct card hand[], int size) {
    int value = 0, aces = 0;
    for (int i = 0; i < size; i++) {
        value += values[hand[i].rank];
        if (hand[i].rank == 0) {
            aces++;
        }
    }
    while (value > 21 && aces > 0) {
        value -= 10;
        aces--;
    }
    return value;
}

int get_choice() {
    int choice = 0;
    do {
        printf("Enter 1 for hit or 2 for stand: ");
        scanf("%d", &choice);
    } while (choice != 1 && choice != 2);
    return choice;
}