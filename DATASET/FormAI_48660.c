//FormAI DATASET v1.0 Category: Database Indexing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 1000
#define MAX_KEYWORDS 100

typedef struct Record {
    int id;
    char name[50];
    char description[100];
} Record;

typedef struct Keyword {
    char keyword[20];
    int record_ids[MAX_RECORDS];
    int num_records;
} Keyword;

Keyword keywords[MAX_KEYWORDS];
int num_keywords = 0;
Record records[MAX_RECORDS];
int num_records = 0;

// Function to add a record to the database
void addRecord(int id, char name[], char description[]) {
    Record newRecord;
    newRecord.id = id;
    strcpy(newRecord.name, name);
    strcpy(newRecord.description, description);

    records[num_records] = newRecord;
    num_records++;
}

// Function to add a keyword to the indexing system
void addKeyword(char keyword[], int record_id) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(keywords[i].keyword, keyword) == 0) {
            // Keyword already exists, add the record id to the list
            keywords[i].record_ids[keywords[i].num_records] = record_id;
            keywords[i].num_records++;
            return;
        }
    }

    // Keyword doesn't exist, create a new keyword object and add to keywords array
    Keyword newKeyword;
    strcpy(newKeyword.keyword, keyword);
    newKeyword.record_ids[0] = record_id;
    newKeyword.num_records = 1;

    keywords[num_keywords] = newKeyword;
    num_keywords++;
}

// Function to search the database for records containing a certain keyword
void searchDatabase(char keyword[]) {
    bool found = false;

    printf("Results for '%s':\n", keyword);

    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(keywords[i].keyword, keyword) == 0) {
            found = true;

            for (int j = 0; j < keywords[i].num_records; j++) {
                int record_id = keywords[i].record_ids[j];

                printf("ID: %d\n", records[record_id].id);
                printf("Name: %s\n", records[record_id].name);
                printf("Description: %s\n\n", records[record_id].description);
            }
        }
    }

    if (!found) {
        printf("No results found.\n");
    }
}

int main() {
    addRecord(1, "Soccer Ball", "A ball used to play soccer.");
    addKeyword("soccer", 0);
    addKeyword("ball", 0);

    searchDatabase("ball");

    return 0;
}