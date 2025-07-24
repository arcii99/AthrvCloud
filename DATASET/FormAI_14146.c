//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

#define WIDTH 30
#define HEIGHT 20

// Terminal functions
static struct termios term, oterm;
static int getch(void);
static void set_input_mode(void);

// Game function prototypes
void init_game();
void draw_board();
void update_board();
void move_paddle(int dx);
bool is_collision(int x, int y);
void game_over();
bool is_win();
void color(int c);

// Global variables
int board[HEIGHT][WIDTH] = {0};
int score = 0;
int paddle_x = WIDTH / 2 - 2;
int paddle_y = HEIGHT - 2;
int ball_x = WIDTH / 2;
int ball_y = HEIGHT - 3;
int ball_dx = 1;
int ball_dy = -1;
bool game_running = true;

int main() {
    set_input_mode(); // Set terminal input mode
    init_game(); // Initialize game
    
    // Main game loop
    while (game_running) {
        usleep(100000); // Slow down game
        
        // Clear screen and draw board
        system("clear");
        draw_board();
        
        // Get user input
        int key = getch();
        switch (key) {
            case 'a': // Move paddle left
                move_paddle(-1);
                break;
            case 'd': // Move paddle right
                move_paddle(1);
                break;
            case 'q': // Quit game
                game_running = false;
                break;
        }
        
        // Update game state
        update_board();
        
        // Check for game over
        if (ball_y == HEIGHT - 1) {
            game_over();
        }
        
        // Check for win
        if (is_win()) {
            printf("\nYou win!\n");
            game_running = false;
        }
    }
    
    // Restore terminal mode
    tcsetattr(STDIN_FILENO, TCSANOW, &oterm);
    
    return 0;
}

void init_game() {
    // Set random seed
    srand(time(NULL));
    
    // Set initial ball direction randomly
    ball_dx = (rand() % 2) ? 1 : -1;
    
    // Set initial board layout
    for (int i = 0; i < HEIGHT - 3; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = (rand() % 2) ? 1 : 0;
        }
    }
}

void draw_board() {
    // Draw board and paddle
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == paddle_y && j >= paddle_x && j <= paddle_x + 3) {
                printf("="); // Paddle
            } else if (board[i][j] == 1) {
                color(4); // Red brick
                printf("O");
                color(9); // Reset color
            } else if (i == ball_y && j == ball_x) {
                printf("O"); // Ball
            } else {
                printf(" "); // Empty space
            }
        }
        printf("\n"); // New line
    }
    
    // Draw score
    printf("Score: %d\n", score);
}

void update_board() {
    // Move ball
    ball_x += ball_dx;
    ball_y += ball_dy;
    
    // Check for ball collision with walls or paddle
    if (ball_x == 0 || ball_x == WIDTH - 1) {
        ball_dx = -ball_dx; // Bounce off walls
    } else if (ball_y == paddle_y - 1 && ball_x >= paddle_x && ball_x <= paddle_x + 3) {
        ball_dy = -ball_dy; // Bounce off paddle
        score += 10;
    }
    
    // Check for ball collision with bricks
    if (is_collision(ball_x, ball_y)) {
        board[ball_y][ball_x] = 0; // Remove brick
        ball_dy = -ball_dy; // Bounce off brick
        score += 20;
    }
}

void move_paddle(int dx) {
    // Move paddle if within board limits
    if (paddle_x + dx >= 0 && paddle_x + dx + 3 <= WIDTH) {
        paddle_x += dx;
    }
}

bool is_collision(int x, int y) {
    // Check if ball collides with any brick
    if (y < 0 || y >= HEIGHT) {
        return false;
    }
    if (x < 0 || x >= WIDTH) {
        return false;
    }
    if (board[y][x] == 1) {
        return true;
    }
    return false;
}

void game_over() {
    printf("\nGame over! Final score: %d\n", score);
    game_running = false;
}

bool is_win() {
    // Check if all bricks have been destroyed
    for (int i = 0; i < HEIGHT - 3; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

void color(int c) {
    printf("\033[0;%dm", c);
}

// Terminal functions implementation

static void set_input_mode(void) {
    tcgetattr(STDIN_FILENO, &oterm);
    term = oterm;
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static int getch(void) {
    int c = 0;
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    if (select(1, &fds, NULL, NULL, &tv)) {
        c = getchar();
    }
    return c;
}