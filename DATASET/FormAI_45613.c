//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program analyzes the C drive and displays the total amount
 * of disk space used and available space.
 */

int main(void) {
    int totalSpace, usedSpace, availableSpace;

    // Open the C drive for analysis
    FILE *fp = fopen("C:\\", "r");

    // Check if the drive was opened successfully
    if (fp == NULL) {
        printf("Error opening C drive\n");
        exit(EXIT_FAILURE);
    }

    // Analyze the drive
    char c;
    int size = 0;
    while ((c = fgetc(fp)) != EOF) {
        size++;
    }

    // Calculate space statistics
    totalSpace = size;
    usedSpace = totalSpace - availableSpace; // Currently set to 0 for demonstration purposes
    availableSpace = 0; // Currently set to 0 for demonstration purposes

    printf("Disk space statistics for C drive:\n");
    printf("Total space: %d bytes\n", totalSpace);
    printf("Used space: %d bytes\n", usedSpace);
    printf("Available space: %d bytes\n", availableSpace);

    // Close the C drive
    fclose(fp);

    return 0;
}