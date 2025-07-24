//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROW 10
#define COL 10
#define WALL 1
#define EMPTY 0

/* Define a struct to represent a square in the maze */
typedef struct {
    int row;
    int col;
} Square;

/* Define a struct to represent a node in the search tree */
typedef struct {
    Square pos;
    int f_score;
} Node;

/* Define a struct to represent a priority queue */
typedef struct {
    Node *nodes[ROW*COL];
    int length;
} PriorityQueue;

/* Helper function to compare f_scores of two nodes */
int compare_nodes(Node *n1, Node *n2) {
    return n1->f_score - n2->f_score;
}

/* Helper function to initialize the priority queue */
PriorityQueue *initialize_pq() {
    PriorityQueue *pq = malloc(sizeof(PriorityQueue));
    pq->length = 0;
    return pq;
}

/* Helper function to insert a node into the priority queue */
void insert_node(PriorityQueue *pq, Node *node) {
    int i;
    for (i = pq->length-1; i >= 0; i--) {
        if (compare_nodes(node, pq->nodes[i]) >= 0)
            break;
        pq->nodes[i+1] = pq->nodes[i];
    }
    pq->nodes[i+1] = node;
    pq->length++;
}

/* Helper function to remove the node with the lowest f_score from the priority queue */
Node *pop_min_node(PriorityQueue *pq) {
    if (pq->length == 0)
        return NULL;
    Node *node = pq->nodes[0];
    pq->length--;
    int i;
    for (i = 0; i < pq->length; i++) {
        pq->nodes[i] = pq->nodes[i+1];
    }
    pq->nodes[i] = NULL;
    return node;
}

/* Helper function to check if a square is within the bounds of the maze */
bool is_valid_square(int maze[ROW][COL], Square sq) {
    return sq.row >= 0 && sq.row < ROW && sq.col >= 0 && sq.col < COL && maze[sq.row][sq.col] == EMPTY;
}

/* Helper function to compute the heuristic (Manhattan distance) between two squares */
int heuristic(Square s1, Square s2) {
    return abs(s1.row - s2.row) + abs(s1.col - s2.col);
}

/* Main function to perform A* search */
void astar_search(int maze[ROW][COL], Square start, Square end) {
    /* Initialize the open and closed lists */
    PriorityQueue *open_list = initialize_pq();
    Node *start_node = malloc(sizeof(Node));
    start_node->pos = start;
    start_node->f_score = heuristic(start, end);
    insert_node(open_list, start_node);
    bool closed_list[ROW][COL];
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            closed_list[i][j] = false;
        }
    }
    /* Initialize the arrays to keep track of parent nodes and g_scores */
    Node *parent_nodes[ROW][COL];
    int g_scores[ROW][COL];
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            parent_nodes[i][j] = NULL;
            g_scores[i][j] = INT_MAX;
        }
    }
    g_scores[start.row][start.col] = 0;
    /* Perform the search */
    while (open_list->length > 0) {
        /* Get the node with the lowest f_score from the open list */
        Node *current_node = pop_min_node(open_list);
        /* Check if we've reached the goal */
        if (current_node->pos.row == end.row && current_node->pos.col == end.col) {
            /* Reconstruct the path by following the parent pointers backwards */
            printf("Path found!\n");
            Square path[ROW*COL];
            int path_length = 0;
            Node *node = current_node;
            while (node != NULL) {
                path[path_length] = node->pos;
                node = parent_nodes[node->pos.row][node->pos.col];
                path_length++;
            }
            /* Print the path */
            for (i = path_length-1; i >= 0; i--) {
                printf("(%d, %d)", path[i].row, path[i].col);
                if (i > 0)
                    printf(" -> ");
            }
            printf("\n");
            return;
        }
        /* Add the current node to the closed list */
        closed_list[current_node->pos.row][current_node->pos.col] = true;
        /* Consider all neighbors of the current node */
        Square neighbors[4] = {{current_node->pos.row-1, current_node->pos.col},
                               {current_node->pos.row+1, current_node->pos.col},
                               {current_node->pos.row, current_node->pos.col-1},
                               {current_node->pos.row, current_node->pos.col+1}};
        for (i = 0; i < 4; i++) {
            Square neighbor = neighbors[i];
            /* Check if the neighbor is within the maze and is empty */
            if (!is_valid_square(maze, neighbor))
                continue;
            /* Check if the neighbor is already in the closed list */
            if (closed_list[neighbor.row][neighbor.col])
                continue;
            /* Compute the tentative g_score and f_score for the neighbor */
            int tentative_g_score = g_scores[current_node->pos.row][current_node->pos.col] + 1;
            int tentative_f_score = tentative_g_score + heuristic(neighbor, end);
            /* Check if the neighbor is already in the open list */
            bool in_open_list = false;
            Node *open_node;
            for (j = 0; j < open_list->length; j++) {
                open_node = open_list->nodes[j];
                if (open_node->pos.row == neighbor.row && open_node->pos.col == neighbor.col) {
                    in_open_list = true;
                    break;
                }
            }
            /* If the neighbor is not in the open list, add it */
            if (!in_open_list) {
                Node *neighbor_node = malloc(sizeof(Node));
                neighbor_node->pos = neighbor;
                neighbor_node->f_score = tentative_f_score;
                insert_node(open_list, neighbor_node);
            }
            /* If the neighbor is already in the open list and the tentative g_score is better, update it */
            else if (tentative_g_score < g_scores[neighbor.row][neighbor.col]) {
                open_node->f_score = tentative_f_score;
            }
            /* Update the parent and g_score arrays */
            parent_nodes[neighbor.row][neighbor.col] = current_node;
            g_scores[neighbor.row][neighbor.col] = tentative_g_score;
        }
    }
    /* If we reach this point, there is no path from start to end */
    printf("No path found!\n");
}

/* Helper function to print the maze */
void print_maze(int maze[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c ", maze[i][j] == WALL ? '#' : '.');
        }
        printf("\n");
    }
}

int main() {
    /* Create a maze */
    int maze[ROW][COL] = {{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          {1, 1, 1, 0, 1, 0, 0, 1, 1, 0},
                          {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
                          {0, 1, 1, 0, 1, 0, 1, 1, 0, 1},
                          {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                          {1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
                          {0, 0, 0, 1, 1, 1, 1, 0, 0, 0}};
    /* Set the start and end points */
    Square start = {0, 0};
    Square end = {9, 9};
    /* Print the maze */
    printf("Maze:\n");
    print_maze(maze);
    /* Run the search */
    astar_search(maze, start, end);
    return 0;
}