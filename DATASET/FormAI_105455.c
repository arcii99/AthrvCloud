//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 50
#define HEIGHT 20
#define ENEMY_COUNT 10
#define BULLET_COUNT 5

char space[HEIGHT][WIDTH]; // Two dimensional array to represent the game field
int player_x = WIDTH / 2; // Starting position for player

// Struct to represent bullets
struct Bullet {
    int x;
    int y;
    int active;
};

// Struct to represent enemies
struct Enemy {
    int x;
    int y;
    int speed;
    int active;
};

// Initialize the game field with spaces
void initialize_space() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            space[i][j] = ' ';
        }
    }
}

// Draw the game field on the screen
void draw_space() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", space[i][j]);
        }
        printf("\n");
    }
}

// Move the player left
void move_player_left() {
    if (player_x > 0) {
        player_x--;
        space[HEIGHT-1][player_x] = 'X';
        space[HEIGHT-1][player_x+1] = ' ';
    }
}

// Move the player right
void move_player_right() {
    if (player_x < WIDTH-1) {
        player_x++;
        space[HEIGHT-1][player_x] = 'X';
        space[HEIGHT-1][player_x-1] = ' ';
    }
}

// Fire a bullet
void fire_bullet(struct Bullet bullet_list[]) {
    int i;
    for (i = 0; i < BULLET_COUNT; i++) {
        if (!bullet_list[i].active) {
            bullet_list[i].x = player_x;
            bullet_list[i].y = HEIGHT-2;
            bullet_list[i].active = 1;
            space[bullet_list[i].y][bullet_list[i].x] = '-';
            break;
        }
    }
}

// Move the bullets
void move_bullets(struct Bullet bullet_list[]) {
    int i;
    for (i = 0; i < BULLET_COUNT; i++) {
        if (bullet_list[i].active) {
            space[bullet_list[i].y][bullet_list[i].x] = ' ';
            bullet_list[i].y--;
            if (bullet_list[i].y < 0) {
                bullet_list[i].active = 0;
            }
            else {
                space[bullet_list[i].y][bullet_list[i].x] = '-';
            }
        }
    }
}

// Move the enemies
void move_enemies(struct Enemy enemy_list[]) {
    int i;
    for (i = 0; i < ENEMY_COUNT; i++) {
        if (enemy_list[i].active) {
            space[enemy_list[i].y][enemy_list[i].x] = ' ';
            enemy_list[i].y += enemy_list[i].speed;
            if (enemy_list[i].y > HEIGHT-1) {
                enemy_list[i].active = 0;
            }
            else {
                space[enemy_list[i].y][enemy_list[i].x] = 'O';
            }
        }
    }
}

// Collision detection for bullets and enemies
void detect_collisions(struct Bullet bullet_list[], struct Enemy enemy_list[]) {
    int i, j;
    for (i = 0; i < BULLET_COUNT; i++) {
        if (bullet_list[i].active) {
            for (j = 0; j < ENEMY_COUNT; j++) {
                if (enemy_list[j].active && bullet_list[i].x == enemy_list[j].x && bullet_list[i].y == enemy_list[j].y) {
                    bullet_list[i].active = 0;
                    enemy_list[j].active = 0;
                    space[bullet_list[i].y][bullet_list[i].x] = ' ';
                    space[enemy_list[j].y][enemy_list[j].x] = ' ';
                }
            }
        }
    }
}

// Main game loop
int main() {
    // Initialize the game field
    initialize_space();
    
    // Initialize the player
    space[HEIGHT-1][player_x] = 'X';
    
    // Initialize the bullets
    struct Bullet bullet_list[BULLET_COUNT];
    int i;
    for (i = 0; i < BULLET_COUNT; i++) {
        bullet_list[i].active = 0;
    }
    
    // Initialize the enemies
    struct Enemy enemy_list[ENEMY_COUNT];
    for (i = 0; i < ENEMY_COUNT; i++) {
        enemy_list[i].x = (rand() % (WIDTH-2)) + 1;
        enemy_list[i].y = 0;
        enemy_list[i].speed = (rand() % 3) + 1;
        enemy_list[i].active = 1;
        space[enemy_list[i].y][enemy_list[i].x] = 'O';
    }
    
    // Setup keyboard input
    struct termios orig_termios;
    tcgetattr(STDIN_FILENO, &orig_termios);
    struct termios new_termios = orig_termios;
    new_termios.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    
    // Main game loop
    while (1) {
        system("clear");
        
        // Handle keyboard input
        char c = ' ';
        if (read(STDIN_FILENO, &c, 1) == -1) {
            break;
        }
        if (c == 'a') {
            move_player_left();
        }
        if (c == 'd') {
            move_player_right();
        }
        if (c == ' ') {
            fire_bullet(bullet_list);
        }
        
        // Move bullets
        move_bullets(bullet_list);
        
        // Move enemies
        move_enemies(enemy_list);
        
        // Detect collisions
        detect_collisions(bullet_list, enemy_list);
        
        // Draw the game field
        draw_space();
        
        // Wait for a bit before continuing
        usleep(100000);
    }
    
    // Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
    
    return 0;
}