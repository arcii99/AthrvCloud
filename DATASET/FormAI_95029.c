//FormAI DATASET v1.0 Category: Data recovery tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the C Data Recovery tool!\n");

    int numFiles;

    printf("Please enter the number of files you wish to recover: ");
    scanf("%d", &numFiles);

    int recoveredFiles[numFiles];

    for (int i = 0; i < numFiles; i++) {
        printf("Please enter the file number to recover: ");
        scanf("%d", &recoveredFiles[i]);

        if (recoveredFiles[i] < 0) {
            printf("Error: Invalid file number entered. Please try again.\n");
            i--;
        }
    }

    printf("\n");

    printf("Initiating data recovery process...\n");

    for (int i = 0; i < numFiles; i++) {
        printf("Recovering file %d...\n", recoveredFiles[i]);
    }

    printf("Data recovery complete!\n");

    return 0;
}