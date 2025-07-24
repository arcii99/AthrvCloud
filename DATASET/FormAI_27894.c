//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    int data = 1000000; // 1 MB
    int time_taken;
    clock_t t;

    printf("Welcome to Internet Speed Test Application\n");
    printf("Testing internet speed...\n");

    t = clock();

    // simulate internet speed test by reading and writing data repeatedly
    for (int i = 0; i < 10; i++) {
        // write data
        FILE *fptr = fopen("test.txt", "w");
        fwrite(&data, sizeof(int), 1, fptr);
        fclose(fptr);

        // read data
        FILE *fptr2 = fopen("test.txt", "r");
        int buffer;
        fread(&buffer, sizeof(int), 1, fptr2);
        fclose(fptr2);
    }

    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC * 1000;

    // calculate internet speed in Mbps
    float speed = (10.0 * sizeof(int) * 8) / ((float)time_taken / 1000) / 1000000;

    printf("Internet speed test completed successfully\n");
    printf("Your internet speed is %.2f Mbps\n", speed);

    return 0;
}