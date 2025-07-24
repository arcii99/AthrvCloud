//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 10
#define COL 10

int grid[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int open_set[ROW*COL], closed_set[ROW*COL];
int start_r = 2, start_c = 2, end_r = 8, end_c = 8;

int h(int r, int c){
    return abs(r - end_r) + abs(c - end_c);
}

void trace_path(int came_from[][COL], int r, int c){
    if (came_from[r][c] != -1){
        trace_path(came_from, came_from[r][c]/COL, came_from[r][c]%COL);
    }
    printf("(%d,%d)", r, c);
}

void A_star(int start_r, int start_c, int end_r, int end_c){
    int g_score[ROW][COL];
    for (int r = 0; r < ROW; r++){
        for (int c = 0; c < COL; c++){
            g_score[r][c] = INT_MAX;
        }
    }
    g_score[start_r][start_c] = 0;
    int f_score[ROW][COL];
    for (int r = 0; r < ROW; r++){
        for (int c = 0; c < COL; c++){
            f_score[r][c] = INT_MAX;
        }
    }
    f_score[start_r][start_c] = h(start_r, start_c);
    int came_from[ROW][COL];
    for (int r = 0; r < ROW; r++){
        for (int c = 0; c < COL; c++){
            came_from[r][c] = -1;
        }
    }
    int open_set_count = 0;
    open_set[open_set_count++] = start_r*COL + start_c;
    while (open_set_count > 0){
        int current = open_set[0], current_r = current/COL, current_c = current%COL;
        for (int i = 0; i < open_set_count-1; i++){
            open_set[i] = open_set[i+1];
        }
        open_set_count--;
        closed_set[current] = 1;
        if (current_r == end_r && current_c == end_c){
            trace_path(came_from, current_r, current_c);
            return;
        }
        int nb[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
        for (int i = 0; i < 8; i++){
            int nr = current_r + nb[i][0], nc = current_c + nb[i][1];
            if (nr < 0 || nc < 0 || nr >= ROW || nc >= COL || grid[nr][nc] == 1){
                continue;
            }
            int tentative_g_score = g_score[current_r][current_c] + 1;
            if (closed_set[nr*COL + nc] == 1 && tentative_g_score >= g_score[nr][nc]){
                continue;
            }
            if (closed_set[nr*COL + nc] != 1 || tentative_g_score < g_score[nr][nc]){
                came_from[nr][nc] = current_r*COL + current_c;
                g_score[nr][nc] = tentative_g_score;
                f_score[nr][nc] = g_score[nr][nc] + h(nr, nc);
                if (closed_set[nr*COL + nc] != 1){
                    for (int i = 0; i < open_set_count; i++){
                        if (open_set[i] == nr*COL + nc){
                            goto found;
                        }   
                    }
                    open_set[open_set_count++] = nr*COL + nc;
                }
                found:;
            }
        }
    }
    printf("No path found.");
}

int main(){
    grid[3][1] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;
    grid[3][4] = 1;
    grid[7][3] = 1;
    grid[7][4] = 1;
    grid[7][5] = 1;
    grid[8][5] = 1;
    A_star(start_r, start_c, end_r, end_c);
    return 0;
}