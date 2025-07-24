//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: realistic
#include <stdio.h>

#define ROW 10
#define COLUMN 10

// struct to represent a node in the grid
typedef struct Node {
    int x;
    int y;
    int f;
    int g;
    int h;
    struct Node* parent;
} Node;

// function to calculate the Euclidean distance between two nodes
int euclidean(Node* start, Node* end) {
    int x = abs(start->x - end->x);
    int y = abs(start->y - end->y);
    return (int) (sqrt(x*x + y*y) * 10);
}

// function to find the node with the lowest f value in the open list
Node* lowest_f(Node** open_list, int size) {
    Node* lowest = open_list[0];
    for (int i = 0; i < size; i++) {
        if (open_list[i]->f < lowest->f) {
            lowest = open_list[i];
        }
    }
    return lowest;
}

// function to check if a node is in the closed list
int in_closed_list(Node** closed_list, Node* node, int size) {
    for (int i = 0; i < size; i++) {
        if (closed_list[i]->x == node->x && closed_list[i]->y == node->y) {
            return 1;
        }
    }
    return 0;
}

// function to check if a node is in the open list
int in_open_list(Node** open_list, Node* node, int size) {
    for (int i = 0; i < size; i++) {
        if (open_list[i]->x == node->x && open_list[i]->y == node->y) {
            return 1;
        }
    }
    return 0;
}

// function to add a node to the open list
void add_to_open_list(Node** open_list, Node* node, int* size) {
    open_list[*size] = node;
    (*size)++;
}

// function to remove a node from the open list
void remove_from_open_list(Node** open_list, Node* node, int* size) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (open_list[i]->x == node->x && open_list[i]->y == node->y) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < *size - 1; i++) {
            open_list[i] = open_list[i + 1];
        }
        (*size)--;
    }
}

// function to find the path from start to end using A*
Node** find_path(int grid[ROW][COLUMN], Node* start, Node* end) {
    Node* open_list[ROW * COLUMN];
    Node* closed_list[ROW * COLUMN];
    int open_size = 0;
    int closed_size = 0;

    add_to_open_list(open_list, start, &open_size);

    while (open_size > 0) {
        Node* current = lowest_f(open_list, open_size);
        if (current->x == end->x && current->y == end->y) {
            Node** path = malloc(sizeof(Node*) * ROW * COLUMN);
            Node* temp = current;
            int count = 0;
            while (temp != NULL) {
                path[count] = temp;
                temp = temp->parent;
                count++;
            }
            return path;
        }
        remove_from_open_list(open_list, current, &open_size);
        closed_list[closed_size] = current;
        closed_size++;

        // check neighbors
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (current->x + i < 0 || current->x + i >= ROW || current->y + j < 0 || current->y + j >= COLUMN) {
                    continue;
                }
                if (grid[current->x + i][current->y + j] == 0) {
                    continue;
                }
                Node* neighbor = malloc(sizeof(Node));
                neighbor->x = current->x + i;
                neighbor->y = current->y + j;
                neighbor->g = current->g + 10;
                neighbor->h = euclidean(neighbor, end);
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current;
                if (in_closed_list(closed_list, neighbor, closed_size)) {
                    free(neighbor);
                    continue;
                }
                if (!in_open_list(open_list, neighbor, open_size)) {
                    add_to_open_list(open_list, neighbor, &open_size);
                } else {
                    free(neighbor);
                }
            }
        }
    }

    // no path found
    return NULL;
}

int main() {
    int grid[ROW][COLUMN] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    Node start_node = {1, 1, 0};
    Node end_node = {8, 8, 0};

    Node** path = find_path(grid, &start_node, &end_node);
    if (path == NULL) {
        printf("No path found\n");
    } else {
        for (int i = ROW * COLUMN - 1; i >= 0; i--) {
            if (path[i] != NULL) {
                printf("(%d, %d) ", path[i]->x, path[i]->y);
            }
        }
        printf("\n");
        free(path);
    }

    return 0;
}