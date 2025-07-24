//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 10
#define DELIMITER ","

typedef struct {
    int id;
    char name[MAX_LINE_LENGTH];
    int age;
} Person;

void read_csv(char *filename, Person people[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    // read header
    char header[MAX_LINE_LENGTH];
    if (fgets(header, MAX_LINE_LENGTH, file)) {
        // ignore header
    }

    // read data
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char *field;
        int field_count = 0;

        // tokenize line by delimiter ","
        field = strtok(line, DELIMITER);
        while (field && field_count < MAX_FIELDS) {
            switch (field_count) {
                case 0:
                    people[*count].id = atoi(field);
                    break;
                case 1:
                    strncpy(people[*count].name, field, MAX_LINE_LENGTH);
                    break;
                case 2:
                    people[*count].age = atoi(field);
                    break;
            }

            field = strtok(NULL, DELIMITER);
            field_count++;
        }

        (*count)++;
    }

    fclose(file);
}

int main() {
    Person people[MAX_LINE_LENGTH];
    int count = 0;

    read_csv("people.csv", people, &count);

    printf("ID\tName\tAge\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", people[i].id, people[i].name, people[i].age);
    }

    return 0;
}