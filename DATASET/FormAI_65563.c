//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10
#define INF 1000000

typedef struct node {
    int x, y;
    int cost;
    struct node *next;
} node_t;

int maze[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 0, 1, 1, 1, 0},
    {0, 1, 0, 0, 1, 0, 0, 1, 1, 0},
    {0, 1, 1, 0, 1, 0, 1, 1, 1, 0},
    {0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {0, 1, 0, 0, 1, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

node_t* create_node(int x, int y, int cost);
void add_node(node_t **list, node_t *node);
void remove_node(node_t **list, node_t *node);
int get_cost(int x, int y);
void print_path(node_t *node);
void find_path(int start_x, int start_y, int end_x, int end_y);

int main(void) {
    int start_x = 1, start_y = 1;
    int end_x = 8, end_y = 8;

    find_path(start_x, start_y, end_x, end_y);

    return 0;
}

node_t* create_node(int x, int y, int cost) {
    node_t *node = (node_t*)malloc(sizeof(node_t));
    node->x = x;
    node->y = y;
    node->cost = cost;
    node->next = NULL;
    return node;
}

void add_node(node_t **list, node_t *node) {
    if (*list == NULL) {
        *list = node;
    } else {
        node_t *current = *list;
        node_t *prev = NULL;
        while (current != NULL && current->cost < node->cost) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) {
            node->next = *list;
            *list = node;
        } else {
            node->next = prev->next;
            prev->next = node;
        }
    }
}

void remove_node(node_t **list, node_t *node) {
    if (*list == node) {
        *list = node->next;
    } else {
        node_t *current = *list;
        while (current != NULL && current->next != node) {
            current = current->next;
        }
        if (current != NULL) {
            current->next = node->next;
        }
    }
    free(node);
}

int get_cost(int x, int y) {
    if (x >= 0 && x < ROWS && y >= 0 && y < COLS) {
        return maze[x][y];
    } else {
        return INF;
    }
}

void print_path(node_t *node) {
    if (node != NULL) {
        print_path(node->next);
        printf("(%d, %d) -> ", node->x, node->y);
    }
}

void find_path(int start_x, int start_y, int end_x, int end_y) {
    int costs[ROWS][COLS];
    node_t *open_list = NULL, *closed_list = NULL;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            costs[i][j] = INF;
        }
    }

    costs[start_x][start_y] = 0;
    add_node(&open_list, create_node(start_x, start_y, 0));

    while (open_list != NULL) {
        node_t *current = open_list;
        remove_node(&open_list, current);
        add_node(&closed_list, current);

        if (current->x == end_x && current->y == end_y) {
            printf("Path found: ");
            print_path(current);
            printf("\n");
            return;
        }

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int next_x = current->x + i;
                int next_y = current->y + j;
                int cost = current->cost + get_cost(next_x, next_y);

                if (cost < costs[next_x][next_y]) {
                    costs[next_x][next_y] = cost;
                    node_t *next_node = create_node(next_x, next_y, cost);

                    node_t *open_node = open_list;
                    while (open_node != NULL && (open_node->x != next_x || open_node->y != next_y)) {
                        open_node = open_node->next;
                    }
                    if (open_node != NULL) {
                        if (open_node->cost > cost) {
                            remove_node(&open_list, open_node);
                            add_node(&open_list, next_node);
                        }
                    } else {
                        node_t *closed_node = closed_list;
                        while (closed_node != NULL && (closed_node->x != next_x || closed_node->y != next_y)) {
                            closed_node = closed_node->next;
                        }
                        if (closed_node != NULL) {
                            if (closed_node->cost > cost) {
                                remove_node(&closed_list, closed_node);
                                add_node(&open_list, next_node);
                            }
                        } else {
                            add_node(&open_list, next_node);
                        }
                    }
                }
            }
        }
    }

    printf("Path not found!\n");
}