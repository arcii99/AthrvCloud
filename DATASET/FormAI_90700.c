//FormAI DATASET v1.0 Category: Table Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_PLAYERS 4

int num_of_players = 0;
int game_board[ROWS][COLS] = {{0}};

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t game_over = PTHREAD_COND_INITIALIZER;

void* play_game(void* player_num) {
    int player = *(int*) player_num;
    int score = 0;
    int row, col;
    
    while(1) {
        pthread_mutex_lock(&lock);
        
        if(num_of_players == MAX_PLAYERS) {
            pthread_cond_signal(&game_over);
            pthread_mutex_unlock(&lock);
            break;
        }
        
        row = rand() % ROWS;
        col = rand() % COLS;
        int score_increase = rand() % 10 + 1;
        
        if(game_board[row][col] + score_increase > 100) {
            score_increase = 100 - game_board[row][col];
        }
        
        game_board[row][col] += score_increase;
        score += score_increase;
        
        printf("Player %d scored %d on cell (%d, %d). Total score: %d\n", player, score_increase, row, col, score);
        
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    
    pthread_exit((void*) score);
}

int main() {
    srand(time(NULL));
    
    pthread_t players[MAX_PLAYERS];
    int player_nums[MAX_PLAYERS];
    
    for(int i = 0; i < MAX_PLAYERS; i++) {
        player_nums[i] = i+1;
        pthread_create(&players[i], NULL, play_game, (void*) &player_nums[i]);
        num_of_players++;
    }
    
    pthread_mutex_lock(&lock);
    pthread_cond_wait(&game_over, &lock);
    pthread_mutex_unlock(&lock);
    
    int max_score = 0;
    int winning_player = -1;
    
    for(int i = 0; i < MAX_PLAYERS; i++) {
        void* player_score;
        pthread_join(players[i], &player_score);
        
        if((int)player_score > max_score) {
            max_score = (int)player_score;
            winning_player = i+1;
        }
    }
    
    printf("The game is over!\n");
    printf("Player %d wins with a score of %d\n", winning_player, max_score);
    
    return 0;
}