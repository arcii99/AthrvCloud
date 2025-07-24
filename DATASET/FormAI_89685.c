//FormAI DATASET v1.0 Category: Memory Game ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CARDS 20

void shuffle(int cards[MAX_CARDS], int size);
void printCards(int cards[MAX_CARDS], int size);
int playGame(int cards[MAX_CARDS], int size);

int main()
{
    int cards[MAX_CARDS];
    int size = 10;
    int pairs = size/2;
    int counter = 0;

    //initialize array with pairs
    for(int i=0;i<pairs;i++){
        cards[counter] = i+1;
        cards[counter+1] = i+1;
        counter += 2;
    }

    shuffle(cards, size); //shuffle cards

    printf("Memory Game\n");
    printf("---------------\n");
    printf("Instructions:\nMatch all pairs of cards\n");
    printf("Enter 0 to exit game\n\n");

    printCards(cards, size); //print cards

    int result = playGame(cards, size); //play game

    if(result==1){
        printf("Congratulations! You won!\n");
    }else{
        printf("Game Over\n");
    }

    return 0;
}

//shuffle cards
void shuffle(int cards[MAX_CARDS], int size){
    srand(time(NULL));
    for(int i=0;i<size;i++){
        int randomIndex = rand() % size;
        int temp = cards[i];
        cards[i] = cards[randomIndex];
        cards[randomIndex] = temp;
    }
}

//print cards
void printCards(int cards[MAX_CARDS], int size){
    printf("Cards:\n");
    for(int i=0;i<size;i++){
        printf("[%d] ",cards[i]);
    }
    printf("\n\n");
}

//play game
int playGame(int cards[MAX_CARDS], int size){
    int pairs = size/2;
    int matchedCards[MAX_CARDS] = {0};
    int gameOver = 0;

    while(!gameOver){
        int choice1, choice2;

        printf("Enter first card index: ");
        scanf("%d",&choice1);

        if(choice1==0){
            return 0; //exit game
        }

        while(matchedCards[choice1-1]==1){ //check if card is already matched
            printf("Card already matched! Enter another index: ");
            scanf("%d",&choice1);

            if(choice1==0){
                return 0; //exit game
            }
        }

        printf("Enter second card index: ");
        scanf("%d",&choice2);

        if(choice2==0){
            return 0; //exit game
        }

        while(matchedCards[choice2-1]==1 || choice1==choice2){ //check if card is already matched or same as previous choice
            if(matchedCards[choice2-1]==1){
                printf("Card already matched! Enter another index: ");
            }else{
                printf("Cannot select same card! Enter another index: ");
            }
            scanf("%d",&choice2);

            if(choice2==0){
                return 0; //exit game
            }
        }

        //check if cards match
        if(cards[choice1-1]==cards[choice2-1]){
            matchedCards[choice1-1] = 1;
            matchedCards[choice2-1] = 1;

            printf("Match Found!\n\n");

            pairs--;

            if(pairs==0){
                return 1; //all cards matched
            }
        }else{
            printf("No Match Found!\n\n");
        }
    }

    return 0;
}