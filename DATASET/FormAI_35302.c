//FormAI DATASET v1.0 Category: Data recovery tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to our C Data Recovery Tool!\n");
    printf("Have you ever accidentally deleted important files and couldn't recover them? Worry no more!\n");
    printf("Our program uses advanced algorithms to scan your storage device and recover as much data as possible.\n");
    printf("Please enter the name of the device you want to scan: ");

    char device_name[256];
    scanf("%s", device_name);

    printf("Scanning %s...\n", device_name);

    // Simulating scanning process
    for (int i = 0; i < 10; i++) {
        printf("Scanned %d%% of %s\n", i*10, device_name);
        sleep(1);
    }

    printf("Scan complete! Found 10 files.\n");

    // Simulating file recovery process
    for (int i = 0; i < 10; i++) {
        printf("Recovering file %d...\n", i+1);
        sleep(1);
    }

    printf("All files recovered successfully! Thank you for using our C Data Recovery Tool!\n");

    return 0;
}