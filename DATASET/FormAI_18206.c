//FormAI DATASET v1.0 Category: Poker Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARD_NUM 52

typedef struct {
    int rank; // 11 = Jack, 12 = Queen, 13 = King, 14 = Ace
    int suit; // 1 = Spades, 2 = Hearts, 3 = Clubs, 4 = Diamonds
} Card;

void init_deck(Card deck[CARD_NUM]);
void shuffle_deck(Card deck[CARD_NUM]);
void print_card(Card card);
int get_rank_score(Card card);

int main() {
    Card deck[CARD_NUM];
    int player_score = 0;
    int dealer_score = 0;
    int num_turns = 0;

    init_deck(deck);
    shuffle_deck(deck);

    // Deal first two cards to player
    printf("Your cards:\n");
    for (int i = 0; i < 2; i++) {
        Card card = deck[num_turns++];
        print_card(card);
        player_score += get_rank_score(card);
    }
    printf("\nYour score: %d\n\n", player_score);

    // Deal first two cards to dealer
    printf("Dealer's cards:\n");
    for (int i = 0; i < 2; i++) {
        Card card = deck[num_turns++];
        if (i == 0) {
            printf("Hidden Card\n");
        } else {
            print_card(card);
            dealer_score += get_rank_score(card);
        }
    }

    // Player's turn
    while (1) {
        char choice;
        printf("\nDo you want to hit (h) or stand (s)? ");
        scanf(" %c", &choice);

        if (choice == 'h') {
            Card card = deck[num_turns++];
            printf("You drew:\n");
            print_card(card);
            player_score += get_rank_score(card);
            printf("\nYour score: %d\n\n", player_score);

            if (player_score > 21) {
                printf("Bust! You lose.\n");
                return 0;
            }
        } else {
            break;
        }
    }

    // Dealer's turn
    printf("\nDealer's turn:\n");
    printf("Dealer's hidden card was:\n");
    print_card(deck[1]);
    dealer_score += get_rank_score(deck[1]);
    printf("Dealer's score: %d\n", dealer_score);

    while (dealer_score < 17) {
        Card card = deck[num_turns++];
        printf("Dealer drew:\n");
        print_card(card);
        dealer_score += get_rank_score(card);
        printf("Dealer's score: %d\n", dealer_score);

        if (dealer_score > 21) {
            printf("Dealer busts! You win.\n");
            return 0;
        }
    }

    // Determine winner
    if (dealer_score > player_score) {
        printf("Dealer wins.\n");
    } else if (dealer_score == player_score) {
        printf("Tie! Nobody wins.\n");
    } else {
        printf("You win!\n");
    }

    return 0;
}

void init_deck(Card deck[CARD_NUM]) {
    int i = 0;
    for (int rank = 2; rank <= 14; rank++) {
        for (int suit = 1; suit <= 4; suit++) {
            deck[i].rank = rank;
            deck[i].suit = suit;
            i++;
        }
    }
}

void shuffle_deck(Card deck[CARD_NUM]) {
    srand(time(NULL));
    for (int i = 0; i < CARD_NUM; i++) {
        int j = rand() % CARD_NUM;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(Card card) {
    char rank;
    if (card.rank < 11) {
        rank = card.rank + '0';
    } else if (card.rank == 11) {
        rank = 'J';
    } else if (card.rank == 12) {
        rank = 'Q';
    } else if (card.rank == 13) {
        rank = 'K';
    } else {
        rank = 'A';
    }

    char suit_char;
    if (card.suit == 1) {
        suit_char = 'S';
    } else if (card.suit == 2) {
        suit_char = 'H';
    } else if (card.suit == 3) {
        suit_char = 'C';
    } else {
        suit_char = 'D';
    }

    printf("%c%c ", rank, suit_char);
}

int get_rank_score(Card card) {
    if (card.rank < 11) {
        return card.rank;
    } else if (card.rank < 14) {
        return 10;
    } else {
        return 11;
    }
}