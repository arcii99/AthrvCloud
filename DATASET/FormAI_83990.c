//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#define CLEAR() printf("\033[H\033[J")
#define BORDERS() printf("==========\n")
#define ROWS 20
#define COLS 10

int getch(void);
void draw_board(char board[ROWS][COLS]);
void draw_border(void);
void move_player(char board[ROWS][COLS], int player_pos);
void shoot_bullet(char board[ROWS][COLS], int player_pos, int *bullet_pos, int *bullet_fired);
void move_bullet(char board[ROWS][COLS], int *bullet_pos, int *bullet_fired);

int main()
{
    char board[ROWS][COLS] = {0};
    int player_pos = COLS/2;
    int bullet_pos = -1;
    int bullet_fired = 0;
    int game_over = 0;
    
    while(!game_over)
    {
        CLEAR(); // clear the terminal screen
        draw_border(); // draw game borders
        draw_board(board); // draw game board
        move_player(board, player_pos); // update player position
        shoot_bullet(board, player_pos, &bullet_pos, &bullet_fired); // shoot a bullet if spacebar is pressed
        if(bullet_fired == 1)
        {
            move_bullet(board, &bullet_pos, &bullet_fired); // move fired bullet
        }
        usleep(100000); // sleep for 100ms
    }
    return 0;
}

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

void draw_board(char board[ROWS][COLS])
{
    int r, c;
    for(r=0; r<ROWS; r++)
    {
        for(c=0; c<COLS; c++)
        {
            if(board[r][c] == 1)
            {
                printf("O");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void draw_border(void)
{
    BORDERS();
    printf("|         |\n");
    printf("|         |\n");
    BORDERS();
}

void move_player(char board[ROWS][COLS], int player_pos)
{
    int ch = getch();
    if(ch == 'a' && player_pos > 0) // move left
    {
        board[ROWS-1][player_pos-1] = 1;
        board[ROWS-1][player_pos+1] = 0;
        player_pos--;
    }
    else if(ch == 'd' && player_pos < COLS-1) // move right
    {
        board[ROWS-1][player_pos+1] = 1;
        board[ROWS-1][player_pos-1] = 0;
        player_pos++;
    }
}

void shoot_bullet(char board[ROWS][COLS], int player_pos, int *bullet_pos, int *bullet_fired)
{
    if(getch() == ' ') // spacebar to shoot bullet
    {
        board[ROWS-2][player_pos] = 1;
        *bullet_pos = ROWS-2;
        *bullet_fired = 1;
    }
}

void move_bullet(char board[ROWS][COLS], int *bullet_pos, int *bullet_fired)
{
    if(*bullet_pos > 0) // move bullet up
    {
        board[*bullet_pos][COLS/2] = 0;
        board[*bullet_pos-1][COLS/2] = 1;
        (*bullet_pos)--;
    }
    else // bullet hit top border
    {
        board[0][COLS/2] = 0;
        *bullet_fired = 0;
        *bullet_pos = -1;
    }
}