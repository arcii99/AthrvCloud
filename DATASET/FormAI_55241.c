//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10

int map[WIDTH][HEIGHT] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int start[2] = {0,0};
int end[2] = {9,9};

int* pathfind() {
    int H = abs(end[0] - start[0]) + abs(end[1] - start[1]);

    int open_list[WIDTH*HEIGHT][3];
    int closed_list[WIDTH*HEIGHT][3];
    int p, q, r, s;
    for(p=0; p<WIDTH*HEIGHT; p++) { open_list[p][0] = -1; open_list[p][1] = -1; open_list[p][2] = -1; }
    for(q=0; q<WIDTH*HEIGHT; q++) { closed_list[q][0] = -1; closed_list[q][1] = -1; closed_list[q][2] = -1; }
    p = 0;
    open_list[p][0] = start[0]; open_list[p][1] = start[1]; open_list[p][2] = H;

    while(open_list[0][0] != -1) {
        p = 0;
        int min = open_list[0][2];
        for(q=1; q<WIDTH*HEIGHT; q++) {
            if(open_list[q][0] == -1) { break; }
            if(open_list[q][2] < min) {
                min = open_list[q][2];
                p = q; }
            if(open_list[q][2] == min) {
                if(abs(open_list[q][0] - end[0]) + abs(open_list[q][1] - end[1]) < abs(open_list[p][0] - end[0]) + abs(open_list[p][1] - end[1])) {
                    p = q; } } }
        int x = open_list[p][0];
        int y = open_list[p][1];
        closed_list[s][0] = open_list[p][0];
        closed_list[s][1] = open_list[p][1];
        closed_list[s][2] = open_list[p][2];
        open_list[p][0] = -1;
        s++;

        if(x == end[0] && y == end[1]) {
            int* path = malloc(sizeof(int) * s * 2);
            for(r=0; r<s; r++) { path[r*2] = closed_list[r][0]; path[r*2 + 1] = closed_list[r][1]; }
            return path; }

        int neighbors[8][2] = {{x-1, y}, {x-1, y-1}, {x, y-1}, {x+1, y-1}, {x+1, y}, {x+1, y+1}, {x, y+1}, {x-1, y+1}};
        for(q=0; q<8; q++) {
            int nx = neighbors[q][0];
            int ny = neighbors[q][1];
            if(nx < 0 || ny < 0 || nx >= WIDTH || ny >= HEIGHT || map[nx][ny] == 1) { continue; }
            int H = abs(nx - end[0]) + abs(ny - end[1]);
            int G = closed_list[s-1][2] - abs(nx - end[0]) - abs(ny - end[1]);
            bool skip = false;
            for(r=0; r<s; r++) {
                if(closed_list[r][0] == nx && closed_list[r][1] == ny) {
                    if(closed_list[r][2] > G+H) {
                        closed_list[r][2] = G+H; }
                    else { skip = true; }
                    break; } }
            if(skip) { continue; }
            for(r=0; r<WIDTH*HEIGHT; r++) {
                if(open_list[r][0] == -1) { break; }
                if(open_list[r][0] == nx && open_list[r][1] == ny) {
                    if(open_list[r][2] > G+H) {
                        open_list[r][2] = G+H; }
                    skip = true;
                    break; } }
            if(skip) { continue; }
            int f = G + H;
            int i = 0;
            while(open_list[i][0] != -1) { i++; }
            open_list[i][0] = nx;
            open_list[i][1] = ny;
            open_list[i][2] = f; }
    }

    return NULL;
}

int main() {
    int i, j;

    int* path = pathfind();
    for(i=0; i<HEIGHT; i++) {
        for(j=0; j<WIDTH; j++) {
            if(map[i][j] == 1) { printf("#"); }
            else if(i == start[0] && j == start[1]) { printf("S"); }
            else if(i == end[0] && j == end[1]) { printf("E"); }
            else {
                bool in_path = false;
                int k;
                for(k=1; k<path[0]; k++) {
                    if(i == path[k*2] && j == path[k*2+1]) {
                        printf(".");
                        in_path = true;
                        break; }
                }
                if(!in_path) { printf(" "); }
            }
        }
        printf("\n");
    }

    return 0;
}