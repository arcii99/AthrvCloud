//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_LEN 50
#define MAX_FIELDS 10

struct record {
    char** fields;
};

struct csv_reader {
    char* filename;
    FILE* file;
    int num_fields;
    char** field_names;
    struct record* records;
    int num_records;
};

struct csv_reader* csv_reader_create(char* filename, int num_fields, char** field_names);
void csv_reader_destroy(struct csv_reader* reader);
int csv_reader_parse(struct csv_reader* reader);
void csv_reader_print(struct csv_reader* reader);

int main() {
    char* filename = "data.csv";
    int num_fields = 3;
    char* field_names[] = {"Name", "Age", "City"};

    struct csv_reader* reader = csv_reader_create(filename, num_fields, field_names);
    if (!reader) {
        printf("Error: failed to create CSV reader\n");
        return 1;
    }

    int ret = csv_reader_parse(reader);
    if (ret) {
        printf("Error: failed to parse CSV file\n");
        csv_reader_destroy(reader);
        return 1;
    }

    csv_reader_print(reader);

    csv_reader_destroy(reader);
    return 0;
}

struct csv_reader* csv_reader_create(char* filename, int num_fields, char** field_names) {
    struct csv_reader* reader = (struct csv_reader*)malloc(sizeof(struct csv_reader));
    if (!reader) {
        return NULL;
    }

    reader->filename = filename;
    reader->file = NULL;
    reader->num_fields = num_fields;

    reader->field_names = (char**)malloc(num_fields * sizeof(char*));
    if (!reader->field_names) {
        free(reader);
        return NULL;
    }

    for (int i = 0; i < num_fields; i++) {
        reader->field_names[i] = (char*)malloc(MAX_FIELD_LEN * sizeof(char));
        if (!reader->field_names[i]) {
            for (int j = 0; j < i; j++) {
                free(reader->field_names[j]);
            }
            free(reader->field_names);
            free(reader);
            return NULL;
        }
        strncpy(reader->field_names[i], field_names[i], MAX_FIELD_LEN);
    }

    reader->records = NULL;
    reader->num_records = 0;

    return reader;
}

void csv_reader_destroy(struct csv_reader* reader) {
    if (reader) {
        if (reader->file) {
            fclose(reader->file);
        }

        if (reader->field_names) {
            for (int i = 0; i < reader->num_fields; i++) {
                free(reader->field_names[i]);
            }
            free(reader->field_names);
        }

        if (reader->records) {
            for (int i = 0; i < reader->num_records; i++) {
                for (int j = 0; j < reader->num_fields; j++) {
                    free(reader->records[i].fields[j]);
                }
                free(reader->records[i].fields);
            }
            free(reader->records);
        }

        free(reader);
    }
}

int csv_reader_parse(struct csv_reader* reader) {
    if (!reader) {
        return 1;
    }

    reader->file = fopen(reader->filename, "r");
    if (!reader->file) {
        return 1;
    }

    reader->records = (struct record*)malloc(sizeof(struct record));
    if (!reader->records) {
        fclose(reader->file);
        return 1;
    }

    char line[MAX_FIELDS * MAX_FIELD_LEN];
    while (fgets(line, sizeof(line), reader->file)) {
        char* field = strtok(line, ",");
        int field_num = 0;

        reader->records = (struct record*)realloc(reader->records, (reader->num_records + 1) * sizeof(struct record));
        if (!reader->records) {
            fclose(reader->file);
            return 1;
        }

        reader->records[reader->num_records].fields = (char**)malloc(reader->num_fields * sizeof(char*));
        if (!reader->records[reader->num_records].fields) {
            fclose(reader->file);
            return 1;
        }

        while (field && field_num < reader->num_fields) {
            reader->records[reader->num_records].fields[field_num] = (char*)malloc(MAX_FIELD_LEN * sizeof(char));
            if (!reader->records[reader->num_records].fields[field_num]) {
                fclose(reader->file);
                return 1;
            }

            strncpy(reader->records[reader->num_records].fields[field_num], field, MAX_FIELD_LEN);

            field = strtok(NULL, ",");
            field_num++;
        }

        reader->num_records++;
    }

    fclose(reader->file);
    reader->file = NULL;

    return 0;
}

void csv_reader_print(struct csv_reader* reader) {
    if (reader) {
        printf("CSV file: %s\n", reader->filename);

        printf("Field names:\n");
        for (int i = 0; i < reader->num_fields; i++) {
            printf("%s ", reader->field_names[i]);
        }
        printf("\n");

        printf("Records:\n");
        for (int i = 0; i < reader->num_records; i++) {
            for (int j = 0; j < reader->num_fields; j++) {
                printf("%s ", reader->records[i].fields[j]);
            }
            printf("\n");
        }
    }
}