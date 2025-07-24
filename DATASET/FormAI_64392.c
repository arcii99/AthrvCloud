//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

#define BOARD_WIDTH 30
#define BOARD_HEIGHT 20
#define BOARD_SIZE (BOARD_WIDTH * BOARD_HEIGHT)

#define INVADER_COUNT 20
#define MAX_BULLETS 3

#define ASCII_INVADER 'X'
#define ASCII_SHIP 'V'
#define ASCII_BULLET '^'

#define INVADER_MOVE_WAIT_NS 200000000
#define BULLET_MOVE_WAIT_NS 150000000
#define SHIP_MOVE_WAIT_NS 100000000


// Board
static char board[BOARD_HEIGHT][BOARD_WIDTH];
static pthread_mutex_t board_mutex;


// Invaders
typedef struct {
    int x, y;
    bool alive;
    pthread_t thread_id;
} invader_t;

static invader_t invaders[INVADER_COUNT];
static pthread_mutex_t invaders_mutex;


// Ship
typedef struct {
    int x, y;
    pthread_t thread_id;
} ship_t;

static ship_t ship;
static pthread_mutex_t ship_mutex;


// Bullets
typedef struct {
    int x, y;
    pthread_t thread_id;
} bullet_t;

static bullet_t bullets[MAX_BULLETS];
static pthread_mutex_t bullets_mutex;
static int bullet_count;


// Forward declarations
void init_game();
void init_board();
void init_invaders();
void init_ship();
void init_bullets();
void draw_board();
void move_invaders();
void move_ship();
void move_bullets();
void fire_bullet(int x, int y);
void kill_bullet(int i);
bool is_game_over();
void* invader_thread_func(void* arg);
void* ship_thread_func(void* arg);
void* bullet_thread_func(void* arg);


int main() {
    init_game();
    draw_board();
    
    while (!is_game_over()) {
        move_invaders();
        move_ship();
        move_bullets();
        draw_board();
        
        // Wait a bit for the next frame
        struct timespec ts = {0, 100000000};
        nanosleep(&ts, NULL);
    }
    
    printf("GAME OVER\n");
    
    return 0;
}


void init_game() {
    srand(time(NULL));
    init_board();
    init_invaders();
    init_ship();
    init_bullets();
}


void init_board() {
    pthread_mutex_init(&board_mutex, NULL);
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = ' ';
        }
    }
}


void init_invaders() {
    pthread_mutex_init(&invaders_mutex, NULL);
    for (int i = 0; i < INVADER_COUNT; i++) {
        invaders[i].x = rand() % (BOARD_WIDTH - 2) + 1;
        invaders[i].y = rand() % (BOARD_HEIGHT / 2) + 1;
        invaders[i].alive = true;
        
        pthread_create(&invaders[i].thread_id, NULL, invader_thread_func, &invaders[i]);
    }
}


void init_ship() {
    pthread_mutex_init(&ship_mutex, NULL);
    ship.x = BOARD_WIDTH / 2;
    ship.y = BOARD_HEIGHT - 2;
    pthread_create(&ship.thread_id, NULL, ship_thread_func, NULL);
}


void init_bullets() {
    pthread_mutex_init(&bullets_mutex, NULL);
    bullet_count = 0;
}


void draw_board() {
    pthread_mutex_lock(&board_mutex);
    system("clear");
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    pthread_mutex_unlock(&board_mutex);
}


void move_invaders() {
    struct timespec ts = {0, INVADER_MOVE_WAIT_NS};
    nanosleep(&ts, NULL);
    
    pthread_mutex_lock(&invaders_mutex);
    for (int i = 0; i < INVADER_COUNT; i++) {
        if (!invaders[i].alive) {
            continue;
        }
        
        // Erase current position
        pthread_mutex_lock(&board_mutex);
        board[invaders[i].y][invaders[i].x] = ' ';
        pthread_mutex_unlock(&board_mutex);
        
        // Move down
        invaders[i].y++;
        
        // Check for collision with ship
        pthread_mutex_lock(&ship_mutex);
        if (invaders[i].x == ship.x && invaders[i].y == ship.y) {
            printf("Ship hit by an invader!\n");
            exit(1);
        }
        pthread_mutex_unlock(&ship_mutex);
        
        // Check if invader is at the bottom
        if (invaders[i].y == BOARD_HEIGHT - 1) {
            invaders[i].alive = false;
            continue;
        }
        
        // Draw new position
        pthread_mutex_lock(&board_mutex);
        board[invaders[i].y][invaders[i].x] = ASCII_INVADER;
        pthread_mutex_unlock(&board_mutex);  
    }
    pthread_mutex_unlock(&invaders_mutex);
}


void move_ship() {
    struct timespec ts = {0, SHIP_MOVE_WAIT_NS};
    nanosleep(&ts, NULL);
    
    pthread_mutex_lock(&ship_mutex);
    int c = getchar();
    if (c == 'a' && ship.x > 1) {
        // Move left
        board[ship.y][ship.x] = ' ';
        ship.x--;
        board[ship.y][ship.x] = ASCII_SHIP;
    } else if (c == 'd' && ship.x < BOARD_WIDTH - 2) {
        // Move right
        board[ship.y][ship.x] = ' ';
        ship.x++;
        board[ship.y][ship.x] = ASCII_SHIP;
    }
    pthread_mutex_unlock(&ship_mutex);    
}


void move_bullets() {
    struct timespec ts = {0, BULLET_MOVE_WAIT_NS};
    nanosleep(&ts, NULL);
    
    pthread_mutex_lock(&bullets_mutex);
    for (int i = 0; i < bullet_count; i++) {
        // Erase current position
        pthread_mutex_lock(&board_mutex);
        board[bullets[i].y][bullets[i].x] = ' ';
        pthread_mutex_unlock(&board_mutex);
        
        // Move up
        bullets[i].y--;
        
        // Check for collision with invaders
        pthread_mutex_lock(&invaders_mutex);
        for (int j = 0; j < INVADER_COUNT; j++) {
            if (!invaders[j].alive) {
                continue;
            }
            if (bullets[i].x == invaders[j].x && bullets[i].y == invaders[j].y) {
                printf("Invader hit by a bullet!\n");
                invaders[j].alive = false;
                kill_bullet(i);
            }
        }
        pthread_mutex_unlock(&invaders_mutex);
        
        // Check if bullet is at the top
        if (bullets[i].y == 0) {
            kill_bullet(i);
        } else {
            // Draw new position
            pthread_mutex_lock(&board_mutex);
            board[bullets[i].y][bullets[i].x] = ASCII_BULLET;
            pthread_mutex_unlock(&board_mutex);
        }   
    }
    pthread_mutex_unlock(&bullets_mutex);
}


void fire_bullet(int x, int y) {
    pthread_mutex_lock(&bullets_mutex);
    if (bullet_count < MAX_BULLETS) {
        bullets[bullet_count].x = x;
        bullets[bullet_count].y = y - 1;
        pthread_create(&bullets[bullet_count].thread_id, NULL, bullet_thread_func, &bullets[bullet_count]);
        bullet_count++;
    }
    pthread_mutex_unlock(&bullets_mutex);
}


void kill_bullet(int i) {
    pthread_mutex_lock(&bullets_mutex);
    pthread_cancel(bullets[i].thread_id);
    bullet_count--;
    for (int j = i; j < bullet_count; j++) {
        bullets[j] = bullets[j + 1];
    }
    pthread_mutex_unlock(&bullets_mutex);
}


bool is_game_over() {
    pthread_mutex_lock(&invaders_mutex);
    bool result = true;
    for (int i = 0; i < INVADER_COUNT; i++) {
        if (invaders[i].alive) {
            result = false;
            break;
        }
    }
    pthread_mutex_unlock(&invaders_mutex);
    return result;
}


void* invader_thread_func(void* arg) {
    invader_t* invader = (invader_t*)arg;
    
    while (invader->alive) {
        // Wait a bit
        struct timespec ts = {0, INVADER_MOVE_WAIT_NS};
        nanosleep(&ts, NULL);
        
        // Check if invader is still alive
        pthread_mutex_lock(&invaders_mutex);
        if (!invader->alive) {
            pthread_mutex_unlock(&invaders_mutex);
            return NULL;
        }
        pthread_mutex_unlock(&invaders_mutex);
        
        // Check if bullet is already at this position
        pthread_mutex_lock(&bullets_mutex);
        bool bullet_collides = false;
        for (int i = 0; i < bullet_count; i++) {
            if (bullets[i].x == invader->x && bullets[i].y == invader->y + 1) {
                bullet_collides = true;
                break;
            }
        }
        pthread_mutex_unlock(&bullets_mutex);
        
        // If no bullet collides, fire a new one
        if (!bullet_collides) {
            fire_bullet(invader->x, invader->y);
        }
    }
    
    return NULL;
}


void* ship_thread_func(void* arg) {
    while (true) {
        // Wait for space key
        int c = getchar();
        if (c == ' ') {
            // Fire a bullet
            pthread_mutex_lock(&ship_mutex);
            fire_bullet(ship.x, ship.y);
            pthread_mutex_unlock(&ship_mutex);            
        }
    }
    
    return NULL;
}


void* bullet_thread_func(void* arg) {
    bullet_t* bullet = (bullet_t*)arg;
    while (true) {
        // Wait a bit
        struct timespec ts = {0, BULLET_MOVE_WAIT_NS};
        nanosleep(&ts, NULL);
        
        // Check if bullet is still alive
        pthread_mutex_lock(&bullets_mutex);
        bool bullet_still_exists = false;
        for (int i = 0; i < bullet_count; i++) {
            if (&bullets[i] == bullet) {
                bullet_still_exists = true;
                break;
            }
        }
        if (!bullet_still_exists) {
            pthread_mutex_unlock(&bullets_mutex);
            return NULL;
        }
        pthread_mutex_unlock(&bullets_mutex);
        
        // Check if it collides with something
        pthread_mutex_lock(&board_mutex);
        if (board[bullet->y - 1][bullet->x] == ASCII_INVADER) {
            // Hit an invader
            pthread_mutex_unlock(&board_mutex);
            return NULL;
        } else if (board[bullet->y - 1][bullet->x] == ASCII_SHIP) {
            // Hit the ship
            pthread_mutex_unlock(&board_mutex);
            printf("Ship hit by a bullet!\n");
            exit(1);
        }
        
        // Move bullet up
        board[bullet->y][bullet->x] = ' ';
        bullet->y--;
        board[bullet->y][bullet->x] = ASCII_BULLET;
        pthread_mutex_unlock(&board_mutex);
    }
    
    return NULL;
}