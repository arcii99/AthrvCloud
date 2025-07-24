//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, sum = 0;
    double average;
    clock_t start_time, end_time;
    double duration;

    start_time = clock();

    printf("Welcome to the Internet Speed Test Application\n");

    // Generate 10 random internet speeds between 1 and 100 Mbps
    srand(time(0));
    int speeds[10];
    printf("Generating 10 random internet speeds...\n");
    for (i = 0; i < 10; i++) {
        speeds[i] = rand() % 100 + 1;
        printf("Test %d: %d Mbps\n", i + 1, speeds[i]);
        sum += speeds[i];
    }

    average = (double) sum / 10;
    printf("Average speed: %.2lf Mbps\n", average);
    if (average >= 50) {
        printf("Your internet speed is excellent!\n");
    } else if (average >= 30 && average < 50) {
        printf("Your internet speed is good\n");
    } else {
        printf("Your internet speed is poor\n");
    }

    end_time = clock();
    duration = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nTotal duration: %.2lf seconds\n", duration);

    return 0;
}