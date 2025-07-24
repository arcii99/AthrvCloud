//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int invasion_prob = rand() % 101;
    char *response;

    if (invasion_prob > 80) {
        response = "Run for cover! The aliens are definitely coming!";
    } else if (invasion_prob > 60) {
        response = "Keep on the lookout, there's a moderate chance of an alien invasion.";
    } else {
        response = "Don't worry, the probability of an alien invasion is low.";
    }

    printf("Alien Invasion Probability: %d%%\n", invasion_prob);
    printf("%s\n", response);

    return 0;
}