//FormAI DATASET v1.0 Category: Poker Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle deck of cards
void shuffle(int *deck, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        j = i + rand() % (n-i);
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

// Function to deal a card from the top of the deck
int deal(int *deck, int *cards_dealt) {
    int card = deck[*cards_dealt];
    (*cards_dealt)++;
    return card;
}

// Function to calculate the value of a hand
int value(char *hand[], int n) {
    int i, sum = 0;
    for (i = 0; i < n; i++) {
        if (hand[i][0] == 'A') {
            sum += 11;
        } else if (hand[i][0] == 'K' || hand[i][0] == 'Q' || hand[i][0] == 'J') {
            sum += 10;
        } else {
            sum += atoi(&hand[i][0]);
        }
    }
    for (i = 0; i < n; i++) {
        if (hand[i][0] == 'A' && sum > 21) {
            sum -= 10;
        }
    }
    return sum;
}

// Function to print a hand
void print_hand(char *hand[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s ", hand[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int deck[52];
    int i, cards_dealt = 0;
    char *ranks[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    char *suits[] = {"C","D","H","S"};
    char *player_hand[5];
    char *dealer_hand[5];

    // Initialize deck of cards
    for (i = 0; i < 52; i++) {
        deck[i] = i;
    }

    // Shuffle deck of cards
    shuffle(deck, 52);

    // Deal initial hands
    for (i = 0; i < 2; i++) {
        player_hand[i] = (char *)malloc(3 * sizeof(char));
        sprintf(player_hand[i], "%s%s", ranks[deck[cards_dealt]/4], suits[deck[cards_dealt]%4]);
        cards_dealt++;
        dealer_hand[i] = (char *)malloc(3 * sizeof(char));
        sprintf(dealer_hand[i], "%s%s", ranks[deck[cards_dealt]/4], suits[deck[cards_dealt]%4]);
        cards_dealt++;
    }

    printf("Dealer's Hand: ");
    printf("%s XX\n", dealer_hand[0]);
    printf("Your Hand: ");
    print_hand(player_hand, 2);
    printf("Your Hand Value: %d\n", value(player_hand, 2));

    // Player turn
    while (1) {
        char choice;
        printf("Hit or Stay? (h/s): ");
        scanf(" %c", &choice);
        if (choice == 'h') {
            player_hand[i] = (char *)malloc(3 * sizeof(char));
            sprintf(player_hand[i], "%s%s", ranks[deck[cards_dealt]/4], suits[deck[cards_dealt]%4]);
            cards_dealt++;
            printf("Your Hand: ");
            print_hand(player_hand, i+1);
            printf("Your Hand Value: %d\n", value(player_hand, i+1));
            if (value(player_hand, i+1) > 21) {
                printf("Bust! You Lose!\n");
                return 0;
            }
            i++;
        } else if (choice == 's') {
            break;
        } else {
            printf("Invalid Choice!\n");
        }
    }

    // Dealer turn
    i = 2;
    printf("Dealer's Hand: ");
    print_hand(dealer_hand, 2);
    printf("Dealer's Hand Value: %d\n", value(dealer_hand, 2));
    while (value(dealer_hand, i) < 17) {
        dealer_hand[i] = (char *)malloc(3 * sizeof(char));
        sprintf(dealer_hand[i], "%s%s", ranks[deck[cards_dealt]/4], suits[deck[cards_dealt]%4]);
        cards_dealt++;
        printf("Dealer Draws: %s\n", dealer_hand[i]);
        printf("Dealer's Hand: ");
        print_hand(dealer_hand, i+1);
        printf("Dealer's Hand Value: %d\n", value(dealer_hand, i+1));
        i++;
    }

    // Determine winner
    int player_value = value(player_hand, i), dealer_value = value(dealer_hand, i);
    if (player_value > dealer_value || dealer_value > 21) {
        printf("You Win!\n");
    } else if (player_value == dealer_value) {
        printf("Push!\n");
    } else {
        printf("Dealer Wins!\n");
    }

    // Free allocated memory
    for (i = 0; i < 5; i++) {
        free(player_hand[i]);
        free(dealer_hand[i]);
    }

    return 0;
}