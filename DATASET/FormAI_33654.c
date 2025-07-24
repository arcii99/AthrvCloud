//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10
#define MAX 100

typedef struct {
    int x, y; // coordinates of node
    int f, g, h; // values for A* algorithm 
    int parent_x, parent_y; // coordinates of parent node
    int is_wall; // flag for wall or not 
} Node;

Node start, end; // starting and ending nodes
Node* open_list[MAX]; // list of all open nodes
int open_size=0; // size of open list
Node* closed_list[MAX]; // list of all closed nodes
int closed_size=0; // size of closed list
Node* wall_list[MAX]; // list of all wall nodes
int wall_size=0; // size of wall list

int heuristic(int x, int y) {
    return abs(end.x - x) + abs(end.y - y);
}

void add_open(Node* n) {
    if(open_size < MAX) {
        open_list[open_size] = n;
        open_size++;
    }
}

void add_closed(Node* n) {
    if(closed_size < MAX) {
        closed_list[closed_size] = n;
        closed_size++;
    }
}

void add_wall(Node* n) {
    if(wall_size < MAX) {
        wall_list[wall_size] = n;
        wall_size++;
    }
}

int is_valid(int x, int y) {
    if(x < 0 || x >= ROW || y < 0 || y >= COL) // out of bounds
        return 0;
    for(int i=0; i<wall_size; i++) { // check if wall
        if(wall_list[i]->x == x && wall_list[i]->y == y)
            return 0;
    }
    for(int i=0; i<closed_size; i++) { // check if closed list
        if(closed_list[i]->x == x && closed_list[i]->y == y)
            return 0;
    }
    return 1;
}

void update_node(Node* current, Node* neighbor) {
    neighbor->parent_x = current->x;
    neighbor->parent_y = current->y;
    neighbor->g = current->g + 1;
    neighbor->h = heuristic(neighbor->x, neighbor->y);
    neighbor->f = neighbor->g + neighbor->h;
}

void find_path() {
    add_open(&start);
    while(open_size > 0) {
        int current_index = 0;
        for(int i=0; i<open_size; i++) {
            if(open_list[i]->f < open_list[current_index]->f)
                current_index = i;
        }
        Node* current = open_list[current_index];
        if(current->x == end.x && current->y == end.y) { // path found
            printf("Path found!\n");
            return;
        }
        for(int x=-1; x<=1; x++) {
            for(int y=-1; y<=1; y++) {
                if(x == 0 && y == 0) // current node
                    continue;
                int neighbor_x = current->x + x;
                int neighbor_y = current->y + y;
                if(is_valid(neighbor_x, neighbor_y)) {
                    Node neighbor;
                    neighbor.x = neighbor_x;
                    neighbor.y = neighbor_y;
                    neighbor.is_wall = 0;
                    int in_open = 0, in_closed = 0;
                    for(int i=0; i<open_size; i++) { // check if already in open list
                        if(open_list[i]->x == neighbor.x && open_list[i]->y == neighbor.y) {
                            in_open = 1;
                            if(current->g + 1 < open_list[i]->g) { // found better path
                                update_node(current, open_list[i]);
                            }
                            break;
                        }
                    }
                    for(int i=0; i<closed_size; i++) { // check if already in closed list
                        if(closed_list[i]->x == neighbor.x && closed_list[i]->y == neighbor.y) {
                            in_closed = 1;
                            break;
                        }
                    }
                    if(!in_open && !in_closed) {
                        update_node(current, &neighbor);
                        add_open(&neighbor); // add to open list
                    }
                }
            }
        }
        add_closed(current); // add current node to closed list
        // remove from open list
        open_size--;
        for(int i=current_index; i<open_size; i++) {
            open_list[i] = open_list[i+1];
        }
    }
    printf("Path not found.\n");
}

int main() {
    // build wall
    for(int i=2; i<8; i++) {
        Node wall;
        wall.x = 5;
        wall.y = i;
        wall.is_wall = 1;
        add_wall(&wall);
    }
    // set start and end nodes
    start.x = 0;
    start.y = 0;
    start.parent_x = -1; // no parent
    start.parent_y = -1;
    start.is_wall = 0;
    start.g = 0;
    start.h = heuristic(start.x, start.y);
    start.f = start.g + start.h;
    end.x = 9;
    end.y = 9;
    end.parent_x = -1; // no parent
    end.parent_y = -1;
    end.is_wall = 0;
    end.g = 0;
    end.h = heuristic(end.x, end.y);
    end.f = end.g + end.h;
    // find path
    find_path();
    return 0;
}