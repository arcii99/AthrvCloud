//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int bingo[5][5] = {0};
    int chosenNumbers[25] = {0};
    int randomNumber, x, y;
    char name[20];

    printf("Welcome to C Bingo Simulator! Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! Let's start the game!\n\n", name);
    
    //initialize random number generator
    srand(time(NULL));

    //populate the bingo card with random numbers
    for(x=0; x<5; x++){
        for(y=0; y<5; y++){
            if(x==2 && y==2){
                //free space
                bingo[x][y] = -1;
            }else{
                //generate random number (between 1 and 75) and check if it's already on the card
                do{
                    randomNumber = rand() % 75 + 1;
                }while(numberIsAlreadyOnCard(randomNumber, bingo));
                
                bingo[x][y] = randomNumber;
            }
        }
    }

    //print the bingo card
    printf("Here is your bingo card, %s:\n", name);
    printBingoCard(bingo);

    //start the game
    int turns = 0;
    int gameOver = 0;
    while(!gameOver){
        turns++;
        printf("\n\nTurn %d: ", turns);
        
        //generate random number (between 1 and 75) and check if it's already been called
        do{
            randomNumber = rand() % 75 + 1;
        }while(numberHasBeenCalled(randomNumber, chosenNumbers));
        
        printf("Number %d has been called!\n", randomNumber);

        //update the card with the called number
        updateBingoCard(randomNumber, bingo);

        //print the updated card
        printf("\nUpdated bingo card:\n");
        printBingoCard(bingo);
        
        //check for a win
        if(checkForWin(bingo)){
            printf("\n\nBINGO! %s has won the game in %d turns!", name, turns);
            gameOver = 1;
        }else if(turns == 75){
            printf("\n\nGAME OVER! The maximum number of turns has been reached. Nobody has won :(");
            gameOver = 1;
        }

        //add the called number to the list of chosen numbers
        chosenNumbers[turns-1] = randomNumber;
    }

    return 0;
}

//function to check if a number is already on the bingo card
int numberIsAlreadyOnCard(int number, int bingo[5][5]){
    int x, y;

    for(x=0; x<5; x++){
        for(y=0; y<5; y++){
            if(bingo[x][y] == number){
                return 1;
            }
        }
    }

    return 0;
}

//function to print the bingo card
void printBingoCard(int bingo[5][5]){
    int x, y;

    for(x=0; x<5; x++){
        for(y=0; y<5; y++){
            if(bingo[x][y] == -1){
                //free space
                printf("[   ]");
            }else{
                printf("[%2d]", bingo[x][y]);
            }
        }
        printf("\n");
    }
}

//function to check if a number has already been called
int numberHasBeenCalled(int number, int chosenNumbers[]){
    int i;

    for(i=0; i<25; i++){
        if(chosenNumbers[i] == number){
            return 1;
        }
    }

    return 0;
}

//function to update the bingo card with the called number
void updateBingoCard(int number, int bingo[5][5]){
    int x, y;

    for(x=0; x<5; x++){
        for(y=0; y<5; y++){
            if(bingo[x][y] == number){
                bingo[x][y] = -2; //mark as called
            }
        }
    }
}

//function to check for a win
int checkForWin(int bingo[5][5]){
    int x, y, row, col, diag1=0, diag2=0;

    //check rows and columns
    for(row=0; row<5; row++){
        for(col=0; col<5; col++){
            if(bingo[row][col] != -2){
                break;
            }
        }
        if(col == 5){
            return 1; //win by row
        }
        
        for(col=0; col<5; col++){
            if(bingo[col][row] != -2){
                break;
            }
        }
        if(col == 5){
            return 1; //win by column
        }
    }

    //check diagonals
    for(x=0; x<5; x++){
        if(bingo[x][x] != -2){
            break;
        }
    }
    if(x == 5){
        return 1; //win by diagonal
    }
    
    for(x=0; x<5; x++){
        if(bingo[x][4-x] != -2){
            break;
        }
    }
    if(x == 5){
        return 1; //win by diagonal
    }

    return 0; //no win yet
}