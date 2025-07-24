//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define ROW 5        // number of rows 
#define COL 10       // number of columns 

int score = 0;       // player score
bool gameOver = false;
bool alienWin = false;


// Declare alien matrix
int alienMatrix[ROW][COL] =  {
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
                            };

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;  // initialise mutex


// Function to display the current alien matrix
void displayAlienMatrix() {
    int i, j;
    for(i=0;i<ROW;i++) {
        for(j=0;j<COL;j++) {
            printf("%d ", alienMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to move the alien matrix horizontally
void moveAlienMatrixHorizontal(int dx) {
    pthread_mutex_lock(&mutex1);  // critical section
    int i, j;
    for(i=0;i<ROW;i++) {
        for(j=0;j<COL;j++) {
            if(alienMatrix[i][j] == 1) {
                alienMatrix[i][j] = 0;
                if(j+dx >= COL) {
                    gameOver = true;
                    alienWin = true;
                    pthread_mutex_unlock(&mutex1);
                    return;
                }
                if(j+dx < 0) {
                    gameOver = true;
                    pthread_mutex_unlock(&mutex1);
                    return;
                }
                alienMatrix[i][j+dx] = 1;
            }
        }
    }
    pthread_mutex_unlock(&mutex1);
}

// Function to move the alien matrix vertically
void moveAlienMatrixVertical(int dy) {
    pthread_mutex_lock(&mutex1);  // critical section
    int i, j;
    for(i=0;i<ROW;i++) {
        for(j=0;j<COL;j++) {
            if(alienMatrix[i][j] == 1) {
                alienMatrix[i][j] = 0;
                if(i+dy >= ROW) {
                    gameOver = true;
                    pthread_mutex_unlock(&mutex1);
                    return;
                }
                alienMatrix[i+dy][j] = 1;
            }
        }
    }   
    pthread_mutex_unlock(&mutex1);
}

// Function to simulate a player shot
void playerShoot(int x, int y) {
    pthread_mutex_lock(&mutex1);  // critical section
    if(alienMatrix[x][y] == 1) {
        alienMatrix[x][y] = 0;
        score++;
    }
    pthread_mutex_unlock(&mutex1);
}

// Function to simulate an alien shot
void alienShoot() {
    pthread_mutex_lock(&mutex1);  // critical section
    int i, j;
    for(i=ROW-1;i>=0;i--) {
        for(j=0;j<COL;j++) {
            if(alienMatrix[i][j] == 1) {
                int x = rand()%3;
                if(x == 0) {
                    playerShoot(i, j);
                }
            }
        }
    }
    pthread_mutex_unlock(&mutex1);
}


int main() {

    pthread_t tid[2]; // Create two threads for moving the alien matrix

    while(true) {

        if(gameOver == true) {
            break;
        }

        usleep(1000000);    // sleep for 1 second
        moveAlienMatrixHorizontal(1);
        displayAlienMatrix();

        usleep(1000000);    // sleep for 1 second
        moveAlienMatrixHorizontal(-1);
        displayAlienMatrix();

        usleep(1000000);    // sleep for 1 second
        moveAlienMatrixVertical(1);
        displayAlienMatrix();

        usleep(1000000);    // sleep for 1 second
        moveAlienMatrixVertical(-1);
        displayAlienMatrix();

        // Create two threads for shooting
        pthread_create(&tid[0], NULL, alienShoot, NULL);
        pthread_create(&tid[1], NULL, playerShoot, NULL);

        // Wait for threads to finish
        pthread_join(tid[0], NULL);
        pthread_join(tid[1], NULL);

    }

    if(alienWin == true) {
        printf("Game Over. Aliens Win.\n");
    }
    else {
        printf("Game Over. You Win.\n");
    }
    printf("Final Score: %d\n", score);

    return 0;
}