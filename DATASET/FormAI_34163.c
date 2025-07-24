//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>

char board[3][3]; // the tic tac toe board

// this function prints the current board
void print_board()
{
    printf("\t  1 2 3\n");
    printf("\t +-+-+-+\n");
    for (int i = 0; i < 3; i++) {
        printf("\t%c|%c|%c|%d\n", 'A'+i, board[i][0], board[i][1], board[i][2]);
        printf("\t +-+-+-+\n");
    }
}

// this function gets the user's move and updates the board
void get_user_move()
{
    printf("Your turn. Please enter your move (e.g. B2):\n");
    char move[3];
    scanf("%s", move);
    if (move[0] < 'A' || move[0] > 'C' || move[1] < '1' || move[1] > '3') {
        printf("Invalid move. Please try again.\n");
        get_user_move();
    }
    int row = move[0] - 'A';
    int col = move[1] - '1';
    if (board[row][col] != ' ') {
        printf("That spot is already taken. Please try again.\n");
        get_user_move();
    }
    board[row][col] = 'X'; // update the board with the user's move
}

// this function checks if the game is over
char check_game_over()
{
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
    }
    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];
    // check for a tie
    int num_spaces = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                num_spaces++;
        }
    }
    if (num_spaces == 0)
        return 'T';
    // game is not over yet
    return ' ';
}

// this function makes the computer's move
void make_computer_move()
{
    printf("Haha, now it's my turn!\n");
    int row, col;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                row = i;
                col = j;
            }
        }
    }
   
    printf("I'll play at %c%d!\n", 'A'+row, col+1); // The AI does not really do anything here...
    board[row][col] = 'O'; // update the board with the AI's move
}

// the main function
int main()
{
    // initialize the board to empty spaces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    while (1) {
        print_board();
        get_user_move();
        char winner = check_game_over();
        if (winner != ' ') {
            if (winner == 'T') {
                printf("It's a tie! We're both losers!\n");
            } else {
                printf("Congratulations, you won! I'll get you next time!\n");
            }
            break;
        }
        make_computer_move();
        winner = check_game_over();
        if (winner != ' ') {
            if (winner == 'T') {
                printf("It's a tie! We're both losers!\n");
            } else {
                printf("Haha, I win!!! You are no match for my AI prowess!\n");
            }
            break;
        }
    }
    return 0;
}