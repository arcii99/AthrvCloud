//FormAI DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>

//Function to print the game board
void print_board(char board[][3]) {
    printf("\n");
    printf("\t\t %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t-----------\n");
    printf("\t\t %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t-----------\n");
    printf("\t\t %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

//Function to check if any player has won
int check_win(char board[][3], char player) {
    int i, j;

    //Check for horizontal win
    for(i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    //Check for vertical win
    for(i=0; i<3; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    //Check for diagonal win
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    } else if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    int i, j, row, col, turn=1;
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    printf("\nWelcome to Tic Tac Toe!\n");
    printf("Player 1 (X) - Player 2 (O)\n\n");

    //Game loop
    while(1) {
        //Print the board
        print_board(board);

        //Get player input
        if(turn % 2 == 1) {
            printf("Player 1 (X) Turn: ");
        } else {
            printf("Player 2 (O) Turn: ");
        }
        scanf("%d %d", &row, &col);

        //Check if the input is valid
        if(row<0 || row>2 || col<0 || col>2) {
            printf("Invalid input. Please enter row and column numbers between 0 and 2.\n\n");
            continue;
        } else if(board[row][col] != ' ') {
            printf("That position is already occupied. Please choose another.\n\n");
            continue;
        }

        //Update the board
        if(turn % 2 == 1) {
            board[row][col] = 'X';
        } else {
            board[row][col] = 'O';
        }

        //Check if any player has won
        if(check_win(board, 'X')) {
            print_board(board);
            printf("Congratulations! Player 1 (X) has won!\n");
            break;
        } else if(check_win(board, 'O')) {
            print_board(board);
            printf("Congratulations! Player 2 (O) has won!\n");
            break;
        }

        //Check if the game has ended in a tie
        int flag=0;
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                if(board[i][j] == ' ') {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) {
                break;
            }
        }
        if(flag == 0) {
            print_board(board);
            printf("The game has ended in a tie!\n");
            break;
        }

        turn++;
    }

    return 0;
}