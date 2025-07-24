//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define BILLION  1000000000.0

double test_speed() {
    struct timespec start, end;
    double elapsed_time;

    clock_gettime(CLOCK_MONOTONIC, &start);

    // do some network operation here
    // for example, request to a website
    system("curl -o /dev/null http://example.com");

    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed_time = (end.tv_sec - start.tv_sec) +
            (end.tv_nsec - start.tv_nsec) / BILLION;
    return elapsed_time;
}

void display_result(double elapsed_time) {
    if (elapsed_time < 1) {
        printf("Your internet speed is super fast!\n");
    } else if (elapsed_time < 5) {
        printf("Your internet speed is fast!\n");
    } else if (elapsed_time < 10) {
        printf("Your internet speed is average!\n");
    } else {
        printf("Your internet speed is slow!\n");
    }
    printf("Elapsed time: %.4f seconds\n", elapsed_time);
}

int main() {
    double elapsed_time = test_speed();
    display_result(elapsed_time);
    return 0;
}