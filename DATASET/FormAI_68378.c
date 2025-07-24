//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//function to generate random numbers for Bingo card
void generateCard(int card[][5]){
    srand(time(NULL));
    int count = 0;
    int nums[] = {1,2,3,4,5,6,7,8,9};

    //generate 5 random numbers for each column
    for(int col=0; col<5; col++){
        //shuffle the numbers for each column
        for(int i=0; i<9; i++){
            int r = rand() % 9;
            int temp = nums[i];
            nums[i] = nums[r];
            nums[r] = temp;
        }
        //assign numbers to each row of the column
        for(int row=0; row<5; row++){
            if(count == 12) //middle cell should be empty
                card[row][col] = 0;
            else
                card[row][col] = nums[count];
            count++;
        }
    }
}

//function to print the Bingo card
void printCard(int card[][5]){
    printf("\n");
    printf(" B   I   N   G   O\n");
    for(int row=0; row<5; row++){
        for(int col=0; col<5; col++){
            if(card[row][col] == 0)
                printf(" - ");
            else
                printf("%2d ", card[row][col]);
        }
        printf("\n");
    }
}

//function to check for a Bingo
int checkBingo(int card[][5]){
    int rowSum, colSum, diagSum1=0, diagSum2=0;
    //check rows for Bingo
    for(int row=0; row<5; row++){
        rowSum = 0;
        for(int col=0; col<5; col++)
            rowSum += card[row][col];
        if(rowSum == 0) //Bingo found
            return 1;
    }
    //check columns for Bingo
    for(int col=0; col<5; col++){
        colSum = 0;
        for(int row=0; row<5; row++)
            colSum += card[row][col];
        if(colSum == 0) //Bingo found
            return 1;
    }
    //check diagonals for Bingo
    for(int row=0; row<5; row++){
        diagSum1 += card[row][row];
        diagSum2 += card[row][4-row];
    }
    if(diagSum1 == 0 || diagSum2 == 0) //Bingo found
        return 1;

    return 0; //no Bingo yet
}


int main(){
    //initialize Bingo card
    int card[5][5];
    generateCard(card);
    printCard(card);

    //start Bingo game
    int num, row, col;
    while(1){
        printf("\nEnter a number (1-9), 0 to quit: ");
        scanf("%d", &num);
        if(num == 0)
            break;
        //check if number is on the card
        int found = 0;
        for(row=0; row<5; row++){
            for(col=0; col<5; col++){
                if(card[row][col] == num){
                    card[row][col] = 0; //mark number as found
                    found = 1;
                    break;
                }
            }
            if(found)
                break;
        }
        if(found)
            printCard(card);
        else
            printf("Number not found on card.\n");
        //check for Bingo
        if(checkBingo(card)){
            printf("\nBingo! You win!\n");
            break;
        }
    }

    return 0;
}