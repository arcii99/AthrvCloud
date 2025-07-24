//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Function to generate random download and upload speeds */
void generateSpeed(int *download, int *upload) {
    *download = rand() % 100 + 1;
    *upload = rand() % 100 + 1;
}

/* Function to print the results */
void printResults(int download, int upload) {
    printf("\nDownload Speed: %d Mbps\n", download);
    printf("Upload Speed: %d Mbps\n", upload);
}

/* Main function */
int main() {
    int download, upload;
    srand(time(0)); //set seed for random number generator
    printf("Starting Internet Speed Test ...\n");
    generateSpeed(&download, &upload);
    printf("Testing Download Speed...\n");
    //Simulate download speed test with a delay of 5 seconds
    for(int i = 1; i <= 5; i++) {
        printf("Testing...%d seconds\n", i);
        sleep(1);
    }
    printf("Download test completed!\n");
    printf("Testing Upload Speed...\n");
    //Simulate upload speed test with a delay of 5 seconds
    for(int i = 1; i <= 5; i++) {
        printf("Testing...%d seconds\n", i);
        sleep(1);
    }
    printf("Upload test completed!\n");
    generateSpeed(&download, &upload);
    printf("\nSpeed test results:\n");
    printResults(download, upload);
    return 0;
}