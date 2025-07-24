//FormAI DATASET v1.0 Category: Digital Diary ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//structure to represent a single entry in the digital diary
typedef struct{
    char date[11];
    char time[6];
    char entry[500];
} DiaryEntry;

//function declarations
void createEntry(DiaryEntry *entry);
void displayEntries(DiaryEntry *entries, int numOfEntries);
void updateEntry(DiaryEntry *entry, int entryIndex);
void deleteEntry(DiaryEntry *entries, int *numOfEntries, int entryIndex);
void saveEntries(DiaryEntry *entries, int numOfEntries);
void loadEntries(DiaryEntry *entries, int *numOfEntries);
bool validateInt(char num[]);
bool validateMonth(char month[]);
bool validateYear(char year[]);

int main()
{
    DiaryEntry entries[100];    //array to hold all the diary entries
    int numOfEntries = 0;       //counter to keep track of number of entries
    char option[10];
    char buffer[100];

    printf("Welcome to your digital diary!\n");
    loadEntries(entries, &numOfEntries);   //load previous entries (if any)

    do{
        printf("\nOptions:\n");
        printf("1. View Entries\n");
        printf("2. Create an Entry\n");
        printf("3. Update an Existing Entry\n");
        printf("4. Delete an Entry\n");
        printf("5. Exit\n");

        //get user's choice of action
        printf("\nEnter your choice (1-5): ");
        fgets(option, 10, stdin);
        option[strcspn(option, "\n")] = 0;   //removes newline character from input

        //perform action based on user's choice
        if(strcmp(option, "1") == 0){
            displayEntries(entries, numOfEntries);
        }
        else if(strcmp(option, "2") == 0){
            createEntry(&entries[numOfEntries]);
            numOfEntries++;
        }
        else if(strcmp(option, "3") == 0){
            int entryIndex;
            printf("\nEnter the index of the entry you want to update (0-%d): ", numOfEntries-1);
            
            fgets(buffer, 100, stdin);
            buffer[strcspn(buffer, "\n")] = 0;   //removes newline character from input

            if(!validateInt(buffer)){
                printf("\nInvalid input!\n");
                continue;
            }
            entryIndex = atoi(buffer);

            if(entryIndex < 0 || entryIndex >= numOfEntries){
                printf("\nInvalid index!\n");
                continue;
            }
            updateEntry(&entries[entryIndex], entryIndex);
        }
        else if(strcmp(option, "4") == 0){
            int entryIndex;
            printf("\nEnter the index of the entry you want to delete (0-%d): ", numOfEntries-1);
            
            fgets(buffer, 100, stdin);
            buffer[strcspn(buffer, "\n")] = 0;   //removes newline character from input

            if(!validateInt(buffer)){
                printf("\nInvalid input!\n");
                continue;
            }
            entryIndex = atoi(buffer);

            if(entryIndex < 0 || entryIndex >= numOfEntries){
                printf("\nInvalid index!\n");
                continue;
            }
            deleteEntry(entries, &numOfEntries, entryIndex);
        }
        else if(strcmp(option, "5") == 0){
            printf("\nSaving entries and exiting...\n");
            saveEntries(entries, numOfEntries);   //save entries before exiting
        }
        else{
            printf("\nInvalid option!\n");
        }

    }while(strcmp(option, "5") != 0);
    
    return 0;
}

//function to create a new diary entry
void createEntry(DiaryEntry *entry){
    printf("\nEnter the date (DD/MM/YYYY): ");
    fgets(entry->date, 11, stdin);
    entry->date[strcspn(entry->date, "\n")] = 0;   //removes newline character from input

    char day[3];
    char month[3];
    char year[5];

    strncpy(day, entry->date, 2);
    strncpy(month, entry->date+3, 2);
    strncpy(year, entry->date+6, 4);

    if(!validateInt(day) || !validateMonth(month) || !validateYear(year)){
        printf("\nInvalid date format!\n");
        return;
    }

    printf("Enter the time (HH:MM): ");
    fgets(entry->time, 6, stdin);
    entry->time[strcspn(entry->time, "\n")] = 0;   //removes newline character from input

    char hour[3];
    char minute[3];

    strncpy(hour, entry->time, 2);
    strncpy(minute, entry->time+3, 2);

    if(!validateInt(hour) || !validateInt(minute)){
        printf("\nInvalid time format!\n");
        return;
    }

    printf("Enter your entry (maximum 500 characters):\n");
    fgets(entry->entry, 500, stdin);
    entry->entry[strcspn(entry->entry, "\n")] = 0;   //removes newline character from input

    printf("\nEntry created!\n");
}

//function to display all previously saved diary entries
void displayEntries(DiaryEntry *entries, int numOfEntries){
    if(numOfEntries == 0){
        printf("\nYou have no entries yet!\n");
    }
    else{
        printf("\nYour Entries:\n");
        for(int i=0; i<numOfEntries; i++){
            printf("%d. Date: %s, Time: %s\n   Entry: %s\n", i, entries[i].date, entries[i].time, entries[i].entry);
        }
    }
}

//function to update an existing diary entry
void updateEntry(DiaryEntry *entry, int entryIndex){
    char option[10];
    char buffer[100];

    printf("\nCurrent Entry:\n");
    printf("   Date: %s, Time: %s\n   Entry: %s\n", entry->date, entry->time, entry->entry);

    do{
        printf("\nWhat would you like to update?\n");
        printf("1. Date\n");
        printf("2. Time\n");
        printf("3. Entry\n");
        printf("4. Cancel\n");

        //get user's choice of field to update
        printf("\nEnter your choice (1-4): ");
        fgets(option, 10, stdin);
        option[strcspn(option, "\n")] = 0;   //removes newline character from input

        //perform update based on user's choice
        if(strcmp(option, "1") == 0){
            printf("\nEnter the new date (DD/MM/YYYY): ");
            fgets(buffer, 11, stdin);
            buffer[strcspn(buffer, "\n")] = 0;   //removes newline character from input

            char day[3];
            char month[3];
            char year[5];

            strncpy(day, buffer, 2);
            strncpy(month, buffer+3, 2);
            strncpy(year, buffer+6, 4);

            if(!validateInt(day) || !validateMonth(month) || !validateYear(year)){
                printf("\nInvalid date format!\n");
                continue;
            }

            strncpy(entry->date, buffer, 11);
            printf("\nDate updated!\n");
        }
        else if(strcmp(option, "2") == 0){
            printf("\nEnter the new time (HH:MM): ");
            fgets(buffer, 6, stdin);
            buffer[strcspn(buffer, "\n")] = 0;   //removes newline character from input

            char hour[3];
            char minute[3];

            strncpy(hour, buffer, 2);
            strncpy(minute, buffer+3, 2);

            if(!validateInt(hour) || !validateInt(minute)){
                printf("\nInvalid time format!\n");
                continue;
            }

            strncpy(entry->time, buffer, 6);
            printf("\nTime updated!\n");
        }
        else if(strcmp(option, "3") == 0){
            printf("\nEnter the new entry (maximum 500 characters):\n");
            fgets(buffer, 500, stdin);
            buffer[strcspn(buffer, "\n")] = 0;   //removes newline character from input

            strncpy(entry->entry, buffer, 500);
            printf("\nEntry updated!\n");
        }
        else if(strcmp(option, "4") == 0){
            printf("\nUpdate cancelled.\n");
        }
        else{
            printf("\nInvalid option!\n");
        }
    }while(strcmp(option, "4") != 0);

}

//function to delete an existing diary entry
void deleteEntry(DiaryEntry *entries, int *numOfEntries, int entryIndex){
    for(int i=entryIndex; i<(*numOfEntries)-1; i++){
        strncpy(entries[i].date, entries[i+1].date, 11);
        strncpy(entries[i].time, entries[i+1].time, 6);
        strncpy(entries[i].entry, entries[i+1].entry, 500);
    }
    (*numOfEntries)--;
    printf("\nEntry deleted!\n");
}

//function to save all diary entries to a file
void saveEntries(DiaryEntry *entries, int numOfEntries){
    FILE *fp;

    fp = fopen("diary.txt", "w");
    if(fp == NULL){
        printf("\nError opening file!\n");
        return;
    }

    fprintf(fp, "%d\n", numOfEntries);

    for(int i=0; i<numOfEntries; i++){
        fprintf(fp, "%s\n", entries[i].date);
        fprintf(fp, "%s\n", entries[i].time);
        fprintf(fp, "%s\n", entries[i].entry);
    }

    fclose(fp);
}

//function to load all previously saved diary entries from a file
void loadEntries(DiaryEntry *entries, int *numOfEntries){
    FILE *fp;
    char buffer[100];

    fp = fopen("diary.txt", "r");
    if(fp == NULL){
        return;
    }

    fgets(buffer, 10, fp);
    buffer[strcspn(buffer, "\n")] = 0;
    (*numOfEntries) = atoi(buffer);

    for(int i=0; i<(*numOfEntries); i++){
        fgets(entries[i].date, 11, fp);
        entries[i].date[strcspn(entries[i].date, "\n")] = 0;

        fgets(entries[i].time, 6, fp);
        entries[i].time[strcspn(entries[i].time, "\n")] = 0;

        fgets(entries[i].entry, 500, fp);
        entries[i].entry[strcspn(entries[i].entry, "\n")] = 0;
    }

    fclose(fp);
}

//function to validate if a string contains only a valid integer
bool validateInt(char num[]){
    for(int i=0; i<strlen(num); i++){
        if(num[i]<'0' || num[i]>'9'){
            return false;
        }
    }
    return true;
}

//function to validate if a string contains only a valid month (01-12)
bool validateMonth(char month[]){
    int m = atoi(month);
    return (m>=1 && m<=12);
}

//function to validate if a string contains only a valid year (1900-9999)
bool validateYear(char year[]){
    int y = atoi(year);
    return (y>=1900 && y<=9999);
}