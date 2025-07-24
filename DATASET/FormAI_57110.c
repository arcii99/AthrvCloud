//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 10
#define COLS 10

typedef struct{
    int row, col;
} point_t;

typedef struct node{
    point_t point;
    struct node *parent;
    int f, g, h;
} node_t;

int map[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 1, 0, 1, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
    {1, 1, 1, 0, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}
};

int manhattan_distance(point_t p1, point_t p2) {
    return abs(p2.row - p1.row) + abs(p2.col - p1.col);
}

bool is_valid(point_t point) {
    return point.row >= 0 && point.col >= 0 && point.row < ROWS && point.col < COLS && map[point.row][point.col] == 0;
}

bool is_present(node_t *node, int row, int col) {
    return node != NULL && node->point.row == row && node->point.col == col;
}

bool is_wall(int row, int col) {
    return map[row][col] == 1;
}

void print_map() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

node_t* create_node(int row, int col, node_t* parent, point_t end_point) {
    node_t* node = malloc(sizeof(node_t));
    node->point.row = row;
    node->point.col = col;
    node->parent = parent;
    node->g = parent != NULL ? parent->g + 1 : 0;
    node->h = manhattan_distance(node->point, end_point);
    node->f = node->g + node->h;
    return node;
}

void add_node_to_open_list(node_t** open_list, node_t* node) {
    node_t* temp = *open_list;
    if (*open_list == NULL || node->f < (*open_list)->f) {
        node->parent = *open_list;
        *open_list = node;
    } else {
        while (temp->parent != NULL && temp->parent->f < node->f) {
            temp = temp->parent;
        }
        node->parent = temp->parent;
        temp->parent = node;
    }
}

node_t* find_node_in_list(node_t* list, int row, int col) {
    while (list != NULL && !is_present(list, row, col)) {
        list = list->parent;
    }
    return list;
}

void free_list(node_t* list) {
    while (list != NULL) {
        node_t* temp = list->parent;
        free(list);
        list = temp;
    }
}

void find_path(point_t start_point, point_t end_point) {
    node_t* open_list = create_node(start_point.row, start_point.col, NULL, end_point);
    node_t* closed_list = NULL;
    
    while (open_list != NULL) {
        node_t* current_node = open_list;
        open_list = open_list->parent;
        current_node->parent = closed_list;
        closed_list = current_node;
        
        if (current_node->point.row == end_point.row && current_node->point.col == end_point.col) {
            node_t* path = closed_list;
            while (path != NULL) {
                printf("(%d,%d) ", path->point.row, path->point.col);
                path = path->parent;
            }
            printf("\n");
            free_list(open_list);
            free_list(closed_list);
            return;
        }
        
        point_t neighbors[] = { {current_node->point.row-1, current_node->point.col}, 
                                {current_node->point.row+1, current_node->point.col}, 
                                {current_node->point.row, current_node->point.col-1}, 
                                {current_node->point.row, current_node->point.col+1} };
        
        for (int i = 0; i < 4; i++) {
            if (!is_valid(neighbors[i]) || is_present(closed_list, neighbors[i].row, neighbors[i].col) || is_wall(neighbors[i].row, neighbors[i].col)) {
                continue;
            }
            node_t* neighbor_node = find_node_in_list(open_list, neighbors[i].row, neighbors[i].col);
            if (neighbor_node == NULL) {
                neighbor_node = create_node(neighbors[i].row, neighbors[i].col, current_node, end_point);
                add_node_to_open_list(&open_list, neighbor_node);
            } else {
                if (neighbor_node->g > current_node->g + 1) {
                    neighbor_node->g = current_node->g + 1;
                    neighbor_node->f = neighbor_node->g + neighbor_node->h;
                    neighbor_node->parent = current_node;
                }
            }
        }
    }
    
    printf("Path not found\n");
    free_list(open_list);
    free_list(closed_list);
}

int main() {
    print_map();

    point_t start_point = {5, 0};
    point_t end_point = {9, 9};
    printf("Finding path from (%d,%d) to (%d,%d)\n\n", start_point.row, start_point.col, end_point.row, end_point.col);

    find_path(start_point, end_point);
    return 0;
}