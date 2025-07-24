//FormAI DATASET v1.0 Category: Memory Game ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct{
    char suit[10];
    int value;
}Card;

void swap(Card* card1, Card* card2){
    Card temp = *card1;
    *card1 = *card2;
    *card2 = temp;
}

void shuffle(Card arr[], int n){
    srand(time(NULL));
    for(int i=n-1; i>0; i--){
        int j = rand()%(i+1);
        swap(&arr[i], &arr[j]);
    }
}

void printDeck(Card deck[], int n){
    for(int i=0; i<n; i++){
        printf("%s %d\n", deck[i].suit, deck[i].value);
    }
    printf("\n");
}

int main(){
    int n = 20;
    Card deck[n];

    // initialize deck
    for(int i=0; i<n; i++){
        if(i%5 == 0){
            sprintf(deck[i].suit, "Spade");
            deck[i].value = (i/5)+1;
        }
        else if(i%5 == 1){
            sprintf(deck[i].suit, "Heart");
            deck[i].value = (i/5)+1;
        }
        else if(i%5 == 2){
            sprintf(deck[i].suit, "Diamond");
            deck[i].value = (i/5)+1;
        }
        else if(i%5 == 3){
            sprintf(deck[i].suit, "Club");
            deck[i].value = (i/5)+1;
        }
        else{
            sprintf(deck[i].suit, "Joker");
            deck[i].value = 100;
        }
    }

    printf("Initial Deck:\n");
    printDeck(deck, n);

    // shuffle deck
    shuffle(deck, n);

    printf("Shuffled Deck:\n");
    printDeck(deck, n);

    // memory game
    printf("MEMORY GAME\n");
    printf("Try to match the pairs of cards.\n");

    int numPairs = 0;
    int numGuesses = 0;
    int pairsGuessed[n/2];
    for(int i=0; i<n/2; i++){
        pairsGuessed[i] = 0;
    }

    while(numPairs < n/2){
        int choice1, choice2;
        printf("Enter the position of the first card: ");
        scanf("%d", &choice1);
        while(choice1 < 0 || choice1 >= n){
            printf("Invalid position. Try again: ");
            scanf("%d", &choice1);
        }

        while(pairsGuessed[choice1/2] == 1){
            printf("Pair already guessed. Choose another position (or enter -1 to quit): ");
            scanf("%d", &choice1);
            if(choice1 == -1){
                printf("Game over. Number of guesses: %d\n", numGuesses);
                exit(0);
            }
        }

        printf("Enter the position of the second card: ");
        scanf("%d", &choice2);
        while(choice2 < 0 || choice2 >= n || choice2 == choice1){
            printf("Invalid position. Try again: ");
            scanf("%d", &choice2);
        }

        while(pairsGuessed[choice2/2] == 1){
            printf("Pair already guessed. Choose another position (or enter -1 to quit): ");
            scanf("%d", &choice2);
            if(choice2 == -1){
                printf("Game over. Number of guesses: %d\n", numGuesses);
                exit(0);
            }
        }

        printf("Cards at position %d and %d: %s %d, %s %d\n", choice1, choice2, deck[choice1].suit, deck[choice1].value, deck[choice2].suit, deck[choice2].value);

        if(deck[choice1].value == deck[choice2].value){
            printf("Pair found!\n");
            pairsGuessed[choice1/2] = 1;
            numPairs++;
        }
        else{
            printf("No match found.\n");
        }
        numGuesses++;
    }

    printf("Congratulations! You found all the pairs. Number of guesses: %d\n", numGuesses);

    return 0;
}