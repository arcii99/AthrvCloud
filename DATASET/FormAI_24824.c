//FormAI DATASET v1.0 Category: Checkers Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int board[8][8]; //This is the game board
int player = 1; //This is the player who is currently taking the turn
int turns; //This is to keep count of the turns taken by each player

void setup_board() { //This function sets up the board with initial pieces
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) { //Black squares on the board
                if (i < 3) {
                    board[i][j] = 1; //1 represents player 1's pieces
                }
                else if (i > 4) {
                    board[i][j] = 2; //2 represents player 2's pieces
                }
                else {
                    board[i][j] = 0; //Empty squares
                }
            }
            else { //White squares on the board
                board[i][j] = 0; //Empty squares
            }
        }
    }
}

void print_board() { //This function prints the board
    printf("\n  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 1) { //Player 1's pieces
                printf("O ");
            }
            else if (board[i][j] == 2) { //Player 2's pieces
                printf("X ");
            }
            else { //Empty squares
                printf("- ");
            }
        }
        printf("\n");
    }
}

int is_valid_move(int from_x, int from_y, int to_x, int to_y) { //This function checks if a move is valid
    if (to_x < 0 || to_x > 7 || to_y < 0 || to_y > 7) { //Destination square is out of bounds
        return 0;
    }
    if (board[to_x][to_y] != 0) { //Destination square is not empty
        return 0;
    }
    if (player == 1) { //Player 1's turn
        if (board[from_x][from_y] == 1) { //Moving a regular piece
            if (to_x - from_x == 1 && abs(to_y - from_y) == 1) { //Moving one square diagonally forward
                return 1;
            }
            else if (to_x - from_x == 2 && abs(to_y - from_y) == 2) { //Jumping over an opponent's piece
                int jump_x = (from_x + to_x) / 2; //Calculating the coordinates of the jumped square
                int jump_y = (from_y + to_y) / 2;
                if (board[jump_x][jump_y] == 2) { //Jumped piece belongs to the opponent
                    return 1;
                }
            }
        }
        else if (board[from_x][from_y] == 3) { //Moving a king piece
            if (abs(to_x - from_x) == 1 && abs(to_y - from_y) == 1) { //Moving one square diagonally in any direction
                return 1;
            }
            else if (abs(to_x - from_x) == 2 && abs(to_y - from_y) == 2) { //Jumping over an opponent's piece
                int jump_x = (from_x + to_x) / 2; //Calculating the coordinates of the jumped square
                int jump_y = (from_y + to_y) / 2;
                if (board[jump_x][jump_y] == 2) { //Jumped piece belongs to the opponent
                    return 1;
                }
            }
        }
    }
    else if (player == 2) { //Player 2's turn
        if (board[from_x][from_y] == 2) { //Moving a regular piece
            if (to_x - from_x == -1 && abs(to_y - from_y) == 1) { //Moving one square diagonally forward
                return 1;
            }
            else if (to_x - from_x == -2 && abs(to_y - from_y) == 2) { //Jumping over an opponent's piece
                int jump_x = (from_x + to_x) / 2; //Calculating the coordinates of the jumped square
                int jump_y = (from_y + to_y) / 2;
                if (board[jump_x][jump_y] == 1) { //Jumped piece belongs to the opponent
                    return 1;
                }
            }
        }
        else if (board[from_x][from_y] == 4) { //Moving a king piece
            if (abs(to_x - from_x) == 1 && abs(to_y - from_y) == 1) { //Moving one square diagonally in any direction
                return 1;
            }
            else if (abs(to_x - from_x) == 2 && abs(to_y - from_y) == 2) { //Jumping over an opponent's piece
                int jump_x = (from_x + to_x) / 2; //Calculating the coordinates of the jumped square
                int jump_y = (from_y + to_y) / 2;
                if (board[jump_x][jump_y] == 1) { //Jumped piece belongs to the opponent
                    return 1;
                }
            }
        }
    }
    return 0; //Move is invalid
}

void move_piece(int from_x, int from_y, int to_x, int to_y) { //This function moves a piece
    board[to_x][to_y] = board[from_x][from_y]; //Moving the piece to the destination square
    board[from_x][from_y] = 0; //Emptying the square where the piece was before
    if (player == 1 && to_x == 7) { //Player 1's regular piece reaches the end of the board
        board[to_x][to_y] = 3; //Promoting the piece to a king piece
    }
    else if (player == 2 && to_x == 0) { //Player 2's regular piece reaches the end of the board
        board[to_x][to_y] = 4; //Promoting the piece to a king piece
    }
    if (abs(to_x - from_x) == 2) { //Jumping over an opponent's piece
        int jump_x = (from_x + to_x) / 2; //Calculating the coordinates of the jumped square
        int jump_y = (from_y + to_y) / 2;
        board[jump_x][jump_y] = 0; //Emptying the square where the jumped piece was
    }
}

int count_pieces(int player) { //This function counts the number of pieces a player has on the board
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == player || board[i][j] == player + 2) { //Counting the player's regular and king pieces
                count++;
            }
        }
    }
    return count;
}

int check_win() { //This function checks if a player has won
    if (count_pieces(1) == 0) { //Player 2 wins if player 1 has no pieces left
        return 2;
    }
    else if (count_pieces(2) == 0) { //Player 1 wins if player 2 has no pieces left
        return 1;
    }
    else { //No player has won yet
        return 0;
    }
}

void check_king() { //This function checks if a regular piece has reached the end of the board and should be promoted to a king piece
    for (int i = 0; i < 8; i++) {
        if (board[0][i] == 1) { //Player 1's regular piece
            board[0][i] = 3; //Promoting the piece to a king piece
        }
        if (board[7][i] == 2) { //Player 2's regular piece
            board[7][i] = 4; //Promoting the piece to a king piece
        }
    }
}

int main() {
    setup_board(); //Setting up the board with initial pieces
    while (1) { //Looping until a player wins
        turns++; //Incrementing the number of turns taken
        printf("\nTurn %d\n", turns);
        print_board(); //Printing the board
        int from_x, from_y, to_x, to_y;
        printf("Player %d, enter move (from_x from_y to_x to_y): ", player);
        scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);
        while (!is_valid_move(from_x, from_y, to_x, to_y)) { //Looping until a valid move is entered
            printf("Invalid move.\n");
            printf("Player %d, enter move (from_x from_y to_x to_y): ", player);
            scanf("%d %d %d %d", &from_x, &from_y, &to_x, &to_y);
        }
        move_piece(from_x, from_y, to_x, to_y); //Moving the piece
        check_king(); //Checking if a piece should be promoted to a king piece
        int winner = check_win(); //Checking if a player has won
        if (winner != 0) { //A player has won
            printf("Player %d wins!\n", winner);
            return 0; //Exiting the program
        }
        if (player == 1) { //Switching to the other player's turn
            player = 2;
        }
        else {
            player = 1;
        }
    }
    return 0;
}