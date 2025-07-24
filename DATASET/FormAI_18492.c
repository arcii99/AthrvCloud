//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20
#define MAX_PATH_LENGTH ROWS*COLS

typedef struct {
    int row, col;
} Point;

typedef struct {
    int length;
    Point path[MAX_PATH_LENGTH];
} Path;

int map[ROWS][COLS] = {  // 0 means empty, 1 means obstacle
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
};

Path get_random_path() {
    srand(time(NULL));
    Path path;
    path.length = 1;
    path.path[0].row = rand() % ROWS;
    path.path[0].col = rand() % COLS;
    while (path.length < MAX_PATH_LENGTH) {
        int row = path.path[path.length-1].row;
        int col = path.path[path.length-1].col;
        if (row == ROWS-1 && col == COLS-1) {
            break;
        }
        if (row > 0 && map[row-1][col] == 0) {
            path.path[path.length].row = row - 1;
            path.path[path.length].col = col;
            path.length++;
            continue;
        }
        if (row < ROWS-1 && map[row+1][col] == 0) {
            path.path[path.length].row = row + 1;
            path.path[path.length].col = col;
            path.length++;
            continue;
        }
        if (col > 0 && map[row][col-1] == 0) {
            path.path[path.length].row = row;
            path.path[path.length].col = col - 1;
            path.length++;
            continue;
        }
        if (col < COLS-1 && map[row][col+1] == 0) {
            path.path[path.length].row = row;
            path.path[path.length].col = col + 1;
            path.length++;
            continue;
        }
        path.length--;
    }
    return path;
}

typedef struct {
    Path path;
    int finished;
} Agent;

void print_map(Path* paths, int num_agents) {
    char cells[ROWS][COLS] = { 0 };
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cells[i][j] = (map[i][j] == 1) ? '#' : '.';
        }
    }
    for (int i = 0; i < num_agents; i++) {
        Path path = paths[i];
        for (int j = 0; j < path.length; j++) {
            int row = path.path[j].row;
            int col = path.path[j].col;
            if (cells[row][col] == '.') {
                cells[row][col] = 'a' + i;
            } else {
                cells[row][col] = '+';
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", cells[i][j]);
        }
        printf("\n");
    }
    printf("--------------------\n");
}

void* move_agent(void* arg) {
    Agent* agent = (Agent*)arg;
    while (!agent->finished) {
        int row = agent->path.path[agent->path.length-1].row;
        int col = agent->path.path[agent->path.length-1].col;
        if (row == ROWS-1 && col == COLS-1) {
            agent->finished = 1;
            break;
        }
        int num_choices = 0;
        int choices[] = { 0, 0, 0, 0 };  // up, down, left, right
        if (row > 0 && map[row-1][col] == 0) {
            choices[num_choices] = 0;
            num_choices++;
        }
        if (row < ROWS-1 && map[row+1][col] == 0) {
            choices[num_choices] = 1;
            num_choices++;
        }
        if (col > 0 && map[row][col-1] == 0) {
            choices[num_choices] = 2;
            num_choices++;
        }
        if (col < COLS-1 && map[row][col+1] == 0) {
            choices[num_choices] = 3;
            num_choices++;
        }
        if (num_choices == 0) {
            agent->path.length--;
        } else {
            int choice = rand() % num_choices;
            switch (choices[choice]) {
                case 0:
                    agent->path.path[agent->path.length].row = row - 1;
                    agent->path.path[agent->path.length].col = col;
                    agent->path.length++;
                    break;
                case 1:
                    agent->path.path[agent->path.length].row = row + 1;
                    agent->path.path[agent->path.length].col = col;
                    agent->path.length++;
                    break;
                case 2:
                    agent->path.path[agent->path.length].row = row;
                    agent->path.path[agent->path.length].col = col - 1;
                    agent->path.length++;
                    break;
                case 3:
                    agent->path.path[agent->path.length].row = row;
                    agent->path.path[agent->path.length].col = col + 1;
                    agent->path.length++;
                    break;
            }
        }
    }
    return NULL;
}

int main() {
    Path paths[10];
    pthread_t threads[10];
    for (int i = 0; i < 10; i++) {
        paths[i] = get_random_path();
        print_map(paths, 10);
        Agent agent = { paths[i], 0 };
        pthread_create(&threads[i], NULL, move_agent, &agent);
    }
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }
    print_map(paths, 10);
    return 0;
}