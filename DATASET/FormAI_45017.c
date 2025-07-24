//FormAI DATASET v1.0 Category: Chess engine ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// This Chess engine is called "The Jester's Gambit". It's guaranteed to make you laugh, or your money back!

int main(){

    char board[8][8] = { // Initializing chess board with piece placement
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };
    
    srand(time(0)); // Initializing random number generator with current time
    
    printf("Welcome to The Jester's Gambit Chess Engine!\n\n");
    
    while(1){ // The game loop
        
        printf("Here's the current board:\n\n");
        
        for(int i=0; i<8; i++){ // Displaying the chess board with piece placement
            for(int j=0; j<8; j++){
                
                if(board[i][j] == '.'){ // Randomly filling blank spaces with emojis

                    int emoji = rand()%5;

                    switch(emoji){
                        case 0:
                            printf("😀 ");
                            break;
                        case 1:
                            printf("🤣 ");
                            break;
                        case 2:
                            printf("😎 ");
                            break;
                        case 3:
                            printf("👑 ");
                            break;
                        case 4:
                            printf("🤔 ");
                            break;
                    }
                    
                } else{ // Displaying chess piece
                    printf("%c ", board[i][j]);
                }
                
            }
            printf("\n");
        }
        
        printf("\nIt's your turn! Type in your move:\n"); // Prompting player to make a move
        
        char player_move[5]; // The player's move
        
        scanf("%s", player_move);
        
        printf("\n\nHaha! You fell for my trap! I move my pawn to d5!\n\n"); // The Jester making a joke
        
    }
    
    return 0;
}