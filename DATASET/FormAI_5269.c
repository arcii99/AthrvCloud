//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// A structure to hold player information
struct player {
    char name[20];
    int score;
    int numberCalled[75];
};

void wait(int seconds){
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}
}

void displayCard(int card[5][5]){
    printf("B   I   N   G   O\n");

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == 2 && j == 2)
                printf(" F  ");
            else
                printf("%2d  ", card[i][j]);
        }
        printf("\n");
    }
}

int checkBingo(int card[5][5], int calledNumbers[], struct player *p){
    int bingoCount = 0;

    // Checking for horizontal bingos
    for(int i = 0; i < 5; i++){
        int flag = 1;
        for(int j = 0; j < 5; j++){
            if(card[i][j] != calledNumbers[card[i][j]]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            printf("%s got a horizontal bingo!\n", p->name);
            p->score++;
            bingoCount++;
        }
    }

    // Checking for vertical bingos
    for(int i = 0; i < 5; i++){
        int flag = 1;
        for(int j = 0; j < 5; j++){
            if(card[j][i] != calledNumbers[card[j][i]]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            printf("%s got a vertical bingo!\n", p->name);
            p->score++;
            bingoCount++;
        }
    }

    // Checking for diagonal bingos
    if(card[0][0] == calledNumbers[card[0][0]] && card[1][1] == calledNumbers[card[1][1]] && card[3][3] == calledNumbers[card[3][3]] && card[4][4] == calledNumbers[card[4][4]]){
        printf("%s got a diagonal bingo!\n", p->name);
        p->score++;
        bingoCount++;
    }
    if(card[0][4] == calledNumbers[card[0][4]] && card[1][3] == calledNumbers[card[1][3]] && card[3][1] == calledNumbers[card[3][1]] && card[4][0] == calledNumbers[card[4][0]]){
        printf("%s got a diagonal bingo!\n", p->name);
        p->score++;
        bingoCount++;
    }

    return bingoCount;
}

int main(){
    // Initializing player objects
    struct player player1, player2;
    player1.score = 0;
    player2.score = 0;

    printf("Enter Player 1's Name: ");
    gets(player1.name);
    printf("Enter Player 2's Name: ");
    gets(player2.name);

    // Initializing the bingo card
    int card[5][5] = {{1,2,3,4,5},
                      {6,7,8,9,10},
                      {11,12,0,13,14},
                      {15,16,17,18,19},
                      {20,21,22,23,24}};

    // Generating a random sequence of numbers
    srand(time(NULL));
    int calledNumbers[75];
    for(int i = 0; i < 75; i++)
        calledNumbers[i] = i+1;
    for(int i = 0; i < 75; i++){
        int r = rand() % 75;
        int temp = calledNumbers[i];
        calledNumbers[i] = calledNumbers[r];
        calledNumbers[r] = temp;
    }

    // Starting the game
    int turnCount = 0;
    while(turnCount < 75){
        int number = calledNumbers[turnCount];

        printf("Number called: %d\n", number);
        wait(2);

        // Marking the called number on the card
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                if(card[i][j] == number){
                    card[i][j] = 0;
                    break;
                }
            }
        }

        // Displaying the updated card
        printf("\n%s's card:\n", player1.name);
        displayCard(card);

        // Checking for bingos
        int bingoCount = checkBingo(card, calledNumbers, &player1);
        if(bingoCount)
            printf("\n%s scored %d bingos!\n", player1.name, bingoCount);

        // Checking if the game is over
        if(player1.score >= 5){
            printf("%s wins the game! Congratulations!\n", player1.name);
            break;
        }

        // Displaying the updated card
        printf("\n%s's card:\n", player2.name);
        displayCard(card);

        // Checking for bingos
        bingoCount = checkBingo(card, calledNumbers, &player2);
        if(bingoCount)
            printf("\n%s scored %d bingos!\n", player2.name, bingoCount);

        // Checking if the game is over
        if(player2.score >= 5){
            printf("%s wins the game! Congratulations!\n", player2.name);
            break;
        }

        turnCount++;
    }

    return 0;
}