//FormAI DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the current board
void display_board(int board[][3]){
    printf("\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int p1_score=0, p2_score=0;     // Keeping track of points for each player
    int p1_turn=1;                  // Firstly, it's player 1's turn
    int round=1;                    // Keeping track of rounds
    srand(time(NULL));             
    
    printf("Let's Play Table Game!\n");
    printf("Two players play this game. Each player gets three turns in one round.\n");
    printf("The game has total three rounds. The one who scores more points wins the game.\n");

    printf("\nInstructions:\n");
    printf("You will see a 3x3 board. Each cell of the board will have a number.\n");
    printf("Player 1 will choose a number between 1-9, where Player 2 will choose a number at random.\n");
    printf("If any two cells have the same number, then Player 1 will score 1 point.\n");

    // Loop for rounds
    for(int r=1; r<=3; r++){
        printf("\n\nROUND %d\n\n",r);
        int board[3][3];
        int nums[9]={0};    // Array to keep track of numbers already chosen

        // Generate random numbers for each cell of the board
        int num=1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int index=rand()%9;
                while(nums[index]!=0) index=rand()%9;
                board[i][j]=num+index;
                nums[index]=1;
                num++;
            }
        }
        display_board(board);

        // Loop for taking player input and checking for matching cells
        for(int t=1;t<=3;t++){
            printf("\nPlayer %d's Turn:\n",p1_turn);
            printf("Enter a number between 1-9: ");
            int chosen_num;
            scanf("%d",&chosen_num);
            while(chosen_num<1 || chosen_num>9){
                printf("Invalid input. Enter a number between 1-9: ");
                scanf("%d",&chosen_num);
            }
            int match=0;    // Checking for match
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(board[i][j]==chosen_num){
                        board[i][j]=0;  // Removing the matched number from the board
                        match=1;
                        break;
                    }
                }
                if(match==1) break;
            }
            if(match==1){
                if(p1_turn==1) p1_score++;
                else p2_score++;
                printf("You got a match!\n");
            }
            else{
                printf("No match. Better luck next time!\n");
            }

            display_board(board);
            p1_turn=p1_turn%2+1;    // Switching turns between 1 and 2
        }
        printf("\nROUND %d OVER!\n",r);
        printf("Player 1's Score: %d\n",p1_score);
        printf("Player 2's Score: %d\n",p2_score);
        round++;
    }

    // Declaring the winner
    printf("\nGAME OVER!\n");
    printf("Player %d wins with a score of %d!",p1_score>p2_score?1:2,p1_score>p2_score?p1_score:p2_score);
    return 0;
}