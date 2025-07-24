//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double calculateSpeed(double timeTaken, double fileSize) {
    return (fileSize / (timeTaken * 1000 * 1000));
}

int main() {
    double size = 50; // The size of the test file in MB
    clock_t start, end;
    double timeTaken;
    double speed;
  
    // Creating a test file
    FILE *fp;
    fp = fopen("test.txt", "w");
    for(int i=0; i<(size*1000*1000); i++) {
        fputc('t', fp);
    }
    fclose(fp);
  
    // Testing the download speed
    printf("Testing download speed...\n");
    start = clock();
    system("curl -o /dev/null https://speed.hetzner.de/100MB.bin");
    end = clock();
    timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    speed = calculateSpeed(timeTaken, 100);
    printf("Your download speed is: %.2f Mbps\n\n", speed);
  
    // Testing the upload speed
    printf("Testing upload speed...\n");
    start = clock();
    system("curl --upload-file test.txt https://file.io");
    end = clock();
    timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;
    speed = calculateSpeed(timeTaken, size);
    printf("Your upload speed is: %.2f Mbps\n", speed);
  
    // Deleting the test file
    system("rm test.txt");
  
    return 0;
}