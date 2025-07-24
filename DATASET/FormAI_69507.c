//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROW 5
#define COL 5

// Structure for each cell in the grid
struct cell {
    int row;
    int col;
};

// Structure for the node in the Priority Queue
struct pqnode {
    struct cell c;
    int f;
};

int grid[ROW][COL] = {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

bool closed_list[ROW][COL];
struct cell came_from[ROW][COL];
int g_scores[ROW][COL];
int f_scores[ROW][COL];

// Helper function to calculate the heuristic value
int heuristic(struct cell current, struct cell goal) {
    int h_score = abs(goal.row - current.row) + abs(goal.col - current.col);
    return h_score;
}

// Helper function to check if a cell is a valid neighbor
bool is_neighbor_valid(struct cell current, int row, int col) {
    if (row < 0 || col < 0 || row >= ROW || col >= COL || grid[row][col] == 1 || closed_list[row][col]) {
        return false;
    }
    return true;
}

// Helper function to get the neighbor cells
void get_neighbors(struct cell current, struct cell* neighbors, int* neighbors_count, struct cell goal) {
    int row = current.row;
    int col = current.col;
    *neighbors_count = 0;
    
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int neighbor_row = row + i;
            int neighbor_col = col + j;
            if (is_neighbor_valid(current, neighbor_row, neighbor_col)) {
                neighbors[*neighbors_count].row = neighbor_row;
                neighbors[*neighbors_count].col = neighbor_col;
                (*neighbors_count)++;
            }
        }
    }
}

// Helper function to get the node with the lowest f-score from the PriorityQueue
struct pqnode get_lowest_fscore_node(struct pqnode* pq, int count) {
    int index = 0;
    int lowest_fscore = pq[0].f;
    for (int i = 0; i < count; i++) {
        if (pq[i].f < lowest_fscore) {
            index = i;
            lowest_fscore = pq[i].f;
        }
    }
    return pq[index];
}

// Helper function to add a node to the PriorityQueue
void add_to_pq(struct pqnode* pq, int* count, struct cell current, int f_score) {
    struct pqnode node;
    node.c = current;
    node.f = f_score;
    pq[*count] = node;
    (*count)++;
}

// Main function for the A* Pathfinding algorithm
void a_star(struct cell start, struct cell goal) {
    memset(closed_list, false, sizeof closed_list);
    memset(g_scores, -1, sizeof g_scores);
    memset(f_scores, -1, sizeof f_scores);
    
    int current_f_score = 0;
    int count_pq = 0;
    struct pqnode pq[ROW * COL];
    add_to_pq(pq, &count_pq, start, heuristic(start, goal));
    g_scores[start.row][start.col] = 0;
    f_scores[start.row][start.col] = heuristic(start, goal);
    
    while (count_pq > 0) {
        struct pqnode current_node = get_lowest_fscore_node(pq, count_pq);
        struct cell current = current_node.c;
        
        if (current.row == goal.row && current.col == goal.col) {
            printf("Goal found!\n");
            return;
        }
        
        closed_list[current.row][current.col] = true;
        
        struct cell neighbors[8];
        int neighbors_count = 0;
        get_neighbors(current, neighbors, &neighbors_count, goal);
        
        for (int i = 0; i < neighbors_count; i++) {
            int tentative_g_score = g_scores[current.row][current.col] + 1;
            struct cell neighbor = neighbors[i];
            
            if (tentative_g_score < g_scores[neighbor.row][neighbor.col]) {
                g_scores[neighbor.row][neighbor.col] = tentative_g_score;
                f_scores[neighbor.row][neighbor.col] = tentative_g_score + heuristic(neighbor, goal);
                came_from[neighbor.row][neighbor.col] = current;
                current_f_score = f_scores[neighbor.row][neighbor.col];
                add_to_pq(pq, &count_pq, neighbor, current_f_score);
            }
        }
    }
    printf("Goal not found.\n");
}

// Helper function to print the path found from A* algorithm
void print_path(struct cell start, struct cell goal) {
    struct cell current = goal;
    while (current.row != start.row || current.col != start.col) {
        printf("(%d, %d) -> ", current.row, current.col);
        current = came_from[current.row][current.col];
    }
    printf("(%d, %d)\n", start.row, start.col);
}

// Main function to test the A* Pathfinding algorithm
int main() {
    struct cell start = {1, 1};
    struct cell goal = {4, 3};
    a_star(start, goal);
    print_path(start, goal);
    return 0;
}