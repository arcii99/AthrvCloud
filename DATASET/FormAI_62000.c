//FormAI DATASET v1.0 Category: Poker Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void print_hand(char name[], int hand[]) {
    printf("%s's hand: ", name);
    for (int i = 0; i < 5; i++) {
        if (hand[i] < 11) {
            printf("%d ", hand[i]);
        } else if (hand[i] == 11) {
            printf("J ");
        } else if (hand[i] == 12) {
            printf("Q ");
        } else if (hand[i] == 13) {
            printf("K ");
        } else if (hand[i] == 14) {
            printf("A ");
        }
    }
    printf("\n\n");
}

int main() {
    srand(time(NULL));
    int deck[52];
    for (int i = 0; i < 52; i++) {
        deck[i] = i + 2;
    }

    int player_hand[5];
    int dealer_hand[5];

    int player_score = 0;
    int dealer_score = 0;

    for (int i = 0; i < 2; i++) {
        int random_num = rand() % 52;
        player_hand[i] = deck[random_num];
        player_score += player_hand[i];

        for (int j = random_num; j < 51; j++) {
            deck[j] = deck[j+1];
        }
    }

    for (int i = 0; i < 2; i++) {
        int random_num = rand() % 52;
        dealer_hand[i] = deck[random_num];
        dealer_score += dealer_hand[i];

        for (int j = random_num; j < 51; j++) {
            deck[j] = deck[j+1];
        }
    }

    printf("Sherlock's Poker Game\n\n");

    print_hand("Player", player_hand);
    print_hand("Dealer", dealer_hand);

    char hit_or_stand[10];
    while (1) {
        printf("Hit or Stand? ");
        scanf("%s", hit_or_stand);

        if (strcmp(hit_or_stand, "Hit") == 0) {
            int random_num = rand() % 52;
            player_hand[2] = deck[random_num];
            player_score += player_hand[2];

            printf("\nPlayer's hand: ");
            for (int i = 0; i < 3; i++) {
                if (player_hand[i] < 11) {
                    printf("%d ", player_hand[i]);
                } else if (player_hand[i] == 11) {
                    printf("J ");
                } else if (player_hand[i] == 12) {
                    printf("Q ");
                } else if (player_hand[i] == 13) {
                    printf("K ");
                } else if (player_hand[i] == 14) {
                    printf("A ");
                }
            }

            printf("\n\n");
            if (player_score > 21) {
                printf("Busted! Dealer wins!\n");
                return 0;
            }
        } else if (strcmp(hit_or_stand, "Stand") == 0) {
            while (dealer_score < 17) {
                int random_num = rand() % 52;
                dealer_hand[2] = deck[random_num];
                dealer_score += dealer_hand[2];

                printf("Dealer's hand: ");
                for (int i = 0; i < 3; i++) {
                    if (dealer_hand[i] < 11) {
                        printf("%d ", dealer_hand[i]);
                    } else if (dealer_hand[i] == 11) {
                        printf("J ");
                    } else if (dealer_hand[i] == 12) {
                        printf("Q ");
                    } else if (dealer_hand[i] == 13) {
                        printf("K ");
                    } else if (dealer_hand[i] == 14) {
                        printf("A ");
                    }
                }
                printf("\n\n");

                if (dealer_score > 21) {
                    printf("Dealer busted! Player wins!\n");
                    return 0;
                }
            }

            if (player_score > dealer_score) {
                printf("Player wins!\n");
            } else if (player_score < dealer_score) {
                printf("Dealer wins!\n");
            } else {
                printf("It's a tie!\n");
            }

            return 0;
        } else {
            printf("Invalid input. Please enter Hit or Stand.\n", hit_or_stand);
        }
    }
}