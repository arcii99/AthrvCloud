//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    float downloadSpeed;
    float uploadSpeed;
    
    // generate random download and upload speeds between 1-100 Mbps
    srand(time(NULL));
    downloadSpeed = rand() % 100 + 1;
    uploadSpeed = rand() % 100 + 1;
    
    printf("Welcome to the Internet Speed Test!\n\n");
    printf("Your download speed is %.2f Mbps\n", downloadSpeed);
    printf("Your upload speed is %.2f Mbps\n", uploadSpeed);
    
    if(downloadSpeed >= 50) {
        printf("\nWow, your download speed is lightning fast!\n");
    } else if(downloadSpeed >= 25) {
        printf("\nYour download speed is pretty good, but could be better.\n");
    } else {
        printf("\nYour download speed needs some improvement.\n");
    }
    
    if(uploadSpeed >= 50) {
        printf("Your upload speed is also amazing, great job!\n");
    } else if(uploadSpeed >= 25) {
        printf("Your upload speed is decent, but could be improved.\n");
    } else {
        printf("Your upload speed is too slow, work on improving it.\n");
    }
    
    printf("\nThank you for using the Internet Speed Test!");
    
    return 0;
}