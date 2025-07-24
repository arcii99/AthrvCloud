//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: medieval
#include <stdio.h>

#define ROW_SIZE 8
#define COL_SIZE 8

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point from;
    int g, f;
} Square;

Square grid[ROW_SIZE][COL_SIZE];
Point path[ROW_SIZE*COL_SIZE];
int path_len;

Point start = {2, 1};
Point end = {7, 5};

void print_grid() {
    int i, j;
    for(i = 0; i < ROW_SIZE; i++) {
        for(j = 0; j < COL_SIZE; j++) {
            if(grid[i][j].g == -1)
                printf("X ");
            else if(i == start.x && j == start.y)
                printf("S ");
            else if(i == end.x && j == end.y)
                printf("E ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void print_path() {
    int i;
    printf("Path: ");
    for(i = path_len-1; i >= 0; i--) {
        printf("(%d, %d) ", path[i].x, path[i].y);
    }
    printf("\n");
}

int manhattan_dist(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int check_bounds(Point p) {
    return (p.x >= 0 && p.x < ROW_SIZE && p.y >= 0 && p.y < COL_SIZE);
}

void reconstruct_path(Square current) {
    while(current.from.x != start.x || current.from.y != start.y) {
        path[path_len++] = current.from;
        current = grid[current.from.x][current.from.y];
    }
}

void a_star() {
    Point neighbors[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    Square curr;
    curr.from = start;
    curr.g = 0;
    curr.f = curr.g + manhattan_dist(start, end);
    grid[curr.from.x][curr.from.y] = curr;
    Square open_set[ROW_SIZE*COL_SIZE];
    int open_set_len = 1;
    open_set[0] = curr;
    Square closed_set[ROW_SIZE][COL_SIZE] = {{{0}}};
    while(open_set_len > 0) {
        int i;
        int curr_idx = 0;
        for(i = 0; i < open_set_len; i++) {
            if(open_set[i].f < open_set[curr_idx].f)
                curr_idx = i;
        }
        curr = open_set[curr_idx];
        if(curr.from.x == end.x && curr.from.y == end.y) {
            reconstruct_path(curr);
            return;
        }
        open_set_len--;
        open_set[curr_idx] = open_set[open_set_len];
        closed_set[curr.from.x][curr.from.y] = curr;
        for(i = 0; i < 4; i++) {
            Point neighbor = {curr.from.x + neighbors[i].x, curr.from.y + neighbors[i].y};
            if(!check_bounds(neighbor) || closed_set[neighbor.x][neighbor.y].g != 0 || neighbor.x == curr.from.x && neighbor.y == curr.from.y)
                continue;
            int temp_g = curr.g + 1;
            int find_in_set = 0;
            int j;
            Square neighbor_set = {};
            for(j = 0; j < open_set_len; j++) {
                if(open_set[j].from.x == neighbor.x && open_set[j].from.y == neighbor.y) {
                    find_in_set = 1;
                    neighbor_set = open_set[j];
                    break;
                }
            }
            neighbor_set.from = neighbor;
            neighbor_set.g = temp_g;
            neighbor_set.f = neighbor_set.g + manhattan_dist(neighbor, end);
            if(!find_in_set) {
                open_set[open_set_len++] = neighbor_set;
                grid[neighbor.x][neighbor.y] = neighbor_set;
            }
            else if(temp_g < neighbor_set.g) {
                neighbor_set.g = temp_g;
                neighbor_set.f = neighbor_set.g + manhattan_dist(neighbor, end);
                open_set[j] = neighbor_set;
            }
        }
    }
}

int main() {
    int i, j;
    for(i = 0; i < ROW_SIZE; i++) {
        for(j = 0; j < COL_SIZE; j++) {
            grid[i][j].g = -1;
        }
    }
    grid[start.x][start.y].g = 0;
    printf("Initial Grid:\n");
    print_grid();
    a_star();
    printf("Final Grid:\n");
    print_grid();
    print_path();
    return 0;
}