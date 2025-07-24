//FormAI DATASET v1.0 Category: Recursive ; Style: imaginative
#include <stdio.h>

// Imagine a forest with a wide variety of trees.
// This recursive function calculates the total number of leaves in the forest.
int countLeaves(int numTrees, int treesWithLeaves[], int leavesPerTree[]) {
    int totalLeaves = 0;

    // Base case: No more trees in this corner of the forest.
    if (numTrees == 0) {
        return 0;
    }

    // Check if the current tree has any leaves.
    if (treesWithLeaves[numTrees-1] == 1) {
        totalLeaves += leavesPerTree[numTrees-1];
    }

    // Recursively count the leaves in the rest of the forest.
    totalLeaves += countLeaves(numTrees-1, treesWithLeaves, leavesPerTree);

    return totalLeaves;
}

int main() {
    // Imagine a forest with 7 trees.
    int numTrees = 7;

    // Imagine which trees have leaves.
    int treesWithLeaves[] = {1, 0, 1, 1, 0, 0, 1};

    // Imagine how many leaves each tree has.
    int leavesPerTree[] = {10, 0, 5, 8, 0, 0, 3};

    // Calculate the total number of leaves in the forest using recursion.
    int totalLeaves = countLeaves(numTrees, treesWithLeaves, leavesPerTree);

    // Print out the total number of leaves.
    printf("The total number of leaves in the forest is: %d\n", totalLeaves);

    return 0;
}