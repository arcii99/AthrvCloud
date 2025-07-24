//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF_SIZE 1024
#define MAX_FIELD_SIZE 128
#define MAX_FIELDS 20

typedef struct {
    char data[MAX_FIELD_SIZE];
} Field;

typedef struct {
    Field fields[MAX_FIELDS];
    int num_fields;
} Record;

void parse_csv(const char* path, Record* records, int max_records) {
    FILE* fp = fopen(path, "r");

    if (!fp) {
        printf("Failed to open file %s\n", path);
        exit(1);
    }

    int i = 0;
    int j = 0;
    int k = 0;
    int c = 0;
    int quote = 0;
    char buff[MAX_BUFF_SIZE];
    Field field;
    Record record;

    memset(records, 0, sizeof(Record) * max_records);

    while ((c = fgetc(fp)) != EOF) {
        if (c == ',') {
            buff[j++] = '\0';
            strcpy(field.data, buff);
            record.fields[k++] = field;
            memset(buff, 0, MAX_BUFF_SIZE);
            j = 0;
        } else if (c == '\n') {
            buff[j++] = '\0';
            strcpy(field.data, buff);
            record.fields[k++] = field;
            memset(buff, 0, MAX_BUFF_SIZE);
            j = 0;

            if (i < max_records) {
                record.num_fields = k;
                records[i++] = record;
            } else {
                break;
            }

            k = 0;
        } else if (c == '"') {
            quote = !quote;
        } else {
            buff[j++] = c;

            if (j == MAX_BUFF_SIZE) {
                printf("Max buffer size exceeded!\n");
                exit(1);
            }
        }
    }

    fclose(fp);
}

int main() {
    char* path = "example.csv";
    Record records[10];
    int i, j;

    parse_csv(path, records, 10);

    for (i = 0; i < 10; i++) {
        Record record = records[i];

        for (j = 0; j < record.num_fields; j++) {
            printf("%s ", record.fields[j].data);
        }

        printf("\n");
    }

    return 0;
}