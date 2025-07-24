//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

/* Function to read keyboard input without pressing enter */
char getch(){
    char c;
    struct termios oldattr, newattr;

    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);

    c = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);

    return c;
}

#define ROWS 20
#define COLS 30

/* Function to initialize the game board */
void initialize_board(int board[ROWS][COLS]){
    int i, j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(i==ROWS-1)
                board[i][j] = 1;
            else if(j==0 || j==COLS-1)
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
}

/* Function to print the game board */
void print_board(int board[ROWS][COLS]){
    int i, j;
    int brick_count = 0;
    system("clear");
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(board[i][j]==1){
                printf("#");
                brick_count++;
            }
            else if(board[i][j]==2){
                printf("O");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Bricks left: %d\n", brick_count-64);
}

/* Function to move the paddle */
void move_paddle(int board[ROWS][COLS], int paddle_pos[2]){
    char c = getch();

    if(c=='a' && paddle_pos[1]-1>0){
        board[paddle_pos[0]][paddle_pos[1]] = 0;
        paddle_pos[1]--;
        board[paddle_pos[0]][paddle_pos[1]] = 2;
    }
    else if(c=='d' && paddle_pos[1]+4<COLS){
        board[paddle_pos[0]][paddle_pos[1]+3] = 0;
        paddle_pos[1]++;
        board[paddle_pos[0]][paddle_pos[1]+3] = 2;
    }
}

/* Function to move the ball */
void move_ball(int board[ROWS][COLS], int paddle_pos[2], int ball_pos[2], int ball_dir[2], int *lives){
    int i;
    int new_pos[2] = { ball_pos[0] + ball_dir[0], ball_pos[1] + ball_dir[1] };

    int hit_paddle = (new_pos[0]==paddle_pos[0]-1 && new_pos[1]>=paddle_pos[1] && new_pos[1]<=paddle_pos[1]+3);

    if(board[new_pos[0]][new_pos[1]]==1){
        board[new_pos[0]][new_pos[1]] = 0;
        ball_dir[0] *= -1;
    }
    else if(board[new_pos[0]][new_pos[1]+1]==1){
        board[new_pos[0]][new_pos[1]+1] = 0;
        ball_dir[0] *= -1;
    }
    else if(board[new_pos[0]+1][new_pos[1]]==1){
        board[new_pos[0]+1][new_pos[1]] = 0;
        ball_dir[1] *= -1;
    }
    else if(board[new_pos[0]+1][new_pos[1]+1]==1){
        board[new_pos[0]+1][new_pos[1]+1] = 0;
        ball_dir[1] *= -1;
    }
    else if(new_pos[0]==ROWS-1){
        (*lives)--;
        if((*lives)==0){
            printf("Game Over!\n");
            exit(0);
        }
        ball_pos[0] = ROWS-3;
        ball_pos[1] = COLS/2;
        ball_dir[0] = -1;
        ball_dir[1] = 0;
    }
    else if(hit_paddle){
        ball_dir[0] *= -1;
    }

    board[ball_pos[0]][ball_pos[1]] = 0;
    ball_pos[0] += ball_dir[0];
    ball_pos[1] += ball_dir[1];
    board[ball_pos[0]][ball_pos[1]] = 3;
}

/* Main function */
int main(){
    int board[ROWS][COLS];
    int paddle_pos[2] = { ROWS-2, COLS/2-2 };
    int ball_pos[2] = { ROWS-3, COLS/2 };
    int ball_dir[2] = { -1, 0 };
    int lives = 3;

    initialize_board(board);
    board[paddle_pos[0]][paddle_pos[1]] = 2;
    board[ball_pos[0]][ball_pos[1]] = 3;

    while(1){
        print_board(board);
        move_paddle(board, paddle_pos);
        move_ball(board, paddle_pos, ball_pos, ball_dir, &lives);
        usleep(50000);
    }

    return 0;
}