//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 25

//Global variables
int board[ROWS][COLS];
bool nums[MAX_NUM];
int num_count = 0;
bool bingo = false;

//Thread variables
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;

//Function to initialize the board with random numbers
void init_board() {
    //Set all elements to zero
    memset(board, 0, sizeof(board));

    //Initialize random number generator
    srand(time(NULL));

    //Fill the board with random numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int num = rand() % MAX_NUM + 1;
            while (nums[num-1] == true) {
                num = rand() % MAX_NUM + 1;
            }
            nums[num-1] = true;
            board[i][j] = num;
        }
    }
}

//Function to print the board
void print_board() {
    printf("\n\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("\t%d", board[i][j]);
        }
        printf("\n\n");
    }
}

//Function to check if a number exists on the board
bool check_num(int num) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == num)
                return true;
        }
    }
    return false;
}

//Function to mark a number on the board
void mark_num(int num) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == num)
                board[i][j] = 0;
        }
    }
    num_count++;
}

//Function to check if a row has all zeros
bool check_row(int row) {
    for (int i = 0; i < COLS; i++) {
        if (board[row][i] != 0)
            return false;
    }
    return true;
}

//Function to check if a column has all zeros
bool check_col(int col) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][col] != 0)
            return false;
    }
    return true;
}

//Function to check if a diagonal has all zeros
bool check_diag() {
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == j)
                diag1 += board[i][j];
            if (i + j == ROWS - 1)
                diag2 += board[i][j];
        }
    }
    if (diag1 == 0 || diag2 == 0)
        return true;
    else
        return false;
}

//Function for player thread
void *player(void *arg) {
    int *player_num = (int *) arg;

    for (;;) {
        sleep(1);
        //Lock mutex
        pthread_mutex_lock(&mutex1);

        if (bingo) {
            printf("\nPlayer %d: I won the game!", *player_num);
            //Signal cond2 to wake up monitor thread
            pthread_cond_signal(&cond2);
            pthread_mutex_unlock(&mutex1);
            pthread_exit(NULL);
        }

        int num = rand() % MAX_NUM + 1;
        while (nums[num-1] == false) {
            num = rand() % MAX_NUM + 1;
        }
        printf("\nPlayer %d: My number is %d", *player_num, num);

        if (check_num(num)) {
            mark_num(num);
            printf("\nPlayer %d: Yay, I marked my number", *player_num);

            //Check if any player has won
            if (check_row(0) || check_row(1) || check_row(2) || check_row(3) || check_row(4) ||
                    check_col(0) || check_col(1) || check_col(2) || check_col(3) || check_col(4) ||
                    check_diag()) {
                printf("\nPlayer %d: Bingo!", *player_num);
                bingo = true;
                //Signal cond2 to wake up monitor thread
                pthread_cond_signal(&cond2);
                pthread_mutex_unlock(&mutex1);
                pthread_exit(NULL);
            }
        } else {
            printf("\nPlayer %d: Oops, my number is not on the board", *player_num);
        }
        //Signal cond1 to wake up monitor thread
        pthread_cond_signal(&cond1);
        //Unlock mutex
        pthread_mutex_unlock(&mutex1);
    }
}

//Function for monitor thread
void *monitor(void *arg) {
    for (;;) {
        //Lock mutex
        pthread_mutex_lock(&mutex1);
        //Wait for cond1 signal from player thread
        pthread_cond_wait(&cond1, &mutex1);

        if (num_count == MAX_NUM) {
            printf("\n\nGame over: All numbers marked, but no bingo");
            exit(EXIT_SUCCESS);
        }

        print_board();
        //Unlock mutex
        pthread_mutex_unlock(&mutex1);
    }
}

int main() {
    //Initialize board
    init_board();

    //Create threads
    pthread_t t1, t2, t3;
    int p1 = 1, p2 = 2, p3 = 3;
    pthread_create(&t1, NULL, player, &p1);
    pthread_create(&t2, NULL, player, &p2);
    pthread_create(&t3, NULL, monitor, NULL);

    //Join threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    //Destroy mutex and condition variable
    pthread_mutex_destroy(&mutex1);
    pthread_cond_destroy(&cond1);
    pthread_cond_destroy(&cond2);

    return 0;
}