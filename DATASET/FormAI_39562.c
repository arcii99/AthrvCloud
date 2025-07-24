//FormAI DATASET v1.0 Category: Digital Diary ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {   // define a structure for each diary entry
    int day, month, year;
    char title[50];
    char content[2000];
} DiaryEntry;

DiaryEntry *diary = NULL;  // initialize global pointer to entry array
int numEntries = 0;  // initialize number of entries in diary


void saveToFile() {   // function to save diary to file
    FILE *fp = fopen("diary.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return;
    }

    fprintf(fp, "%d\n", numEntries);   // first line in file is number of entries

    for (int i = 0; i < numEntries; i++) {  // loop over all diary entries and write to file
        fprintf(fp, "%02d/%02d/%d\n", diary[i].day, diary[i].month, diary[i].year);
        fprintf(fp, "%s\n", diary[i].title);
        fprintf(fp, "%s\n", diary[i].content);
    }

    fclose(fp);
}

void readFromFile() {  // function to read diary from file at program start
    FILE *fp = fopen("diary.txt", "r");
    if (fp == NULL) {
        return;   // no diary yet, start with empty diary
    }

    fscanf(fp, "%d\n", &numEntries);   // first line in file is number of entries
    diary = (DiaryEntry*) realloc(diary, numEntries * sizeof(DiaryEntry));  // allocate diary array based on number of entries in file

    for (int i = 0; i < numEntries; i++) {  // loop over all diary entries and read from file
        fscanf(fp, "%02d/%02d/%d\n", &diary[i].day, &diary[i].month, &diary[i].year);
        fgets(diary[i].title, 50, fp);  
        diary[i].title[strcspn(diary[i].title, "\n")] = '\0';   // read title and remove newline character
        fgets(diary[i].content, 2000, fp);
        diary[i].content[strcspn(diary[i].content, "\n")] = '\0';  // read content and remove newline character
    }

    fclose(fp);
}

void newEntry() {   // function to create new diary entry and add to diary array
    numEntries++;
    diary = (DiaryEntry*) realloc(diary, numEntries * sizeof(DiaryEntry));
    time_t currentTime;
    time(&currentTime);
    struct tm * localTime = localtime(&currentTime);
    diary[numEntries-1].day = localTime->tm_mday;
    diary[numEntries-1].month = localTime->tm_mon + 1;
    diary[numEntries-1].year = localTime->tm_year + 1900;
    printf("\nEnter title of new entry: ");
    fgets(diary[numEntries-1].title, 50, stdin);
    diary[numEntries-1].title[strcspn(diary[numEntries-1].title, "\n")] = '\0';  // remove newline character
    printf("Enter content of new entry (max 2000 characters):\n");
    fgets(diary[numEntries-1].content, 2000, stdin);
    diary[numEntries-1].content[strcspn(diary[numEntries-1].content, "\n")] = '\0';  // remove newline character
    printf("\nNew entry added!\n");
}

void viewEntries() {   // function to view all diary entries
    for (int i = 0; i < numEntries; i++) {
        printf("\nDate: %02d/%02d/%d\nTitle: %s\nContent: %s\n", diary[i].day, diary[i].month, diary[i].year, diary[i].title, diary[i].content);
    }
}

int main() {
    readFromFile();  // read diary from file at program start

    char choice;
    do {
        printf("\n\nChoose an option:\n1. Create new entry\n2. View all entries\n3. Save diary to file\n4. Exit\n");
        scanf(" %c", &choice);
        getchar();   // remove newline character from input buffer

        switch (choice) {
            case '1':
                newEntry();
                break;
            case '2':
                viewEntries();
                break;
            case '3':
                saveToFile();
                break;
            case '4':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != '4');

    return 0;
}