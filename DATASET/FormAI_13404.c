//FormAI DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>

int main() {
    // Creating a file pointer
    FILE *fp;
    char filename[20], data[100], choice;
    int ch;

    // User input for file name and opening the file
    printf("Enter the file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "w+");

    // Checking if file is successfully opened or not
    if (fp == NULL) {
        printf("Error occurred while opening the file!\n");
        return 1;
    }

    // Storing data in file
    do {
        printf("Enter data: ");
        scanf(" %[^\n]", data);
        fprintf(fp, "%s\n", data);
        printf("Do you want to add more data? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    printf("\nData successfully saved in the file.\n");

    // Reading the data from file
    printf("\nData from the file: \n");
    rewind(fp); // placing pointer to beginning of the file
    while ((ch = fgetc(fp)) != EOF) { 
        printf("%c", ch);
    }

    // Closing the file
    fclose(fp);

    return 0;
}