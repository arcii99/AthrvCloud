//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 20

// Player struct
typedef struct Player {
    int x;
    int y;
    int score;
} Player;

// Fruit struct
typedef struct Fruit {
    int x;
    int y;
    int value;
} Fruit;

// Function to print game board
void print_board(Player p, Fruit f, char board[][WIDTH+1]) {
    system("clear"); // Clear terminal window
    for(int i=0; i<HEIGHT; i++) {
        printf("%s\n", board[i]);
    }
    printf("Score: %d\n", p.score);
    printf("Fruit value: %d\n", f.value);
}

// Function to update player position
void update_player(Player* p, char board[][WIDTH+1], char move) {
    int new_x = p->x;
    int new_y = p->y;
    if(move == 'w' && p->y > 0 && board[p->y-1][p->x] != '|') {
        new_y--;
    } else if(move == 'a' && p->x > 0 && board[p->y][p->x-1] != '|') {
        new_x--;
    } else if(move == 's' && p->y < HEIGHT-1 && board[p->y+1][p->x] != '|') {
        new_y++;
    } else if(move == 'd' && p->x < WIDTH-1 && board[p->y][p->x+1] != '|') {
        new_x++;
    }
    p->x = new_x;
    p->y = new_y;
}

// Function to update fruit position
void update_fruit(Fruit* f, Player p) {
    int new_x = rand() % WIDTH;
    int new_y = rand() % HEIGHT;
    if(new_x == p.x && new_y == p.y) {
        update_fruit(f, p); // Fruit spawned on player, try again
        return;
    }
    f->x = new_x;
    f->y = new_y;
    f->value = rand() % 10 + 1; // Random value between 1-10
}

int main() {
    char board[HEIGHT][WIDTH+1];
    srand(time(NULL)); // Initialize random seed

    // Initialize player, fruit and board
    Player player = {WIDTH/2, HEIGHT-1, 0};
    Fruit fruit = {rand() % WIDTH, rand() % HEIGHT, rand() % 10 + 1};
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            if(i == player.y && j == player.x) {
                board[i][j] = 'O'; // Player symbol
            } else if(i == fruit.y && j == fruit.x) {
                board[i][j] = '*'; // Fruit symbol
            } else {
                board[i][j] = ' '; // Empty space symbol
            }
            if(i == 0 || i == HEIGHT-1) {
                board[i][j] = '-'; // Wall symbol
            }
            if(j == 0 || j == WIDTH-1) {
                board[i][j] = '|'; // Wall symbol
            }
            board[i][WIDTH] = '\0'; // Null terminate each row
        }
    }

    char move; // Player move input
    while(1) { // Infinite loop until game over
        print_board(player, fruit, board);
        printf("Enter move (w,a,s,d): ");
        scanf(" %c", &move);
        update_player(&player, board, move);
        if(player.x == fruit.x && player.y == fruit.y) { // Player collected fruit
            player.score += fruit.value;
            update_fruit(&fruit, player);
        }
    }
    return 0;
}