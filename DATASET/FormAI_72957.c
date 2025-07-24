//FormAI DATASET v1.0 Category: Poker Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 52
#define MAX_PLAYERS 5
#define HAND_SIZE 2
#define DEALER 0
#define MINIMUM_BET 10

struct Player {
    char name[20];
    int balance;
    int current_hand[HAND_SIZE];
    int bet;
    int wins;
    int losses;
};

typedef struct Player Player;

void shuffle(int *deck) {
    int i, j, temp;
    for(i=0; i<MAX_CARDS; i++) {
        j = rand() % MAX_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int calculate_total(int *hand) {
    int i, total=0;
    for(i=0; i<HAND_SIZE; i++) {
        if(hand[i]>=10) {
            total += 10;
        } else if(hand[i]==1) {
            total += 11;
        } else {
            total += hand[i];
        }
    }
    for(i=0; i<HAND_SIZE; i++) {
        if(hand[i]==1 && total>21) {
            total -= 10;
        }
    }
    return total;
}

void deal_hand(Player *players, int *deck) {
    int i, j;
    for(i=0; i<MAX_PLAYERS; i++) {
        for(j=0; j<HAND_SIZE; j++) {
            players[i].current_hand[j] = deck[i*2+j];
        }
    }
}

void display_game(Player *players, int current_player, int dealer_hand_visible) {
    int i, j, total=0;
    printf("\n*** CURRENT GAME STATUS ***\n");
    for(i=0; i<MAX_PLAYERS; i++) {
        printf("\n%s's", players[i].name);
        printf(" current hand: ");
        for(j=0; j<HAND_SIZE; j++) {
            if(i==dealer_hand_visible) {
                printf("%d ", players[i].current_hand[0]);
                printf("? ");
                break;
            } else {
                printf("%d ", players[i].current_hand[j]);
            }
        }
        printf("\n%s's", players[i].name);
        printf(" total score: %d", calculate_total(players[i].current_hand));
        if(i==current_player && i!=DEALER) {
            printf("\n%s's", players[i].name);
            printf(" current bet: %d", players[i].bet);
            printf("\n%s's", players[i].name);
            printf(" current balance: %d", players[i].balance);
        }
        printf("\n");
    }
}

int get_player_input(Player *players, int current_player) {
    int input;
    printf("\n%s's", players[current_player].name);
    printf(" choose your action:");
    printf("\n1. Hit");
    printf("\n2. Stand");
    printf("\n3. Double Down");
    if(players[current_player].balance>=(players[current_player].bet*2) && players[current_player].current_hand[0]!=players[current_player].current_hand[1]) {
        printf("\n4. Split");
    }
    printf("\n> ");
    scanf("%d", &input);
    return input;
}

void perform_action(Player *players, int current_player, int *deck) {
    int input, current_total, i;
    do {
        input = get_player_input(players, current_player);
        switch(input) {
            case 1:
                players[current_player].current_hand[HAND_SIZE] = deck[0];
                for(i=0; i<MAX_CARDS; i++) {
                    deck[i] = deck[i+1];
                }
                current_total = calculate_total(players[current_player].current_hand);
                if(current_total>21) {
                    printf("\n%s's", players[current_player].name);
                    printf(" hand is busted!");
                    players[current_player].losses++;
                    players[current_player].balance -= players[current_player].bet;
                    return;
                } else if(current_total==21) {
                    printf("\n%s's", players[current_player].name);
                    printf(" hand is a blackjack!");
                    players[current_player].wins++;
                    players[current_player].balance += players[current_player].bet*2;
                    return;
                }
                break;
            case 2:
                printf("\n%s's", players[current_player].name);
                printf(" has stood on their hand.");
                return;
            case 3:
                if(players[current_player].balance<(players[current_player].bet*2)) {
                    printf("\n%s's", players[current_player].name);
                    printf(" does not have enough balance to double down!");
                    break;
                }
                printf("\n%s's", players[current_player].name);
                printf(" has doubled down!");
                players[current_player].balance -= players[current_player].bet;
                players[current_player].bet *= 2;
                players[current_player].current_hand[HAND_SIZE] = deck[0];
                for(i=0; i<MAX_CARDS; i++) {
                    deck[i] = deck[i+1];
                }
                current_total = calculate_total(players[current_player].current_hand);
                if(current_total>21) {
                    printf("\n%s's", players[current_player].name);
                    printf(" hand is busted!");
                    players[current_player].losses++;
                    return;
                } else if(current_total==21) {
                    printf("\n%s's", players[current_player].name);
                    printf(" hand is a blackjack!");
                    players[current_player].wins++;
                    players[current_player].balance += players[current_player].bet*2;
                    return;
                }
                return;
            case 4:
                printf("\n%s's", players[current_player].name);
                printf(" has split their hand!");
                players[current_player+1].balance = players[current_player].balance;
                players[current_player+1].bet = players[current_player].bet;
                players[current_player+1].current_hand[0] = players[current_player].current_hand[1];
                players[current_player+1].current_hand[1] = deck[0];
                players[current_player].current_hand[1] = deck[1];
                for(i=0; i<MAX_CARDS-2; i++) {
                    deck[i] = deck[i+2];
                }
                current_total = calculate_total(players[current_player].current_hand);
                if(current_total>21) {
                    printf("\n%s's", players[current_player].name);
                    printf(" first hand is busted!");
                    players[current_player].losses++;
                    players[current_player].current_hand[0] = 0;
                    players[current_player+1].current_hand[0] = 0;
                } else if(current_total==21) {
                    printf("\n%s's", players[current_player].name);
                    printf(" first hand is a blackjack!");
                    players[current_player].wins++;
                    players[current_player].balance += players[current_player].bet*2;
                    players[current_player].current_hand[0] = 0;
                    players[current_player+1].current_hand[0] = 0;
                }
                current_total = calculate_total(players[current_player+1].current_hand);
                if(current_total>21) {
                    printf("\n%s's", players[current_player].name);
                    printf(" second hand is busted!");
                    players[current_player+1].losses++;
                    return;
                } else if(current_total==21) {
                    printf("\n%s's", players[current_player].name);
                    printf(" second hand is a blackjack!");
                    players[current_player+1].wins++;
                    players[current_player+1].balance += players[current_player+1].bet*2;
                    return;
                }
                break;
        }
    } while(input != 2);
}

void play_game(Player *players, int *deck) {
    int i, j, current_player=0, dealer_total, dealer_hand_visible=DEALER;
    char choice;
    do {
        printf("\n*** NEW ROUND STARTING ***\n");
        for(i=0; i<MAX_PLAYERS; i++) {
            printf("\n%s's", players[i].name);
            printf(" current balance: %d", players[i].balance);
            do {
                printf("\n%s's", players[i].name);
                printf(" enter your bet amount (minimum bet is %d):", MINIMUM_BET);
                printf("\n> ");
                scanf("%d", &players[i].bet);
            } while(players[i].bet<MINIMUM_BET || players[i].bet>players[i].balance);
            players[i].balance -= players[i].bet;
        }
        shuffle(deck);
        deal_hand(players, deck);
        display_game(players, current_player, dealer_hand_visible);
        perform_action(players, current_player, deck);
        current_player++;
        while(current_player<MAX_PLAYERS && players[current_player].current_hand[0]!=0) {
            display_game(players, current_player, dealer_hand_visible);
            perform_action(players, current_player, deck);
            current_player++;
        }
        dealer_total = calculate_total(players[DEALER].current_hand);
        dealer_hand_visible = DEALER;
        while(dealer_total<17) {
            printf("\nDealer is drawing a card...");
            players[DEALER].current_hand[HAND_SIZE] = deck[0];
            for(i=0; i<MAX_CARDS; i++) {
                deck[i] = deck[i+1];
            }
            display_game(players, current_player, dealer_hand_visible);
            dealer_total = calculate_total(players[DEALER].current_hand);
        }
        for(i=0; i<MAX_PLAYERS; i++) {
            if(players[i].current_hand[0]!=0) {
                if(calculate_total(players[i].current_hand)>21) {
                    printf("\n%s's", players[i].name);
                    printf(" hand is busted!");
                    players[i].losses++;
                } else if(dealer_total>21 || calculate_total(players[i].current_hand)>dealer_total) {
                    printf("\n%s's", players[i].name);
                    printf(" wins!");
                    players[i].wins++;
                    players[i].balance += players[i].bet*2;
                } else if(calculate_total(players[i].current_hand)==dealer_total) {
                    printf("\n%s's", players[i].name);
                    printf(" and Dealer have a tie!");
                    players[i].balance += players[i].bet;
                } else {
                    printf("\n%s's", players[i].name);
                    printf(" loses!");
                    players[i].losses++;
                }
            }
            players[i].current_hand[0] = 0;
            players[i].current_hand[1] = 0;
            players[i].bet = 0;
        }
        printf("\nDo you want to continue playing?('y' for Yes / 'n' for No):");
        printf("\n> ");
        scanf(" %c", &choice);
        current_player = 0;
    } while(choice=='y' || choice=='Y');
}

int main() {
    int deck[MAX_CARDS], i;
    Player players[MAX_PLAYERS] = {
        {"Player 1", 100, {0, 0}, 0, 0, 0},
        {"Player 2", 100, {0, 0}, 0, 0, 0},
        {"Player 3", 100, {0, 0}, 0, 0, 0},
        {"Player 4", 100, {0, 0}, 0, 0, 0},
        {"Dealer", 0, {0, 0}, 0, 0, 0}
    };
    srand(time(NULL));
    for(i=0; i<MAX_CARDS; i++) {
        deck[i] = (i % 13) + 1;
    }
    play_game(players, deck);
    return 0;
}