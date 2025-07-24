//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define KB 1024
#define MB (1024 * KB)
#define TIME_LIMIT 10

double test_speed(size_t data_size) {
    size_t samples = 0;
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < TIME_LIMIT) {
        char *data = malloc(data_size);
        if (data == NULL) {
            fprintf(stderr, "Error: Out of memory.\n");
            exit(EXIT_FAILURE);
        }
        // Fill memory with random data
        for (size_t i = 0; i < data_size; i++) {
            data[i] = rand() % 256;
        }
        // Start timer and write data
        clock_t start_clock = clock();
        size_t bytes_written = fwrite(data, 1, data_size, stdout);
        clock_t end_clock = clock();
        free(data);
        // Increment samples if data was written successfully
        if (bytes_written == data_size) {
            double time_elapsed = (double)(end_clock - start_clock) / CLOCKS_PER_SEC;
            samples++;
            printf("%zu bytes written in %.3f seconds.\n", data_size, time_elapsed);
        }
    }
    return (double)(samples * data_size) / TIME_LIMIT;
}

int main() {
    srand((unsigned int)time(NULL));
    printf("Testing download speed...\n");
    double download_speed = test_speed(10 * MB);
    printf("Your download speed is %.2f MB/s.\n", download_speed / MB);
    printf("Testing upload speed...\n");
    double upload_speed = test_speed(1 * MB);
    printf("Your upload speed is %.2f MB/s.\n", upload_speed / MB);
    return 0;
}