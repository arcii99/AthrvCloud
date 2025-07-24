//FormAI DATASET v1.0 Category: Database querying ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *database;
    database = fopen("database.txt", "r");
    char line[100];
    char *search_term = "Watson";
    int found = 0;

    printf("Looking for records containing '%s'...\n", search_term);

    while (fgets(line, sizeof(line), database)) {
        char *record = strtok(line, ",");
        char *name = strtok(NULL, ",");
        char *occupation = strtok(NULL, "\n");

        if (strstr(record, search_term) || strstr(name, search_term) || strstr(occupation, search_term)) {
            printf("FOUND:\nRecord: %s\nName: %s\nOccupation: %s\n", record, name, occupation);
            found = 1;
        }
    }

    if (!found)
        printf("Sorry, no records found with '%s'.\n", search_term);

    fclose(database);
    return 0;
}