//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COLUMN 10

// Define structure for Node
typedef struct Node {
    int x;
    int y;
    int f;
    int g;
    int h;
    int is_obstacle;
    struct Node *parent;
} Node;

// Declare global 2D grid
Node grid[ROW][COLUMN];

// Initialize grid with random obstacles
void initialize() {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COLUMN; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].f = 0;
            grid[i][j].g = 0;
            grid[i][j].h = 0;
            grid[i][j].is_obstacle = rand() % 2;
            grid[i][j].parent = NULL;
        }
    }
}

// Check if given node is valid
int is_valid(int x, int y) {
    if(x >= 0 && x < ROW && y >= 0 && y < COLUMN) {
        if(!grid[x][y].is_obstacle) {
            return 1;
        }
    }
    return 0;
}

// Calculate Manhattan distance between two nodes
int manhattan_distance(Node *a, Node *b) {
    int d = abs(a->x - b->x) + abs(a->y - b->y);
    return d;
}

// Find path from start node to end node using A* algorithm
void a_star_algorithm(Node *start, Node *end) {
    Node *open_set = start;
    Node *closed_set = NULL;
    Node *current = NULL;
    
    while(open_set != NULL) {
        current = open_set;
        
        // If current node is the end node, return path
        if(current->x == end->x && current->y == end->y) {
            while(current->parent != NULL) {
                printf("(%d, %d) -> ", current->x, current->y);
                current = current->parent;
            }
            printf("(%d, %d)\n", start->x, start->y);
            return;
        }
        
        // Remove the current node from the open set
        open_set = open_set->parent;
        
        // Add the current node to the closed set
        current->parent = closed_set;
        closed_set = current;
        
        // Check adjacent nodes
        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }
                
                // Calculate the f, g, and h values for adjacent nodes
                int x = current->x + i;
                int y = current->y + j;
                
                if(is_valid(x, y)) {
                    Node *adjacent = &grid[x][y];
                    int g = current->g + 1;
                    int h = manhattan_distance(adjacent, end);
                    int f = g + h;
                    
                    // If adjacent node is already in the closed set, continue
                    int in_closed_set = 0;
                    Node *temp = closed_set;
                    while(temp != NULL) {
                        if(temp->x == adjacent->x && temp->y == adjacent->y) {
                            in_closed_set = 1;
                            break;
                        }
                        temp = temp->parent;
                    }
                    if(in_closed_set) {
                        continue;
                    }
                    
                    // If adjacent node is not in the open set, add it
                    if(adjacent->parent == NULL) {
                        adjacent->f = f;
                        adjacent->g = g;
                        adjacent->h = h;
                        adjacent->parent = open_set;
                        open_set = adjacent;
                    }
                    
                    // If adjacent node is already in the open set, update its values if necessary
                    else if(f < adjacent->f) {
                        adjacent->f = f;
                        adjacent->g = g;
                        adjacent->h = h;
                        adjacent->parent = open_set;
                    }
                }
            }
        }
    }
    
    // If no path exists, print error message
    printf("No path exists from (%d, %d) to (%d, %d)\n", start->x, start->y, end->x, end->y);
}

int main() {
    // Initialize grid
    initialize();
    
    // Choose start and end nodes
    Node *start = &grid[0][0];
    Node *end = &grid[ROW-1][COLUMN-1];
    
    // Print initial grid
    printf("Initial grid:\n");
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COLUMN; j++) {
            if(grid[i][j].is_obstacle) {
                printf("# ");
            }
            else if(i == start->x && j == start->y) {
                printf("S ");
            }
            else if(i == end->x && j == end->y) {
                printf("E ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
    
    // Find path from start to end using A* algorithm
    printf("A* search:\n");
    a_star_algorithm(start, end);

    return 0;
}