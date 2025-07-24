//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_BAGS 1000
#define MAX_WEIGHT 100 // in kgs
#define MAX_TIME 10 // in seconds

typedef struct {
    int id;
    float weight;
    int time;
} Baggage;

int main() {
    int n_bags;
    Baggage bags[MAX_BAGS];
    srand(time(NULL));

    printf("Enter number of bags to process (max %d): ", MAX_BAGS);
    scanf("%d", &n_bags);

    // Generate random baggages
    for(int i=0; i<n_bags; i++) {
        bags[i].id = i+1;
        bags[i].weight = (rand() % MAX_WEIGHT) + 1;
        bags[i].time = (rand() % MAX_TIME) + 1;
    }

    // Simulate baggage handling
    printf("\nProcessing baggage...\n\n");

    for(int i=0; i<n_bags; i++) {
        printf("Processing baggage %d of weight %.2f kgs for %d seconds...\n", bags[i].id, bags[i].weight, bags[i].time);

        // Wait for processing time
        for(int j=1; j<=bags[i].time; j++) {
            printf("Processing...(%d/%d)\n", j, bags[i].time);
            sleep(1);
        }

        printf("Baggage %d processed!\n\n", bags[i].id);
    }

    printf("Baggage handling complete!\n");
    return 0;
}