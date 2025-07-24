//FormAI DATASET v1.0 Category: Poker Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARD_NUM 52
#define PLAYER_NUM 2
#define HAND 5

char* cardType[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
char* cardNum[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

int main()
{
    int card[CARD_NUM];
    srand(time(NULL)); 
    printf("Welcome to C Poker Game!!\n");

    for(int i = 0; i < CARD_NUM; i++) 
        card[i] = i;

    for(int i = 0; i < CARD_NUM; i++) 
    {
        //shuffle card
        int j = i + rand() % (CARD_NUM - i);
        int temp = card[j];
        card[j] = card[i];
        card[i] = temp;
    }

    printf("\n");
    for(int p = 0; p < PLAYER_NUM; p++)
    {
        printf("Player %d Cards: ", p+1);
        for(int i = 0; i < HAND; i++) 
        {
            int cardIndex = p * HAND + i;
            int typeIndex = card[cardIndex] / 13;
            int numIndex = card[cardIndex] % 13;
            printf("%s of %s, ", cardNum[numIndex], cardType[typeIndex]);
        }
        printf("\n");
    }
    
    return 0;
}