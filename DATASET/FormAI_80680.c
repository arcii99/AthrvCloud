//FormAI DATASET v1.0 Category: Log analysis ; Style: multiplayer
#include <stdio.h>

// Function to check if two players are in the same team
int arePlayersInSameTeam(int player1ID, int player2ID);

int main() {
    // Sample Log Data
    int player1IDLog[] = {1, 1, 1, 2, 3, 3, 4, 5, 5, 5};
    int player2IDLog[] = {2, 3, 4, 4, 4, 5, 6, 6, 7, 8};
    int numberOfLogs = 10;
    
    // Counters for statistics
    int totalNumberOfMatchesPlayed = 0;
    int numberOfMatchesWithSameTeamPlayers = 0;
    int numberOfMatchesWithoutSameTeamPlayers = 0;
    
    // Analyze the log data
    for (int i = 0; i < numberOfLogs; i++) {
        int player1ID = player1IDLog[i];
        int player2ID = player2IDLog[i];
        totalNumberOfMatchesPlayed++;
        
        // Check if both players are in the same team
        if (arePlayersInSameTeam(player1ID, player2ID)) {
            numberOfMatchesWithSameTeamPlayers++;
        } else {
            numberOfMatchesWithoutSameTeamPlayers++;
        }
    }
    
    // Print the statistics
    printf("Total Number of Matches Played: %d\n", totalNumberOfMatchesPlayed);
    printf("Number of Matches With Same Team Players: %d\n", numberOfMatchesWithSameTeamPlayers);
    printf("Number of Matches Without Same Team Players: %d\n", numberOfMatchesWithoutSameTeamPlayers);
    
    return 0;
}

// Function to check if two players are in the same team
int arePlayersInSameTeam(int player1ID, int player2ID) {
    // Logic to check if both players are in the same team
    if (player1ID % 2 == player2ID % 2) {
        return 1;
    } else {
        return 0;
    }
}