//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: optimized
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

char board[SIZE][SIZE];
char human, computer;

void init_board();
void print_board();
bool is_valid_move(int row, int col);
void human_move();
void computer_move();
bool check_win(char player);
bool is_full();

int main()
{
    srand(time(NULL));

    printf("Welcome to Tic Tac Toe!\n");

    // ask user to choose X or O
    while (true)
    {
        printf("Do you want to play as X or O?\n");
        char choice = getchar();
        fflush(stdin);
        if (choice == 'X' || choice == 'x')
        {
            human = 'X';
            computer = 'O';
            break;
        }
        else if (choice == 'O' || choice == 'o')
        {
            human = 'O';
            computer = 'X';
            break;
        }
        else
            printf("Invalid choice!\n");
    }

    // initialize board and print it
    init_board();
    print_board();

    // loop until the game is over
    while (true)
    {
        if (human == 'X')
        {
            human_move();
            if (check_win(human))
            {
                printf("Congratulations! You win!\n");
                break;
            }
            if (is_full())
            {
                printf("It's a tie!\n");
                break;
            }
            computer_move();
            if (check_win(computer))
            {
                printf("Sorry, you lose!\n");
                break;
            }
            if (is_full())
            {
                printf("It's a tie!\n");
                break;
            }
        }
        else
        {
            computer_move();
            if (check_win(computer))
            {
                printf("Sorry, you lose!\n");
                break;
            }
            if (is_full())
            {
                printf("It's a tie!\n");
                break;
            }
            human_move();
            if (check_win(human))
            {
                printf("Congratulations! You win!\n");
                break;
            }
            if (is_full())
            {
                printf("It's a tie!\n");
                break;
            }
        }
    }

    return 0;
}

void init_board()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = '-';
}

void print_board()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

bool is_valid_move(int row, int col)
{
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
        return false;
    if (board[row][col] != '-')
        return false;
    return true;
}

void human_move()
{
    while (true)
    {
        printf("Enter row and column (1-3): ");
        int row, col;
        scanf("%d %d", &row, &col);
        fflush(stdin);
        row--;
        col--;
        if (is_valid_move(row, col))
        {
            board[row][col] = human;
            print_board();
            break;
        }
        else
            printf("Invalid move, try again!\n");
    }
}

void computer_move()
{
    printf("Computer is thinking...\n");

    // prioritize winning the game
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (is_valid_move(i, j))
            {
                board[i][j] = computer;
                if (check_win(computer))
                {
                    print_board();
                    return;
                }
                board[i][j] = '-';
            }
        }
    }

    // prioritize blocking the human
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (is_valid_move(i, j))
            {
                board[i][j] = human;
                if (check_win(human))
                {
                    board[i][j] = computer;
                    print_board();
                    return;
                }
                board[i][j] = '-';
            }
        }
    }

    // choose a random move
    while (true)
    {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (is_valid_move(row, col))
        {
            board[row][col] = computer;
            print_board();
            return;
        }
    }
}

bool check_win(char player)
{
    if (board[0][0] == player && board[0][1] == player && board[0][2] == player)
        return true;
    if (board[1][0] == player && board[1][1] == player && board[1][2] == player)
        return true;
    if (board[2][0] == player && board[2][1] == player && board[2][2] == player)
        return true;
    if (board[0][0] == player && board[1][0] == player && board[2][0] == player)
        return true;
    if (board[0][1] == player && board[1][1] == player && board[2][1] == player)
        return true;
    if (board[0][2] == player && board[1][2] == player && board[2][2] == player)
        return true;
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool is_full()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == '-')
                return false;
    return true;
}