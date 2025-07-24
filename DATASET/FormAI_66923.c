//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MAP_SIZE 100
#define MAX_ITEMS 10

typedef struct {
    char symbol;
    int row;
    int col;
} Entity;

typedef struct {
    char symbol;
    int row;
    int col;
} Item;

int map[MAX_MAP_SIZE][MAX_MAP_SIZE];
Entity romeo, juliet;
Item items[MAX_ITEMS];

void create_new_map(int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            map[i][j] = rand() % 2;
        }
    }
}

void spawn_romeo() {
    int r, c;
    do {
        r = rand() % MAX_MAP_SIZE;
        c = rand() % MAX_MAP_SIZE;
    } while (map[r][c] != 0);
    romeo.symbol = 'R';
    romeo.row = r;
    romeo.col = c;
}

void spawn_juliet() {
    int r, c;
    do {
        r = rand() % MAX_MAP_SIZE;
        c = rand() % MAX_MAP_SIZE;
    } while (map[r][c] != 0);
    juliet.symbol = 'J';
    juliet.row = r;
    juliet.col = c;
}

void spawn_items(int num_items) {
    int i, r, c;
    for (i = 0; i < num_items; i++) {
        do {
            r = rand() % MAX_MAP_SIZE;
            c = rand() % MAX_MAP_SIZE;
        } while (map[r][c] != 0);
        items[i].symbol = '$';
        items[i].row = r;
        items[i].col = c;
    }
}

void render_map(int rows, int cols) {
    int i, j;
    printf("\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (romeo.row == i && romeo.col == j) {
                printf("%c", romeo.symbol);
            } else if (juliet.row == i && juliet.col == j) {
                printf("%c", juliet.symbol);
            } else {
                printf("%c", map[i][j] ? '#' : '.');
            }
        }
        printf("\n");
    }
}

void render_items(int num_items) {
    int i;
    for (i = 0; i < num_items; i++) {
        if (items[i].row != -1) {
            printf("\n%s is at (%d,%d)", items[i].symbol, items[i].row, items[i].col);
        }
    }
}

void move_entity(Entity *entity, int rows, int cols, int dr, int dc) {
    int new_r = entity->row + dr;
    int new_c = entity->col + dc;
    if (new_r < 0 || new_r >= rows || new_c < 0 || new_c >= cols) {
        printf("\n%s has hit the wall!", entity->symbol);
        return;
    }
    if (map[new_r][new_c] == 1) {
        printf("\n%s has hit the obstacle!", entity->symbol);
        return;
    }
    if (new_r == juliet.row && new_c == juliet.col) {
        printf("\n%s has found Juliet! Congratulations!", entity->symbol);
        exit(0);
    }
    int i;
    for (i = 0; i < MAX_ITEMS; i++) {
        if (items[i].row == new_r && items[i].col == new_c && items[i].symbol != 0) {
            printf("\n%s has found %s!", entity->symbol, items[i].symbol);
            items[i].row = -1;
            items[i].col = -1;
            return;
        }
    }
    entity->row = new_r;
    entity->col = new_c;
}

int main() {
    srand(time(NULL));
    create_new_map(MAX_MAP_SIZE, MAX_MAP_SIZE);
    spawn_romeo();
    spawn_juliet();
    spawn_items(MAX_ITEMS);
    
    int dr, dc;
    char input;
    do {
        render_map(MAX_MAP_SIZE, MAX_MAP_SIZE);
        render_items(MAX_ITEMS);
    
        printf("\nPlease enter your move (up, down, left, right): ");
        scanf(" %c", &input);
        switch (input) {
            case 'w':
                dr = -1;
                dc = 0;
                break;
            case 's':
                dr = 1;
                dc = 0;
                break;
            case 'a':
                dr = 0;
                dc = -1;
                break;
            case 'd':
                dr = 0;
                dc = 1;
                break;
            default:
                printf("\nInvalid input!");
                continue;
        }
        move_entity(&romeo, MAX_MAP_SIZE, MAX_MAP_SIZE, dr, dc);
        move_entity(&juliet, MAX_MAP_SIZE, MAX_MAP_SIZE, dr, dc);
    } while(1);
    
    return 0;
}