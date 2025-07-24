//FormAI DATASET v1.0 Category: Random ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, num, max_num, min_num;

    printf("Enter the maximum number: ");
    scanf("%d", &max_num);
    printf("Enter the minimum number: ");
    scanf("%d", &min_num);

    srand(time(NULL)); // Seed the random number generator with the current time

    printf("Random numbers between %d and %d:\n", min_num, max_num);

    for (i = 0; i < 10; i++) {
        num = (rand() % (max_num - min_num + 1)) + min_num; // Generate a random number within the range
        printf("%d\n", num);
    }

    return 0;
}