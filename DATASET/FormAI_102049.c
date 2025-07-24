//FormAI DATASET v1.0 Category: Chess AI ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Board Initialization
char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

// Function to print the board
void print_board() {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

// Function to make a move
void make_move(int x1, int y1, int x2, int y2) {
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = '.';
}

// Function to check if a move is valid
int is_valid_move(int x1, int y1, int x2, int y2) {
    char piece = board[x1][y1];

    // Invalid move if the pieces are the same color
    if (board[x2][y2] != '.' && ((piece >= 'a' && board[x2][y2] >= 'a') || (piece <= 'Z' && board[x2][y2] <= 'Z')))
        return 0;

    // Check the type of piece and if the move is valid
    switch(piece) {
        case 'p':
            // Check if the pawn can move
            if (y1 != y2 || (board[x2][y2] != '.' && abs(x2 - x1) != 1) || abs(x2 - x1) > 2)
                return 0;

            // First move can move two squares
            if (abs(x2 - x1) == 2 && x1 != 1)
                return 0;

            break;
        case 'P':
            // Check if the pawn can move
            if (y1 != y2 || (board[x2][y2] != '.' && abs(x2 - x1) != 1) || abs(x2 - x1) > 2)
                return 0;

            // First move can move two squares
            if (abs(x2 - x1) == 2 && x1 != 6)
                return 0;

            break;
        case 'r':
        case 'R':
            // Check if the movement is horizontal or vertical
            if (x1 != x2 && y1 != y2)
                return 0;

            // Check if there are any pieces in the way
            if (x1 == x2) {
                // Check if moving to the right or left
                int diff = y2 - y1;
                int i;
                for (i = 1; i < abs(diff); i++) {
                    if (diff > 0 && board[x1][y1+i] != '.')
                        return 0;
                    else if (diff < 0 && board[x1][y1-i] != '.')
                        return 0;
                }
            }
            else {
                // Check if moving up or down
                int diff = x2 - x1;
                int i;
                for (i = 1; i < abs(diff); i++) {
                    if (diff > 0 && board[x1+i][y1] != '.')
                        return 0;
                    else if (diff < 0 && board[x1-i][y1] != '.')
                        return 0;
                }
            }

            break;
        case 'n':
        case 'N':
            // Check if the movement is an L shape
            if (abs(x1 - x2) == 2 && abs(y1 - y2) == 1)
                break;
            else if (abs(x1 - x2) == 1 && abs(y1 - y2) == 2)
                break;
            else
                return 0;

            break;
        case 'b':
        case 'B':
            // Check if the movement is diagonal
            if (abs(x1 - x2) != abs(y1 - y2))
                return 0;

            // Check if any pieces are in the way
            int diffx = x2 - x1;
            int diffy = y2 - y1;
            int i;
            for (i = 1; i < abs(diffx); i++) {
                if (diffx > 0 && diffy > 0 && board[x1+i][y1+i] != '.')
                    return 0;
                else if (diffx > 0 && diffy < 0 && board[x1+i][y1-i] != '.')
                    return 0;
                else if (diffx < 0 && diffy > 0 && board[x1-i][y1+i] != '.')
                    return 0;
                else if (diffx < 0 && diffy < 0 && board[x1-i][y1-i] != '.')
                    return 0;
            }

            break;
        case 'q':
        case 'Q':
            // Check if the movement is horizontal, vertical or diagonal
            if (x1 != x2 && y1 != y2 && abs(x1-x2) != abs(y1-y2))
                return 0;

            // Check if there are any pieces in the way
            if (x1 == x2) {
                // Check if moving to the right or left
                int diff = y2 - y1;
                int i;
                for (i = 1; i < abs(diff); i++) {
                    if (diff > 0 && board[x1][y1+i] != '.')
                        return 0;
                    else if (diff < 0 && board[x1][y1-i] != '.')
                        return 0;
                }
            }
            else if (y1 == y2) {
                // Check if moving up or down
                int diff = x2 - x1;
                int i;
                for (i = 1; i < abs(diff); i++) {
                    if (diff > 0 && board[x1+i][y1] != '.')
                        return 0;
                    else if (diff < 0 && board[x1-i][y1] != '.')
                        return 0;
                }
            }
            else {
                // Check if moving diagonally
                int diffx = x2 - x1;
                int diffy = y2 - y1;
                int i;
                for (i = 1; i < abs(diffx); i++) {
                    if (diffx > 0 && diffy > 0 && board[x1+i][y1+i] != '.')
                        return 0;
                    else if (diffx > 0 && diffy < 0 && board[x1+i][y1-i] != '.')
                        return 0;
                    else if (diffx < 0 && diffy > 0 && board[x1-i][y1+i] != '.')
                        return 0;
                    else if (diffx < 0 && diffy < 0 && board[x1-i][y1-i] != '.')
                        return 0;
                }
            }

            break;
        case 'k':
        case 'K':
            // Check if the movement is valid
            if (abs(x1 - x2) > 1 || abs(y1 - y2) > 1 || (x1 == x2 && y1 == y2))
                return 0;

            break;
        default:
            return 0;
    }

    // Move is valid
    return 1;
}

// Chess AI function
void chess_ai() {
    int i, j, x, y, max_score = 0;
    char c1, c2;

    // Loop through each piece on the board
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] != '.') {
                // Check if the piece is the AI's own color
                if (board[i][j] >= 'a' && board[i][j] <= 'z') {
                    // Loop through to find the best move
                    int ii, jj;
                    for (ii = 0; ii < 8; ii++) {
                        for (jj = 0; jj < 8; jj++) {
                            if (is_valid_move(i, j, ii, jj)) {
                                int score = abs(ii - i) + abs(jj - j);
                                if (score > max_score) {
                                    x = i;
                                    y = j;
                                    c1 = ii + 'a';
                                    c2 = jj + '1';
                                    max_score = score;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Make the move
    printf("AI move: %c%d to %c%d\n", x + 'a', y + 1, c1, c2);
    make_move(x, y, c1 - 'a', c2 - '1');
}

// Main function
int main() {
    printf("***Welcome to the Chess Game!***\n");
    printf("Initial Board:\n");
    print_board();

    int player_turn = 1;
    char move[5];
    while (1) {
        if (player_turn) {
            printf("Player's Move: ");
            scanf("%s", move);
            if (is_valid_move(move[0] - 'a', move[1] - '1', move[2] - 'a', move[3] - '1'))
                make_move(move[0] - 'a', move[1] - '1', move[2] - 'a', move[3] - '1');
            else {
                printf("Invalid move, try again.\n");
                continue;
            }
        }
        else {
            chess_ai();
        }

        print_board();

        // Check if the game is over
        int i, j, count = 0;
        for (i = 0; i < 8; i++)
            for (j = 0; j < 8; j++)
                if (board[i][j] == 'k' || board[i][j] == 'K')
                    count++;

        if (count < 2) {
            printf("Game over!\n");
            break;
        }

        player_turn = !player_turn;
    }

    return 0;
}