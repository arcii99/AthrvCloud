//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>

int findMax(int arr[], int n) {
    int i, max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void distributeCandies(int candies[], int n) {
    int i, maxCandies, extraCandies = 0;
    
    // Find max number of candies
    maxCandies = findMax(candies, n);
    
    // Calculate extra candies needed for each child
    for (i = 0; i < n; i++) {
        extraCandies += maxCandies - candies[i];
    }
    
    // Distribute candies
    for (i = 0; i < n; i++) {
        int totalCandies = candies[i] + extraCandies;
        if (totalCandies >= ((maxCandies * n) / 2)) {
            printf("Child %d can have a happy Halloween! They received %d candies.\n", i+1, totalCandies);
        } else {
            printf("Child %d may be disappointed. They only got %d candies.\n", i+1, totalCandies);
        }
    }
}

int main() {
    int n, i;
    printf("How many children are trick-or-treating? ");
    scanf("%d", &n);
    int candies[n];
    for (i = 0; i < n; i++) {
        printf("How many candies did child %d receive? ", i+1);
        scanf("%d", &candies[i]);
    }
    distributeCandies(candies, n);
    return 0;
}