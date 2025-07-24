//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define AI_MARKER 'X'
#define HUMAN_MARKER 'O'

int empty_cells(char board[SIZE][SIZE]);
int evaluate(char board[SIZE][SIZE]);
int is_game_over(char board[SIZE][SIZE]);
int minmax(char board[SIZE][SIZE], int depth, int is_ai);
void display_board(char board[SIZE][SIZE]);
void init_board(char board[SIZE][SIZE]);
int get_human_move(char board[SIZE][SIZE]);
int get_computer_move(char board[SIZE][SIZE]);

int main()
{
    char board[SIZE][SIZE];
    int turn, human_move, computer_move;
    
    init_board(board);
    
    printf("Welcome to Tic Tac Toe!\n\n");
    printf("You will be playing against the computer.\n\n");
    printf("The board is numbered from 1 to 9 as shown below:\n\n");
    printf(" 1 | 2 | 3 \n");
    printf("---+---+---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---+---+---\n");
    printf(" 7 | 8 | 9 \n\n");
    
    printf("To make a move, enter a number from 1 to 9.\n\n");
    
    // randomly determine who goes first
    srand(time(NULL));
    turn = rand() % 2;
    
    while (empty_cells(board) && !is_game_over(board))
    {
        display_board(board);
        
        if (turn == 0)
        {
            printf("Your turn.\n\n");
            human_move = get_human_move(board);
            board[(human_move - 1) / SIZE][(human_move - 1) % SIZE] = HUMAN_MARKER;
            turn = 1;
        }
        else
        {
            printf("Computer's turn.\n\n");
            computer_move = get_computer_move(board);
            board[(computer_move - 1) / SIZE][(computer_move - 1) % SIZE] = AI_MARKER;
            turn = 0;
        }
    }
    
    display_board(board);
    
    if (is_game_over(board))
    {
        if (evaluate(board) == 1)
            printf("You lost!\n\n");
        else if (evaluate(board) == -1)
            printf("You won!\n\n");
        else
            printf("It's a tie!\n\n");
    }
    
    return 0;
}

// returns the number of empty cells on the board
int empty_cells(char board[SIZE][SIZE])
{
    int i, j, count = 0;
    
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                count++;
    
    return count;
}

// evaluates the state of the game
int evaluate(char board[SIZE][SIZE])
{
    int i, j, row_sum, col_sum, diag_sum;
    
    // check rows
    for (i = 0; i < SIZE; i++) {
        row_sum = 0;
        for (j = 0; j < SIZE; j++)
            row_sum += board[i][j];
        if (row_sum == AI_MARKER*SIZE)
            return 1; // AI wins
        else if (row_sum == HUMAN_MARKER*SIZE)
            return -1; // human wins
    }
    
    // check columns
    for (j = 0; j < SIZE; j++) {
        col_sum = 0;
        for (i = 0; i < SIZE; i++)
            col_sum += board[i][j];
        if (col_sum == AI_MARKER*SIZE)
            return 1; // AI wins
        else if (col_sum == HUMAN_MARKER*SIZE)
            return -1; // human wins
    }
    
    // check diagonals
    diag_sum = board[0][0] + board[1][1] + board[2][2];
    if (diag_sum == AI_MARKER*SIZE || diag_sum == HUMAN_MARKER*SIZE)
        return (diag_sum == AI_MARKER*SIZE) ? 1 : -1;
    
    diag_sum = board[0][2] + board[1][1] + board[2][0];
    if (diag_sum == AI_MARKER*SIZE || diag_sum == HUMAN_MARKER*SIZE)
        return (diag_sum == AI_MARKER*SIZE) ? 1 : -1;
    
    return 0; // no winner yet
}

// checks if the game is over
int is_game_over(char board[SIZE][SIZE])
{
    return (evaluate(board) || !empty_cells(board));
}

// minmax algorithm with alpha-beta pruning to determine best move
int minmax(char board[SIZE][SIZE], int depth, int is_ai)
{
    int i, j, score, best_score = (is_ai) ? -999 : 999;
    
    if (depth == 0 || is_game_over(board))
        return evaluate(board);
    
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                if (is_ai)
                {
                    board[i][j] = AI_MARKER;
                    score = minmax(board, depth-1, 0);
                    best_score = (score > best_score) ? score : best_score;
                    board[i][j] = ' ';
                }
                else
                {
                    board[i][j] = HUMAN_MARKER;
                    score = minmax(board, depth-1, 1);
                    best_score = (score < best_score) ? score : best_score;
                    board[i][j] = ' ';
                }
            }
        }
    
    return best_score;
}

// displays the board
void display_board(char board[SIZE][SIZE])
{
    int i, j;
    
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
}

// initializes the board to empty cells
void init_board(char board[SIZE][SIZE])
{
    int i, j;
    
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

// prompts the user to enter a move and returns the corresponding cell number
int get_human_move(char board[SIZE][SIZE])
{
    int move;
    
    while (1)
    {
        printf("Enter your move (1-9): ");
        scanf("%d", &move);
        
        if (move < 1 || move > 9)
            printf("Invalid move. Try again.\n\n");
        else if (board[(move - 1) / SIZE][(move - 1) % SIZE] != ' ')
            printf("Cell already occupied. Try again.\n\n");
        else
            return move;
    }
}

// returns the best move for the computer using the minmax algorithm
int get_computer_move(char board[SIZE][SIZE])
{
    int i, j, best_move;
    int score, best_score = -999;
    
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = AI_MARKER;
                score = minmax(board, 4, 0);
                if (score > best_score)
                {
                    best_move = i*SIZE+j+1;
                    best_score = score;
                }
                board[i][j] = ' ';
            }
        }
    
    return best_move;
}