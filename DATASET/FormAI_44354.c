//FormAI DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>

int main() {
    FILE *fp;
    int i, num, arr[10];

    // Writing to a file
    fp = fopen("numbers.txt", "w");

    // Writing numbers to the file
    for(i = 0; i < 10; i++) {
        printf("Enter a number: ");
        scanf("%d", &num);
        fprintf(fp, "%d ", num);
    }

    fclose(fp);

    // Reading from a file
    fp = fopen("numbers.txt", "r");

    // Checking if file exists or not
    if(fp == NULL) {
        printf("File doesn't exist.");
        return 0;
    }

    // Reading numbers from the file
    for(i = 0; i < 10; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);

    // Printing numbers read from the file
    printf("Numbers read from file:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}