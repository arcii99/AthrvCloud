//FormAI DATASET v1.0 Category: Database simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    int id;
    char name[20];
    char email[20];
};

int main() {
    struct record* database;
    int num_records, i;
    printf("Enter the number of records: ");
    scanf("%d", &num_records);
    database = malloc(num_records * sizeof(struct record));
    if (database == NULL) {
        printf("Error: unable to allocate memory\n");
        return 1;
    }
    for (i = 0; i < num_records; i++) {
        printf("Enter record %d's ID, name, and email (separated by spaces): ", i+1);
        scanf("%d %s %s", &database[i].id, database[i].name, database[i].email);
    }
    printf("Database initialized:\n");
    for (i = 0; i < num_records; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", database[i].id, database[i].name, database[i].email);
    }
    free(database);
    return 0;
}