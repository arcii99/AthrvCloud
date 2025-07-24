//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

//define the play area
#define ROWS 30
#define COLS 60

//game variables
int score = 0;
int bricks_left = 30;

//paddle variables
int paddle_pos = COLS / 2 - 3;

//ball variables
int ball_pos_x, ball_pos_y;
int ball_dir_x = 1, ball_dir_y = -1;

//bricks variables
int bricks[ROWS][COLS];

//get input from user without waiting for enter key
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

//initialize the bricks matrix and set them to 1 to indicate they have not been hit yet
void init_bricks() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            bricks[i][j] = 1;
        }
    }
}

//draw the game board with all the entities
void draw_board() {
    system("clear"); //to clear the screen
    printf("Score: %d\n\n", score);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                printf("#"); //draw the borders
            } else if (i == ROWS - 2 && j >= paddle_pos && j < paddle_pos + 6) {
                printf("="); //draw the paddle
            } else if (i == ball_pos_y && j == ball_pos_x) {
                printf("O"); //draw the ball
            } else if (bricks[i][j] == 1) {
                printf("*"); //draw the bricks
            } else {
                printf(" "); //draw empty spaces
            }
        }
        printf("\n");
    }
}

//update the position of the paddle based on user input
void update_paddle(char input) {
    if (input == 'a' && paddle_pos > 1) {
        paddle_pos--;
    } else if (input == 'd' && paddle_pos < COLS - 7) {
        paddle_pos++;
    }
}

//update the position of the ball and check for collision with the walls, paddle, and bricks
void update_ball() {
    ball_pos_x += ball_dir_x;
    ball_pos_y += ball_dir_y;

    if (ball_pos_x == 1 || ball_pos_x == COLS - 2) { //hit the left or right wall
        ball_dir_x *= -1;
    } else if (ball_pos_y == 1) { //hit the top wall
        ball_dir_y *= -1;
    } else if (ball_pos_y == ROWS - 2 && ball_pos_x >= paddle_pos && ball_pos_x < paddle_pos + 6) { //hit the paddle
        ball_dir_y *= -1;
    } else if (ball_pos_y == ROWS - 2 && (ball_pos_x < paddle_pos || ball_pos_x > paddle_pos + 5)) { //miss the paddle
        ball_pos_x = COLS / 2 - 1;
        ball_pos_y = ROWS / 2;
        ball_dir_x = 1;
        ball_dir_y = -1;
        score -= 2; //penalty for missing the paddle
    }

    //check for collision with the bricks
    if (ball_pos_y <= ROWS - 6) {
        if (bricks[ball_pos_y][ball_pos_x] == 1) {
            bricks[ball_pos_y][ball_pos_x] = 0;
            ball_dir_y *= -1;
            score++;
            bricks_left--;
        }
    }
}

//main function to run the game loop
int main() {
    srand(time(NULL)); //initialize the random seed
    ball_pos_x = COLS / 2 - 1; //initialize ball position
    ball_pos_y = ROWS / 2;
    init_bricks(); //initialize the bricks
    char input;

    while (1) { //game loop
        draw_board(); //draw the board
        if (bricks_left == 0) { //check for win condition
            printf("Congratulations, you won!\n");
            break;
        }
        if (ball_pos_y == ROWS - 1) { //check for game over condition
            printf("Game Over\n");
            break;
        }
        input = getch(); //get user input
        update_paddle(input);
        update_ball();
        usleep(50000); //delay the loop to allow user to see the changes
    }

    return 0;
}