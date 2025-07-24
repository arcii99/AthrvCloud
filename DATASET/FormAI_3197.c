//FormAI DATASET v1.0 Category: Poker Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *arr, int n)
{
    srand(time(NULL)); //seed random number generator with current time
    for(int i=n-1; i>0; i--)
    {
        int j = rand() % (i+1); //generate a random index from 0 to i (inclusive)
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    int deck[52];
    for(int i=0; i<52; i++)
        deck[i] = i;
    
    shuffle(deck, 52);
    
    printf("Welcome to C Poker Game!\n");
    printf("Here is your hand:\n");
    for(int i=0; i<5; i++)
    {
        int card = deck[i];
        int suit = card / 13;
        int rank = card % 13;
        printf("Card %d: ", i+1);
        switch(rank)
        {
            case 0:
                printf("Ace ");
                break;
            case 10:
                printf("Jack ");
                break;
            case 11:
                printf("Queen ");
                break;
            case 12:
                printf("King ");
                break;
            default:
                printf("%d ", rank+1);
        }
        switch(suit)
        {
            case 0:
                printf("of Hearts\n");
                break;
            case 1:
                printf("of Diamonds\n");
                break;
            case 2:
                printf("of Clubs\n");
                break;
            case 3:
                printf("of Spades\n");
                break;
        }
    }
    return 0;
}