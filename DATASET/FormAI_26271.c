//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int map[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point point;
    int f;
    int g;
    int h;
} Node;

bool is_valid(Point point) {
    return point.row >= 0 && point.row < ROWS && point.col >= 0 && point.col < COLS;
}

bool is_obstacle(Point point) {
    return map[point.row][point.col] == 1;
}

bool is_goal(Point point1, Point point2) {
    return point1.row == point2.row && point1.col == point2.col;
}

int distance(Point point1, Point point2) {
    int dx = point1.col - point2.col;
    int dy = point1.row - point2.row;
    return abs(dx) + abs(dy);
}

void print_path(Point path[], int length) {
    printf("Path: ");
    for (int i = 0; i < length; i++) {
        printf("(%d,%d) ", path[i].row, path[i].col);
    }
    printf("\n");
}

void print_map() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == 1)
                printf("# ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

Node create_node(Point point, int g, Point goal) {
    Node node;
    node.point = point;
    node.g = g;
    node.h = distance(point, goal);
    node.f = node.g + node.h;
    return node;
}

void add_to_open(Node node, int *open_count, Node open[]) {
    open[(*open_count)++] = node;
}

Node get_lowest_f_node(int open_count, Node open[]) {
    Node lowest_f_node = open[0];
    int lowest_f = open[0].f;
    for (int i = 1; i < open_count; i++) {
        if (open[i].f < lowest_f) {
            lowest_f = open[i].f;
            lowest_f_node = open[i];
        }
    }
    return lowest_f_node;
}

void remove_from_open(int index, int *open_count, Node open[]) {
    for (int i = index; i < (*open_count) - 1; i++) {
        open[i] = open[i + 1];
    }
    (*open_count)--;
}

bool is_node_in_open(Node node, int open_count, Node open[]) {
    for (int i = 0; i < open_count; i++) {
        if (is_goal(node.point, open[i].point)) {
            return true;
        }
    }
    return false;
}

bool is_node_in_closed(Node node, int closed_count, Node closed[]) {
    for (int i = 0; i < closed_count; i++) {
        if (is_goal(node.point, closed[i].point)) {
            return true;
        }
    }
    return false;
}

int find_best_node_index(Point goal, int open_count, Node open[]) {
    int best_node_index = 0;
    int best_f = open[0].f;
    for (int i = 1; i < open_count; i++) {
        Node node = open[i];
        if (node.f < best_f || (node.f == best_f && node.h < open[best_node_index].h)) {
            best_node_index = i;
            best_f = node.f;
        }
    }
    return best_node_index;
}

void retrace_path(Point current_point, Point start_point, Node closed[], int closed_count) {
    Point path[ROWS * COLS];
    int path_length = 0;
    Point previous_point = current_point;
    for (int i = closed_count - 1; i >= 0; i--) {
        Node node = closed[i];
        if (is_goal(previous_point, node.point)) {
            path[path_length++] = previous_point;
            previous_point = node.point;
        }
    }
    path[path_length++] = start_point;
    print_path(path, path_length);
}

void a_star(Point start_point, Point goal_point) {
    int open_count = 0;
    Node open[ROWS * COLS];
    int closed_count = 0;
    Node closed[ROWS * COLS];
    Node start_node = create_node(start_point, 0, goal_point);
    add_to_open(start_node, &open_count, open);
    int iterations = 0;
    while (open_count > 0 && iterations < ROWS * COLS) {
        iterations++;
        Node current_node = get_lowest_f_node(open_count, open);
        remove_from_open(0, &open_count, open);
        add_to_open(current_node, &closed_count, closed);
        if (is_goal(current_node.point, goal_point)) {
            printf("Path found in %d iterations.\n", iterations);
            retrace_path(current_node.point, start_point, closed, closed_count);
            return;
        }
        Point neighbors[] = {
            {current_node.point.row - 1, current_node.point.col},
            {current_node.point.row, current_node.point.col + 1},
            {current_node.point.row + 1, current_node.point.col},
            {current_node.point.row, current_node.point.col - 1}
        };
        for (int i = 0; i < 4; i++) {
            if (is_valid(neighbors[i]) && !is_obstacle(neighbors[i]) && !is_node_in_closed(create_node(neighbors[i], 0, goal_point), closed_count, closed)) {
                int tentative_g = current_node.g + 1;
                Node neighbor_node = create_node(neighbors[i], tentative_g, goal_point);
                if (is_node_in_open(neighbor_node, open_count, open)) {
                    int neighbor_index = find_best_node_index(goal_point, open_count, open);
                    if (open[neighbor_index].g > tentative_g) {
                        open[neighbor_index].g = tentative_g;
                        open[neighbor_index].f = open[neighbor_index].g + open[neighbor_index].h;
                    }
                } else {
                    add_to_open(neighbor_node, &open_count, open);
                }
            }
        }
    }
    printf("Path not found.\n");
}

int main() {
    Point start_point = {1, 1};
    Point goal_point = {ROWS - 2, COLS - 2};
    print_map();
    a_star(start_point, goal_point);
    return 0;
}