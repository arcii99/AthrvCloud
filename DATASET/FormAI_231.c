//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 10
#define COLS 10

typedef struct{
    int row;
    int col;
} point;

float euclidean_distance(point a, point b){
    return sqrt(pow((a.row - b.row), 2) + pow((a.col - b.col), 2));
}

void print_map(int map[ROWS][COLS], point start, point end, point path[ROWS * COLS], int length){
    printf("Start: (%d, %d)\nEnd: (%d, %d)\n", start.row, start.col, end.row, end.col);
    printf("Map:\n");
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            int is_path = 0;
            for(int k = 0; k < length; k++){
                if(path[k].row == i && path[k].col == j){
                    is_path = 1;
                    break;
                }
            }
            if(is_path){
                printf("* ");
            } else if(i == start.row && j == start.col){
                printf("S ");
            } else if(i == end.row && j == end.col){
                printf("E ");
            } else if(map[i][j] == 0){
                printf("  ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

point* a_star(int map[ROWS][COLS], point start, point end){
    point* path = malloc(sizeof(point) * ROWS * COLS);
    int closed[ROWS][COLS];
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            closed[i][j] = 0;
        }
    }
    float g_score[ROWS][COLS];
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            g_score[i][j] = INFINITY;
        }
    }
    g_score[start.row][start.col] = 0;
    float f_score[ROWS][COLS];
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            f_score[i][j] = INFINITY;
        }
    }
    f_score[start.row][start.col] = euclidean_distance(start, end);
    point came_from[ROWS][COLS];
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            came_from[i][j].row = -1;
            came_from[i][j].col = -1;
        }
    }

    point* open = malloc(sizeof(point) * ROWS * COLS);
    int open_length = 1;
    open[0] = start;
    while(open_length > 0){
        point current = open[0];
        if(current.row == end.row && current.col == end.col){
            int path_length = 0;
            point point_path[ROWS * COLS];
            point_path[0] = current;
            while(came_from[current.row][current.col].row != -1){
                current = came_from[current.row][current.col];
                path_length++;
                point_path[path_length] = current;
            }
            for(int i = 0; i < path_length / 2; i++){
                point temp = point_path[i];
                point_path[i] = point_path[path_length - i];
                point_path[path_length - i] = temp;
            }
            for(int i = 0; i < ROWS * COLS; i++){
                if(i < path_length){
                    path[i] = point_path[i];
                } else {
                    path[i].row = -1;
                    path[i].col = -1;
                }
            }
            free(open);
            return path;
        }
        open[0] = open[open_length - 1];
        open_length--;
        point neighbors[4];
        neighbors[0].row = current.row - 1;
        neighbors[0].col = current.col;
        neighbors[1].row = current.row;
        neighbors[1].col = current.col - 1;
        neighbors[2].row = current.row + 1;
        neighbors[2].col = current.col;
        neighbors[3].row = current.row;
        neighbors[3].col = current.col + 1;
        for(int i = 0; i < 4; i++){
            point neighbor = neighbors[i];
            if(neighbor.row < 0 || neighbor.row >= ROWS || neighbor.col < 0 || neighbor.col >= COLS){
                continue;
            }
            if(map[neighbor.row][neighbor.col]){
                continue;
            }
            if(closed[neighbor.row][neighbor.col]){
                continue;
            }
            float tentative_g_score = g_score[current.row][current.col] + 1;
            if(tentative_g_score >= g_score[neighbor.row][neighbor.col]){
                continue;
            }
            came_from[neighbor.row][neighbor.col] = current;
            g_score[neighbor.row][neighbor.col] = tentative_g_score;
            f_score[neighbor.row][neighbor.col] = g_score[neighbor.row][neighbor.col] + euclidean_distance(neighbor, end);
            int j;
            for(j = open_length - 1; j >= 0; j--){
                if(f_score[open[j].row][open[j].col] <= f_score[neighbor.row][neighbor.col]){
                    break;
                }
                open[j + 1] = open[j];
            }
            open[j + 1] = neighbor;
            open_length++;
        }
    }
    free(open);
    free(path);
    point* empty_path = malloc(sizeof(point));
    empty_path[0].row = -1;
    empty_path[0].col = -1;
    return empty_path;
}

int main(){
    int map[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
    };
    point start;
    start.row = 8;
    start.col = 1;
    point end;
    end.row = 1;
    end.col = 1;
    point* path = a_star(map, start, end);
    int length = 0;
    while(path[length].row != -1){
        length++;
    }
    print_map(map, start, end, path, length);
    free(path);
    return 0;
}