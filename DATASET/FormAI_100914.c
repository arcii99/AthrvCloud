//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define ROWS 7
#define COLS 10

/* Function to initialize the game board */
void init_board(char board[][COLS], int *ball_x, int *ball_y, int *paddle_x, int *paddle_y, int *score) {
    int i, j;
    srand(time(NULL));
    
    /* Initialize board with blank spaces */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
    
    /* Initialize paddle and ball positions */
    *paddle_x = 4;
    *paddle_y = 8;
    *ball_x = 3;
    *ball_y = 6;
    
    /* Place paddle on board */
    for (i = *paddle_x; i < *paddle_x + 3; i++) {
        board[6][i] = '=';
    }
    
    /* Place ball on board */
    board[*ball_x][*ball_y] = 'O';
    
    /* Initialize score to 0 */
    *score = 0;
}

/* Function to print the game board */
void print_board(char board[][COLS], int score) {
    int i, j;
    
    /* Print board */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    
    /* Print score */
    printf("Score: %d\n", score);
}

/* Function to move paddle left */
void move_left(int *paddle_x, char board[][COLS]) {
    int i;
    
    /* Check if it is possible to move left */
    if (*paddle_x > 0) {
        /* Remove paddle from current position */
        for (i = *paddle_x; i < *paddle_x + 3; i++) {
            board[6][i] = ' ';
        }
        /* Move paddle to new position */
        *paddle_x -= 1;
        for (i = *paddle_x; i < *paddle_x + 3; i++) {
            board[6][i] = '=';
        }
    }
}

/* Function to move paddle right */
void move_right(int *paddle_x, char board[][COLS]) {
    int i;
    
    /* Check if it is possible to move right */
    if (*paddle_x < COLS - 3) {
        /* Remove paddle from current position */
        for (i = *paddle_x; i < *paddle_x + 3; i++) {
            board[6][i] = ' ';
        }
        /* Move paddle to new position */
        *paddle_x += 1;
        for (i = *paddle_x; i < *paddle_x + 3; i++) {
            board[6][i] = '=';
        }
    }
}

/* Function to move ball and check for collisions */
int move_ball(int *ball_x, int *ball_y, int *paddle_x, int *paddle_y, char board[][COLS], int *score) {
    /* Move ball */
    board[*ball_x][*ball_y] = ' ';
    *ball_x -= 1;
    *ball_y += 1;
    board[*ball_x][*ball_y] = 'O';
    
    /* Check for collisions with walls */
    if (*ball_x == 0) {
        return 0;
    }
    if (*ball_y == COLS - 1 || *ball_y == 0) {
        *ball_y -= 1;
    }
    
    /* Check for collision with paddle */
    if (*ball_x == ROWS - 2 && (*ball_y == *paddle_y || *ball_y == *paddle_y + 1 || *ball_y == *paddle_y + 2)) {
        *score += 1;
        return 1;
    }
    
    return 2;
}

/* Function to read keyboard input */
int getch() {
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

int main() {
    char board[ROWS][COLS];
    int ball_x, ball_y, paddle_x, paddle_y, score, i, key_input, ball_state;
    init_board(board, &ball_x, &ball_y, &paddle_x, &paddle_y, &score);
    print_board(board, score);

    /* Game loop */
    while (1) {
        /* Move ball every 300ms */
        usleep(300000);
        ball_state = move_ball(&ball_x, &ball_y, &paddle_x, &paddle_y, board, &score);
        print_board(board, score);
        if (ball_state == 0) {
            printf("Game over!\n");
            break;
        }
        else if (ball_state == 1) {
            printf("Nice hit!\n");
        }
        
        /* Check for keyboard input */
        key_input = getch();
        if (key_input == 'a' || key_input == 'A') {
            move_left(&paddle_x, board);
        }
        else if (key_input == 'd' || key_input == 'D') {
            move_right(&paddle_x, board);
        }
    }
    
    return 0;
}