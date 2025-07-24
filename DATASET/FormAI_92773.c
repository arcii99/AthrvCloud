//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

/* Define board size */
#define ROWS 20
#define COLS 20

/* Define colors for pacman and ghosts */
#define PACMAN_COLOR "\033[33;1m"
#define GHOST_COLOR "\033[31;1m"

/* Define symbols for objects */
#define PACMAN_SYMBOL 'C'
#define GHOST_SYMBOL 'G'
#define WALL_SYMBOL '#'
#define COIN_SYMBOL '.'

/* Define key codes */
#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67

/* Define the board */
char board[ROWS][COLS];

/* Define Pacman position variables */
int pacman_row, pacman_col;

/* Define Ghost position variables */
int ghost_row, ghost_col;

/* Define coin variables */
int coin_count = 0;
int coins[ROWS][COLS];

/* Define function to read keyboard input */
char getkey()
{
    struct termios oldattr, newattr;
    char ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

/* Define function to generate random number between min and max */
int random_number(int min, int max)
{
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

/* Define function to initialize the board */
void init_board()
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (i == 0 || j == 0 || i == ROWS - 1 || j == COLS - 1 || (i == ROWS / 2 && j % 2 == 0))
            {
                board[i][j] = WALL_SYMBOL;
            }
            else
            {
                board[i][j] = COIN_SYMBOL;
                coins[i][j] = 1;
                coin_count++;
            }
        }
    }
    pacman_row = ROWS / 2;
    pacman_col = COLS / 2;
    board[pacman_row][pacman_col] = PACMAN_SYMBOL;
    ghost_row = random_number(1, ROWS - 2);
    ghost_col = random_number(1, COLS - 2);
    while (ghost_row == pacman_row && ghost_col == pacman_col)
    {
        ghost_row = random_number(1, ROWS - 2);
        ghost_col = random_number(1, COLS - 2);
    }
    board[ghost_row][ghost_col] = GHOST_SYMBOL;
}

/* Define function to update the board */
void update_board(char key)
{
    int new_pacman_row = pacman_row;
    int new_pacman_col = pacman_col;
    switch (key)
    {
    case KEY_UP:
        new_pacman_row--;
        break;
    case KEY_DOWN:
        new_pacman_row++;
        break;
    case KEY_LEFT:
        new_pacman_col--;
        break;
    case KEY_RIGHT:
        new_pacman_col++;
        break;
    }
    if (board[new_pacman_row][new_pacman_col] != WALL_SYMBOL)
    {
        if (board[new_pacman_row][new_pacman_col] == COIN_SYMBOL)
        {
            coin_count--;
            coins[new_pacman_row][new_pacman_col] = 0;
        }
        board[pacman_row][pacman_col] = COIN_SYMBOL;
        board[new_pacman_row][new_pacman_col] = PACMAN_SYMBOL;
        pacman_row = new_pacman_row;
        pacman_col = new_pacman_col;
    }
    if (ghost_row < pacman_row)
    {
        if (board[ghost_row + 1][ghost_col] != WALL_SYMBOL)
        {
            board[ghost_row][ghost_col] = COIN_SYMBOL;
            ghost_row++;
            board[ghost_row][ghost_col] = GHOST_SYMBOL;
        }
    }
    else if (ghost_row > pacman_row)
    {
        if (board[ghost_row - 1][ghost_col] != WALL_SYMBOL)
        {
            board[ghost_row][ghost_col] = COIN_SYMBOL;
            ghost_row--;
            board[ghost_row][ghost_col] = GHOST_SYMBOL;
        }
    }
    else if (ghost_col < pacman_col)
    {
        if (board[ghost_row][ghost_col + 1] != WALL_SYMBOL)
        {
            board[ghost_row][ghost_col] = COIN_SYMBOL;
            ghost_col++;
            board[ghost_row][ghost_col] = GHOST_SYMBOL;
        }
    }
    else if (ghost_col > pacman_col)
    {
        if (board[ghost_row][ghost_col - 1] != WALL_SYMBOL)
        {
            board[ghost_row][ghost_col] = COIN_SYMBOL;
            ghost_col--;
            board[ghost_row][ghost_col] = GHOST_SYMBOL;
        }
    }
}

/* Define function to print the board */
void print_board()
{
    int i, j;
    printf("\033[2J\033[1;1H");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == PACMAN_SYMBOL)
            {
                printf("%s%c", PACMAN_COLOR, board[i][j]);
            }
            else if (board[i][j] == GHOST_SYMBOL)
            {
                printf("%s%c", GHOST_COLOR, board[i][j]);
            }
            else
            {
                printf("%c", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("Coins left: %d\n", coin_count);
}

int main()
{
    int game_on = 1;
    init_board();
    while (game_on)
    {
        print_board();
        char key = getkey();
        update_board(key);
        if (coin_count == 0)
        {
            printf("Congratulations, you won!\n");
            game_on = 0;
        }
        else if (pacman_row == ghost_row && pacman_col == ghost_col)
        {
            printf("Game over, you lost!\n");
            game_on = 0;
        }
    }
    return 0;
}