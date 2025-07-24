//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Alan Touring
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 10
#define COL 10
#define INF INT_MAX

enum CellType {
    OBSTACLE,
    OPEN
};

typedef struct {
    int row, col;
} Cell;

int heuristic(Cell start, Cell end) {
    return abs(start.row - end.row) + abs(start.col - end.col);
}

bool is_within_bounds(Cell cell) {
    return cell.row >= 0 && cell.col >= 0 && cell.row < ROW && cell.col < COL;
}

bool is_open(Cell cell, enum CellType grid[][COL]) {
    return grid[cell.row][cell.col] == OPEN;
}

void set_open(Cell cell, enum CellType grid[][COL]) {
    grid[cell.row][cell.col] = OPEN;
}

void set_obstacle(Cell cell, enum CellType grid[][COL]) {
    grid[cell.row][cell.col] = OBSTACLE;
}

bool is_destination(Cell cell, Cell destination) {
    return cell.row == destination.row && cell.col == destination.col;
}

void print_path(Cell path[], int len) {
    printf("Path: ");
    for (int i = 0; i < len; i++) {
        printf("(%d,%d) ", path[i].row, path[i].col);
    }
    printf("\n");
}

void a_star(Cell grid[][COL], Cell start, Cell destination) {
    printf("A* pathfinding algorithm.\n");
    printf("Start: (%d,%d), Destination: (%d,%d).\n", start.row, start.col, destination.row, destination.col);

    Cell came_from[ROW][COL];
    enum CellType closed_set[ROW][COL];
    int f_score[ROW][COL];
    int g_score[ROW][COL];

    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            closed_set[row][col] = OBSTACLE;
            f_score[row][col] = INF;
            g_score[row][col] = INF;
        }
    }

    closed_set[start.row][start.col] = OPEN;
    g_score[start.row][start.col] = 0;
    f_score[start.row][start.col] = heuristic(start, destination);

    Cell open_set[ROW * COL];
    int open_set_len = 1;
    open_set[0] = start;

    while (open_set_len != 0) {
        Cell current = open_set[0];
        int current_f_score = f_score[current.row][current.col];

        for (int i = 0; i < open_set_len; i++) {
            Cell cell = open_set[i];
            int f = f_score[cell.row][cell.col];
            if (f < current_f_score) {
                current = cell;
                current_f_score = f;
            }
        }

        if (is_destination(current, destination)) {
            Cell path[ROW * COL];
            int path_len = 0;

            Cell node = current;
            while (true) {
                path[path_len] = node;
                path_len++;
                if (node.row == start.row && node.col == start.col) {
                    break;
                }
                node = came_from[node.row][node.col];
            }

            print_path(path, path_len);
            return;
        }

        for (int row = -1; row <= 1; row++) {
            for (int col = -1; col <= 1; col++) {
                if (row == 0 && col == 0) {
                    continue;
                }

                Cell neighbour = { current.row + row, current.col + col };

                if (!is_within_bounds(neighbour)) {
                    continue;
                }

                if (!is_open(neighbour, grid)) {
                    continue;
                }

                int tentative_g_score = g_score[current.row][current.col] + 1;

                if (tentative_g_score < g_score[neighbour.row][neighbour.col]) {
                    came_from[neighbour.row][neighbour.col] = current;
                    g_score[neighbour.row][neighbour.col] = tentative_g_score;
                    f_score[neighbour.row][neighbour.col] = g_score[neighbour.row][neighbour.col] + heuristic(neighbour, destination);

                    if (closed_set[neighbour.row][neighbour.col] == OBSTACLE) {
                        closed_set[neighbour.row][neighbour.col] = OPEN;
                        open_set[open_set_len] = neighbour;
                        open_set_len++;
                    }
                }
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    Cell start = { 1, 1 };
    Cell destination = { 8, 8 };

    Cell grid[ROW][COL] = {
        { {OBSTACLE}, {OBSTACLE}, {OBSTACLE}, {OBSTACLE}, {OBSTACLE}, {OBSTACLE}, {OBSTACLE}, {OBSTACLE}, {OBSTACLE}, {OBSTACLE} },
        { {OBSTACLE}, {OPEN},      {OPEN},      {OPEN},      {OBSTACLE}, {OPEN},      {OPEN},      {OPEN},      {OPEN},      {OBSTACLE} },
        { {OBSTACLE}, {OPEN},      {OBSTACLE}, {OPEN},      {OPEN},      {OPEN},      {OBSTACLE}, {OBSTACLE}, {OPEN},      {OBSTACLE} },
        { {OBSTACLE}, {OPEN},      {OBSTACLE}, {OPEN},      {OBSTACLE}, {OPEN},      {OBSTACLE}, {OPEN},      {OPEN},      {OBSTACLE} },
        { {OBSTACLE}, {OPEN},      {OBSTACLE}, {OPEN},      {OBSTACLE}, {OPEN},      {OPEN},      {OPEN},      {OPEN},      {OBSTACLE} },
        { {OBSTACLE}, {OPEN},      {OBSTACLE}, {OPEN},      {OBSTACLE}, {OPEN},      {OBSTACLE}, {OBSTACLE}, {OPEN},      {OBSTACLE} },
        { {OBSTACLE}, {OPEN},      {OPEN},      {OPEN},      {OPEN},      {OPEN},      {OBSTACLE}, {OPEN},      {OPEN},      {OBSTACLE} },
        { {OBSTACLE}, {OPEN},      {OBSTACLE}, {OBSTACLE}, {OPEN},      {OPEN},      {OPEN},      {OPEN},      {OPEN},      {OBSTACLE} },
        { {OBSTACLE}, {OPEN},      {OPEN},      {OPEN},      {OPEN},      {OPEN},      {OBSTACLE}, {OPEN},      {OPEN},      {OBSTACLE} },
        { {OBSTACLE}, {OBSTACLE}, {OBSTACLE}, {OBSTACLE}, {OBSTACLE}, {OBSTACLE}, {OBSTACLE}, {OBSTACLE}, {OBSTACLE}, {OBSTACLE} }
    };

    a_star(grid, start, destination);

    return 0;
}