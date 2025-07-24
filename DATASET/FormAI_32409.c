//FormAI DATASET v1.0 Category: Memory Game ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 4

void initializeBoard(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE]);
void shuffleCards(int arr[],int n);
void shuffleBoard(int board[SIZE][SIZE]);
int isGameOver(int board[SIZE][SIZE]);
int revealCard(int board[SIZE][SIZE],int x, int y);
void playGame(int board[SIZE][SIZE]);

int main(){
    int board[SIZE][SIZE];
    initializeBoard(board);
    shuffleBoard(board);
    playGame(board);

    return 0;
}


void initializeBoard(int board[SIZE][SIZE]){
    int i,j,val=0;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            board[i][j]=val;
            val++;
            if(val>5){
                val=0;
            }
        }
    }
}

void printBoard(int board[SIZE][SIZE]){
    printf("---------------------\n");
    int i,j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if(board[i][j]==-1){
                printf("| * ");
            }
            else{
                printf("| %d ",board[i][j]);
            }
        }
        printf("|\n---------------------\n");
    }
}

void shuffleCards(int arr[],int n){
    srand(time(NULL));  // seed random number generator with current time

    int i, j, temp;
    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void shuffleBoard(int board[SIZE][SIZE]){
    int i,j;
    int numCards=SIZE*SIZE/2;

    int cards[numCards];

    for(i=0;i<numCards;i++){
        cards[i]=i;
    }

    shuffleCards(cards,numCards);

    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            board[i][j]=-1;
        }
    }

    int x,y;
    for(i=0;i<numCards;i++){
        x=rand()%SIZE;
        y=rand()%SIZE;

        while(board[x][y]!=-1){
            x=rand()%SIZE;
            y=rand()%SIZE;
        }

        board[x][y]=cards[i];
    }
}

int isGameOver(int board[SIZE][SIZE]){
    int i,j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if(board[i][j]==-1){
                return 0;
            }
        }
    }
    return 1;
}

// revealCard returns the value at the given position (x,y)
//  - if the position is already revealed, return -2
//  - if the position is out of bounds, return -1
// Otherwise, reveal the card and return its value
int revealCard(int board[SIZE][SIZE],int x, int y){
    if(x<0 || x>=SIZE || y<0 || y>=SIZE){
        return -1;
    }
    if(board[x][y]!=-1){
        return -2;
    }
    return board[x][y]=board[x][y];
}


void playGame(int board[SIZE][SIZE]){
    int x1,y1,x2,y2;

    printf("Welcome to the game. Please enter the row and column of the two cards you want to flip separated by a space (ex: 0 1):\n");

    while(!isGameOver(board)){

        printBoard(board);

        printf("Enter the position of the first card to flip: ");
        scanf("%d %d",&x1,&y1);

        while(revealCard(board,x1,y1)==-2){
            printf("Invalid choice. This card has already been flipped. Please choose another card.\n");
            printf("Enter the position of the first card to flip: ");
            scanf("%d %d",&x1,&y1);
        }

        printBoard(board);

        printf("Enter the position of the second card to flip: ");
        scanf("%d %d",&x2,&y2);

        while(revealCard(board,x2,y2)==-2 || (x1==x2 && y1==y2)){
            printf("Invalid choice. This card has already been flipped or it's the same as the first one. Please choose another card.\n");
            printf("Enter the position of the second card to flip: ");
            scanf("%d %d",&x2,&y2);
        }

        printBoard(board);

        if(board[x1][y1]==board[x2][y2]){
            board[x1][y1]=-2;
            board[x2][y2]=-2;
            printf("Great! You found a matching pair!\n");
        }
        else{
            printf("Sorry, these cards do not match.\n");
        }

    }

    printf("Congratulations! You've matched all the cards!\n");
}