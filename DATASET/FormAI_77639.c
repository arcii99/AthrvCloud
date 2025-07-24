//FormAI DATASET v1.0 Category: Poker Game ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shuffle(int cardDeck[52]);
void dealCards(int cardDeck[52], char *face[], char *suit[]);

int main(){
    int cardDeck[52]={0};
    char *face[]={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    char *suit[]={"Hearts","Diamonds","Clubs","Spades"};

    srand(time(NULL));
    shuffle(cardDeck);

    dealCards(cardDeck,face,suit);

    return 0;
}

void shuffle(int cardDeck[52]){
    int temp = 0, num =0;

    for(num=0; num<52; num++){
        cardDeck[num] = num;
    }

    for(num=0; num<52; num++){
        int random = rand()%52;
        temp = cardDeck[num];
        cardDeck[num]=cardDeck[random];
        cardDeck[random]=temp;
    }
}

void dealCards(int cardDeck[52], char *face[], char *suit[]){
    int playerHand[5]={cardDeck[0],cardDeck[1],cardDeck[2],cardDeck[3],cardDeck[4]};
    int dealerHand[5]={cardDeck[5],cardDeck[6],cardDeck[7],cardDeck[8],cardDeck[9]};

    printf("Player hand: \n");
    for(int i=0;i<5;i++){
        printf("%s of %s\n",face[playerHand[i]%13],suit[playerHand[i]/13]);
    }

    printf("\nDealer hand: \n");
    for(int i=0;i<5;i++){
        printf("%s of %s\n",face[dealerHand[i]%13],suit[dealerHand[i]/13]);
    }
}