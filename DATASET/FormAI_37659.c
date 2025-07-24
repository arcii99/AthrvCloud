//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: shape shifting
#include <stdio.h>

// Function to draw the Tic Tac Toe game board
void drawBoard(char board[][3]){
    printf("\n     0   1   2\n\n");
    for(int i=0;i<3;i++){
        printf("%d   ",i);
        for(int j=0;j<3;j++){
            if(j==2){
                printf("%c ", board[i][j]);
                continue;
            }
            printf("%c | ", board[i][j]);
        }
        if(i==2){
            printf("\n");
            continue;
        }
        printf("\n    -----------\n");
    }
}

// Function to check if a player has won the game
int checkWin(char board[][3], char player){
    // Check all rows
    for(int i=0;i<3;i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return 1;
        }
    }
    // Check all columns
    for(int j=0;j<3;j++){
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player){
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return 1;
    }
    return 0;
}

// Function to make the computer's move
void computerMove(char board[][3], char computer, char player){
    // Check for winning moves in rows
    for(int i=0;i<3;i++){
        if(board[i][0] == board[i][1] && board[i][0] == computer && board[i][2] == ' '){
            board[i][2] = computer;
            return;
        }
        if(board[i][0] == board[i][2] && board[i][0] == computer && board[i][1] == ' '){
            board[i][1] = computer;
            return;
        }
        if(board[i][1] == board[i][2] && board[i][1] == computer && board[i][0] == ' '){
            board[i][0] = computer;
            return;
        }
    }
    // Check for winning moves in columns
    for(int j=0;j<3;j++){
        if(board[0][j] == board[1][j] && board[0][j] == computer && board[2][j] == ' '){
            board[2][j] = computer;
            return;
        }
        if(board[0][j] == board[2][j] && board[0][j] == computer && board[1][j] == ' '){
            board[1][j] = computer;
            return;
        }
        if(board[1][j] == board[2][j] && board[1][j] == computer && board[0][j] == ' '){
            board[0][j] = computer;
            return;
        }
    }
    // Check for winning moves in the diagonals
    if(board[0][0] == board[1][1] && board[0][0] == computer && board[2][2] == ' '){
        board[2][2] = computer;
        return;
    }
    if(board[0][0] == board[2][2] && board[0][0] == computer && board[1][1] == ' '){
        board[1][1] = computer;
        return;
    }
    if(board[1][1] == board[2][2] && board[1][1] == computer && board[0][0] == ' '){
        board[0][0] = computer;
        return;
    }
    if(board[0][2] == board[1][1] && board[0][2] == computer && board[2][0] == ' '){
        board[2][0] = computer;
        return;
    }
    if(board[0][2] == board[2][0] && board[0][2] == computer && board[1][1] == ' '){
        board[1][1] = computer;
        return;
    }
    if(board[1][1] == board[2][0] && board[1][1] == computer && board[0][2] == ' '){
        board[0][2] = computer;
        return;
    }
    // Block player from winning in rows
    for(int i=0;i<3;i++){
        if(board[i][0] == board[i][1] && board[i][0] == player && board[i][2] == ' '){
            board[i][2] = computer;
            return;
        }
        if(board[i][0] == board[i][2] && board[i][0] == player && board[i][1] == ' '){
            board[i][1] = computer;
            return;
        }
        if(board[i][1] == board[i][2] && board[i][1] == player && board[i][0] == ' '){
            board[i][0] = computer;
            return;
        }
    }
    // Block player from winning in columns
    for(int j=0;j<3;j++){
        if(board[0][j] == board[1][j] && board[0][j] == player && board[2][j] == ' '){
            board[2][j] = computer;
            return;
        }
        if(board[0][j] == board[2][j] && board[0][j] == player && board[1][j] == ' '){
            board[1][j] = computer;
            return;
        }
        if(board[1][j] == board[2][j] && board[1][j] == player && board[0][j] == ' '){
            board[0][j] = computer;
            return;
        }
    }
    // Block player from winning in the diagonals
    if(board[0][0] == board[1][1] && board[0][0] == player && board[2][2] == ' '){
        board[2][2] = computer;
        return;
    }
    if(board[0][0] == board[2][2] && board[0][0] == player && board[1][1] == ' '){
        board[1][1] = computer;
        return;
    }
    if(board[1][1] == board[2][2] && board[1][1] == player && board[0][0] == ' '){
        board[0][0] = computer;
        return;
    }
    if(board[0][2] == board[1][1] && board[0][2] == player && board[2][0] == ' '){
        board[2][0] = computer;
        return;
    }
    if(board[0][2] == board[2][0] && board[0][2] == player && board[1][1] == ' '){
        board[1][1] = computer;
        return;
    }
    if(board[1][1] == board[2][0] && board[1][1] == player && board[0][2] == ' '){
        board[0][2] = computer;
        return;
    }
    // Make a random move if no winning or blocking move is available
    int row, col;
    do{
        row = rand() % 3;
        col = rand() % 3;
    }while(board[row][col] != ' ');
    board[row][col] = computer;
}

// Function to play Tic Tac Toe game
void playTicTacToe(){
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int turn = 0;
    char player, computer;

    // Randomly assign X or O to player and computer
    if(rand() % 2 == 0){
        player = 'X';
        computer = 'O';
    }
    else{
        player = 'O';
        computer = 'X';
    }

    while(turn < 9){
        // Draw the game board
        drawBoard(board);
        // Print the player's turn
        if(turn % 2 == 0){
            printf("\nPlayer's Turn (%c)\n", player);
            int row, col;
            do{
                printf("Enter row (0-2): ");
                scanf("%d", &row);
                printf("Enter column (0-2): ");
                scanf("%d", &col);
            }while(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');
            board[row][col] = player;
            if(checkWin(board, player)){
                printf("\nCongratulations! You won the game!\n");
                return;
            }
        }
        // Computer's turn
        else{
            printf("\nComputer's Turn (%c)\n", computer);
            computerMove(board, computer, player);
            if(checkWin(board, computer)){
                printf("\nOops! You lost the game!\n");
                return;
            }
        }
        turn++;
    }
    // If all the cells are filled and no player has won, the game is tied
    drawBoard(board);
    printf("\nGame Tied!\n");
}

// Main function
int main(){
    while(1){
        printf("\n***Tic Tac Toe***\n\n");
        playTicTacToe();
        char choice;
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &choice);
        if(choice != 'Y' && choice != 'y'){
            break;
        }
    }
    return 0;
}