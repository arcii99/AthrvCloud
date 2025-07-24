//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75
#define BINGO_BOARD_SIZE 25
#define THREAD_COUNT 2

typedef struct{
    int bingoBoard[BINGO_BOARD_SIZE];
    int* numbersCalled;
    bool paused;
    pthread_mutex_t mutex;
} BingoGame;

void initializeBingoBoard(BingoGame* game){
    for(int i = 0; i < BINGO_BOARD_SIZE; i++){
        game->bingoBoard[i] = rand() % MAX_NUM + 1;
    }
}

void callBingoNumber(BingoGame* game){
    while(!game->paused){
        int numberCalled = rand() % MAX_NUM + 1;
        
        // Check if number has already been called
        bool isDuplicate = false;
        for(int i = 0; i < MAX_NUM; i++){
            if(game->numbersCalled[i] == numberCalled){
                isDuplicate = true;
                break;
            }
        }
        
        if(!isDuplicate){
            // Add number to called numbers
            for(int i = 0; i < MAX_NUM; i++){
                if(game->numbersCalled[i] == 0){
                    game->numbersCalled[i] = numberCalled;
                    break;
                }
            }
            
            // Check if number is on the bingo board
            for(int i = 0; i < BINGO_BOARD_SIZE; i++){
                if(game->bingoBoard[i] == numberCalled){
                    game->bingoBoard[i] = 0;
                }
            }
        }
    }
}

void printBingoBoard(BingoGame* game){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(game->bingoBoard[i*ROWS+j] == 0){
                printf("[X]");
            } else {
                printf("[%2d]", game->bingoBoard[i*ROWS+j]);
            }
        }
        printf("\n");
    }
}

void* callBingo(void* bingoGame){
    BingoGame* game = (BingoGame*)bingoGame;
    callBingoNumber(game);
    return NULL;
}

int main(){
    BingoGame game;
    game.numbersCalled = (int*)calloc(MAX_NUM, sizeof(int));
    initializeBingoBoard(&game);
    game.paused = false;
    pthread_mutex_init(&game.mutex, NULL);
    
    pthread_t threads[THREAD_COUNT];
    for(int i = 0; i < THREAD_COUNT; i++){
        pthread_create(&threads[i], NULL, callBingo, &game);
    }
    
    // Game loop
    while(!(game.paused && game.numbersCalled[MAX_NUM-1] != 0)){
        pthread_mutex_lock(&game.mutex);
        printBingoBoard(&game);
        printf("\n");
        pthread_mutex_unlock(&game.mutex);
        usleep(500000);
    }
    
    // Print final bingo board
    printBingoBoard(&game);
    printf("\n");
    
    // Free allocated memory
    free(game.numbersCalled);
    
    // Exit
    return 0;
}