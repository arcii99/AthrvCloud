//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

struct Node {
    int x,y;
    int cost;
    int heuristic;
    struct Node *parent;
};

int start_x, start_y, end_x, end_y;
int map[ROW][COL];
int visited[ROW][COL];

int heuristic(int x, int y) 
{
    return abs(end_x - x) + abs(end_y - y); // Manhatten Distance Heuristic
}

void add_to_frontier(struct Node *frontier[], struct Node *new_node, int *frontier_count) 
{
    for (int i=0; i < *frontier_count; i++){
        if (new_node->heuristic < frontier[i]->heuristic) {
            for (int j=*frontier_count-1; j >= i; j--) {
                frontier[j+1] = frontier[j];
            }
            frontier[i] = new_node;
            (*frontier_count)++;
            return;
        }
    }

    frontier[*frontier_count] = new_node;
    (*frontier_count)++;
}

void print_map() 
{
    printf("\n=================================================\n");
    for (int i=0; i < ROW; i++) {
        for (int j=0; j < COL; j++) {
            if (map[i][j] == 0) {
                printf(" .");
            } else {
                printf(" X");
            }
        }
        printf("\n");
    }
}

void print_path(struct Node *current_node) 
{
    while (current_node != NULL) {
        map[current_node->y][current_node->x] = 2;
        current_node = current_node->parent;
    }
}

void find_path() 
{
    struct Node *frontier[ROW*COL];
    int frontier_count = 0;
    frontier[frontier_count] = malloc(sizeof(struct Node));

    frontier[frontier_count]->x = start_x;
    frontier[frontier_count]->y = start_y;
    frontier[frontier_count]->cost = 0;
    frontier[frontier_count]->heuristic = heuristic(start_x, start_y);
    frontier[frontier_count]->parent = NULL; 
    visited[start_y][start_x] = 1;
    frontier_count = 1;

    struct Node *current_node;

    while (frontier_count > 0) {
        printf("\nFrontier:\n");
        for (int i=0; i < frontier_count; i++){
            printf("(%d, %d) Cost: %d, Heuristic: %d\n",
            frontier[i]->x,
            frontier[i]->y,
            frontier[i]->cost,
            frontier[i]->heuristic);
        }

        current_node = frontier[0];
        printf("\nExploring (%d, %d)\n", current_node->x, current_node->y);

        if (current_node->x == end_x && current_node->y == end_y) {
            print_path(current_node);
            printf("\nPath Found!\n");
            return;
        }

        for (int y=current_node->y-1; y <= current_node->y+1; y++){
            for (int x=current_node->x-1; x <= current_node->x+1; x++){
                
                if (x < 0 || y < 0 || x >= COL || y >= ROW){
                    continue;
                }
                if (x == current_node->x && y == current_node->y){
                    continue;
                }
                if (visited[y][x] == 1){
                    continue;
                }
                if (map[y][x] == 1){
                    continue;
                }
                printf("Adding (%d, %d)\n", x, y);

                struct Node *new_node = malloc(sizeof(struct Node));
                new_node->parent = current_node;
                new_node->x = x;
                new_node->y = y;
                new_node->cost = current_node->cost + 1;
                new_node->heuristic = heuristic(x, y);

                add_to_frontier(frontier, new_node, &frontier_count);
                visited[y][x] = 1;
            }
        }
        for (int i=1; i < frontier_count; i++){
            frontier[i-1] = frontier[i];
        }
        frontier_count--;
    }

    printf("\nERROR: No path found\n");
}

int main() {
    start_x = 2;
    start_y = 2;
    end_x = 8;
    end_y = 8;

    // Fill Map with Obstacles
    for (int i=0; i < ROW; i++) {
        for (int j=0; j < COL; j++) {
            if (i == 5 && j > 3 && j < 7) {
                map[i][j] = 1;
            } else if (i == 8 && j > 5 && j < 9) {
                map[i][j] = 1;
            } else if (i == 2 && j > 1 && j < 5) {
                map[i][j] = 1;
            } else if (i == 4 && j > 7 && j < 9) {
                map[i][j] = 1;
            } else {
                map[i][j] = 0;
            }
        }
    }

    visited[start_y][start_x] = 1;

    print_map();
    find_path();
    print_map();

    return 0;
}