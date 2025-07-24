//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'.', '.', '.', '#', '.', '.', '.', '#', '.', '.'},
    {'.', '#', '.', '.', '.', '#', '.', '.', '.', '#'},
    {'.', '#', '.', '#', '.', '.', '.', '#', '.', '#'},
   {'.', '.', '.', '.', '#', '.', '#', '.', '#', '.'},
    {'.', '#', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'.', '.', '#', '.', '#', '.', '.', '.', '#', '#'},
    {'.', '#', '.', '.', '.', '#', '.', '.', '.', '#'},
    {'.', '.', '.', '#', '.', '.', '.', '.', '.', '.'},
    {'.', '#', '.', '.', '.', '#', '.', '.', '#', '.'},
    {'.', '.', '.', '#', '.', '.', '.', '.', '.', '#'}
};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int path_found = 0; // to check if path has been found or not

struct node
{
    int row, col;
};

// The function to check if x and y are valid indices for maze[]
int is_valid_move(int row, int col)
{
    if (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] != '#')
        return 1;

    return 0;
}

void* find_path(void* arg)
{
    struct node current = *((struct node*)arg); // current node
    int row = current.row;
    int col = current.col;

    if (maze[row][col] == 'E')
    {
        path_found = 1;
        return NULL;
    }

    // mark the current node as visited
    maze[row][col] = '#';

    // right move
    if (is_valid_move(row, col + 1))
    {
        struct node right = { row, col + 1 };
        pthread_mutex_lock(&mutex);
        if (!path_found) // check if path has been found or not
            find_path(&right);
        pthread_mutex_unlock(&mutex);
    }

    // down move
    if (is_valid_move(row + 1, col))
    {
        struct node down = { row + 1, col };
        pthread_mutex_lock(&mutex);
        if (!path_found) // check if path has been found or not
            find_path(&down);
        pthread_mutex_unlock(&mutex);
    }

    // left move
    if (is_valid_move(row, col - 1))
    {
        struct node left = { row, col - 1 };
        pthread_mutex_lock(&mutex);
        if (!path_found) // check if path has been found or not
            find_path(&left);
        pthread_mutex_unlock(&mutex);
    }

    // up move
    if (is_valid_move(row - 1, col))
    {
        struct node up = { row - 1, col };
        pthread_mutex_lock(&mutex);
        if (!path_found) // check if path has been found or not
            find_path(&up);
        pthread_mutex_unlock(&mutex);
    }

    // backtrack
    maze[row][col] = '.';
    return NULL;
}

int main()
{
    pthread_t thread1, thread2, thread3;

    // set starting and ending points
    struct node start = { 0, 0 };
    struct node end = { ROW - 1, COL - 1 };

    // create threads for each move
    pthread_create(&thread1, NULL, find_path, &start);
    pthread_create(&thread2, NULL, find_path, &start);
    pthread_create(&thread3, NULL, find_path, &start);

    // join threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    // print the maze to see the path taken
    printf("\nThe path taken:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}