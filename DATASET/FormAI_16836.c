//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: introspective
#include <stdio.h>
#include <stdbool.h>

// Constants
#define ROWS 10
#define COLS 10
#define WALL 1
#define PATH 0

// Structs
typedef struct {
    int row;
    int col;
} Point;

// Globals
Point start = {0, 0}; // Starting point
Point goal = {ROWS-1, COLS-1}; // Goal point
int world[ROWS][COLS] = { // Example world
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Functions
bool is_valid(Point point) {
    return point.row >= 0 && point.row < ROWS &&
           point.col >= 0 && point.col < COLS &&
           world[point.row][point.col] == PATH;
}

int calculate_distance(Point a, Point b) {
    int dx = b.col - a.col;
    int dy = b.row - a.row;
    return dx*dx + dy*dy;
}

void print_world() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            char symbol = world[row][col] == WALL ? '#' : '.';
            printf("%c ", symbol);
        }
        printf("\n");
    }
}

void print_path(Point path[], int length) {
    for (int i = 0; i < length; i++) {
        printf("(%d, %d) ", path[i].row, path[i].col);
    }
    printf("\n");
}

Point get_min_distance(Point points[], int lengths[]) {
    Point min_point = {-1, -1};
    int min_distance = -1;
    for (int i = 0; i < ROWS*COLS; i++) {
        if (is_valid(points[i])) {
            int distance = lengths[i];
            if (min_distance < 0 || distance < min_distance) {
                min_distance = distance;
                min_point = points[i];
            }
        }
    }
    return min_point;
}

int main() {
    printf("Start: (%d, %d)\n", start.row, start.col);
    printf("Goal: (%d, %d)\n", goal.row, goal.col);

    printf("World:\n");
    print_world();

    // Initialize visited and distance arrays
    bool visited[ROWS][COLS] = {};
    int distances[ROWS][COLS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            distances[row][col] = -1;
        }
    }

    // Initialize starting point
    Point open_set[ROWS*COLS] = {start};
    int open_set_lengths[ROWS*COLS] = {0};
    distances[start.row][start.col] = calculate_distance(start, goal);

    // Main loop
    while (true) {
        // Get current point
        Point current = get_min_distance(open_set, open_set_lengths);
        if (current.row < 0 || current.col < 0) {
            printf("No more points to visit\n");
            break;
        }

        printf("Visiting (%d, %d)\n", current.row, current.col);
        visited[current.row][current.col] = true;

        // Check if goal has been reached
        if (current.row == goal.row && current.col == goal.col) {
            printf("Goal reached!\n");
            break;
        }

        // Calculate neighbors
        Point neighbors[4] = {
            {current.row-1, current.col},
            {current.row+1, current.col},
            {current.row, current.col-1},
            {current.row, current.col+1}
        };

        // Update distance and add to open set
        for (int i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];
            if (is_valid(neighbor) && !visited[neighbor.row][neighbor.col]) {
                int new_distance = distances[current.row][current.col] + calculate_distance(current, neighbor);
                if (distances[neighbor.row][neighbor.col] < 0 || new_distance < distances[neighbor.row][neighbor.col]) {
                    printf("Updating distance to (%d, %d) to %d\n", neighbor.row, neighbor.col, new_distance);
                    distances[neighbor.row][neighbor.col] = new_distance;
                    open_set[neighbor.row*COLS + neighbor.col] = neighbor;
                    open_set_lengths[neighbor.row*COLS + neighbor.col] = new_distance + calculate_distance(neighbor, goal);
                }
            }
        }

        print_world();
    }

    // Backtrace path
    if (visited[goal.row][goal.col]) {
        Point path[ROWS*COLS];
        int length = 0;
        Point current = goal;
        while (current.row != start.row || current.col != start.col) {
            path[length++] = current;
            printf("Backtracking to (%d, %d)\n", current.row, current.col);

            Point neighbors[4] = {
                {current.row-1, current.col},
                {current.row+1, current.col},
                {current.row, current.col-1},
                {current.row, current.col+1}
            };

            Point min_point = {-1, -1};
            int min_distance = -1;
            for (int i = 0; i < 4; i++) {
                Point neighbor = neighbors[i];
                if (is_valid(neighbor) && visited[neighbor.row][neighbor.col]) {
                    int distance = distances[neighbor.row][neighbor.col];
                    if (min_distance < 0 || distance < min_distance) {
                        min_distance = distance;
                        min_point = neighbor;
                    }
                }
            }

            current = min_point;
        }
        path[length++] = start;
        printf("Backtracking to (%d, %d)\n", start.row, start.col);
        printf("Path: ");
        print_path(path, length);
    } else {
        printf("No path found\n");
    }

    return 0;
}