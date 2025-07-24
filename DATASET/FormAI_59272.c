//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <pthread.h>
#define ROWS 5
#define COLS 5
#define MAX_PLAYERS 10

//initialize struct for players
typedef struct {
    char* name;
    int score;
    int guessed_nums[25];
    bool won;
} player;

player players[MAX_PLAYERS];

int num_players;
int bingo_board[ROWS][COLS];
pthread_mutex_t board_lock;

//function to generate a random number between lower and upper limits
int gen_rand_num(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

//function to create the bingo board
void create_board() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (j == 2 && i == 2) //middle cell is a free space
                bingo_board[i][j] = 0;
            else {
                //generate random number between different limits for each column
                if (j == 0) bingo_board[i][j] = gen_rand_num(1, 15);
                else if (j == 1) bingo_board[i][j] = gen_rand_num(16, 30);
                else if (j == 3) bingo_board[i][j] = gen_rand_num(31, 45);
                else if (j == 4) bingo_board[i][j] = gen_rand_num(46, 60);
            }
        }
    }
}

//function to print the bingo board
void print_board() {
    printf("\nB - I - N - G - O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (j == 2 && i == 2)
                printf("    ");
            else
                printf("%2d  ", bingo_board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//function to check if a given number matches any number on the board
bool check_num(int num) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (bingo_board[i][j] == num)
                return true;
        }
    }
    return false;
}

//function to update player score and guessed_nums list
void update_player(int player_index, int num) {
    players[player_index].score++;
    for (int i = 0; i < 25; i++) {
        if (players[player_index].guessed_nums[i] == 0) {
            players[player_index].guessed_nums[i] = num;
            break;
        }
    }
}

//function to check if a player has won
bool check_winner(int player_index) {
    int count = 0;
    //check horizontal rows
    for (int i = 0; i < ROWS; i++) {
        count = 0;
        for (int j = 0; j < COLS; j++) {
            for (int k = 0; k < 25; k++) {
                if (players[player_index].guessed_nums[k] == bingo_board[i][j]) {
                    count++;
                    break;
                }
            }
        }
        if (count == COLS)
            return true;
    }
    //check vertical columns
    for (int i = 0; i < COLS; i++) {
        count = 0;
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < 25; k++) {
                if (players[player_index].guessed_nums[k] == bingo_board[j][i]) {
                    count++;
                    break;
                }
            }
        }
        if (count == ROWS)
            return true;
    }
    //check diagonal from top left to bottom right
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == j) {
                for (int k = 0; k < 25; k++) {
                    if (players[player_index].guessed_nums[k] == bingo_board[i][j]) {
                        count++;
                        break;
                    }
                }
            }
        }
    }
    if (count == ROWS)
        return true;
    //check diagonal from top right to bottom left
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i + j == 4) {
                for (int k = 0; k < 25; k++) {
                    if (players[player_index].guessed_nums[k] == bingo_board[i][j]) {
                        count++;
                        break;
                    }
                }
            }
        }
    }
    if (count == ROWS)
        return true;
    return false;
}

//thread function to handle each player's turn
void* play_game(void* arg) {
    int player_index = *(int*) arg;
    free(arg);
    char buf[256];
    while (true) {
        sleep(1);
        sprintf(buf, "Enter a number %s: ", players[player_index].name);
        write(STDOUT_FILENO, buf, strlen(buf));
        int num = 0;
        read(STDIN_FILENO, buf, 256);
        buf[strcspn(buf, "\n")] = '\0'; //remove newline character
        if (isdigit(buf[0])) {
            num = atoi(buf);
            if (num < 1 || num > 60) {
                sprintf(buf, "Number is not valid. Enter a number between 1 and 60.\n");
                write(STDOUT_FILENO, buf, strlen(buf));
                continue;
            }
            else if (check_num(num) == false) {
                sprintf(buf, "Number %d is not on the board. Try again.\n", num);
                write(STDOUT_FILENO, buf, strlen(buf));
                continue;
            }
            else {
                pthread_mutex_lock(&board_lock);
                update_player(player_index, num);
                if (check_winner(player_index) == true) {
                    players[player_index].won = true;
                    sprintf(buf, "BINGO! %s has won.\n", players[player_index].name);
                    write(STDOUT_FILENO, buf, strlen(buf));
                    pthread_mutex_unlock(&board_lock);
                    pthread_exit(NULL);
                }
                pthread_mutex_unlock(&board_lock);
            }
        }
        else {
            sprintf(buf, "Input is not valid. Enter a number between 1 and 60.\n");
            write(STDOUT_FILENO, buf, strlen(buf));
            continue;
        }
    }
}

int main() {
    printf("Welcome to the Bingo Simulator!\n");
    create_board();
    print_board();
    char buf[256];
    while (true) {
        sprintf(buf, "How many players? (1 - %d): ", MAX_PLAYERS);
        write(STDOUT_FILENO, buf, strlen(buf));
        read(STDIN_FILENO, buf, 256);
        buf[strcspn(buf, "\n")] = '\0'; //remove newline character
        if (isdigit(buf[0])) {
            num_players = atoi(buf);
            if (num_players < 1 || num_players > MAX_PLAYERS) {
                sprintf(buf, "Number of players is not valid. Enter a number between 1 and %d.\n", MAX_PLAYERS);
                write(STDOUT_FILENO, buf, strlen(buf));
                continue;
            }
            else {
                //initialize players
                for (int i = 0; i < num_players; i++) {
                    players[i].name = malloc(256);
                    sprintf(players[i].name, "Player %d", i+1);
                    players[i].score = 0;
                    for (int j = 0; j < 25; j++) {
                        players[i].guessed_nums[j] = 0;
                    }
                    players[i].won = false;
                }
                //create threads for each player
                pthread_t tid[num_players];
                for (int i = 0; i < num_players; i++) {
                    int* arg = malloc(sizeof(*arg));
                    *arg = i;
                    pthread_create(&tid[i], NULL, play_game, arg);
                }
                //wait for all threads to finish
                for (int i = 0; i < num_players; i++) {
                    pthread_join(tid[i], NULL);
                }
                //print final scores
                printf("FINAL SCORES:\n");
                for (int i = 0; i < num_players; i++) {
                    printf("%s: %d\n", players[i].name, players[i].score);
                    free(players[i].name);
                }
                break;
            }
        }
        else {
            sprintf(buf, "Input is not valid. Enter a number between 1 and %d.\n", MAX_PLAYERS);
            write(STDOUT_FILENO, buf, strlen(buf));
            continue;
        }
    }
    return 0;
}