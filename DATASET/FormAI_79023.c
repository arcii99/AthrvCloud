//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(char* board)
{
    printf("\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}

int check_win(char* board)
{
    int wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for (i = 0; i < 8; ++i) 
    {
        if (board[wins[i][0]] != ' ' && board[wins[i][0]] == board[wins[i][1]] && board[wins[i][0]] == board[wins[i][2]])
        {
            if (board[wins[i][0]] == 'X') 
              return 1;
            else 
              return 2;
        }
    }
    return 0;
}

int get_ai_move(char* board)
{
    int i, j;
    for (i = 0; i < 9; ++i) {
        if (board[i] == ' ') {
            board[i] = 'O';
            if (check_win(board) == 2) {
                board[i] = ' ';
                return i;
            }
            board[i] = ' ';
        }
    }
    for (i = 0; i < 9; ++i) {
        if (board[i] == ' ') {
            board[i] = 'X';
            if (check_win(board) == 1) {
                board[i] = 'O';
                return i;
            }
            board[i] = ' ';
        }
    }
    do {
        j = rand() % 9;
    } while (board[j] != ' ');
    board[j] = 'O';
    return j;
}

int main()
{
    char board[9];
    int i, move;
    srand(time(NULL));
    for (i = 0; i < 9; ++i) {
        board[i] = ' ';
    }
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are X, I am O.\n");
    printf("To make a move, enter a number from 0 to 8:\n");
    while (1) {
        print_board(board);
        printf("Enter your move: ");
        scanf("%d", &move);
        if (move < 0 || move > 8 || board[move] != ' ') {
            printf("Invalid move!\n");
            continue;
        }
        board[move] = 'X';
        if (check_win(board) == 1) {
            print_board(board);
            printf("You win!\n");
            break;
        }
        if (i == 8) {
            print_board(board);
            printf("It's a tie!\n");
            break;
        }
        ++i;
        move = get_ai_move(board);
        printf("I make a move: %d\n", move);
        if (check_win(board) == 2) {
            print_board(board);
            printf("You lose!\n");
            break;
        }
    }
    return 0;
}