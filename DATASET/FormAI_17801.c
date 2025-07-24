//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

char board[HEIGHT][WIDTH];

typedef struct {
    int x, y;
} position;

typedef struct {
    position pos;
    char symbol;
} entity;

entity pacman = {{0, 0}, 'C'};
entity ghost = {{HEIGHT - 1, WIDTH - 1}, 'G'};

void clear_board(){
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            board[i][j] = '.';
        }
    }
}

void print_board(){
    printf("\n");
    printf("  ");
    for(int i=0; i<WIDTH; i++){
        printf("%d", i % 10);
    }
    printf("\n");
    for(int i=0; i<HEIGHT; i++){
        printf("%d ", i);
        for(int j=0; j<WIDTH; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void update_entity(entity *e, int new_x, int new_y){
    board[e->pos.x][e->pos.y] = '.';
    e->pos.x = new_x;
    e->pos.y = new_y;
    board[e->pos.x][e->pos.y] = e->symbol;
}

bool move_pacman(char direction){
    int new_x = pacman.pos.x;
    int new_y = pacman.pos.y;
    if(direction == 'w' && pacman.pos.x > 0){ // up
        new_x--;
    }else if(direction == 's' && pacman.pos.x < HEIGHT-1){ // down
        new_x++;
    }else if(direction == 'a' && pacman.pos.y > 0){ // left
        new_y--;
    }else if(direction == 'd' && pacman.pos.y < WIDTH-1){ // right
        new_y++;
    }else{
        return false;
    }
    if(board[new_x][new_y] == '.'){
        update_entity(&pacman, new_x, new_y);
        return true;
    }else if(board[new_x][new_y] == 'G'){
        printf("\nGame Over! Ghost caught you.");
        return false;
    }
}

void move_ghost(){
    int dx = pacman.pos.x - ghost.pos.x;
    int dy = pacman.pos.y - ghost.pos.y;

    int new_x = ghost.pos.x;
    int new_y = ghost.pos.y;

    if(dx > 0 && ghost.pos.x < HEIGHT-1){ // move down
        new_x++;
    }else if(dx < 0 && ghost.pos.x > 0){ // move up
        new_x--;
    }

    if(dy > 0 && ghost.pos.y < WIDTH-1){ // move right
        new_y++;
    }else if(dy < 0 && ghost.pos.y > 0){ // move left
        new_y--;
    }

    if(board[new_x][new_y] == '.'){
        update_entity(&ghost, new_x, new_y);
    }
}

int main(){
    srand(time(NULL));
    clear_board();
    board[pacman.pos.x][pacman.pos.y] = pacman.symbol;
    board[ghost.pos.x][ghost.pos.y] = ghost.symbol;

    char input;
    while(true){
        print_board();
        printf("\nEnter a direction (wasd): ");
        scanf(" %c", &input);
        if(move_pacman(input) == false){
            break;
        }
        move_ghost();
    }
    return 0;
}