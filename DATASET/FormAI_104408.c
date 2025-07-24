//FormAI DATASET v1.0 Category: Checkers Game ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

int main(){

    printf("Welcome to Checkers Game! \n");

    printf("\t   A B C D E F G H\n");
    printf("\t  ----------------\n");
    for(int i=0; i<8; i++){
        printf("\t%d|",i+1);
        for(int j=0; j<8; j++){
            if(i%2 == 0){
                if(j%2==0){
                    printf("  ");
                }else{
                    printf("##");
                }
            }else{
                if(j%2==0){
                    printf("##");
                }else{
                    printf("  ");
                }
            }
        }
        printf("|%d\n",i+1);
    }
    printf("\t  ----------------\n");
    printf("\t   A B C D E F G H\n");
    printf("\n");
    printf("The pieces are represented as follows: \n");
    printf("* for Player 1, O for Player 2 \n");

    char board[8][8] = {
        {' ','*',' ','*',' ','*',' ','*'},
        {'*',' ','*',' ','*',' ','*',' '},
        {' ','*',' ','*',' ','*',' ','*'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'O',' ','O',' ','O',' ','O',' '},
        {' ','O',' ','O',' ','O',' ','O'},
        {'O',' ','O',' ','O',' ','O',' '}
    };

    int playerTurn = 1;

    while(1){
        printf("\n *** Player %d Turn *** \n",playerTurn);

        //Print the current board
        printf("\t   A B C D E F G H\n");
        printf("\t  ----------------\n");
        for(int i=0; i<8; i++){
            printf("\t%d|",i+1);
            for(int j=0; j<8; j++){
                printf("%c ",board[i][j]);
            }
            printf("|%d\n",i+1);
        }
        printf("\t  ----------------\n");
        printf("\t   A B C D E F G H\n");

        //Get user's move
        int fromRow, fromCol, toRow, toCol;
        printf("\nEnter the piece row and column you want to move: ");
        scanf("%d%d",&fromRow,&fromCol);
        printf("Enter the position row and column you want to move to: ");
        scanf("%d%d",&toRow,&toCol);

        //Check if the move is valid
        if(fromRow<0 || fromRow>7 || fromCol<0 || fromCol>7 || toRow<0 || toRow>7 || toCol<0 || toCol>7){
            printf("Invalid move! Please enter again. \n");
            continue;
        }
        if(board[fromRow][fromCol] == ' '){
            printf("Invalid move! Please enter again. \n");
            continue;
        }
        if(board[toRow][toCol] != ' '){
            printf("Invalid move! Please enter again. \n");
            continue;
        }
        if(playerTurn == 1 && (board[fromRow][fromCol] != '*' && board[fromRow][fromCol] != 'K')){
            printf("Invalid move! Please enter again. \n");
            continue;
        }
        if(playerTurn == 2 && (board[fromRow][fromCol] != 'O' && board[fromRow][fromCol] != 'k')){
            printf("Invalid move! Please enter again. \n");
            continue;
        }
        int diffRow = toRow - fromRow;
        int diffCol = toCol - fromCol;
        if(diffRow<0) diffRow = -diffRow;
        if(diffCol<0) diffCol = -diffCol;
        if(diffRow != diffCol){
            printf("Invalid move! Please enter again. \n");
            continue;
        }
        if(diffRow>2){
            printf("Invalid move! Please enter again. \n");
            continue;
        }
        if(diffRow<2 && playerTurn == 1){
            printf("Invalid move! Please enter again. \n");
            continue;
        }
        if(diffRow<2 && playerTurn == 2){
            printf("Invalid move! Please enter again. \n");
            continue;
        }
        if(diffRow==2){
            int captureRow = (fromRow+toRow)/2;
            int captureCol = (fromCol+toCol)/2;
            if(playerTurn == 1 && board[captureRow][captureCol] != 'O' && board[captureRow][captureCol] != 'k'){ 
                printf("Invalid move! Please enter again. \n");
                continue;
            }
            if(playerTurn == 2 && board[captureRow][captureCol] != '*' && board[captureRow][captureCol] != 'K'){ 
                printf("Invalid move! Please enter again. \n");
                continue;
            }
            board[captureRow][captureCol] = ' ';
        }

        //Move the piece
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = ' ';

        //Check if a piece becomes a king
        if(playerTurn == 1 && toRow == 0 && board[toRow][toCol] == '*'){
            board[toRow][toCol] = 'K';
        }
        if(playerTurn == 2 && toRow == 7 && board[toRow][toCol] == 'O'){
            board[toRow][toCol] = 'k';
        }

        //Check if the game is over
        int player1Pieces = 0;
        int player2Pieces = 0;
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(board[i][j] == '*' || board[i][j] == 'K'){
                    player1Pieces++;
                }else if(board[i][j] == 'O' || board[i][j] == 'k'){
                    player2Pieces++;
                }
            }
        }
        if(player1Pieces == 0){
            printf("\n *** Player 2 wins! *** \n");
            break;
        }
        if(player2Pieces == 0){
            printf("\n *** Player 1 wins! *** \n");
            break;
        }

        //Switch player turn
        if(playerTurn == 1){
            playerTurn = 2;
        }else{
            playerTurn = 1;
        }
    }

    return 0;
}