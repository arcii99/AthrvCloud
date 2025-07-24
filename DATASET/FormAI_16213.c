//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdio.h>

#define BOARD_SIZE 9

char board[BOARD_SIZE];

void display_board(void);
int get_player_choice(void);
int check_win(void);
int minimax(int);
int mini(int, int);
int max(int, int);

int main(void)
{
    // Initialize the board with empty spaces
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = ' ';
    }

    // Display the empty board
    display_board();

    // Main game loop
    int player_choice, computer_choice;
    while (1)
    {
        // Player's turn
        player_choice = get_player_choice();
        board[player_choice] = 'X';
        display_board();

        // Check if the game is over
        if (check_win())
        {
            printf("You win!\n");
            break;
        }

        // Computer's turn
        computer_choice = minimax(1);
        board[computer_choice] = 'O';
        printf("Computer chooses %d\n", computer_choice);
        display_board();

        // Check if the game is over
        if (check_win())
        {
            printf("Computer wins!\n");
            break;
        }

        // Check for a tie game
        int tie_game = 1;
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            if (board[i] == ' ')
            {
                tie_game = 0;
                break;
            }
        }
        if (tie_game)
        {
            printf("Tie game\n");
            break;
        }
    }

    return 0;
}

void display_board(void)
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

int get_player_choice(void)
{
    int choice;
    printf("Enter a number from 0 to 8 to place your mark: ");
    scanf("%d", &choice);

    while (board[choice] != ' ')
    {
        printf("Location is already taken, please choose a different location: ");
        scanf("%d", &choice);
    }

    return choice;
}

int check_win(void)
{
    // Check rows
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
    {
        return 1;
    }
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
    {
        return 1;
    }
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
    {
        return 1;
    }

    // Check columns
    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
    {
        return 1;
    }
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
    {
        return 1;
    }
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
    {
        return 1;
    }

    // Check diagonals
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
    {
        return 1;
    }
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
    {
        return 1;
    }

    return 0;
}

int minimax(int maximize)
{
    int best_score, best_move;
    best_score = maximize ? -1000 : 1000;
    best_move = -1;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i] == ' ')
        {
            board[i] = maximize ? 'O' : 'X';
            int score = mini(!maximize, 0);
            board[i] = ' ';

            if (maximize)
            {
                if (score > best_score)
                {
                    best_score = score;
                    best_move = i;
                }
            }
            else
            {
                if (score < best_score)
                {
                    best_score = score;
                    best_move = i;
                }
            }
        }
    }

    return best_move;
}

int mini(int maximize, int depth)
{
    if (check_win() != 0)
    {
        return check_win() > 0 ? 1 : -1;
    }
    else if (depth == 4)
    {
        return 0;
    }

    int best_score = maximize ? 1000 : -1000;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i] == ' ')
        {
            board[i] = maximize ? 'X' : 'O';
            int score = maxi(!maximize, depth + 1);
            board[i] = ' ';

            best_score = maximize ? min(best_score, score) : max(best_score, score);
        }
    }

    return best_score;
}

int maxi(int maximize, int depth)
{
    if (check_win() != 0)
    {
        return check_win() > 0 ? 1 : -1;
    }
    else if (depth == 4)
    {
        return 0;
    }

    int best_score = maximize ? -1000 : 1000;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i] == ' ')
        {
            board[i] = maximize ? 'O' : 'X';
            int score = mini(!maximize, depth + 1);
            board[i] = ' ';

            best_score = maximize ? max(best_score, score) : min(best_score, score);
        }
    }

    return best_score;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}