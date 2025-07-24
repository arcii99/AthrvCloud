//FormAI DATASET v1.0 Category: Poker Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player1[5], player2[5];
    char suits[4][9] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char ranks[13][6] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                        "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    srand(time(NULL));
    
    // Distribute 5 cards to player 1
    printf("Player 1's hand: ");
    for(int i=0; i<5; i++) {
        int r = rand() % 13;
        int s = rand() % 4;
        player1[i] = r + s*100;
        printf("%s of %s, ", ranks[r], suits[s]);
    }
    printf("\n");
    
    // Distribute 5 cards to player 2
    printf("Player 2's hand: ");
    for(int i=0; i<5; i++) {
        int r = rand() % 13;
        int s = rand() % 4;
        player2[i] = r + s*100;
        printf("%s of %s, ", ranks[r], suits[s]);
    }
    printf("\n");
    
    // Find out the winner
    int sum1=0, sum2=0;
    for(int i=0; i<5; i++) {
        sum1 += player1[i]%100;
        sum2 += player2[i]%100;
    }
    if(sum1 > sum2)
        printf("Player 1 Wins!\n");
    else if(sum1 < sum2)
        printf("Player 2 Wins!\n");
    else
        printf("It's a Tie!\n");
    
    return 0;
}