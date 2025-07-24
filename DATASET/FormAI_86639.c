//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLS 50

bool visited[ROWS][COLS];
char grid[ROWS][COLS];
int player_x, player_y;

void generate_map(){
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            grid[i][j] = '#';
            visited[i][j] = false;
        }
    }
    srand(time(NULL));
    int rooms = rand() % 6 + 5;
    for(i = 0; i < rooms; i++){
        int x = rand() % (ROWS - 10) + 1;
        int y = rand() % (COLS - 20) + 1;
        int width = rand() % 8 + 4;
        int height = rand() % 8 + 4;
        for(int r = x; r < x+height; r++){
            for(int c = y; c < y+width; c++){
                grid[r][c] = '.';
            }
        }
    }
    player_x = rand() % ROWS;
    player_y = rand() % COLS;
    grid[player_x][player_y] = '@';
}

void print_map(){
    system("clear");
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

bool is_valid_move(int x, int y){
    if(x < 0 || x >= ROWS || y < 0 || y >= COLS){
        return false;
    }
    if(grid[x][y] == '#'){
        return false;
    }
    return true;
}

void move_player(int dx, int dy){
    int new_x = player_x + dx;
    int new_y = player_y + dy;
    if(is_valid_move(new_x, new_y)){
        grid[player_x][player_y] = '.';
        player_x = new_x;
        player_y = new_y;
        grid[player_x][player_y] = '@';
    }
}

int main(){
    generate_map();
    print_map();
    char input;
    while(1){
        input = getchar();
        getchar(); // Clear input buffer
        switch(input){
            case 'h':
                move_player(0, -1);
                break;
            case 'j':
                move_player(1, 0);
                break;
            case 'k':
                move_player(-1, 0);
                break;
            case 'l':
                move_player(0, 1);
                break;
            case 'q':
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid input\n");
                break;
        }
        print_map();
    }
    return 0;
}