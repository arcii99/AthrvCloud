//FormAI DATASET v1.0 Category: Recursive ; Style: configurable
#include <stdio.h>

// Configurable settings
#define MAX_LEVEL 5
#define MAX_COUNT 10

void printIndent(int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
}

int recursiveFunction(int level, int count) {
    if (level > MAX_LEVEL) {
        return 0;
    }

    for (int i = 1; i <= count; i++) {
        printIndent(level);
        printf("Level %d, iteration %d\n", level, i);

        recursiveFunction(level + 1, MAX_COUNT - i);
    }

    return 0;
}

int main() {
    recursiveFunction(1, MAX_COUNT);

    return 0;
}