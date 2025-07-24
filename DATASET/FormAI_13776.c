//FormAI DATASET v1.0 Category: Chess AI ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// defining the chess board
char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

// defining the move counter
int move = 1;

// defining the current player
char currentPlayer = 'w';

// defining the function to display the board
void display_board() {
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n\n");
}

// defining the function to get the current player's move
void get_move() {
    char from[3];
    char to[3];

    printf("Enter your move (e.g. e2e4): ");
    scanf("%s%s", from, to);

    int fromRow = 8 - (from[1] - '0');
    int fromCol = from[0] - 'a';
    int toRow = 8 - (to[1] - '0');
    int toCol = to[0] - 'a';

    // validating the move
    if (board[fromRow][fromCol] == ' '
        || (board[fromRow][fromCol] == 'P' && fromRow == 1 && toRow != 3)
        || (board[fromRow][fromCol] == 'p' && fromRow == 6 && toRow != 4)) {
        printf("Invalid move\n");
        get_move();
    } else {
        // checking if the move is legal
        switch (board[fromRow][fromCol]) {
            // pawn
            case 'P':
                if ((toCol == fromCol && (toRow == fromRow + 1 || (toRow == fromRow + 2 && board[fromRow + 1][fromCol] == ' ')))
                    || (toCol == fromCol + 1 && toRow == fromRow + 1 && board[toRow][toCol] != ' ')
                    || (toCol == fromCol - 1 && toRow == fromRow + 1 && board[toRow][toCol] != ' ')) {
                    board[fromRow][fromCol] = ' ';
                    board[toRow][toCol] = 'P';
                    currentPlayer = 'b';
                    move++;
                } else {
                    printf("Invalid move\n");
                    get_move();
                }
                break;
            case 'p':
                if ((toCol == fromCol && (toRow == fromRow - 1 || (toRow == fromRow - 2 && board[fromRow - 1][fromCol] == ' ')))
                    || (toCol == fromCol + 1 && toRow == fromRow - 1 && board[toRow][toCol] != ' ')
                    || (toCol == fromCol - 1 && toRow == fromRow - 1 && board[toRow][toCol] != ' ')) {
                    board[fromRow][fromCol] = ' ';
                    board[toRow][toCol] = 'p';
                    currentPlayer = 'w';
                    move++;
                } else {
                    printf("Invalid move\n");
                    get_move();
                }
                break;
            // rook
            case 'R':
            case 'r':
                if (toRow == fromRow || toCol == fromCol) {
                    int deltaRow = (toRow > fromRow) ? 1 : (toRow < fromRow) ? -1 : 0;
                    int deltaCol = (toCol > fromCol) ? 1 : (toCol < fromCol) ? -1 : 0;
                    int i = fromRow + deltaRow;
                    int j = fromCol + deltaCol;
                    while (i != toRow || j != toCol) {
                        if (board[i][j] != ' ') {
                            printf("Invalid move\n");
                            get_move();
                            return;
                        }
                        i += deltaRow;
                        j += deltaCol;
                    }
                    board[fromRow][fromCol] = ' ';
                    board[toRow][toCol] = (board[toRow][toCol] == ' ') ? 'R' : 'r';
                    currentPlayer = (currentPlayer == 'w') ? 'b' : 'w';
                    move++;
                } else {
                    printf("Invalid move\n");
                    get_move();
                }
                break;
            // knight
            case 'N':
            case 'n':
                if ((abs(toRow - fromRow) == 2 && abs(toCol - fromCol) == 1)
                    || (abs(toRow - fromRow) == 1 && abs(toCol - fromCol) == 2)) {
                    board[fromRow][fromCol] = ' ';
                    board[toRow][toCol] = (board[toRow][toCol] == ' ') ? 'N' : 'n';
                    currentPlayer = (currentPlayer == 'w') ? 'b' : 'w';
                    move++;
                } else {
                    printf("Invalid move\n");
                    get_move();
                }
                break;
            // bishop
            case 'B':
            case 'b':
                if (abs(toRow - fromRow) == abs(toCol - fromCol)) {
                    int deltaRow = (toRow > fromRow) ? 1 : -1;
                    int deltaCol = (toCol > fromCol) ? 1 : -1;
                    int i = fromRow + deltaRow;
                    int j = fromCol + deltaCol;
                    while (i != toRow || j != toCol) {
                        if (board[i][j] != ' ') {
                            printf("Invalid move\n");
                            get_move();
                            return;
                        }
                        i += deltaRow;
                        j += deltaCol;
                    }
                    board[fromRow][fromCol] = ' ';
                    board[toRow][toCol] = (board[toRow][toCol] == ' ') ? 'B' : 'b';
                    currentPlayer = (currentPlayer == 'w') ? 'b' : 'w';
                    move++;
                } else {
                    printf("Invalid move\n");
                    get_move();
                }
                break;
            // queen
            case 'Q':
            case 'q':
                if (toRow == fromRow || toCol == fromCol || abs(toRow - fromRow) == abs(toCol - fromCol)) {
                    int deltaRow = (toRow > fromRow) ? 1 : (toRow < fromRow) ? -1 : 0;
                    int deltaCol = (toCol > fromCol) ? 1 : (toCol < fromCol) ? -1 : 0;
                    int i = fromRow + deltaRow;
                    int j = fromCol + deltaCol;
                    while (i != toRow || j != toCol) {
                        if (board[i][j] != ' ') {
                            printf("Invalid move\n");
                            get_move();
                            return;
                        }
                        i += deltaRow;
                        j += deltaCol;
                    }
                    board[fromRow][fromCol] = ' ';
                    board[toRow][toCol] = (board[toRow][toCol] == ' ') ? 'Q' : 'q';
                    currentPlayer = (currentPlayer == 'w') ? 'b' : 'w';
                    move++;
                } else {
                    printf("Invalid move\n");
                    get_move();
                }
                break;
            // king
            case 'K':
            case 'k':
                if (abs(toRow - fromRow) <= 1 && abs(toCol - fromCol) <= 1) {
                    board[fromRow][fromCol] = ' ';
                    board[toRow][toCol] = (board[toRow][toCol] == ' ') ? 'K' : 'k';
                    currentPlayer = (currentPlayer == 'w') ? 'b' : 'w';
                    move++;
                } else {
                    printf("Invalid move\n");
                    get_move();
                }
                break;
            default:
                printf("Invalid move\n");
                get_move();
                break;
        }
    }
}

// defining the main function
int main() {
    printf("Welcome to the Chess game!\n");
    while (1) {
        printf("Move #%d - %c to move:\n\n", move, currentPlayer);
        display_board();
        get_move();
    }
    return 0;
}