//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// implementation of unique C cryptographic hash function
// inspired by the classic board game "Battleship"

#define BOARD_SIZE 10 // size of the "game board"
#define HASH_SIZE 16 // size of generated hash in bytes

typedef struct {
    int row;
    int col;
} Position;

typedef unsigned char Byte;

typedef struct {
    Byte board[BOARD_SIZE][BOARD_SIZE];
} GameState;

void generateHash(GameState state, Byte hash[]) {
    // set all hash bytes to 0 initially
    memset(hash, 0, HASH_SIZE);
    
    // for each position on the board
    Position pos;
    for (pos.row = 0; pos.row < BOARD_SIZE; pos.row++) {
        for (pos.col = 0; pos.col < BOARD_SIZE; pos.col++) {
            // if the position contains a ship piece
            if (state.board[pos.row][pos.col]) {
                // use the position to "hit" a corresponding byte in the hash
                hash[(pos.row * BOARD_SIZE + pos.col) % HASH_SIZE] ^= state.board[pos.row][pos.col];
            }
        }
    }
}

int main() {
    // initialize game state with one randomly placed ship piece
    GameState state;
    memset(state.board, 0, sizeof(state.board));
    state.board[rand() % BOARD_SIZE][rand() % BOARD_SIZE] = rand() % 256;
    
    // generate hash for initial state
    Byte hash[HASH_SIZE];
    generateHash(state, hash);
    
    // print hash for visualization
    printf("Initial hash: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    
    // simulate some game actions which change the state
    // in a way that should affect the hash value
    
    for (int i = 0; i < 1000; i++) {
        Position target;
        target.row = rand() % BOARD_SIZE;
        target.col = rand() % BOARD_SIZE;
        Byte value = rand() % 256;
        
        state.board[target.row][target.col] ^= value; // "shoot" and change board state
        
        generateHash(state, hash); // generate new hash
        
        // in order to make the hash more unpredictable, 
        // we'll add some random bits to some bytes in the hash
        for (int j = 0; j < HASH_SIZE/2; j++) {
            hash[j] ^= rand() % 256;
        }
        
        // print current hash value
        printf("Turn %d hash: ", i+1);
        for (int j = 0; j < HASH_SIZE; j++) {
            printf("%02x", hash[j]);
        }
        printf("\n");
    }
    
    return 0;
}