//FormAI DATASET v1.0 Category: Poker Game ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char *faces[]={"Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King","Ace"};
char *suits[]={"Clubs","Diamonds","Hearts","Spades"};

//Function to shuffle deck
void shuffleDeck(int deck[][13]){
    int row,column,temp;
    for(row=0;row<4;++row){
        for(column=0;column<13;++column){
            int r=rand()%4,c=rand()%13;
            temp=deck[row][column];
            deck[row][column]=deck[r][c];
            deck[r][c]=temp;
        }
    }
}

//Function to deal cards to players
void dealCards(const char *face[],const  char *suit[],const int deck[][13],char *player1[][2],char *player2[][2],int numCards){

    int count=0,row=0,column=0;
    while(count<numCards){
        if(count%2==0){ //player 1
            player1[row][column]=face[deck[row][column]];
            player1[row][column+1]=suit[deck[row][column]];
        }
        else{ //player 2
            player2[row][column]=face[deck[row][column]];
            player2[row][column+1]=suit[deck[row][column]];
            ++row;
            column=0; //reset column to start from beginning again
        }
        ++column;
        ++count;
    }
}

//Function to print each player's cards
void printCards(char *player[][2],const int numCards){
    printf("\n\nPrint cards:\n\n");
    int row=0,column=0;
    while(row<numCards/2){
        printf("Player 1: %s of %s\t",player[row][column],player[row][column+1]);
        printf("Player 2: %s of %s\n",player[row+1][column],player[row+1][column+1]);
        ++row;
    }
}

//Function to determine winning hand based on highest card
void determineWinner(char *player1[][2],char *player2[][2],const int numCards){
    int row=0,column=0,p1_highest=0,p2_highest=0;

    while(row<numCards/2){
        //Player 1 highest card
        if(strcmp(player1[row][column],"Two")==0){
            p1_highest=2;
        }
        else if(strcmp(player1[row][column],"Three")==0){
            p1_highest=3;
        }
        else if(strcmp(player1[row][column],"Four")==0){
            p1_highest=4;
        }
        else if(strcmp(player1[row][column],"Five")==0){
            p1_highest=5;
        }
        else if(strcmp(player1[row][column],"Six")==0){
            p1_highest=6;
        }
        else if(strcmp(player1[row][column],"Seven")==0){
            p1_highest=7;
        }
        else if(strcmp(player1[row][column],"Eight")==0){
            p1_highest=8;
        }
        else if(strcmp(player1[row][column],"Nine")==0){
            p1_highest=9;
        }
        else if(strcmp(player1[row][column],"Ten")==0){
            p1_highest=10;
        }
        else if(strcmp(player1[row][column],"Jack")==0){
            p1_highest=11;
        }
        else if(strcmp(player1[row][column],"Queen")==0){
            p1_highest=12;
        }
        else if(strcmp(player1[row][column],"King")==0){
            p1_highest=13;
        }
        else if(strcmp(player1[row][column],"Ace")==0){
            p1_highest=14;
        }

        //Player 2 highest card
        if(strcmp(player2[row][column],"Two")==0){
            p2_highest=2;
        }
        else if(strcmp(player2[row][column],"Three")==0){
            p2_highest=3;
        }
        else if(strcmp(player2[row][column],"Four")==0){
            p2_highest=4;
        }
        else if(strcmp(player2[row][column],"Five")==0){
            p2_highest=5;
        }
        else if(strcmp(player2[row][column],"Six")==0){
            p2_highest=6;
        }
        else if(strcmp(player2[row][column],"Seven")==0){
            p2_highest=7;
        }
        else if(strcmp(player2[row][column],"Eight")==0){
            p2_highest=8;
        }
        else if(strcmp(player2[row][column],"Nine")==0){
            p2_highest=9;
        }
        else if(strcmp(player2[row][column],"Ten")==0){
            p2_highest=10;
        }
        else if(strcmp(player2[row][column],"Jack")==0){
            p2_highest=11;
        }
        else if(strcmp(player2[row][column],"Queen")==0){
            p2_highest=12;
        }
        else if(strcmp(player2[row][column],"King")==0){
            p2_highest=13;
        }
        else if(strcmp(player2[row][column],"Ace")==0){
            p2_highest=14;
        }

        ++row;
    }
    // Determine winner based on highest card value
    if(p1_highest>p2_highest){
        printf("\nPlayer 1 wins!");
    }
    else if(p2_highest>p1_highest){
        printf("\nPlayer 2 wins!");
    }
    else{
        printf("\nIt's a tie!");
    }
}

int main(){
    int deck[4][13]={0};
    srand(time(NULL)); // Seed the random number generator

    //Initialize and populate deck
    for(int row=0;row<4;++row){
        for(int column=0;column<13;++column){
            deck[row][column]=column+13*row;
        }
    }

    shuffleDeck(deck); // Randomize the deck

    const int numCards=10; // Each player gets 5 cards
    char *player1[numCards/2][2]; // 2D array to store player 1's cards
    char *player2[numCards/2][2]; // 2D array to store player 2's cards

    dealCards(faces,suits,deck,player1,player2,numCards); // Deal the cards

    printCards(player1,numCards); // Print each player's cards

    determineWinner(player1,player2,numCards); // Determine the winner based on highest card value

    return 0;
}