//FormAI DATASET v1.0 Category: Checkers Game ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 8 // Size of the checkers board
#define BLACK_PIECE 'x' // Symbol for black piece
#define WHITE_PIECE 'o' // Symbol for white piece
#define EMPTY_SPACE '-' // Symbol for empty space


// Structure to represent each location in the board
typedef struct location{
    int row;
    int col;
} Location;

// Function to initialize the board with empty spaces and black and white pieces
void initializeBoard(char board[][SIZE]){
    int i, j;

    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            if((i+j)%2 == 0){ // Only alternate locations are valid for checkers
                if(i < 3){ // Top 3 rows will have black pieces
                    board[i][j] = BLACK_PIECE;
                }else if(i > 4){ // Bottom 3 rows will have white pieces
                    board[i][j] = WHITE_PIECE;
                }else{
                    board[i][j] = EMPTY_SPACE;
                }
            }else{
                board[i][j] = EMPTY_SPACE;
            }
        }
    }   
}

// Function to print the board
void printBoard(char board[][SIZE]){
    int i, j;

    printf("\n      ");
    for(i=0; i<SIZE; i++){
        printf(" %c   ", i+'A');
    }

    printf("\n   ---------------------------------\n");

    for(i=0; i<SIZE; i++){
        printf(" %d | ", i+1);
        for(j=0; j<SIZE; j++){
            printf("%c | ", board[i][j]);
        }
        printf("%d\n", i+1);
        printf("   ---------------------------------\n");
    }

    printf("      ");
    for(i=0; i<SIZE; i++){
        printf(" %c   ", i+'A');
    }
    printf("\n\n");
}

// Function to check if two locations are adjacent
int isAdjacent(Location location1, Location location2){
    int rowDiff = location1.row - location2.row;
    int colDiff = location1.col - location2.col;

    if(rowDiff == -1 || rowDiff == 1){ // Both locations are in adjacent rows
        if(colDiff == -1 || colDiff == 1){ // Both locations are in adjacent columns
            return 1;
        }
    }

    return 0;
}

// Function to check if a selected piece can make a valid move
int isValidMove(char board[][SIZE], Location currentLoc, Location targetLoc, char player){
    // Check if target location is valid
    if(targetLoc.row < 0 || targetLoc.row >= SIZE || targetLoc.col < 0 || targetLoc.col >= SIZE){ 
        return 0;
    }

    // Check if target location is empty
    if(board[targetLoc.row][targetLoc.col] != EMPTY_SPACE){ 
        return 0;
    }

    // Check if the current player can move in the diagonal direction
    int rowDiff = targetLoc.row - currentLoc.row;
    int colDiff = targetLoc.col - currentLoc.col;
    if(player == BLACK_PIECE){ // Black pieces can only move upwards
        if(rowDiff != -1 || abs(colDiff) != 1){ 
            return 0;
        }
    }else{ // White pieces can only move downwards
        if(rowDiff != 1 || abs(colDiff) != 1){ 
            return 0;
        }
    }

    return 1;
}

// Function to check if any piece of the player can jump over another piece
int canJump(char board[][SIZE], Location currentLoc, char player){
    int i;
    Location tempLoc;
    
    // Check diagonal locations from the current piece
    for(i=-1; i<=1; i+=2){
        tempLoc.row = currentLoc.row + 2 * (player==BLACK_PIECE? -1 : 1); // New location is two rows away in diagonal
        tempLoc.col = currentLoc.col + 2 * i; // New location is two columns away in diagonal

        // Check if the target location is valid and there is a piece in between
        if(tempLoc.row >= 0 && tempLoc.row < SIZE && tempLoc.col >= 0 && tempLoc.col < SIZE){
            Location obstacleLoc = {(currentLoc.row+tempLoc.row)/2, (currentLoc.col+tempLoc.col)/2};
            if(board[tempLoc.row][tempLoc.col] == EMPTY_SPACE && 
               board[obstacleLoc.row][obstacleLoc.col] == (player==BLACK_PIECE? WHITE_PIECE : BLACK_PIECE)){ // Player can jump over the obstacle
                return 1;
            }
        }
    }

    return 0;
}

// Function to check if the player has any valid moves remaining
int hasValidMoves(char board[][SIZE], char player){
    int i, j;

    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            if(board[i][j] == player){ // Valid moves can only be made by the current player's pieces
                Location currentLoc = {i, j};
                if(canJump(board, currentLoc, player)){ // Check if the current piece can jump over another piece
                    return 1;
                }else{
                    Location tempLoc;
                    int k;
                    for(k=-1; k<=1; k+=2){ // Check diagonal moves
                        tempLoc.row = currentLoc.row + (player==BLACK_PIECE? -1 : 1);
                        tempLoc.col = currentLoc.col + k;
                        if(isValidMove(board, currentLoc, tempLoc, player)){ // Check if the move is valid
                            return 1;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

// Function to perform the move
void movePiece(char board[][SIZE], Location currentLoc, Location targetLoc){
    board[targetLoc.row][targetLoc.col] = board[currentLoc.row][currentLoc.col]; // Move the current piece to the target location
    board[currentLoc.row][currentLoc.col] = EMPTY_SPACE; // Set the current location to empty
}

// Function to remove the piece that the player's piece has jumped over
void removeObstacle(char board[][SIZE], Location currentLoc, Location targetLoc){
    int rowDiff = targetLoc.row - currentLoc.row;
    int colDiff = targetLoc.col - currentLoc.col;
    Location obstacleLoc = {currentLoc.row+rowDiff/2, currentLoc.col+colDiff/2}; // Location of the piece that was jumped over

    board[obstacleLoc.row][obstacleLoc.col] = EMPTY_SPACE; // Set the obstacle location to empty
}

// Function to check if the player has won
int hasWon(char board[][SIZE], char player){
    int i, j;

    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            if(board[i][j] == (player==BLACK_PIECE? WHITE_PIECE : BLACK_PIECE)){ // If there is at least 1 piece of the other player still remaining
                return 0;
            }
        }
    }

    return 1; // If all pieces of the other player are eliminated, the current player has won
}

int main(){
    char board[SIZE][SIZE];
    char currentPlayer = BLACK_PIECE;
    int gameRunning = 1;
    Location selectedLoc, targetLoc;

    initializeBoard(board);

    printf("Welcome to Checkers!\n\n");
    printBoard(board);

    while(gameRunning){
        printf("%c's turn:\n", currentPlayer);
        
        selectedLoc.row = -1;
        selectedLoc.col = -1;

        // Get the input for the selected piece and make sure it is valid
        while(selectedLoc.row == -1 || selectedLoc.col == -1 || board[selectedLoc.row][selectedLoc.col] != currentPlayer){
            printf("Enter the row and column of the piece you want to move (ex: 4A): ");
            char input[5];
            scanf("%s", input);
            selectedLoc.col = input[1] - 'A';
            selectedLoc.row = atoi(input+2) - 1;

            if(selectedLoc.row < 0 || selectedLoc.row >= SIZE || selectedLoc.col < 0 || selectedLoc.col >= SIZE || board[selectedLoc.row][selectedLoc.col] != currentPlayer){
                printf("Invalid input! Please try again.\n");
            }
        }

        // Get the input for the target location and make sure it is valid
        int validMove = 0;
        while(!validMove){
            targetLoc.row = -1;
            targetLoc.col = -1;

            printf("Enter the row and column of the target location (ex: 5B): ");
            char input[5];
            scanf("%s", input);
            targetLoc.col = input[1] - 'A';
            targetLoc.row = atoi(input+2) - 1;

            if(!isValidMove(board, selectedLoc, targetLoc, currentPlayer)){
                printf("Invalid move! Please try again.\n");
            }else{
                if(abs(targetLoc.row-selectedLoc.row) == 2){ // If the move is a jump, remove the piece in the middle
                    removeObstacle(board, selectedLoc, targetLoc);
                }
                movePiece(board, selectedLoc, targetLoc); // Move the piece to the target location
                validMove = 1; // Exit the loop if the move is valid
            }
        }

        printBoard(board);

        if(hasWon(board, currentPlayer)){ // Check if the current player has won
            printf("%c has won the game!\n", currentPlayer);
            gameRunning = 0;
        }else if(!hasValidMoves(board, currentPlayer)){ // Check if the current player has any valid moves left
            printf("%c doesn't have any valid moves left and has lost the game!\n", currentPlayer);
            gameRunning = 0;
        }else{
            currentPlayer = currentPlayer == BLACK_PIECE? WHITE_PIECE : BLACK_PIECE; // Switch the current player if the game is still ongoing
        }
    }

    return 0;
}