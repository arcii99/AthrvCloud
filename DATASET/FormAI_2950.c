//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'*', '*', '*', '*', '*', 'O', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', '*'},
    {'*', ' ', '*', '*', '*', ' ', '*', '*', ' ', '*'},
    {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'},
    {'*', '*', '*', ' ', '*', ' ', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', '*'},
    {'*', '*', ' ', '*', '*', '*', '*', '*', ' ', '*'},
    {'*', '*', '*', '*', '*', 'X', '*', '*', '*', '*'}
};

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position pos;
    int move_count;
} QueueItem;

int is_valid_pos(int x, int y) {
    return x >= 0 && x < ROW && y >= 0 && y < COL;
}

int is_end_pos(int x, int y) {
    return maze[x][y] == 'X';
}

void enqueue(QueueItem *queue, int *front, int *rear, Position pos, int move_count) {
    queue[*rear].pos = pos;
    queue[*rear].move_count = move_count;
    (*rear)++;
}

QueueItem dequeue(QueueItem *queue, int *front) {
    (*front)++;
    return queue[*front - 1];
}

int is_queue_empty(int front, int rear) {
    return front == rear;
}

void print_maze() {
    printf("\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_path(QueueItem *queue, int *front, int *rear) {
    QueueItem current_item = queue[*rear - 1];
    int current_count = current_item.move_count - 1;
    int x = current_item.pos.x, y = current_item.pos.y;
    printf("Path: (%d, %d) -> ", x, y);
    while (current_count > 0) {
        for (int i = *front; i < *rear - 1; i++) {
            if (queue[i].move_count == current_count &&
                queue[i].pos.x == x && queue[i].pos.y == y) {
                x = queue[i].pos.x;
                y = queue[i].pos.y;
                printf("(%d, %d) -> ", x, y);
                current_count--;
                break;
            }
        }
    }
    printf("Finish\n\n");
}

void find_path(Position start_pos, Position end_pos) {
    QueueItem queue[ROW * COL];
    int front = 0, rear = 0;
    enqueue(queue, &front, &rear, start_pos, 1);

    while (!is_queue_empty(front, rear)) {
        QueueItem current_item = dequeue(queue, &front);
        int x = current_item.pos.x, y = current_item.pos.y;
        int move_count = current_item.move_count;

        if (is_end_pos(x, y)) {
            printf("\n---------- Path Found! ----------\n");
            print_maze();
            print_path(queue, &front, &rear);
            return;
        }

        if (maze[x][y] != 'O') {
            continue;
        }

        maze[x][y] = move_count % 10 + '0';

        Position up = { x - 1, y };
        if (is_valid_pos(up.x, up.y)) {
            enqueue(queue, &front, &rear, up, move_count + 1);
        }

        Position down = { x + 1, y };
        if (is_valid_pos(down.x, down.y)) {
            enqueue(queue, &front, &rear, down, move_count + 1);
        }

        Position left = { x, y - 1 };
        if (is_valid_pos(left.x, left.y)) {
            enqueue(queue, &front, &rear, left, move_count + 1);
        }

        Position right = { x, y + 1 };
        if (is_valid_pos(right.x, right.y)) {
            enqueue(queue, &front, &rear, right, move_count + 1);
        }
    }

    printf("\n---------- No Path Found! ----------\n");
    print_maze();
}

int main() {
    Position start_pos = { 0, 5 };
    Position end_pos = { 9, 5 };
    find_path(start_pos, end_pos);

    return 0;
}