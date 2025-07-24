//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: decentralized
#include <stdio.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 0, 1, 1},
    {1, 1, 0, 0, 1, 0, 1, 1, 1, 1},
    {1, 1, 0, 1, 1, 0, 0, 0, 0, 1},
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int visited[ROWS][COLS];

struct Point {
    int x;
    int y;
};

struct Point queue[ROWS*COLS];
int head = 0;
int tail = 0;

void enqueue(struct Point p) {
    queue[tail++] = p;
}

struct Point dequeue() {
    return queue[head++];
}

int is_empty() {
    return head == tail;
}

void print_maze() {
    int r, c;

    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            printf("%d ", maze[r][c]);
        }
        printf("\n");
    }
}

void print_path(struct Point p) {
    printf("Path:\n");

    while (maze[p.y][p.x] != 2) {
        printf("(%d,%d) -> ", p.x, p.y);
        maze[p.y][p.x] = -1;

        if (visited[p.y-1][p.x] < visited[p.y][p.x]) {
            p.y--;
        } else if (visited[p.y+1][p.x] < visited[p.y][p.x]) {
            p.y++;
        } else if (visited[p.y][p.x-1] < visited[p.y][p.x]) {
            p.x--;
        } else if (visited[p.y][p.x+1] < visited[p.y][p.x]) {
            p.x++;
        }
    }

    printf("(%d,%d)\n", p.x, p.y);
}

void bfs(struct Point start, struct Point end) {
    int r, c;

    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            visited[r][c] = -1;
        }
    }

    visited[start.y][start.x] = 0;
    enqueue(start);

    while (!is_empty()) {
        struct Point p = dequeue();

        if (p.x == end.x && p.y == end.y) {
            printf("Minimum Path Length: %d\n", visited[p.y][p.x]);
            print_path(p);
            return;
        }

        if (maze[p.y][p.x-1] != 1 && visited[p.y][p.x-1] == -1) {
            visited[p.y][p.x-1] = visited[p.y][p.x]+1;
            enqueue((struct Point) {p.x-1, p.y});
        }

        if (maze[p.y][p.x+1] != 1 && visited[p.y][p.x+1] == -1) {
            visited[p.y][p.x+1] = visited[p.y][p.x]+1;
            enqueue((struct Point) {p.x+1, p.y});
        }

        if (maze[p.y-1][p.x] != 1 && visited[p.y-1][p.x] == -1) {
            visited[p.y-1][p.x] = visited[p.y][p.x]+1;
            enqueue((struct Point) {p.x, p.y-1});
        }

        if (maze[p.y+1][p.x] != 1 && visited[p.y+1][p.x] == -1) {
            visited[p.y+1][p.x] = visited[p.y][p.x]+1;
            enqueue((struct Point) {p.x, p.y+1});
        }
    }

    printf("Path not found.\n");
}

int main() {
    struct Point start = {1, 1};
    struct Point end = {8, 8};

    printf("Maze:\n");
    print_maze();

    bfs(start, end);
    
    return 0;
}