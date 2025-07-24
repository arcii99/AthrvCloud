//FormAI DATASET v1.0 Category: Error handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fp;
    char filename[50];
    char buffer[128];
    int num;

    printf("Enter the name of the file you wish to open: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open the file.\n");
        exit(1);
    } else {
        printf("File opened successfully.\n");
    }

    printf("Enter the number of characters you wish to read: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Error: Number of characters to read must be greater than 0.\n");
        exit(1);
    }

    if (fgets(buffer, num, fp) == NULL) {
        printf("Error: Failed to read the file.\n");
        fclose(fp);
        exit(1);
    }

    printf("The first %d characters in the file:\n%s\n", num, buffer);

    fclose(fp);
    return 0;
}