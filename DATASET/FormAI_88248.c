//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_ENTRIES 1000

// Define a struct to hold each CSV entry
typedef struct {
    char name[20];
    int score;
    char country[20];
} CsvEntry;

CsvEntry csvEntries[MAX_CSV_ENTRIES];
int numEntries = 0;

// Read CSV file and populate csvEntries array
void readCsvFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    char line[1024];
    fgets(line, 1024, file); // Skip header row

    while (fgets(line, 1024, file) != NULL && numEntries < MAX_CSV_ENTRIES) {
        char* name = strtok(line, ",");
        char* scoreStr = strtok(NULL, ",");
        char* country = strtok(NULL, ",");
        int score = atoi(scoreStr);
        CsvEntry entry = { .name = name, .score = score, .country = country };
        csvEntries[numEntries++] = entry;
    }

    fclose(file);
}

// Print all csvEntries
void printCsvEntries() {
    printf("| %-20s | %-6s | %-20s |\n", "Name", "Score", "Country");
    printf("|----------------------|--------|----------------------|\n");
    for (int i = 0; i < numEntries; i++) {
        printf("| %-20s | %-6d | %-20s |\n", csvEntries[i].name, csvEntries[i].score, csvEntries[i].country);
    }
}

int main() {
    char filename[100];

    // Initialize csvEntries array
    for (int i = 0; i < MAX_CSV_ENTRIES; i++) {
        csvEntries[i] = (CsvEntry) { 0 };
    }

    // Ask for CSV file name and read file
    printf("Enter CSV file name: ");
    scanf("%s", filename);
    readCsvFile(filename);

    // Print all csvEntries
    printCsvEntries();

    return 0;
}