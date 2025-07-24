//FormAI DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int table[10][10];
    int row,col;
    int player1_score=0, player2_score=0;
    int turn = 1, chance = 0;
    char c;
    srand(time(NULL)); // to set random number seed
    
    // filling the table with random numbers from 1-50
    for(row=0; row<10; row++){
        for(col=0; col<10; col++){
            table[row][col] = rand()%50+1;
        }
    }
    
    printf("\t\t\t\tC Table Game\n\n");
    
    // game play
    do{
        printf("\nIt's Player %d's turn. Press any key to continue.",turn);
        scanf("%c",&c); // to wait until player presses any key
        system("clear"); // to clear the console window
        
        // printing the table
        printf("\n");
        for(row=0; row<10; row++){
            printf("\t");
            for(col=0; col<10; col++){
                printf("%d ",table[row][col]);
            }
            printf("\n");
        }
        
        // taking input from the player on which row to choose
        printf("\nPlayer %d, Enter the row number to choose (0-9): ", turn);
        scanf("%d",&row);
        
        // validating row input
        while(row>=10 || row<0){
            printf("\nInvalid Input! Enter the row number to choose (0-9): ");
            scanf("%d",&row);
        }
        
        // taking input from the player on which column to choose
        printf("\nPlayer %d, Enter the column number to choose (0-9): ", turn);
        scanf("%d",&col);
        
        // validating column input
        while(col>=10 || col<0){
            printf("\nInvalid Input! Enter the column number to choose (0-9): ");
            scanf("%d",&col);
        }
        
        // checking if the chosen number is already taken
        while(table[row][col] == 0){
            printf("\nThis number has already been chosen! Pick another row and column.\n");
            printf("\nPlayer %d, Enter the row number to choose (0-9): ", turn);
            scanf("%d",&row);
            printf("\nPlayer %d, Enter the column number to choose (0-9): ", turn);
            scanf("%d",&col);
        }
        
        // updating score of the player
        if(chance == 0){
            player1_score += table[row][col];
            printf("\nCongratulations Player %d, you have won %d points!\n", turn, table[row][col]);
            chance = 1; // invite player 2 for the next turn
        }
        else{
            player2_score += table[row][col];
            printf("\nCongratulations Player %d, you have won %d points!\n", turn, table[row][col]);
            chance = 0; // invite player 1 for the next turn
            // increment turn number after each of player 2's turn
            turn++;
        }
        
        // mark the chosen slot as taken (here, we are setting it to 0)
        table[row][col] = 0;
        
    }while(turn<=2 && chance==1); // play the game until both players have played two turns
    
    // declaring the winner after two turns each
    printf("\n\nPlayer 1: %d", player1_score);
    printf("\nPlayer 2: %d", player2_score);
    
    if(player1_score > player2_score) printf("\n\nPlayer 1 wins the game with a score of %d!", player1_score);
    else if(player2_score > player1_score) printf("\n\nPlayer 2 wins the game with a score of %d!", player2_score);
    else printf("\n\nIt's a tie game!");
    
    return 0;
}