//FormAI DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaration of struct
struct Player {
   char name[50];
   int score;
};

// Function to compare two player scores
int compare(const void* a, const void* b) {
    struct Player *player1 = (struct Player*)a;
    struct Player *player2 = (struct Player*)b;
    return (player2->score - player1->score);
}

// Function to create and sort indexing
void createIndex(struct Player players[], int size) {
    // Create a temp variable to hold the sorted version of players[]
    struct Player temp[size];
    memcpy(temp, players, sizeof(struct Player) * size);

    // Sort the temp array by score
    qsort((void*)temp, size, sizeof(struct Player), compare);

    // Print the sorted rankings and index
    printf("\nRankings:\n");
    printf("------------\n");
    for(int i = 0; i < size; i++) {
        printf("%d. %s: %d\n", i+1, temp[i].name, temp[i].score);
    }
    printf("\nIndex:\n");
    printf("------------\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(strcmp(players[j].name, temp[i].name) == 0) {
                printf("%d. %s\n", i+1, players[j].name);
                break;
            }
        }
    }
}

// Main function to initialize a few players and call createIndex()
int main() {
    // Initialize an array of players
    struct Player players[5] = {
        {"John", 100},
        {"Jane", 75},
        {"David", 120},
        {"Sara", 85},
        {"Alex", 90}
    };

    // Call the createIndex function to create the index
    createIndex(players, 5);

    return 0;
}