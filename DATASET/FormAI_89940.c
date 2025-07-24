//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 10;
    int robots[n];
    srand(time(NULL));
    
    // Generate random strength levels for each robot
    for (int i = 0; i < n; i++) {
        robots[i] = rand() % 100 + 1;
    }
    
    int total_strength = 0;
    int num_robots = 0;
    
    // Sort robots in decreasing order of strength
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (robots[j] < robots[j+1]) {
                int temp = robots[j];
                robots[j] = robots[j+1];
                robots[j+1] = temp;
            }
        }
    }
    
    // Choose strongest robots until total strength meets a certain threshold
    int threshold = 300;
    while (total_strength < threshold) {
        total_strength += robots[num_robots];
        num_robots++;
    }
    
    printf("We need %d robots to complete the job with a total strength of %d\n", num_robots, total_strength);
    
    return 0;
}