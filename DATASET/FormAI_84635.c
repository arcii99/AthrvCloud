//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePtr;
    char fileName[50];
    int total_nums, num, i;

    printf("Enter file name to create: ");
    scanf("%s", fileName);

    filePtr = fopen(fileName, "w");

    if (filePtr == NULL) {
        printf("Error creating file. ");
        exit(1);
    }

    printf("Enter the total numbers to store: ");
    scanf("%d", &total_nums);

    for (i = 0; i < total_nums; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        fprintf(filePtr, "%d ", num);
    }

    fclose(filePtr);
    
    printf("File created and saved successfully!\n\n");

    filePtr = fopen(fileName, "r");

    printf("All numbers in the file: ");
    while (!feof(filePtr)) {
        fscanf(filePtr, "%d", &num);
        printf("%d ", num);
    }

    fclose(filePtr);
    
    printf("\nFile read and closed successfully!\n");

    return 0;
}