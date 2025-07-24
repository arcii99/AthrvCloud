//FormAI DATASET v1.0 Category: File handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold player data
typedef struct {
    char name[20];
    int high_score;
    char last_played[20];
} Player;

int main() {
    FILE* file_ptr;
    Player player1 = {"Mike", 1245, "12/24/1985"};
    Player player2 = {"Jen", 1800, "11/05/1992"};

    // Write player data to file
    file_ptr = fopen("players.txt", "w");
    if(file_ptr == NULL) {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }
    fwrite(&player1, sizeof(Player), 1, file_ptr);
    fwrite(&player2, sizeof(Player), 1, file_ptr);
    fclose(file_ptr);
    printf("Player data written to file.\n");

    // Read player data from file
    Player player3, player4;
    file_ptr = fopen("players.txt", "r");
    if(file_ptr == NULL) {
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }
    fread(&player3, sizeof(Player), 1, file_ptr);
    fread(&player4, sizeof(Player), 1, file_ptr);
    fclose(file_ptr);
    printf("Player data read from file.\n");

    // Print player data to console
    printf("\nPlayer 1: \nName: %s\nHigh Score: %d\nLast Played: %s\n", player3.name, player3.high_score, player3.last_played);
    printf("\nPlayer 2: \nName: %s\nHigh Score: %d\nLast Played: %s\n", player4.name, player4.high_score, player4.last_played);

    return 0;
}