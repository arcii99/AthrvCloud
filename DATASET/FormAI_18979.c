//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Sorting Circus!\n\n");

    srand(time(NULL));
    int num_balls = rand() % 20 + 1; // randomized number of balls
    int balls[num_balls];

    printf("Before sorting: \n");
    for (int i = 0; i < num_balls; i++) {
        balls[i] = rand() % 100; // randomly set ball's integer value
        printf("%d ", balls[i]);
    }
    printf("\n\nLet the show begin!\n\n");

    // Sorting act 1: Bubble Sort
    printf("Act 1: Bubble Sort! The balls will be bounced around until they are sorted!\n");
    for (int i = 0; i < num_balls - 1; i++) {
        for (int j = 0; j < num_balls - i - 1; j++) {
            if (balls[j] > balls[j+1]) {
                int temp = balls[j];
                balls[j] = balls[j+1];
                balls[j+1] = temp;
            }
        }
    }

    printf("After Act 1: Bubble Sort: \n");
    for (int i = 0; i < num_balls; i++) {
        printf("%d ", balls[i]);
    }
    printf("\n\nNext act!\n\n");

    // Sorting act 2: Selection Sort
    printf("Act 2: Selection Sort! The balls will perform a line dance and choose their proper position!\n");
    for (int i = 0; i < num_balls - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < num_balls; j++) {
            if (balls[j] < balls[min_idx]) {
                min_idx = j;
            }
        }
        int temp = balls[i];
        balls[i] = balls[min_idx];
        balls[min_idx] = temp;
    }

    printf("After Act 2: Selection Sort: \n");
    for (int i = 0; i < num_balls; i++) {
        printf("%d ", balls[i]);
    }
    printf("\n\nLast but not least, the final act!\n\n");

    // Sorting act 3: Insertion Sort
    printf("Act 3: Insertion Sort! The balls will move around and crawl into their right place!\n");
    for (int i = 1; i < num_balls; i++) {
        int key = balls[i];
        int j = i - 1;
        while (j >= 0 && balls[j] > key) {
            balls[j+1] = balls[j];
            j = j - 1;
        }
        balls[j+1] = key;
    }

    printf("After Act 3: Insertion Sort: \n");
    for (int i = 0; i < num_balls; i++) {
        printf("%d ", balls[i]);
    }
    printf("\n\nThank you for watching! We hope you enjoyed the Sorting Circus!\n");

    return 0;
}