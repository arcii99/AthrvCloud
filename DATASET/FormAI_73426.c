//FormAI DATASET v1.0 Category: Memory Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void shuffle(int arr[]) {
    srand(time(NULL));
    for (int i = MAX - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int arr[MAX];
    for (int i = 0; i < MAX/2; i++) {
        arr[i] = i+1;
        arr[i+MAX/2] = i+1;
    }
    shuffle(arr);
    
    int board[MAX] = {0};
    int tries = 0;
    while (1) {
        printf("Current board:\n");
        for (int i = 0; i < MAX; i++) {
            if (board[i] == 0) {
                printf("[ ]");
            } else {
                printf("[%d]", arr[i]);
            }
        }
        printf("\n");
        
        int pos1, pos2;
        printf("Enter two positions to flip (-1 to quit): ");
        scanf("%d %d", &pos1, &pos2);
        
        if (pos1 == -1 || pos2 == -1) {
            printf("Quitting game...\n");
            break;
        }
        
        if (pos1 < 0 || pos1 >= MAX || pos2 < 0 || pos2 >= MAX) {
            printf("Invalid positions. Please try again.\n");
            continue;
        }
        
        if (board[pos1] != 0 || board[pos2] != 0) {
            printf("One or both positions already flipped. Please try again.\n");
            continue;
        }
        
        board[pos1] = arr[pos1];
        board[pos2] = arr[pos2];
        tries++;
        
        printf("Current board:\n");
        for (int i = 0; i < MAX; i++) {
            if (board[i] == 0) {
                printf("[ ]");
            } else {
                printf("[%d]", board[i]);
            }
        }
        printf("\n");
        
        if (board[pos1] != board[pos2]) {
            board[pos1] = 0;
            board[pos2] = 0;
            printf("Not a match. Please try again.\n");
            continue;
        }
        
        int done = 1;
        for (int i = 0; i < MAX; i++) {
            if (board[i] == 0) {
                done = 0;
                break;
            }
        }
        if (done) {
            printf("Congratulations! You completed the game with %d tries.\n", tries);
            break;
        }
        
        printf("Match found! Great job.\n");
    }
    
    return 0;
}