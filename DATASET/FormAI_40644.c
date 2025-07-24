//FormAI DATASET v1.0 Category: File handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// function to create a new file and add data to it
void createFile() {
    char fileName[20];
    printf("\nEnter the name of the file to create: ");
    scanf("%s", fileName);
    FILE *fp = fopen(fileName, "w");
    if(fp == NULL) {
        printf("\nError: Unable to create file.");
        exit(1);
    }
    char data[100];
    printf("\nEnter the data to add to the file: ");
    getchar(); // consume the extra new line character
    fgets(data, 100, stdin);
    fprintf(fp, "%s", data);
    printf("\nData added successfully.");
    fclose(fp);
}

// function to read data from an existing file
void readFile() {
    char fileName[20];
    printf("\nEnter the name of the file to read: ");
    scanf("%s", fileName);
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("\nError: Unable to open file.");
        exit(1);
    }
    char data[100];
    printf("\nThe data in the file is:\n");
    while(fgets(data, 100, fp)) {
        printf("%s", data);
    }
    fclose(fp);
}

// function to delete an existing file
void deleteFile() {
    char fileName[20];
    printf("\nEnter the name of the file to delete: ");
    scanf("%s", fileName);
    int ret = remove(fileName);
    if(ret == 0) {
        printf("\nFile deleted successfully.");
    } else {
        printf("\nError: Unable to delete file.");
    }
}

int main() {
    int choice;
    while(1) {
        printf("\nFile Handling Menu\n");
        printf("-------------------\n");
        printf("1. Create a new file\n");
        printf("2. Read data from an existing file\n");
        printf("3. Delete an existing file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                createFile();
                break;
            case 2:
                readFile();
                break;
            case 3:
                deleteFile();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }
    return 0;
}