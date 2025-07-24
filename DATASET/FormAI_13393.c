//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define PLAYER1 'X'
#define PLAYER2 'O'
#define EMPTY ' '
#define TIE 'T'
#define BOARD_SIZE 9

void init_board(char board[BOARD_SIZE]);
void display_board(char board[BOARD_SIZE]);
int get_player_move(char board[BOARD_SIZE], char player);
int get_computer_move(char board[BOARD_SIZE], char computer);
char check_winner(char board[BOARD_SIZE]);

int main()
{
    char board[BOARD_SIZE];
    char winner = EMPTY;
    int player_turn = 1;

    init_board(board);

    while (winner == EMPTY)
    {
        display_board(board);

        if (player_turn)
        {
            winner = check_winner(board);
            if (winner != EMPTY)
                break;

            player_turn = 0;
            get_player_move(board, PLAYER1);
        }
        else
        {
            winner = check_winner(board);
            if (winner != EMPTY)
                break;

            player_turn = 1;
            get_computer_move(board, PLAYER2);
        }
    }

    display_board(board);

    if (winner == TIE)
        printf("It's a tie!");
    else if (winner == PLAYER1)
        printf("Player 1 wins!");
    else
        printf("Player 2 wins!");

    return 0;
}

void init_board(char board[BOARD_SIZE])
{
    int i;
    for (i = 0; i < BOARD_SIZE; i++)
        board[i] = EMPTY;
}

void display_board(char board[BOARD_SIZE])
{
    printf("\n");
    int i;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        printf("%c", board[i]);
        if ((i + 1) % 3 != 0)
            printf(" | ");
        else if (i != 8)
            printf("\n---------\n");
        else
            printf("\n");
    }
}

int get_player_move(char board[BOARD_SIZE], char player)
{
    int move = -1;
    while (move < 0 || move > 8 || board[move] != EMPTY)
    {
        printf("Player %c, enter your move (0-8): ", player);
        scanf("%d", &move);
    }
    board[move] = player;
    return move;
}

int get_computer_move(char board[BOARD_SIZE], char computer)
{
    int move = -1;

    // check if can win
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i] == EMPTY) {
            board[i] = computer;
            if (check_winner(board) == computer) {
                move = i;
                break;
            }
            board[i] = EMPTY;
        }
    }

    // check if player can win
    if (move == -1) {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board[i] == EMPTY) {
                board[i] = PLAYER1; //assume player1
                if (check_winner(board) == PLAYER1) {
                    move = i;
                    break;
                }
                board[i] = EMPTY;
            }
        }
    }

    // random move
    if (move == -1) {
        do {
            move = rand() % 9;
        } while (board[move] != EMPTY);
    }
    board[move] = computer;
    return move;
}

char check_winner(char board[BOARD_SIZE])
{

    // check rows
    for (int i = 0; i < BOARD_SIZE; i += 3) {
        if (board[i] != EMPTY && board[i] == board[i+1] && board[i+1] == board[i+2]) {
            return board[i];
        }
    }

    // check columns
    for (int i = 0; i < 3; ++i) {
        if (board[i] != EMPTY && board[i] == board[i+3] && board[i+3] == board[i+6]) {
            return board[i];
        }
    }

    // check diagonals
    if (board[0] != EMPTY && board[0] == board[4] && board[4] == board[8]) {
        return board[0];
    }
    if (board[2] != EMPTY && board[2] == board[4] && board[4] == board[6]) {
        return board[2];
    }

    // check for tie
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i] == EMPTY)
            return EMPTY;
    }

    return TIE;
}