//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

struct node {
    int row;
    int col;
    int g_score;
    int f_score;
    struct node* parent;
};

int map[ROWS][COLS] = {0};
struct node* open_list[ROWS*COLS] = {NULL};
struct node* closed_list[ROWS*COLS] = {NULL};
struct node* start;
struct node* goal;

int heuristic(struct node* current)
{
    int dx = abs(current->col - goal->col);
    int dy = abs(current->row - goal->row);
    return dx + dy;
}

void print_map()
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int is_valid_position(int row, int col)
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }
    return 1;
}

struct node* create_node(int row, int col, struct node* parent)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->row = row;
    new_node->col = col;
    new_node->g_score = 0;
    new_node->f_score = 0;
    new_node->parent = parent;
    return new_node;
}

void add_to_open_list(struct node* current, struct node* neighbor)
{
    struct node* open_node = open_list[find_node_in_open_list(neighbor)];
    if (open_node != NULL) {
        if (current->g_score + 1 < open_node->g_score) {
            open_node->g_score = current->g_score + 1;
            open_node->f_score = open_node->g_score + heuristic(open_node);
            open_node->parent = current;
        }
    } else {
        neighbor->g_score = current->g_score + 1;
        neighbor->f_score = neighbor->g_score + heuristic(neighbor);
        neighbor->parent = current;
        int i = 0;
        while (open_list[i] != NULL && neighbor->f_score >= open_list[i]->f_score) {
            i++;
        }
        int j = ROWS*COLS-1;
        while (j > i) {
            open_list[j] = open_list[j-1];
            j--;
        }
        open_list[i] = neighbor;
    }
}

int find_node_in_open_list(struct node* target_node)
{
    int i = 0;
    while (open_list[i] != NULL) {
        if (open_list[i]->row == target_node->row && open_list[i]->col == target_node->col) {
            return i;
        }
        i++;
    }
    return -1;
}

int is_in_closed_list(struct node* target_node)
{
    int i = 0;
    while (closed_list[i] != NULL) {
        if (closed_list[i]->row == target_node->row && closed_list[i]->col == target_node->col) {
            return 1;
        }
        i++;
    }
    return 0;
}

void remove_from_open_list(struct node* target_node)
{
    int i = find_node_in_open_list(target_node);
    if (i != -1) {
        while (open_list[i + 1] != NULL) {
            open_list[i] = open_list[i + 1];
            i++;
        }
        open_list[i] = NULL;
    }
}

void add_to_closed_list(struct node* target_node)
{
    int i = 0;
    while (closed_list[i] != NULL) {
        i++;
    }
    closed_list[i] = target_node;
}

void reconstruct_path(struct node* start, struct node* goal)
{
    struct node* current = goal;
    while (current != NULL) {
        map[current->row][current->col] = 2;
        current = current->parent;
    }
    print_map();
}

void a_star_algorithm()
{
    start->g_score = 0;
    start->f_score = heuristic(start);
    open_list[0] = start;
    int i = 0;
    while (open_list[i] != NULL && (goal->row != open_list[i]->row || goal->col != open_list[i]->col)) {
        struct node* current = open_list[i];
        i++;
        remove_from_open_list(current);
        if (is_in_closed_list(current)) {
            continue;
        } else {
            add_to_closed_list(current);
        }
        int row = current->row;
        int col = current->col;
        if (is_valid_position(row-1, col) && map[row-1][col] == 0) {
            struct node* neighbor = create_node(row-1, col, current);
            add_to_open_list(current, neighbor);
        }
        if (is_valid_position(row+1, col) && map[row+1][col] == 0) {
            struct node* neighbor = create_node(row+1, col, current);
            add_to_open_list(current, neighbor);
        }
        if (is_valid_position(row, col-1) && map[row][col-1] == 0) {
            struct node* neighbor = create_node(row, col-1, current);
            add_to_open_list(current, neighbor);
        }
        if (is_valid_position(row, col+1) && map[row][col+1] == 0) {
            struct node* neighbor = create_node(row, col+1, current);
            add_to_open_list(current, neighbor);
        }
    }
    reconstruct_path(start, goal);
}

int main()
{
    // Set up obstacles in the map
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 2 && j > 2 && j < 8) {
                map[i][j] = 1;
            }
            if (i == 7 && j > 1 && j < 6) {
                map[i][j] = 1;
            }
        }
    }
    // Set the start and goal nodes
    start = create_node(1, 1, NULL);
    goal = create_node(8, 8, NULL);

    // Run the A* algorithm and print the path
    a_star_algorithm();

    return 0;
}