//FormAI DATASET v1.0 Category: Poker Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define card structure
typedef struct {
    char suit[10];
    char value[3];
    int point;
} card;

// define deck structure
typedef struct {
    card cards[52];
    int top;
} deck;

// initialize deck
void init_deck(deck *d) {
    char suits[4][10] = {"spades", "hearts", "diamonds", "clubs"};
    char values[13][3] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int i, j, point = 2;
    for(i = 0; i < 52; i++) {
        if(i != 0 && i % 13 == 0) {
            point++;
        }
        j = i % 13;
        card c;
        strcpy(c.suit, suits[i / 13]);
        strcpy(c.value, values[j]);
        c.point = point;
        d->cards[i] = c;
    }
    d->top = 0;
}

// shuffle deck
void shuffle(deck *d) {
    srand(time(NULL));
    int i, j;
    card temp;
    for(i = 0; i < 52; i++) {
        j = rand() % 52;
        temp = d->cards[i];
        d->cards[i] = d->cards[j];
        d->cards[j] = temp;
    }
    d->top = 0;
    printf("The deck has been shuffled.\n");
}

// deal card from deck
card deal_card(deck *d) {
    card c = d->cards[d->top];
    d->top++;
    return c;
}

// get total points of hand
int total_points(card hand[], int num_cards) {
    int i, total = 0, num_aces = 0;
    for(i = 0; i < num_cards; i++) {
        total += hand[i].point;
        if(strcmp(hand[i].value, "A") == 0) {
            num_aces++;
        }
    }
    while(num_aces > 0 && total > 21) {
        num_aces--;
        total -= 10;
    }
    return total;
}

int main() {
    deck d;
    init_deck(&d);
    shuffle(&d);
    int num_players, i, j;
    printf("How many players (1-6)?\n");
    scanf("%d", &num_players);
    while(num_players < 1 || num_players > 6) {
        printf("Invalid input. Please enter a number between 1 and 6.\n");
        scanf("%d", &num_players);
    }
    card players[num_players][10];
    int num_cards[num_players];
    for(i = 0; i < num_players; i++) {
        card c1 = deal_card(&d);
        card c2 = deal_card(&d);
        players[i][0] = c1;
        players[i][1] = c2;
        num_cards[i] = 2;
        printf("Player %d: %s %s %d points (%s %s %d points)\n", i+1, c1.suit, c1.value, c1.point, c2.suit, c2.value, c2.point);
    }
    card dealer_hand[10];
    int num_dealer_cards = 2;
    card c3 = deal_card(&d);
    card c4 = deal_card(&d);
    dealer_hand[0] = c3;
    dealer_hand[1] = c4;
    printf("Dealer: %s %s %d points (hidden)\n", c3.suit, c3.value, c3.point);
    while(1) {
        for(i = 0; i < num_players; i++) {
            if(total_points(players[i], num_cards[i]) == 21) {
                printf("Player %d has Blackjack!\n", i+1);
                continue;
            }
            char hit_or_stand[10];
            printf("Player %d, do you want to hit or stand?\n", i+1);
            scanf("%s", hit_or_stand);
            while(strcmp(hit_or_stand, "hit") != 0 && strcmp(hit_or_stand, "stand") != 0) {
                printf("Invalid input. Please enter 'hit' or 'stand'.\n");
                scanf("%s", hit_or_stand);
            }
            while(strcmp(hit_or_stand, "hit") == 0) {
                card c = deal_card(&d);
                players[i][num_cards[i]] = c;
                num_cards[i]++;
                printf("Player %d: %s %s %d points\n", i+1, c.suit, c.value, c.point);
                if(total_points(players[i], num_cards[i]) > 21) {
                    printf("Player %d busts.\n", i+1);
                    break;
                }
                printf("Player %d, do you want to hit or stand?\n", i+1);
                scanf("%s", hit_or_stand);
                while(strcmp(hit_or_stand, "hit") != 0 && strcmp(hit_or_stand, "stand") != 0) {
                    printf("Invalid input. Please enter 'hit' or 'stand'.\n");
                    scanf("%s", hit_or_stand);
                }
            }
        }
        while(total_points(dealer_hand, num_dealer_cards) < 17) {
            card c = deal_card(&d);
            dealer_hand[num_dealer_cards] = c;
            num_dealer_cards++;
            printf("Dealer: %s %s %d points\n", c.suit, c.value, c.point);
            if(total_points(dealer_hand, num_dealer_cards) > 21) {
                printf("Dealer busts.\n");
                break;
            }
        }
        int dealer_total = total_points(dealer_hand, num_dealer_cards);
        for(i = 0; i < num_players; i++) {
            if(total_points(players[i], num_cards[i]) > 21) {
                printf("Player %d loses.\n", i+1);
            }
            else if(total_points(players[i], num_cards[i]) > dealer_total || dealer_total > 21) {
                printf("Player %d wins!\n", i+1);
            }
            else if(total_points(players[i], num_cards[i]) == dealer_total) {
                printf("Player %d ties with dealer.\n", i+1);
            }
            else {
                printf("Player %d loses.\n", i+1);
            }
        }
        char play_again[10];
        printf("Do you want to play again? (yes or no)\n");
        scanf("%s", play_again);
        while(strcmp(play_again, "yes") != 0 && strcmp(play_again, "no") != 0) {
            printf("Invalid input. Please enter 'yes' or 'no'.\n");
            scanf("%s", play_again);
        }
        if(strcmp(play_again, "no") == 0) {
            printf("Thanks for playing!\n");
            break;
        }
        init_deck(&d);
        shuffle(&d);
        for(i = 0; i < num_players; i++) {
            num_cards[i] = 0;
        }
        num_dealer_cards = 0;
    }
    return 0;
}