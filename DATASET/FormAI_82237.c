//FormAI DATASET v1.0 Category: Checkers Game ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#define SIZE 8

//Struct to represent each cell on the board
struct Cell {
    int x;
    int y;
    char value;
};

//Initializing the board
struct Cell board[SIZE][SIZE] = {
        {{0,0}, 'O'}, {{0,1}, ' '}, {{0,2}, 'O'}, {{0,3}, ' '}, {{0,4}, 'O'}, {{0,5}, ' '}, {{0,6}, 'O'}, {{0,7}, ' '},
        {{1,0}, ' '}, {{1,1}, 'O'}, {{1,2}, ' '}, {{1,3}, 'O'}, {{1,4}, ' '}, {{1,5}, 'O'}, {{1,6}, ' '}, {{1,7}, 'O'},
        {{2,0}, 'O'}, {{2,1}, ' '}, {{2,2}, 'O'}, {{2,3}, ' '}, {{2,4}, 'O'}, {{2,5}, ' '}, {{2,6}, 'O'}, {{2,7}, ' '},
        {{3,0}, ' '}, {{3,1}, ' '}, {{3,2}, ' '}, {{3,3}, ' '}, {{3,4}, ' '}, {{3,5}, ' '}, {{3,6}, ' '}, {{3,7}, ' '},
        {{4,0}, ' '}, {{4,1}, ' '}, {{4,2}, ' '}, {{4,3}, ' '}, {{4,4}, ' '}, {{4,5}, ' '}, {{4,6}, ' '}, {{4,7}, ' '},
        {{5,0}, 'X'}, {{5,1}, ' '}, {{5,2}, 'X'}, {{5,3}, ' '}, {{5,4}, 'X'}, {{5,5}, ' '}, {{5,6}, 'X'}, {{5,7}, ' '},
        {{6,0}, ' '}, {{6,1}, 'X'}, {{6,2}, ' '}, {{6,3}, 'X'}, {{6,4}, ' '}, {{6,5}, 'X'}, {{6,6}, ' '}, {{6,7}, 'X'},
        {{7,0}, 'X'}, {{7,1}, ' '}, {{7,2}, 'X'}, {{7,3}, ' '}, {{7,4}, 'X'}, {{7,5}, ' '}, {{7,6}, 'X'}, {{7,7}, ' '}
};

//Function to print the board
void printBoard() {
    printf("\n");
    printf("   0  1  2  3  4  5  6  7\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("|%c|", board[i][j].value);
        }
        printf("\n");
    }
}

//Function to check if a move is valid
int isValidMove(struct Cell sourceCell, struct Cell destinationCell, char player) {
    int diffRow = destinationCell.x - sourceCell.x;
    int diffCol = destinationCell.y - sourceCell.y;

    if(player == 'X' && !isupper(sourceCell.value)) //Checking if the player can move this piece
        return 0;
    if(player == 'O' && !islower(sourceCell.value))
        return 0;
    if(destinationCell.value != ' ') //Checking if there is already a piece on the destination cell
        return 0;
    if(abs(diffRow) != abs(diffCol)) //Checking if the piece is moving diagonally
        return 0;
    if(abs(diffRow) == 1) //Checking if the move is only one unit away
        return 1;

    //Code for jumping over another player's piece
    int jumpRowIndex = (sourceCell.x + destinationCell.x) / 2;
    int jumpColIndex = (sourceCell.y + destinationCell.y) / 2;
    if(destinationCell.x < sourceCell.x) //Checking if the piece is moving upwards
        if(((destinationCell.value == ' ') && (sourceCell.value == 'X' || isupper(sourceCell.value))) || ((destinationCell.value == 'O') && islower(sourceCell.value) && (board[jumpRowIndex][jumpColIndex].value == 'X' || isupper(board[jumpRowIndex][jumpColIndex].value))))
            return 2;
    if(destinationCell.x > sourceCell.x) //Checking if the piece is moving downwards
        if(((destinationCell.value == ' ') && (sourceCell.value == 'O' || islower(sourceCell.value))) || ((destinationCell.value == 'X') && isupper(sourceCell.value) && (board[jumpRowIndex][jumpColIndex].value == 'O' || islower(board[jumpRowIndex][jumpColIndex].value))))
            return 2;

    return 0;
}

//Function to perform a move
void performMove(struct Cell sourceCell, struct Cell destinationCell) {
    destinationCell.value = sourceCell.value;
    sourceCell.value = ' ';
    if(abs(destinationCell.x - sourceCell.x) == 2) { //Checking if a jump occurred and thus removing the piece jumped over
        struct Cell jumpCell = {(destinationCell.x + sourceCell.x) / 2, (destinationCell.y + sourceCell.y) / 2, ' '};
        board[jumpCell.x][jumpCell.y] = jumpCell;
    }

    //Checking if piece reached the other side of the board and promoting it to a king
    if(destinationCell.value == 'O' && destinationCell.x == SIZE - 1)
        destinationCell.value = 'Q';
    if(destinationCell.value == 'X' && destinationCell.x == 0)
        destinationCell.value = 'K';
}

//Function to check if the game has ended
int isGameOver() {
    int xCount = 0;
    int oCount = 0;
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if(board[i][j].value == 'X' || board[i][j].value == 'K')
                xCount++;
            else if(board[i][j].value == 'O' || board[i][j].value == 'Q')
                oCount++;

    if(xCount == 0) {
        printf("\nGame Over! O Wins!\n");
        return 1;
    }
    else if(oCount == 0) {
        printf("\nGame Over! X Wins!\n");
        return 1;
    }
    return 0;
}

int main() {
    char currentPlayer = 'X';
    while(1) {
        printBoard();
        printf("%c's Turn:\n", currentPlayer);
        int sourceX, sourceY, destX, destY;
        printf("Enter the row and column numbers of the piece you want to move: ");
        scanf("%d%d", &sourceX, &sourceY);
        printf("Enter the row and column numbers of the destination: ");
        scanf("%d%d", &destX, &destY);

        struct Cell sourceCell = {sourceX, sourceY, board[sourceX][sourceY].value};
        struct Cell destinationCell = {destX, destY, board[destX][destY].value};

        int validMove = isValidMove(sourceCell, destinationCell, currentPlayer);

        if(validMove == 0) {
            printf("Not a valid move. Try again.\n");
            continue;
        }

        if(validMove == 1) {
            performMove(sourceCell, destinationCell);
            currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
        }

        if(validMove == 2) {
            printf("Jumping over the piece!\n");
            performMove(sourceCell, destinationCell);
            while(validMove == 2) {
                printBoard();
                printf("%c's Turn:\n", currentPlayer);
                printf("Enter the row and column numbers of the next destination: ");
                scanf("%d%d", &destX, &destY);
                struct Cell temp = destinationCell;
                destinationCell = (struct Cell) {destX, destY, board[destX][destY].value};
                validMove = isValidMove(destinationCell, temp, currentPlayer);
                if(validMove == 2) {
                    printf("Jumping over the piece!\n");
                    performMove(destinationCell, temp);
                }
                else if(validMove == 1) {
                    performMove(destinationCell, temp);
                    currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
                }
                else {
                    printf("Not a valid move. Try again.\n");
                    continue;
                }
                if(isGameOver())
                    return 0;
            }
        }

        if(isGameOver())
            return 0;
    }
}