//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 8

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int cost[8] = {10, 14, 10, 14, 10, 14, 10, 14};

int heuristic(int x1, int y1, int x2, int y2){
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    return 10 * (dx + dy) + (14 - 2 * 10) * (dx < dy ? dx : dy);
}

typedef struct {
    int x, y; // index of node
    int f, g; // f:heuristic + g:distance
} Node;

int map[ROW][COL] = {{0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 1, 0, 0, 0, 0},
                     {0, 0, 0, 1, 0, 0, 0, 0},
                     {0, 0, 0, 1, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0}};

bool visited[ROW][COL];

void print_map(){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(map[i][j] == 0){
                printf("%c", ' ');
            }
            else if(map[i][j] == 1){
                printf("%c", 'X');
            }
            else{
                printf("%c", '?');
            }
        }
        printf("\n");
    }
}

void print_route(int sx, int sy, int tx, int ty){
    Node n = {tx, ty, 0, 0};
    while(!(n.x == sx && n.y == sy)){
        printf("(%d,%d)<-", n.x, n.y);
        int x = n.x, y = n.y;
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < ROW && ny >= 0 && ny < COL && visited[nx][ny]){
                n.x = nx, n.y = ny;
                break;
            }
        }
    }
    printf("(%d,%d)\n", sx, sy);
}

Node best_node(int tx, int ty, int x, int y, int f, int g){
    Node node = {x, y, f + heuristic(x, y, tx, ty), g};
    if(map[x][y] == 1){
        node.f += 1000;
    }
    return node;
}

Node find_min_f_node(Node* nodes, size_t len){
    Node node = {0};
    node.f = 1e9 + 1e8;
    for(int i = 0; i < len; i++){
        if(nodes[i].f < node.f){
            node = nodes[i];
        }
    }
    return node;
}

bool astar(int sx, int sy, int tx, int ty){
    Node start = {sx, sy, heuristic(sx, sy, tx, ty), 0};
    if(map[sx][sy] == 1){
        return false;
    }
    Node nodes[ROW * COL];
    size_t len = 0;
    nodes[len++] = start;
    while(len != 0){
        Node node = find_min_f_node(nodes, len);
        visited[node.x][node.y] = true;
        if(node.x == tx && node.y == ty){
            print_route(sx, sy, tx, ty);
            return true;
        }
        for(int i = 0; i < 8; i++){
            int nx = node.x + dx[i], ny = node.y + dy[i];
            if(nx >= 0 && nx < ROW && ny >= 0 && ny < COL && !visited[nx][ny]){
                int g = node.g + cost[i];
                nodes[len++] = best_node(tx, ty, nx, ny, node.f, g);
                visited[nx][ny] = true;
            }
        }
    }
    return false;
}

int main(){
    int sx = 0, sy = 0, tx = ROW - 1, ty = COL - 1;
    printf("Map:\n");
    print_map();
    if(astar(sx, sy, tx, ty)){
        printf("Path exists!\n");
    }
    else{
        printf("No path found!\n");
    }
    return 0;
}