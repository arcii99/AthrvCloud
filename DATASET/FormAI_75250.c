//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed random number generator
    int n = 10; // Number of castles
    int castle[n][2]; // castle[i][0] is gold, castle[i][1] is number of soldiers
    
    // Initialize castles with random gold and soldiers
    for(int i=0; i<n; i++) {
        castle[i][0] = rand() % 1000 + 1; // Random gold from 1-1000
        castle[i][1] = rand() % 100 + 1; // Random soldiers from 1-100
        printf("Castle %d: Gold=%d Soldiers=%d\n", i+1, castle[i][0], castle[i][1]);
    }
    
    // Greedy algorithm to choose best castles to attack
    int gold = 0, soldiers = 0;
    int attacked[n];
    for(int i=0; i<n; i++) {
        attacked[i] = 0;
    }
    
    for(int i=0; i<n; i++) {
        int max_gold = -1, max_castle;
        for(int j=0; j<n; j++) {
            if(attacked[j] == 1) {
                continue; // Ignore already attacked castles
            }
            if(castle[j][0] > max_gold) {
                max_gold = castle[j][0];
                max_castle = j;
            }
        }
        // Attack the castle with the most gold
        attacked[max_castle] = 1;
        gold += castle[max_castle][0];
        soldiers += castle[max_castle][1];
        printf("Attacked Castle %d\n", max_castle+1);
        printf("Gold=%d Soldiers=%d\n", gold, soldiers);
        if(soldiers > 500) {
            printf("Retreated after winning %d gold and killing %d soldiers\n", gold, soldiers);
            break; // Retreat if too many soldiers are killed
        }
    }
    return 0;
}