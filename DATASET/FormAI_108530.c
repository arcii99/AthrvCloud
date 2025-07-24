//FormAI DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_RECORDS 1000
#define MAX_FIELD_LENGTH 50

typedef struct {
    char name[MAX_FIELD_LENGTH];
    int age;
    char occupation[MAX_FIELD_LENGTH];
    float salary;
} Record;

int main() {

    FILE *file = fopen("data.txt", "r");
    if (!file) {
        printf("Error: failed to open file!\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    Record records[MAX_NUM_RECORDS];
    int num_records = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char *str = strdup(line); // make a copy of the line
        char *tok = strtok(str, ","); // tokenize the line using comma as delimiter
        Record record;

        // parse the fields
        if (tok) {
            strncpy(record.name, tok, MAX_FIELD_LENGTH);
            tok = strtok(NULL, ",");
            if (tok) record.age = atoi(tok);
            else record.age = 0;
            tok = strtok(NULL, ",");
            if (tok) strncpy(record.occupation, tok, MAX_FIELD_LENGTH);
            else record.occupation[0] = '\0';
            tok = strtok(NULL, ",");
            if (tok) record.salary = atof(tok);
            else record.salary = 0.0f;
        }

        // add the record to the array
        records[num_records++] = record;

        // free memory
        free(str);
    }

    // close file
    fclose(file);

    // print records
    for (int i = 0; i < num_records; i++) {
        Record record = records[i];
        printf("Name: %s\n", record.name);
        printf("Age: %d\n", record.age);
        printf("Occupation: %s\n", record.occupation);
        printf("Salary: %.2f\n", record.salary);
        printf("------------------\n");
    }

    return 0;
}