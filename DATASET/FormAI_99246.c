//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int ghostCounter = 3 + rand() % 4; // 3 to 6 ghosts
    int ghostIDs[ghostCounter];
    for(int i=0; i<ghostCounter; i++) {
        ghostIDs[i] = i + 1;
    }
    int timeLeft = 300; // 5 minutes
    int score = 0;
    while(timeLeft > 0) {
        int randomEvent = rand() % 10;
        if(randomEvent < 3) {
            int randomGhost = rand() % ghostCounter;
            printf("A ghost with ID #%d has appeared!\n", ghostIDs[randomGhost]);
            if(rand() % 2) {
                printf("You were scared and lost some time!\n");
            } else {
                printf("You managed to stay calm and gained some score!\n");
                score += 10;
            }
        } else if(randomEvent < 7) {
            int lostTime = rand() % 20 + 10;
            printf("You've lost %d seconds due to a malfunctioning door!\n", lostTime);
            timeLeft -= lostTime;
        } else {
            int gainedTime = rand() % 20 + 10;
            printf("You've gained %d seconds due to finding a hidden exit!\n", gainedTime);
            timeLeft += gainedTime;
        }
        printf("Time left: %d seconds. Score: %d\n", timeLeft, score);
    }
    printf("Time's up!\n");
    if(score >= 50) {
        printf("You made it out alive with a score of %d!\n", score);
    } else {
        printf("You failed to escape with a score of %d. Better luck next time!\n", score);
    }
    return 0;
}