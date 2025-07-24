//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define ROWS 25
#define COLS 25

char maze[ROWS][COLS];
int start_row = 0, start_col = 0;
int end_row = ROWS-1, end_col = COLS-1;

pthread_barrier_t barrier;

typedef struct node{
    int row, col;
    struct node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;
pthread_mutex_t lock;

void push(int row, int col){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;
    
    pthread_mutex_lock(&lock);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
    pthread_mutex_unlock(&lock);
}

void pop(int* row, int* col){
    pthread_mutex_lock(&lock);
    Node* curr = head;
    if(curr != NULL){
        *row = curr->row;
        *col = curr->col;
        head = curr->next;
        free(curr);
    }
    pthread_mutex_unlock(&lock);
}

int is_empty(){
    pthread_mutex_lock(&lock);
    int empty = (head == NULL);
    pthread_mutex_unlock(&lock);
    return empty;
}

void generate_maze(){
    srand(time(NULL));
    int r, c;
    
    // Set border walls
    for(r=0; r<ROWS; r++){
        for(c=0; c<COLS; c++){
            if(r == 0 || c == 0 || r == ROWS-1 || c == COLS-1){
                maze[r][c] = '#';
            }
            else{
                maze[r][c] = ' ';
            }
        }
    }
    
    // Choose random starting point
    start_row = rand()%ROWS;
    start_col = rand()%COLS;
    maze[start_row][start_col] = 'S';
    
    // Choose random ending point
    end_row = rand()%ROWS;
    end_col = rand()%COLS;
    maze[end_row][end_col] = 'E';
    
    // Generate maze using DFS algorithm
    push(start_row, start_col);
    while(!is_empty()){
        int curr_row, curr_col;
        pop(&curr_row, &curr_col);
        maze[curr_row][curr_col] = '.';
        int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int i, j, temp_row, temp_col, count = 4;
        while(count > 0){
            i = rand()%4;
            count--;
            temp_row = curr_row + directions[i][0];
            temp_col = curr_col + directions[i][1];
            if(temp_row >= 0 && temp_row < ROWS && temp_col >= 0 && temp_col < COLS && maze[temp_row][temp_col] == ' '){
                push(temp_row, temp_col);
            }
        }
    }
}

void print_maze(){
    int r, c;
    for(r=0; r<ROWS; r++){
        for(c=0; c<COLS; c++){
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

void* solve_maze(void* arg){
    int id = *(int*)arg;
    int r, c;
    while(1){
        pthread_barrier_wait(&barrier);
        if(id == 0){ // Starting cell (S)
            r = start_row;
            c = start_col;
        }
        else{ // Non-starting cells
            if(is_empty()){ // End condition
                pthread_exit(NULL);
            }
            pop(&r, &c);
        }
        if(r == end_row && c == end_col){ // Found end
            printf("Path found by thread %d\n", id);
            pthread_exit(NULL);
        }
        int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int i, temp_row, temp_col;
        for(i=0; i<4; i++){
            temp_row = r + directions[i][0];
            temp_col = c + directions[i][1];
            if(temp_row >= 0 && temp_row < ROWS && temp_col >= 0 && temp_col < COLS && maze[temp_row][temp_col] != '#'){
                push(temp_row, temp_col);
                maze[temp_row][temp_col] = '#';
            }
        }
    }
}

int main(){
    generate_maze();
    print_maze();
    
    pthread_barrier_init(&barrier, NULL, ROWS*COLS);
    pthread_mutex_init(&lock, NULL);
    pthread_t threads[ROWS*COLS];
    int ids[ROWS*COLS];
    int i;
    for(i=0; i<ROWS*COLS; i++){
        ids[i] = i;
        pthread_create(&threads[i], NULL, solve_maze, &ids[i]);
    }
    
    for(i=0; i<ROWS*COLS; i++){
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&lock);
    pthread_barrier_destroy(&barrier);
    return 0;
}