//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define MAX_NODES MAP_WIDTH*MAP_HEIGHT
#define MAP_GOAL_X 9
#define MAP_GOAL_Y 9

typedef struct {
    int x, y;
} node;

typedef struct {
    node pos;
    int g;
    int h;
    int f;
    int closed;
    int parent;
} path_node;

static path_node node_list[MAX_NODES];
static int node_count = 0;
static int open_list[MAX_NODES];
static int open_count = 0;

void add_node(node position, int parent_index, int g, int h) {
    int i;
    int node_index = -1;
    int new_f = g + h;

    for(i = 0; i < node_count; i++) {
        if(node_list[i].pos.x == position.x &&
                node_list[i].pos.y == position.y) {
            node_index = i;
            break;
        }
    }

    if(node_index == -1) {
        node_index = node_count++;
        node_list[node_index].pos = position;
        node_list[node_index].closed = 0;
        node_list[node_index].parent = parent_index;
        node_list[node_index].g = g;
        node_list[node_index].h = h;
        node_list[node_index].f = new_f;
    } else if(g < node_list[node_index].g) {
        node_list[node_index].parent = parent_index;
        node_list[node_index].g = g;
        node_list[node_index].f = new_f;
    }
}

int find_path(node start_pos, int* path) {
    int i;
    int current_index = -1;
    int goal_index = -1;
    int path_found = 0;
    int current_g = 0;
    int new_g = 0;
    node current_pos, new_pos;

    node_count = 0;
    open_count = 0;

    add_node(start_pos, -1, 0,
            abs(MAP_GOAL_X-start_pos.x) + abs(MAP_GOAL_Y-start_pos.y));

    while(open_count > 0) {
        current_index = open_list[0];
        current_pos = node_list[current_index].pos;

        if(current_pos.x == MAP_GOAL_X && current_pos.y == MAP_GOAL_Y) {
            goal_index = current_index;
            path_found = 1;
            break;
        }

        node_list[current_index].closed = 1;
        open_count--;
        open_list[0] = open_list[open_count];

        for(i = 0; i < 4; i++) {
            switch(i) {
                case 0:
                    new_pos.x = current_pos.x-1;
                    new_pos.y = current_pos.y;
                    break;
                case 1:
                    new_pos.x = current_pos.x+1;
                    new_pos.y = current_pos.y;
                    break;
                case 2:
                    new_pos.x = current_pos.x;
                    new_pos.y = current_pos.y-1;
                    break;
                case 3:
                    new_pos.x = current_pos.x;
                    new_pos.y = current_pos.y+1;
                    break;
            }

            if(new_pos.x < 0 || new_pos.x >= MAP_WIDTH ||
                    new_pos.y < 0 || new_pos.y >= MAP_HEIGHT) {
                continue; 
            }

            if(path[current_pos.x+MAP_WIDTH*current_pos.y] == 1) {
                continue;
            }

            if(path[new_pos.x+MAP_WIDTH*new_pos.y] == 1) {
                continue;
            }

            new_g = node_list[current_index].g + 1;

            add_node(new_pos, current_index, new_g,
                    abs(MAP_GOAL_X-new_pos.x) + abs(MAP_GOAL_Y-new_pos.y));

            for(i = open_count-1; i >= 0; i--) {
                if(node_list[open_list[i]].f <= node_list[open_list[0]].f) {
                    break;
                }

                open_list[i+1] = open_list[i];
            }

            open_list[i+1] = node_count-1;
            open_count++;
        }
    }

    if(path_found) {
        i = goal_index;
        int path_index = 0;

        while(node_list[i].parent != -1) {
            path[path_index++] = i;
            i = node_list[i].parent;
        }

        return path_index;
    }

    return -1;
}

int main() {
    int start_x = 0, start_y = 0;
    int path[(MAP_WIDTH*MAP_HEIGHT)/2];
    int path_length;

    int i, j;
    int map[MAP_WIDTH*MAP_HEIGHT] = {
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,1,0,0,1,0,
        0,0,0,0,0,1,0,0,1,0,
        0,0,0,0,0,1,0,0,1,0,
        0,0,0,0,1,1,1,1,1,0,
        0,0,1,1,1,1,0,0,1,0,
        0,0,1,0,0,0,0,0,1,0,
        0,0,1,0,0,0,0,0,1,0,
        0,0,1,0,0,0,0,0,1,0,
        0,0,1,0,0,0,0,0,0,0
    };

    path_length = find_path((node){start_x, start_y}, path);

    if(path_length >= 0) {
        printf("Path found from (%d,%d) to (%d,%d):\n",
                start_x, start_y, MAP_GOAL_X, MAP_GOAL_Y);

        for(i = path_length-1; i >= 0; i--) {
            printf("\t(%d,%d)\n", node_list[path[i]].pos.x, node_list[path[i]].pos.y);
        }
    } else {
        printf("Path not found from (%d,%d) to (%d,%d)\n",
                start_x, start_y, MAP_GOAL_X, MAP_GOAL_Y);
    }

    return 0;
}