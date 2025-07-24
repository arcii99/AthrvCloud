//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to calculate internet speed
double calculate_speed(double time_taken) {
    double speed = 10000 * sizeof(char) / time_taken;
    return speed;
}

int main() {
    printf("Welcome to Internet Speed Test Application!\n");
    printf("------------------------------------------\n");

    // generating random data
    char* data = malloc(10000 * sizeof(char));
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        data[i] = rand() % 256;
    }

    printf("Downloading data...\n");
    clock_t start_time = clock();
    // downloading data
    for (int i = 0; i < 10000; i++) {
        printf("%c", data[i]);
    }
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    double speed = calculate_speed(time_taken);
    printf("\n\nDownload speed: %lf mb/s", speed);

    free(data);
    return 0;
}