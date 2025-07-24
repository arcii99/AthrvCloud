//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_EVENTS 8
#define MAX_ALERTS 4

int main() {
    int event_score[MAX_EVENTS] = {0};          // array to store scores for each event
    int alert_score[MAX_ALERTS] = {0};          // array to store scores for each alert category
    
    // Simulated event data with scores for different categories
    int events[MAX_EVENTS][4] = {
        {1, 10, 5, 2},
        {2, 8, 5, 1},
        {3, 4, 3, 4},
        {4, 2, 6, 5},
        {5, 9, 7, 3},
        {6, 6, 8, 4},
        {7, 3, 4, 6},
        {8, 7, 2, 5}
    };
    
    // Iterate through each event and calculate the score
    for (int i = 0; i < MAX_EVENTS; i++) {
        int score = 0;
        for (int j = 1; j < 4; j++) {
            score += events[i][j];
        }
        event_score[i] = score;
    }
    
    // Iterate through each event score and check against thresholds
    for (int i = 0; i < MAX_EVENTS; i++) {
        int score = event_score[i];
        if (score >= 15) {
            alert_score[0]++;      // increment the score for category 1
        }
        else if (score >= 10) {
            alert_score[1]++;      // increment the score for category 2
        }
        else if (score >= 5) {
            alert_score[2]++;      // increment the score for category 3
        }
        else {
            alert_score[3]++;      // increment the score for category 4
        }
    }
    
    // Output the final alert scores
    printf("Alerts:\n");
    printf("Category 1: %d\n", alert_score[0]);
    printf("Category 2: %d\n", alert_score[1]);
    printf("Category 3: %d\n", alert_score[2]);
    printf("Category 4: %d\n", alert_score[3]);
    
    return 0;
}