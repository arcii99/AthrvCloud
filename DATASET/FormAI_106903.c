//FormAI DATASET v1.0 Category: Digital Diary ; Style: relaxed
#include <stdio.h>
#include <time.h>

int main() {
    FILE * filePointer;
    char fileName[20];
    char date[20];
    char entryText[200];
    char choice;

    printf("Welcome to your Digital Diary!\n\n");
    printf("Please enter a name for your diary file (without extension): ");
    scanf("%s", fileName);

    filePointer = fopen(strcat(fileName, ".txt"), "a");

    printf("Diary file created successfully!\n\n");

    do {
        printf("Enter today's date (dd/mm/yyyy): ");
        scanf("%s", date);
        fprintf(filePointer, "%s\n", date);

        printf("Enter your diary entry for today:\n");
        scanf(" %[^\n]s", entryText);
        fprintf(filePointer, "%s\n\n", entryText);

        printf("Do you want to add another entry? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\n\nThank you for using your Digital Diary!\n");
    fclose(filePointer);

    return 0;
}