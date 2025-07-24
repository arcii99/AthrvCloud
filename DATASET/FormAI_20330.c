//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define ROW 5
#define COL 5

int matrix[ROW][COL];
int playerPosition;
int score;
pthread_mutex_t lock;

void initializeMatrix() {
    srand(time(NULL));
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COL;j++) {
            matrix[i][j] = rand() % 2;
        }
    }
}

void printMatrix() {
    printf("\n\nScore: %d\n\n", score);
    for(int i=0;i<ROW;i++) {
        for(int j=0;j<COL;j++) {
            if(i == 4 && j == playerPosition) {
                printf("P ");
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void *inputThread(void *arg) {
    char input;
    while(1) {
        input = getchar();
        pthread_mutex_lock(&lock);
        if(input == 'a' && playerPosition > 0) {
            playerPosition--;
        } else if(input == 'd' && playerPosition < 4) {
            playerPosition++;
        }
        pthread_mutex_unlock(&lock);
    }
}

void *updateThread(void *arg) {
    while(1) {
        usleep(500000);
        pthread_mutex_lock(&lock);
        for(int i=ROW-2;i>=0;i--) {
            for(int j=0;j<COL;j++) {
                matrix[i+1][j] = matrix[i][j];
            }
        }
        for(int j=0;j<COL;j++) {
            matrix[0][j] = rand() % 2;
        }
        if(matrix[4][playerPosition] == 1) {
            score++;
        }
        pthread_mutex_unlock(&lock);
    }
}

int main() {
    pthread_t tid[2];
    initializeMatrix();
    pthread_create(&tid[0], NULL, inputThread, NULL);
    pthread_create(&tid[1], NULL, updateThread, NULL);
    while(1) {
        system("clear");
        printMatrix();
    }
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}