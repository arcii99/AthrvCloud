//FormAI DATASET v1.0 Category: Poker Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Cards Structure
struct card{
    char suit;
    int value;
};

//Deck Structure
struct deck{
    struct card cardArr[52];
    int size;
};

//Player Structure
struct player{
    struct card hand[5];
    int score;
};

//Function Declarations
void shuffleDeck(struct deck *d);
void createDeck(struct deck *d);
void dealCards(struct deck *d, struct player *p1, struct player *p2);
void printHand(struct player p);
void evaluateHand(struct player *p);
void getPlayerInput(struct player *p);
void playAgain(char *response);

int main(){
    struct deck d;
    struct player p1, p2;
    char response;
    srand(time(NULL));
    createDeck(&d);
    do{
        shuffleDeck(&d);
        dealCards(&d, &p1, &p2); 
        printf("Your Hand: \n");
        printHand(p1);
        getPlayerInput(&p1);
        evaluateHand(&p1);
        printf("\nOpponent's Hand: \n");
        printHand(p2);
        evaluateHand(&p2);
        if(p1.score>p2.score){
            printf("\nYou win!");
        }
        else{
            printf("\nOpponent wins!");
        }
        playAgain(&response);
    } while(response == 'y' || response == 'Y');
    printf("\nThanks for playing!");
    return 0;
}

void shuffleDeck(struct deck *d){
    int i, j;
    struct card temp;
    for(i=0;i<52;i++){
        j = rand()%52;
        temp = d->cardArr[i];
        d->cardArr[i] = d->cardArr[j];
        d->cardArr[j] = temp;
    }
    d->size = 52;
}

void createDeck(struct deck *d){
    int i, j, index=0;
    char suits[] = {'H', 'D', 'C', 'S'};
    for(i=0;i<4;i++){
        for(j=2;j<=14;j++){
            d->cardArr[index].suit = suits[i];
            d->cardArr[index].value = j;
            index++;
        }
    }
    d->size = 52;
}

void dealCards(struct deck *d, struct player *p1, struct player *p2){
    int i;
    for(i=0;i<5;i++){
        p1->hand[i] = d->cardArr[d->size-1];
        d->size--;
        p2->hand[i] = d->cardArr[d->size-1];
        d->size--;
    }
}

void printHand(struct player p){
    int i;
    for(i=0;i<5;i++){
        printf("%d%c ", p.hand[i].value, p.hand[i].suit);
    }
    printf("\n");
}

void evaluateHand(struct player *p){
    int i, j, tempValue, tempSuit;
    p->score = 0;
    for(i=0;i<5;i++){
        tempValue = p->hand[i].value;
        tempSuit = p->hand[i].suit;
        //Evaluating pairs
        for(j=i+1;j<5;j++){
            if(tempValue == p->hand[j].value){
                p->score++;
            }
        }
        //Evaluating flush
        for(j=i+1;j<5;j++){
            if(tempSuit == p->hand[j].suit){
                p->score++;
            }
        }
    }
    printf("\nScore: %d", p->score);
}

void getPlayerInput(struct player *p){
    int input, i, j;
    struct card tempCard;
    printf("\nEnter the index of the card you want to exchange (0-4): ");
    scanf("%d", &input);
    if(input<0 || input>4){
        printf("Invalid input!\n");
        getPlayerInput(p);
        return;
    }
    tempCard = p->hand[input];
    for(i=input;i<4;i++){
        p->hand[i] = p->hand[i+1];
    }
    p->hand[4] = tempCard;
}

void playAgain(char *response){
    printf("\nDo you want to play again? (y/n) ");
    scanf(" %c", response);
}