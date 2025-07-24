//FormAI DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    char fileName[30];
    FILE *file;
    int choice, num;

    printf("Enter the name of the file to open: ");
    scanf("%s", fileName);

    file = fopen(fileName, "w");

    if (file == NULL) {
        printf("There was an error opening the file!");
        exit(1);
    }

    printf("File opened successfully.\n");
    printf("1. Write data to the file.\n");
    printf("2. Read data from the file.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the number of integers to write to the file: ");
            scanf("%d", &num);

            printf("Enter %d integers to write to the file:\n", num);

            for (int i = 0; i < num; i++) {
                int data;
                scanf("%d", &data);
                fprintf(file, "%d ", data);
            }

            printf("Data written to the file successfully!\n");
            break;
        case 2:
            printf("Reading data from the file...\n");

            char content[100];
            fgets(content, 100, file);
            printf("File content: %s\n", content);
            break;
        default:
            printf("Invalid choice.\n");
    }

    fclose(file);

    return 0;
}